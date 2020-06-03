

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

var server = newSocket()
server.bindAddr(Port(1234))
server.listen()

var client = newSocket()

while true:
  echo "wait for client: "
  server.accept(client)
  client.handle()

