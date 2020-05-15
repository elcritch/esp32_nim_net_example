
import asynchttpserver, asyncdispatch

proc cb*(req: Request) {.async.} =
    await req.respond(Http200, "Hello World")

proc run_http_server*() =
    var server = newAsyncHttpServer()

    waitFor server.serve(Port(8080), cb)
