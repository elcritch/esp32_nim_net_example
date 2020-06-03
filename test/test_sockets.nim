import threadpool
import net
import os
import selectors
import strutils

type
  Server = ref object of RootObj
    socket: Socket

# Amount of data to send
const content = "Hello world!"
const response = "HTTP/1.1 200 OK\r\LContent-Length: " & $content.len & "\r\L\r\L" & content

proc handle(client: Socket) =
  # TaintedString is used for strings coming from the outside, security mechanism.
  var buf = TaintedString""
  try:
    client.readLine(buf, timeout = 20000)
    client.send(response)
  finally:
    client.close()

proc loop(self: Server) =
  var selector = newSelector()
  discard selector.register(self.socket.getFD, {EvRead}, nil)
  while true:
    if selector.select(1000).len > 0:
      var client: Socket = Socket()
      accept(self.socket, client)
      spawn handle(client)

proc listen(server: Server, port: int) =
  server.socket = newSocket()
  try:
    server.socket.bindAddr(port = Port(port))
    server.socket.setSockOpt(OptReuseAddr, true)
    server.socket.setSockOpt(OptKeepAlive, true)
    server.socket.listen()
    echo("Server listening on port " & $port)
    server.loop()
  finally:
    server.socket.close()

when isMainModule:
  var port = 8099
  var server = Server()
  server.listen(port)