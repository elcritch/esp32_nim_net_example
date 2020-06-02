##  #include <erl_format.h>
import strutils
import posix
import net
import einode/src/einode
import einode/src/publish

const
  BUFSIZE* = 1000

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

proc my_listen(port: Port): Socket =
  var socket = newSocket()
  socket.bindAddr(port, address="")
  socket.setSockOpt(OptReuseAddr, true)
  socket.setSockOpt(OptKeepAlive, true)
  socket.listen()
  return socket

proc run_http_server*() {.exportc.} =
  var node_name = "cnode1"
  var port = Port(5000)

  echo("starting: " )
  var einode: EiNode = newEiNode(
    node_name,
    "127.0.0.1",
    cookie = "secretcookie",
    port = 5000,
    alivename = "alpha",
  )

  einode.initialize()

  ##  Listen socket
  var sock = my_listen(port)
  einode.publishServer(address="") 

  # var conn: ErlConnect
  # echo("listening on port: $1" % [$port])
  # echo("Connected to `$1`" % [ $(cast[cstring](conn.nodename[0].addr))])

  # var info: ErlangMsg
  var emsg: EiBuff

  discard new_ei_x_size(emsg.addr, 128)

  ##  Lopp flag
 
  ##  Lopp flag
  for (msgtype, info, eterm) in receive(einode):
    case msgtype
    of REG_SEND:
      var res: cint = 0

      echo("erl_reg_send: msgtype: $1 " %
              [ $info.msgtype, ])

      var main_msg: seq[ErlTerm] = eterm.getTuple()

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

      einode.send(to = info.`from`, msg = rmsg)
    else:
      echo("unhandled message: " & $msgtype)
