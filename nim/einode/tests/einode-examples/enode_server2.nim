##  #include <erl_format.h>
import strutils
import os
import posix
import segfaults
import net
import einode/codec
import einode/ei 

const
  BUFSIZE* = 1000

# proc ei_malloc(size: clong): pointer
proc new_ei_x_size*(x: ptr EiBuff; size: clong): cint

proc foo*(x: int): int =
    return x + 1
proc bar*(y: int): int =
    return y * 2

proc my_listen(port: Port): Socket =
  var socket = newSocket()
  socket.bindAddr(port, address="")
  socket.setSockOpt(OptReuseAddr, true)
  socket.setSockOpt(OptKeepAlive, true)
  socket.listen()
  return socket

proc main*() =
  let arguments = commandLineParams()
  var port: Port = Port(parseInt($(arguments[0])))
  var node_name =
    if len(arguments) == 2:
      arguments[1]
    else:
      "cnode1"

  echo("starting: " )

  discard ei_init()

  var node_addr: InAddr
  ##  32-bit IP number of host
  node_addr.s_addr = inet_addr("127.0.0.1")

  var ec: EiCnode

  if ei_connect_xinit(ec.addr, "alpha",
                      node_name,
                      node_name & "@127.0.0.1",
                      node_addr.addr,
                      "secretcookie", 0) < 0:
    raise newException(LibraryError, "ERROR: when initializing ei_connect_xinit ")

  ##  Listen socket
  var listen: Socket = my_listen(port)

  if ei_publish(ec.addr, port.cint) == -1:
    raise newException(LibraryError, "ERROR: publishing on port $1" % [$port])

  var conn: ErlConnect

  ##  Connection data
  var fd = ei_accept(ec.addr, listen.getFd().cint, conn.addr)
  if fd == ERL_ERROR:
    raise newException(LibraryError, "ERROR: erl_accept on listen socket $1" % [repr(listen)])

  echo("listening on port: $1" % [$port])
  echo("Connected to `$1`" % [ $(cast[cstring](conn.nodename[0].addr))])

  var info: ErlangMsg
  var emsg: EiBuff

  discard new_ei_x_size(emsg.addr, 128)

  ##  Lopp flag
  ## 
  var mtype
  while mtype = ei_xreceive_msg(fd, addr(info), addr(emsg)):
    if mtype == ERL_TICK:
      echo("tick: " & $mtype)
    elif mtype == ERL_ERROR:
      echo("err: " )
      loop = false
      raise newException(LibraryError, "erl_error: " & $mtype)
    else:
      echo("message: " & $mtype)
      if info.msgtype == ERL_REG_SEND:
        var res: cint = 0

        var main_msg: seq[ErlTerm] = eterms.getTuple()
        var rpc_msg = main_msg[2].getTuple()
        var msg_atom = rpc_msg[0].getAtom()
        var msg_arg = rpc_msg[1].getInt32()

        if msg_atom.n == "foo":
          echo( "foo: " & $msg_arg)
          res = foo(msg_arg).cint
        elif msg_atom.n == "bar":
          echo( "bar: " & $msg_arg)
          res = bar(msg_arg).cint
        else:
          echo("other: " & $msg_arg)
          echo("other message: " & $msg_atom)

        var rmsg = newETuple(@[newEAtom("cnode"), newETerm(res)])
        var ssout = termToBinary(rmsg)

        discard ei_send(fd, addr(info.`from`), ssout.data, ssout.pos)


proc new_ei_x_size(x: ptr EiBuff; size: int): cint =
  # x.buff = cast[cstring](ei_malloc(size))
  x.buff = cast[cstring](alloc(size))
  x.buffsz = size.cint
  x.index = 0
  return if x.buff != nil: 0 else: -1

when isMainModule:
  main()
