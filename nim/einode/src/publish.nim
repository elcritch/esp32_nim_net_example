
import strutils
import posix
import net
import options

import einode/codec
import einode/ei
import einode

# export codec
# export ei

proc publishServer*(einode: var EiNode; address: string = "") =

  var socket: Socket = newSocket()
  socket.bindAddr(Port(einode.port), address=address) # bind all
  socket.setSockOpt(OptReuseAddr, true)
  socket.setSockOpt(OptKeepAlive, true)
  socket.listen()

  einode.sock = some(socket)
  if ei_publish(einode.ec.addr, einode.port.cint) == -1:
    raise newException(LibraryError, "ERROR: publishing on port $1" % [$(einode.port)])

  var fd = ei_accept(einode.ec.addr,
                     socket.getFd().cint,
                     einode.conn.addr)

  if fd == ERL_ERROR:
    raise newException(LibraryError, "ERROR: erl_accept on listen socket " & repr(socket))
