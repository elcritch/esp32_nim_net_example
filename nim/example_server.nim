##  #include <erl_format.h>
import strutils
import net
import os
import einode/src/einode
import einode/src/publish
import system/ansi_c

const
  BUFSIZE* = 1000

proc delay*(milsecs: int) {.importc: "delay".}

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

proc run_http_server*() {.exportc.} =
  cprintf("starting: \n")
  for i in 1..10:
    echo("starting: " & $i)
    delay(1_000)

  echo("done: ")

proc other_run_http_server*() {.exportc.} =
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
  # einode.publishServer(address="") 

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
