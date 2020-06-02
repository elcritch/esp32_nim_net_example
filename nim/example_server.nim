##  #include <erl_format.h>
import strutils
import os
import posix
import net
import einode/src/einode

const
  BUFSIZE* = 1000

# int gethostname(char *__name, size_t __len);
var node_name = "cnode"

type TickType* {.importc: "TickType_t", header: """#include <freertos/FreeRTOS.h>
                                                    #include <freertos/task.h>""".} = distinct uint32
var portTICK_PERIOD_MS* {.importc: "portTICK_PERIOD_MS", header: """#include <freertos/FreeRTOS.h>
                                                    #include <freertos/task.h>""".}: cint
proc vTaskDelay*(ticks: TickType) {.importc: "TickType_t", header: """#include <freertos/FreeRTOS.h>
                                                    #include <freertos/task.h>""".}

proc gethostname*(name: cstring, len: csize): cint {.exportc.} =
  copyMem(name, node_name.cstring, len(node_name))

# proc ei_malloc(size: clong): pointer
proc foo*(x: int): int =
    return x + 1
proc bar*(y: int): int =
    return y * 2

var t:TickType = (1_000 div portTICK_PERIOD_MS).TickType

proc run_http_server*() {.exportc.} =
  var node_name: string = "enode"
  echo("starting: " )

  var einode = newEiNode(node_name, "127.0.0.1", cookie = "secretcookie", port = 8181)

  einode.initialize()

  ##  Connect to server
  var server_node = "e1@127.0.0.1"
  einode.connectServer(server_node):
    echo("Warning: unable to connect to node: " & server_node)
    # os.sleep(1_000)
    vTaskDelay(t)


    
  echo("Connected to: " & server_node);

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


when isMainModule:
  run_http_server()
