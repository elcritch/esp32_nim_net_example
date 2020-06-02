##  #include <erl_format.h>
import strutils
import net
import os
import einode/src/einode
# import einode/src/publish
import system/ansi_c

const
  BUFSIZE* = 1000

var ei_tracelevel* {.importc: "ei_tracelevel".}: cint
proc delay*(milsecs: int) {.importc: "delay".}

proc publishServer*(einode: var EiNode; address: string = "") =

  echo("socket start: " )
  ei_tracelevel = 5
  var socket: Socket = newSocket()
  socket.bindAddr(Port(einode.port), address=address) # bind all
  socket.setSockOpt(OptReuseAddr, true)
  socket.setSockOpt(OptKeepAlive, true)
  socket.listen()
  einode.sock = some(socket)
  echo("socket listening: " & $repr(socket) )
  delay(1_000)
  echo("socket publish: " )
  delay(1_000)

  if ei_publish(einode.ec.addr, einode.port.cint) == -1:
    echo("publish error: " )
    delay(1_000)
    raise newException(LibraryError, "ERROR: publishing on port " & $(einode.port))

  echo("socket published: " )
  delay(1_000)
  echo("socket accept: " )
  delay(1_000)

  var fd = ei_accept(einode.ec.addr,
                     socket.getFd().cint,
                     einode.conn.addr)

  if fd == ERL_ERROR:
    raise newException(LibraryError, "ERROR: erl_accept on listen socket " & repr(socket))

# proc ei_malloc(size: clong): pointer
proc new_ei_x_size(x: ptr EiBuff; size: int): cint =
  # x.buff = cast[cstring](ei_malloc(size))
  x.buff = cast[cstring](alloc(size))
  x.buffsz = size.cint
  x.index = 0
  return if x.buff != nil: 0 else: -1

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
  # vTaskDelay(2000 / portTICK_PERIOD_MS);
  delay(1_000)

  var node_name = "cnode1"
  var port = Port(5000)

  echo("starting: " )
  delay(1_000)

  var einode: EiNode = newEiNode(
    node_name,
    "127.0.0.1",
    cookie = "secretcookie",
    port = 5000,
    alivename = "alpha",
  )

  einode.initialize()
  echo("initialized..." )
  delay(1_000)

  # ##  Listen socket
  einode.publishServer(address="") 

  echo("published..." )
  count_down()
  # # var conn: ErlConnect
  # echo("listening on port: $1" & $port)
  # echo("Connected to `$1`" & $(cast[cstring](einode.conn.nodename[0].addr)))

  # # var info: ErlangMsg
  # var emsg: EiBuff

  # discard new_ei_x_size(emsg.addr, 128)

  # ##  Lopp flag
 
  # ##  Lopp flag
  # for (msgtype, info, eterm) in receive(einode):
  #   case msgtype
  #   of REG_SEND:
  #     var res: cint = 0

  #     echo("erl_reg_send: msgtype: $1 " %
  #             [ $info.msgtype, ])

  #     var main_msg: seq[ErlTerm] = eterm.getTuple()

  #     var rpc_msg = main_msg[2].getTuple()
  #     var msg_atom = rpc_msg[0].getAtom()
  #     var msg_arg = rpc_msg[1].getInt32()

  #     if msg_atom.n == "foo":
  #       echo( "foo: " & $msg_arg)
  #       res = foo(msg_arg).cint
  #     elif msg_atom.n == "bar":
  #       echo( "bar: " & $msg_arg)
  #       res = bar(msg_arg).cint
  #     else:
  #       echo("other: " & $msg_arg)
  #       echo("other message: " & $msg_atom)

  #     var rmsg = newETuple(@[newEAtom("cnode"), newETerm(res)])

  #     einode.send(to = info.`from`, msg = rmsg)
  #   else:
  #     echo("unhandled message: " & $msgtype)
