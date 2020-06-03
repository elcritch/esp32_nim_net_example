##  #include <erl_format.h>
import strutils
import net
import posix
import einode/src/einode
import einode/src/einode/ei
# import einode/src/publish
import system/ansi_c

const
  BUFSIZE* = 1000

proc new_ei_x_size*(x: ptr EiBuff; size: clong): cint

var ei_tracelevel* {.importc: "ei_tracelevel".}: cint
var erl_errno* {.importc: "__erl_errno", volatile.}: cint
proc delay*(milsecs: int) {.importc: "delay".}

proc my_listen*(port: Port): Socket =
  var socket = newSocket()
  socket.bindAddr(port, address="")
  socket.setSockOpt(OptReuseAddr, true)
  socket.setSockOpt(OptKeepAlive, true)
  socket.listen()
  return socket

proc publishServer*(einode: var EiNode; address: string = "") =

  echo("socket start: " )
  ei_tracelevel = 5
  var socket: Socket = newSocket()
  socket.bindAddr(Port(einode.port), address=address) # bind all
  socket.setSockOpt(OptReuseAddr, true)
  socket.setSockOpt(OptKeepAlive, true)
  socket.listen()
  einode.sock = some(socket)
  echo("socket listening: " & $repr(socket.getFd()) )
  echo("socket publish: " )
  delay(100)

  # var published_ret = ei_publish(einode.ec.addr, einode.port.cint)
  # if published_ret < 0:
  #   echo("publish error: " & $published_ret )
  #   echo("publish erl_errno: " & $erl_errno )
  #   delay(1_000)
  #   raise newException(LibraryError, "ERROR: publishing on port " & $(einode.port))

  # echo("socket published: " )
  # delay(1_000)
  echo("socket accept: " )
  delay(100)

  var fd = ei_accept(einode.ec.addr,
                     socket.getFd().cint,
                     einode.conn.addr)

  if fd == ERL_ERROR:
    raise newException(LibraryError, "ERROR: erl_accept on listen socket " & repr(socket))

# example procs
proc foo*(x: int): int =
    return x + 1
proc bar*(y: int): int =
    return y * 2

proc count_down*() =
  cprintf("starting: \n")
  for i in 1..10:
    echo("starting: " & $i)
    delay(1_000)

  echo("done: ")

proc run_http_server*() {.exportc.} =
  echo("starting: " )

  var port = Port(4370)
  var name = "cnode"
  var ip = "192.168.1.36"

  echo("starting: " )

  discard ei_init()

  var node_addr: InAddr
  ##  32-bit IP number of host
  node_addr.s_addr = inet_addr(ip)

  var ec: EiCnode

  echo("xinit: " )
  if ei_connect_xinit(ec.addr, "alpha", name, name & "@" & ip, node_addr.addr,
                     "secretcookie", 0) < 0:
    raise newException(LibraryError, "ERROR: when initializing ei_connect_xinit ")

  ##  Listen socket
  echo("listen: " & $port )
  var listen = my_listen(port)

  # if ei_publish(ec.addr, port.cint) == -1:
    # raise newException(LibraryError, "ERROR: publishing on port $1" % [$port])

  var conn: ErlConnect

  ##  Connection data
  echo("accept: " )
  var fd = ei_accept(ec.addr, listen.getFd().cint, conn.addr)
  if fd == ERL_ERROR:
    raise newException(LibraryError, "ERROR: erl_accept on listen socket $1" % [repr(listen)])

  echo("listening on port: " & $port)
  echo("Connected to " & $conn.nodename)

  var info: ErlangMsg
  var emsg: EiBuff
  var x_out: EiBuff

  discard new_ei_x_size(emsg.addr, 128)

  ##  Lopp flag
  var loop: bool = true
  while loop:
    echo("loop: ")
    var got: cint = ei_receive_msg(fd, addr(info), addr(emsg))
    if got == ERL_TICK:
      echo("tick: " & $got)
    elif got == ERL_ERROR:
      echo("err: " )
      loop = false
      raise newException(LibraryError, "erl_error: " & $got)
    else:
      ##  ETERM *fromp, *tuplep, *fnp, *argp, *resp;
      echo("message: " & $got)
      if info.msgtype == ERL_REG_SEND.clong:
        var res: cint = 0
        var version: cint
        var arity: cint
        var msg_atom = newString(MAXATOMLEN + 1)
        var msg_arg: clong
        var pid: ErlangPid

        echo("erl_reg_send: msgtype: $1 buff: $2 idx: $3 bufsz: $4 " %
                [ $info.msgtype, $emsg.buff, $emsg.index, $emsg.buffsz])

        emsg.index = 0
        if ei_decode_version(emsg.buff, addr(emsg.index), addr(version)) < 0:
          raise newException(LibraryError, "ignoring malformed message (bad version: $1) " % [$version])

        if ei_decode_tuple_header(emsg.buff, addr(emsg.index), addr(arity)) < 0:
          raise newException(LibraryError, "ignoring malformed message (not tuple) ")
        if arity != 3:
          raise newException(LibraryError, "ignoring malformed message (must be a 3-arity tuple ")
        if ei_decode_atom(emsg.buff, addr(emsg.index), cstring(msg_atom)) < 0:
          raise newException(LibraryError, "ignoring malformed message (first tuple element not atom ")
        if ei_decode_pid(emsg.buff, emsg.index.addr, pid.addr) < 0:
          raise newException(LibraryError, "ignoring malformed message (first tuple element of second tuple element not pid) ")
        if ei_decode_tuple_header(emsg.buff, addr(emsg.index), addr(arity)) < 0 or
            arity != 2:
          raise newException(LibraryError, "ignoring malformed message (second tuple element not 2-arity tuple) ")
        if ei_decode_atom(emsg.buff, emsg.index.addr, cstring(msg_atom)) < 0:
          raise newException(LibraryError, "ignoring malformed message (first message tuple element not atom) ")
        if ei_decode_long(emsg.buff, emsg.index.addr, msg_arg.addr) < 0:
          raise newException(LibraryError, "ignoring malformed message (second message tuple element not an int)")

        var fname: string = $(cstring(msg_atom))
        echo( "fname: " & fname)
        echo( "fname:len: " & $len(fname))
        echo( "fname:type: " & $typeof(fname))
        echo( "fname:repr: " & repr(fname))
        echo( "fname:foo: " & "foo")

        if fname == "foo":
          echo( "foo: " & $msg_arg)
          res = foo(msg_arg).cint
        if fname == "bar":
          echo( "bar: " & $msg_arg)
          res = bar(msg_arg).cint
        else:
          echo("other: " & $msg_arg)
          echo("other message: " & fname)
          echo("other message: " & $msg_atom)

        x_out.index = 0
        discard ei_x_format(addr(x_out), "{cnode,~i}", res)
        discard ei_send(fd, addr(info.`from`), x_out.buff, x_out.index)
        ##  erl_free_term(argp);

proc new_ei_x_size(x: ptr EiBuff; size: int): cint =
  # x.buff = cast[cstring](ei_malloc(size))
  x.buff = cast[cstring](alloc(size))
  x.buffsz = size.cint
  x.index = 0
  return if x.buff != nil: 0 else: -1
