

import net, strutils

proc handle(client: Socket) =
  var active = true
  while active:
    var msg = client.recvline()
    if msg == "":
      active = false

    echo "client says: ", msg
    var sent = client.trysend(msg)
    echo "client sent: ", sent
  echo "client disconnect "

proc run_tcp_server*() {.exportc.} =
  echo("starting tcp server: " )
  var server = newSocket()
  server.bindAddr(Port(1234))
  server.listen()

  var client = newSocket()

  # No threading or async -- we only support on tcp stream at a time
  while true:
    echo "wait for client: "
    server.accept(client)
    client.handle()

