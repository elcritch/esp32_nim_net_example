
import asynchttpserver, asyncdispatch

proc cb*(req: Request) {.async.} =
    await req.respond(Http200, "Hello World")

proc run_http_server*() {.exportc.} =
    echo "starting http server at http://localhost/8080"
    var server = newAsyncHttpServer()

    waitFor server.serve(Port(8080), cb)

when isMainModule:
    echo "running server"
    run_http_server()

