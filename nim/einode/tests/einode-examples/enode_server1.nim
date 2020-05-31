##  #include <erl_format.h>
import strutils
import os
import posix
import segfaults
import net

import einode/ei 

const
  BUFSIZE* = 1000

# proc ei_malloc(size: clong): pointer
proc new_ei_x_size*(x: ptr EiBuff; size: clong): cint

proc foo*(x: int): int =
    return x + 1
proc bar*(y: int): int =
    return y * 2

proc my_listen*(port: Port): Socket =
  var socket = newSocket()
  socket.bindAddr(port, address="")
  socket.setSockOpt(OptReuseAddr, true)
  socket.setSockOpt(OptKeepAlive, true)
  socket.listen()
  return socket

proc main*() =
  let arguments = commandLineParams()
  var port: Port = Port(parseInt($(arguments[0])))

  echo("starting: " )

  discard ei_init()

  var node_addr: InAddr
  ##  32-bit IP number of host
  node_addr.s_addr = inet_addr("127.0.0.1")

  var ec: EiCnode

  if ei_connect_xinit(ec.addr, "alpha", "cnode", "cnode@127.0.0.1", node_addr.addr,
                     "secretcookie", 0) < 0:
    raise newException(LibraryError, "ERROR: when initializing ei_connect_xinit ")

  ##  Listen socket
  var listen = my_listen(port)

  if ei_publish(ec.addr, port.cint) == -1:
    raise newException(LibraryError, "ERROR: publishing on port $1" % [$port])

  var conn: ErlConnect

  ##  Connection data
  var fd = ei_accept(ec.addr, listen.getFd().cint, conn.addr)
  if fd == ERL_ERROR:
    raise newException(LibraryError, "ERROR: erl_accept on listen socket $1" % [repr(listen)])

  echo("listening on port: $1" % [$port])
  echo("Connected to $1" % [$conn.nodename])

  var info: ErlangMsg
  var emsg: EiBuff
  var x_out: EiBuff

  discard new_ei_x_size(emsg.addr, 128)

  ##  Lopp flag
  var loop: bool = true
  while loop:
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
      if info.msgtype == ERL_REG_SEND:
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

when isMainModule:
  main()
