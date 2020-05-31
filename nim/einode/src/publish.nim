
import strutils
import os
import posix
import net
import options

import einode/codec
import einode/ei
import einode

export codec
export ei

proc publishServer*(einode: var EiNode; address: string = "") =

  var listen = newSocket()
  listen.bindAddr(einode.port, address=address) # bind all
  listen.setSockOpt(OptReuseAddr, true)
  listen.setSockOpt(OptKeepAlive, true)
  listen.listen()

  einode.listen = some(listen)
  if ei_publish(einode.ec.addr, einode.port.cint) == -1:
    raise newException(LibraryError, "ERROR: publishing on port $1" % [$(einode.port)])

  var fd = ei_accept(einode.ec.addr,
                     listen.getFd().cint,
                     einode.conn.addr)

  if fd == ERL_ERROR:
    raise newException(LibraryError, "ERROR: erl_accept on listen socket $1" % [repr(listen)])
