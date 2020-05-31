##
##  %CopyrightBegin%
##
##  Copyright Ericsson AB 1998-2016. All Rights Reserved.
##
##  Licensed under the Apache License, Version 2.0 (the "License");
##  you may not use this file except in compliance with the License.
##  You may obtain a copy of the License at
##
##      http://www.apache.org/licenses/LICENSE-2.0
##
##  Unless required by applicable law or agreed to in writing, software
##  distributed under the License is distributed on an "AS IS" BASIS,
##  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
##  See the License for the specific language governing permissions and
##  limitations under the License.
##
##  %CopyrightEnd%
##

import posix

var EI_HAVE_TIMEOUT* {.importc: "EI_HAVE_TIMEOUT", header: "<ei.h>".}: cint

##  --------------------------------------------------------------------
##                       Defines part of API
##  --------------------------------------------------------------------
##
##  Some error codes might be missing, so here's a backstop definitions
##  of the ones we use with `erl_errno':
##

##  FIXME just a few are documented, does it mean they can't be returned?

var ERL_ERROR* {.importc: "ERL_ERROR", header: "<ei.h>".}: cint
var ERL_NO_DAEMON* {.importc: "ERL_NO_DAEMON", header: "<ei.h>".}: cint
var ERL_NO_PORT* {.importc: "ERL_NO_PORT", header: "<ei.h>".}: cint
var ERL_CONNECT_FAI* {.importc: "ERL_CONNECT_FAI", header: "<ei.h>".}: cint
var ERL_TIMEOUT* {.importc: "ERL_TIMEOUT", header: "<ei.h>".}: cint
var ERL_NO_REMOTE* {.importc: "ERL_NO_REMOTE", header: "<ei.h>".}: cint
var ERL_TICK* {.importc: "ERL_TICK", header: "<ei.h>".}: cint
var ERL_MSG* {.importc: "ERL_MSG", header: "<ei.h>".}: cint
var ERL_NO_TIMEOUT* {.importc: "ERL_NO_TIMEOUT", header: "<ei.h>".}: cint

type 
  ErlApiType* = distinct cint 

proc `$`*(e: ErlApiType): string = $(e.cint)
proc `==`*(o: ErlApiType, e: ErlApiType): bool =  e.cint == o.cint

const
  ApiNoRemote* = ErlApiType(-6)
  ApiTimeout* = ErlApiType(-5)
  ApiConnectFail* = ErlApiType(-4)
  ApiNoPort* = ErlApiType(-3)
  ApiNoDaemon* = ErlApiType(-2)
  ApiError* = ErlApiType(-1)
  ApiTick* = ErlApiType(0)
  ApiMsg* = ErlApiType(1)

var ERL_LINK* {.importc: "ERL_LINK", header: "<ei.h>".}: ErlApiType
var ERL_SEND* {.importc: "ERL_SEND", header: "<ei.h>".}: ErlApiType
var ERL_EXIT* {.importc: "ERL_EXIT", header: "<ei.h>".}: ErlApiType
var ERL_UNLINK* {.importc: "ERL_UNLINK", header: "<ei.h>".}: ErlApiType
var ERL_NODE_LINK* {.importc: "ERL_NODE_LINK", header: "<ei.h>".}: ErlApiType
var ERL_REG_SEND* {.importc: "ERL_REG_SEND", header: "<ei.h>".}: ErlApiType
var ERL_GROUP_LEADER* {.importc: "ERL_GROUP_LEADER", header: "<ei.h>".}: ErlApiType
var ERL_EXIT2* {.importc: "ERL_EXIT2", header: "<ei.h>".}: ErlApiType
var ERL_PASS_THROUGH* {.importc: "ERL_PASS_THROUGH", header: "<ei.h>".}: ErlApiType

# ##  new ones for tracing, from Kenneth

var ERL_SEND_TT* {.importc: "ERL_SEND_TT", header: "<ei.h>".}: cint
var ERL_EXIT_TT* {.importc: "ERL_EXIT_TT", header: "<ei.h>".}: cint
var ERL_REG_SEND_TT* {.importc: "ERL_REG_SEND_TT", header: "<ei.h>".}: cint
var ERL_EXIT2_TT* {.importc: "ERL_EXIT2_TT", header: "<ei.h>".}: cint
var ERL_MONITOR_P* {.importc: "ERL_MONITOR_P", header: "<ei.h>".}: cint
var ERL_DEMONITOR_P* {.importc: "ERL_DEMONITOR_P", header: "<ei.h>".}: cint
var ERL_MONITOR_P_EXIT* {.importc: "ERL_MONITOR_P_EXIT", header: "<ei.h>".}: cint


### ENUM ? 

##  FIXME just a few are documented, does it mean they can't be returned?

type 
  ErlMessageType* = distinct cint 

proc `$`*(e: ErlMessageType): string = $(e.cint)
proc `==`*(o: ErlMessageType, e: ErlMessageType): bool =  e.cint == o.cint

const 
  LINK* = ErlMessageType(1)
  SEND* = ErlMessageType(2)
  EXIT* = ErlMessageType(3)
  UNLINK* = ErlMessageType(4)
  NODE_LINK* = ErlMessageType(5)
  REG_SEND* = ErlMessageType(6)
  GROUP_LEADER* = ErlMessageType(7)
  EXIT2* = ErlMessageType(8)
  
##  new ones for tracing, from Kenneth
const
  SEND_TT* = ErlMessageType(12)
  EXIT_TT* = ErlMessageType(13)
  REG_SEND_TT* = ErlMessageType(16)
  EXIT2_TT* = ErlMessageType(18)
  MONITOR_P* = ErlMessageType(19)
  DEMONITOR_P* = ErlMessageType(20)
  MONITOR_P_EXIT* = ErlMessageType(21)
  PASS_THROUGH* = ErlMessageType(11)


##  --------------------------------------------------------------------
##            Defines used for ei_get_type_internal() output
##  --------------------------------------------------------------------
##
##  these are the term type indicators used in
##  the external (distribution) format
##
##  FIXME we don't want to export these.....

var EXT_ERL_SMALL_INTEGER_EXT* {.importc: "ERL_SMALL_INTEGER_EXT", header: "<ei.h>".}: cint
var EXT_ERL_INTEGER_EXT* {.importc: "ERL_INTEGER_EXT", header: "<ei.h>".}: cint
var EXT_ERL_FLOAT_EXT* {.importc: "ERL_FLOAT_EXT", header: "<ei.h>".}: cint
var EXT_NEW_FLOAT_EXT* {.importc: "NEW_FLOAT_EXT", header: "<ei.h>".}: cint
var EXT_ERL_ATOM_EXT* {.importc: "ERL_ATOM_EXT", header: "<ei.h>".}: cint
var EXT_ERL_SMALL_ATOM_EXT* {.importc: "ERL_SMALL_ATOM_EXT", header: "<ei.h>".}: cint
var EXT_ERL_ATOM_UTF8_EXT* {.importc: "ERL_ATOM_UTF8_EXT", header: "<ei.h>".}: cint
var EXT_ERL_SMALL_ATOM_UTF8_EXT* {.importc: "ERL_SMALL_ATOM_UTF8_EXT", header: "<ei.h>".}: cint
var EXT_ERL_REFERENCE_EXT* {.importc: "ERL_REFERENCE_EXT", header: "<ei.h>".}: cint
var EXT_ERL_NEW_REFERENCE_EXT* {.importc: "ERL_NEW_REFERENCE_EXT", header: "<ei.h>".}: cint
var EXT_ERL_NEWER_REFERENCE_EXT* {.importc: "ERL_NEWER_REFERENCE_EXT", header: "<ei.h>".}: cint
var EXT_ERL_PORT_EXT* {.importc: "ERL_PORT_EXT", header: "<ei.h>".}: cint
var EXT_ERL_NEW_PORT_EXT* {.importc: "ERL_NEW_PORT_EXT", header: "<ei.h>".}: cint
var EXT_ERL_PID_EXT* {.importc: "ERL_PID_EXT", header: "<ei.h>".}: cint
var EXT_ERL_NEW_PID_EXT* {.importc: "ERL_NEW_PID_EXT", header: "<ei.h>".}: cint
var EXT_ERL_SMALL_TUPLE_EXT* {.importc: "ERL_SMALL_TUPLE_EXT", header: "<ei.h>".}: cint
var EXT_ERL_LARGE_TUPLE_EXT* {.importc: "ERL_LARGE_TUPLE_EXT", header: "<ei.h>".}: cint
var EXT_ERL_NIL_EXT* {.importc: "ERL_NIL_EXT", header: "<ei.h>".}: cint
var EXT_ERL_STRING_EXT* {.importc: "ERL_STRING_EXT", header: "<ei.h>".}: cint
var EXT_ERL_LIST_EXT* {.importc: "ERL_LIST_EXT", header: "<ei.h>".}: cint
var EXT_ERL_BINARY_EXT* {.importc: "ERL_BINARY_EXT", header: "<ei.h>".}: cint
var EXT_ERL_BIT_BINARY_EXT* {.importc: "ERL_BIT_BINARY_EXT", header: "<ei.h>".}: cint
var EXT_ERL_SMALL_BIG_EXT* {.importc: "ERL_SMALL_BIG_EXT", header: "<ei.h>".}: cint
var EXT_ERL_LARGE_BIG_EXT* {.importc: "ERL_LARGE_BIG_EXT", header: "<ei.h>".}: cint
var EXT_ERL_NEW_FUN_EXT* {.importc: "ERL_NEW_FUN_EXT", header: "<ei.h>".}: cint
var EXT_ERL_MAP_EXT* {.importc: "ERL_MAP_EXT", header: "<ei.h>".}: cint
var EXT_ERL_FUN_EXT* {.importc: "ERL_FUN_EXT", header: "<ei.h>".}: cint
var EXT_ERL_EXPORT_EXT* {.importc: "ERL_EXPORT_EXT", header: "<ei.h>".}: cint
var EXT_ERL_NEW_CACHE* {.importc: "ERL_NEW_CACHE", header: "<ei.h>".}: cint
var EXT_ERL_CACHED_ATOM* {.importc: "ERL_CACHED_ATOM", header: "<ei.h>".}: cint

## TODO: Check this on major OTP updates. They pretend this should be encapsulated/hidden.
type 
  ErlExtTypes* = enum 
    ERL_CACHED_ATOM = 'C',
    NEW_FLOAT_EXT = 'F',
    ERL_BIT_BINARY_EXT = 'M',
    ERL_NEW_CACHE = 'N',
    ERL_NEW_PID_EXT = 'X',
    ERL_NEW_PORT_EXT = 'Y',
    ERL_NEWER_REFERENCE_EXT = 'Z',
    ERL_SMALL_INTEGER_EXT = 'a',
    ERL_INTEGER_EXT = 'b',
    ERL_FLOAT_EXT = 'c',
    ERL_ATOM_EXT = 'd',
    ERL_REFERENCE_EXT = 'e',
    ERL_PORT_EXT = 'f',
    ERL_PID_EXT = 'g',
    ERL_SMALL_TUPLE_EXT = 'h',
    ERL_LARGE_TUPLE_EXT = 'i',
    ERL_NIL_EXT = 'j',
    ERL_STRING_EXT = 'k',
    ERL_LIST_EXT = 'l',
    ERL_BINARY_EXT = 'm',
    ERL_SMALL_BIG_EXT = 'n',
    ERL_LARGE_BIG_EXT = 'o',
    ERL_NEW_FUN_EXT = 'p',
    ERL_EXPORT_EXT = 'q',
    ERL_NEW_REFERENCE_EXT = 'r',
    ERL_SMALL_ATOM_EXT = 's',
    ERL_MAP_EXT = 't',
    ERL_FUN_EXT = 'u',
    ERL_ATOM_UTF8_EXT = 'v',
    ERL_SMALL_ATOM_UTF8_EXT = 'w'
    ## /* c nodes don't know these two */ ##

##  --------------------------------------------------------------------
##                       Type definitions
##  --------------------------------------------------------------------
##
##  To avoid confusion about the MAXHOSTNAMELEN when compiling the
##  library and when using the library we set a value that we use
##

# var EI_MAX_COOKIE_SIZE* {.importc: "EI_MAX_COOKIE_SIZE", header: "<ei.h>".}: cint
# var MAXATOMLEN* {.importc: "MAXATOMLEN", header: "<ei.h>".}: cint
# var MAXATOMLEN_UTF8* {.importc: "MAXATOMLEN_UTF8", header: "<ei.h>".}: cint
# var EI_MAXHOSTNAMELEN* {.importc: "EI_MAXHOSTNAMELEN", header: "<ei.h>".}: cint
# var EI_MAXALIVELEN* {.importc: "EI_MAXALIVELEN", header: "<ei.h>".}: cint
# var MAXNODELEN* {.importc: "MAXNODELEN", header: "<ei.h>".}: cint

const
  EI_MAX_COOKIE_SIZE* = 512
  MAXATOMLEN* = (255 + 1)
  MAXATOMLEN_UTF8* = (255 * 4 + 1)
  EI_MAXHOSTNAMELEN* = (MAXATOMLEN - 2)
  EI_MAXALIVELEN* = (MAXATOMLEN - 2)
  MAXNODELEN* = MAXATOMLEN

type
  erlang_char_encoding* {.size: sizeof(cint).} = enum
    ERLANG_ASCII = 1, ERLANG_LATIN1 = 2, ERLANG_UTF8 = 4


##  a pid

type
  ErlangPid* {.importc: "erlang_pid", header: "ei.h", bycopy.} = object
    node* {.importc: "node".}: array[MAXATOMLEN_UTF8, char]
    num* {.importc: "num".}: cuint
    serial* {.importc: "serial".}: cuint
    creation* {.importc: "creation".}: cuint


##  a port

type
  ErlangPort* {.importc: "erlang_port", header: "ei.h", bycopy.} = object
    node* {.importc: "node".}: array[MAXATOMLEN_UTF8, char]
    id* {.importc: "id".}: cuint
    creation* {.importc: "creation".}: cuint


##  a ref

type
  ErlangRef* {.importc: "erlang_ref", header: "ei.h", bycopy.} = object
    node* {.importc: "node".}: array[MAXATOMLEN_UTF8, char]
    len* {.importc: "len".}: cint
    n* {.importc: "n".}: array[3, cuint]
    creation* {.importc: "creation".}: cuint


##  a trace token

type
  ErlangTrace* {.importc: "erlang_trace", header: "ei.h", bycopy.} = object
    serial* {.importc: "serial".}: clong
    prev* {.importc: "prev".}: clong
    `from`* {.importc: "from".}: ErlangPid
    label* {.importc: "label".}: clong
    flags* {.importc: "flags".}: clong


##  a message

type
  ErlangMsg* {.importc: "erlang_msg", header: "ei.h", bycopy.} = object
    msgtype* {.importc: "msgtype".}: clong
    `from`* {.importc: "from".}: ErlangPid
    to* {.importc: "to".}: ErlangPid
    toname* {.importc: "toname".}: array[MAXATOMLEN_UTF8, char]
    cookie* {.importc: "cookie".}: array[MAXATOMLEN_UTF8, char]
    token* {.importc: "token".}: ErlangTrace

  ErlangFunType* {.size: sizeof(cint).} = enum
    EI_FUN_CLOSURE, EI_FUN_EXPORT


##  a fun

type
  INNER_C_STRUCT_ei_280* {.importc: "no_name", header: "ei.h", bycopy.} = object
    md5* {.importc: "md5".}: array[16, char]
    index* {.importc: "index".}: clong
    old_index* {.importc: "old_index".}: clong
    uniq* {.importc: "uniq".}: clong
    n_free_vars* {.importc: "n_free_vars".}: clong
    pid* {.importc: "pid".}: ErlangPid
    free_var_len* {.importc: "free_var_len".}: clong
    free_vars* {.importc: "free_vars".}: cstring

  INNER_C_STRUCT_ei_290* {.importc: "no_name", header: "ei.h", bycopy.} = object
    `func`* {.importc: "func".}: cstring
    func_allocated* {.importc: "func_allocated".}: cint

  INNER_C_UNION_ei_279* {.importc: "no_name", header: "ei.h", bycopy, union.} = object
    closure* {.importc: "closure".}: INNER_C_STRUCT_ei_280
    exprt* {.importc: "exprt".}: INNER_C_STRUCT_ei_290

  erlang_fun* {.importc: "erlang_fun", header: "ei.h", bycopy.} = object
    arity* {.importc: "arity".}: clong
    module* {.importc: "module".}: array[MAXATOMLEN_UTF8, char]
    `type`* {.importc: "type".}: ErlangFunType
    u* {.importc: "u".}: INNER_C_UNION_ei_279


##  a big

type
  INNER_C_UNION_ei_308* {.importc: "no_name", header: "ei.h", bycopy, union.} = object 
    i_val* {.importc: "i_val".}: clong
    d_val* {.importc: "d_val".}: cdouble
    atom_name* {.importc: "atom_name".}: array[MAXATOMLEN_UTF8, char]
    pid* {.importc: "pid".}: ErlangPid
    port* {.importc: "port".}: ErlangPort
    `ref`* {.importc: "ref".}: ErlangRef

  ErlangBig* {.importc: "erlang_big", header: "ei.h", bycopy.} = object
    arity* {.importc: "arity".}: cuint
    is_neg* {.importc: "is_neg".}: cint
    digits* {.importc: "digits".}: pointer

  EiTerm* {.importc: "ei_term", header: "ei.h", bycopy.} = object
    ei_type* {.importc: "ei_type".}: char
    arity* {.importc: "arity".}: cint
    size* {.importc: "size".}: cint
    value* {.importc: "value".}: INNER_C_UNION_ei_308


##  XXX

type
  ErlConnect* {.importc: "ErlConnect", header: "ei.h", bycopy.} = object
    ipadr* {.importc: "ipadr".}: array[4, char] ##  stored in network byte order
    nodename* {.importc: "nodename".}: array[MAXNODELEN + 1, char]


const
  EI_SCLBK_INF_TMO* = (not (cast[cuint](0)))
  EI_SCLBK_FLG_FULL_IMPL* = (1 shl 0)

type
  EiSocketCallbacks* {.importc: "ei_socket_callbacks", header: "ei.h", bycopy.} = object
    flags* {.importc: "flags".}: cint
    socket* {.importc: "socket".}: proc (ctx: ptr pointer; setup_ctx: pointer): cint {.
        cdecl.}
    close* {.importc: "close".}: proc (ctx: pointer): cint {.cdecl.}
    listen* {.importc: "listen".}: proc (ctx: pointer; `addr`: pointer; len: ptr cint;
                                     backlog: cint): cint {.cdecl.}
    accept* {.importc: "accept".}: proc (ctx: ptr pointer; `addr`: pointer;
                                     len: ptr cint; tmo: cuint): cint {.cdecl.}
    connect* {.importc: "connect".}: proc (ctx: pointer; `addr`: pointer; len: cint;
                                       tmo: cuint): cint {.cdecl.}
    writev* {.importc: "writev".}: proc (ctx: pointer; iov: pointer; iovcnt: cint;
                                     len: ptr int; tmo: cuint): cint {.cdecl.}
    write* {.importc: "write".}: proc (ctx: pointer; buf: cstring; len: ptr int;
                                   tmo: cuint): cint {.cdecl.}
    read* {.importc: "read".}: proc (ctx: pointer; buf: cstring; len: ptr int;
                                 tmo: cuint): cint {.cdecl.}
    handshake_packet_header_size* {.importc: "handshake_packet_header_size".}: proc (
        ctx: pointer; sz: ptr cint): cint {.cdecl.}
    connect_handshake_complete* {.importc: "connect_handshake_complete".}: proc (
        ctx: pointer): cint {.cdecl.}
    accept_handshake_complete* {.importc: "accept_handshake_complete".}: proc (
        ctx: pointer): cint {.cdecl.}
    get_fd* {.importc: "get_fd".}: proc (ctx: pointer; fd: ptr cint): cint {.cdecl.} ##  end of version 1

  EiCnode* {.importc: "ei_cnode", header: "ei.h", bycopy.} = object
    thishostname* {.importc: "thishostname".}: array[EI_MAXHOSTNAMELEN + 1, char]
    thisnodename* {.importc: "thisnodename".}: array[MAXNODELEN + 1, char]
    thisalivename* {.importc: "thisalivename".}: array[EI_MAXALIVELEN + 1, char] ##  Currently this_ipaddr isn't used
                                                                          ##     struct in_addr this_ipaddr;
    ei_connect_cookie* {.importc: "ei_connect_cookie".}: array[
        EI_MAX_COOKIE_SIZE + 1, char]
    creation* {.importc: "creation".}: cshort
    self* {.importc: "self".}: ErlangPid
    cbs* {.importc: "cbs".}: ptr EiSocketCallbacks
    setup_context* {.importc: "setup_context".}: pointer

  Erl_IpAddr* = ptr InAddr

##  A dynamic version of ei XX

type
  EiBuff* {.importc: "ei_x_buff", header: "ei.h", bycopy.} = object
    buff* {.importc: "buff".}: cstring
    buffsz* {.importc: "buffsz".}: cint
    index* {.importc: "index".}: cint


##  --------------------------------------------------------------------
##     Function definitions (listed in same order as documentation)
##  --------------------------------------------------------------------
##  Handle the connection

proc ei_connect_init*(ec: ptr EiCnode; this_node_name: cstring; cookie: cstring;
                     creation: cshort): cint {.cdecl, importc: "ei_connect_init",
    header: "ei.h".}
proc ei_connect_xinit*(ec: ptr EiCnode; thishostname: cstring;
                      thisalivename: cstring; thisnodename: cstring;
                      thisipaddr: Erl_IpAddr; cookie: cstring; creation: cshort): cint {.
    cdecl, importc: "ei_connect_xinit", header: "ei.h".}
proc ei_connect_init_ussi*(ec: ptr EiCnode; this_node_name: cstring; cookie: cstring;
                          creation: cshort; cbs: ptr EiSocketCallbacks;
                          cbs_sz: cint; setup_context: pointer): cint {.cdecl,
    importc: "ei_connect_init_ussi", header: "ei.h".}
proc ei_connect_xinit_ussi*(ec: ptr EiCnode; thishostname: cstring;
                           thisalivename: cstring; thisnodename: cstring;
                           thisipaddr: Erl_IpAddr; cookie: cstring;
                           creation: cshort; cbs: ptr EiSocketCallbacks;
                           cbs_sz: cint; setup_context: pointer): cint {.cdecl,
    importc: "ei_connect_xinit_ussi", header: "ei.h".}
proc ei_connect*(ec: ptr EiCnode; nodename: cstring): cint {.cdecl,
    importc: "ei_connect", header: "ei.h".}
proc ei_connect_tmo*(ec: ptr EiCnode; nodename: cstring; ms: cuint): cint {.cdecl,
    importc: "ei_connect_tmo", header: "ei.h".}
proc ei_xconnect*(ec: ptr EiCnode; adr: Erl_IpAddr; alivename: cstring): cint {.cdecl,
    importc: "ei_xconnect", header: "ei.h".}
proc ei_xconnect_tmo*(ec: ptr EiCnode; adr: Erl_IpAddr; alivename: cstring; ms: cuint): cint {.
    cdecl, importc: "ei_xconnect_tmo", header: "ei.h".}
proc ei_receive*(fd: cint; bufp: ptr cuchar; bufsize: cint): cint {.cdecl,
    importc: "ei_receive", header: "ei.h".}
proc ei_receive_tmo*(fd: cint; bufp: ptr cuchar; bufsize: cint; ms: cuint): cint {.cdecl,
    importc: "ei_receive_tmo", header: "ei.h".}
proc ei_receive_msg*(fd: cint; msg: ptr ErlangMsg; x: ptr EiBuff): cint {.cdecl,
    importc: "ei_receive_msg", header: "ei.h".}
proc ei_receive_msg_tmo*(fd: cint; msg: ptr ErlangMsg; x: ptr EiBuff; ms: cuint): cint {.
    cdecl, importc: "ei_receive_msg_tmo", header: "ei.h".}
proc ei_xreceive_msg*(fd: cint; msg: ptr ErlangMsg; x: ptr EiBuff): cint {.cdecl,
    importc: "ei_xreceive_msg", header: "ei.h".}
proc ei_xreceive_msg_tmo*(fd: cint; msg: ptr ErlangMsg; x: ptr EiBuff; ms: cuint): cint {.
    cdecl, importc: "ei_xreceive_msg_tmo", header: "ei.h".}
proc ei_send*(fd: cint; to: ptr ErlangPid; buf: cstring; len: cint): cint {.cdecl,
    importc: "ei_send", header: "ei.h".}
proc ei_send_tmo*(fd: cint; to: ptr ErlangPid; buf: cstring; len: cint; ms: cuint): cint {.
    cdecl, importc: "ei_send_tmo", header: "ei.h".}
proc ei_reg_send*(ec: ptr EiCnode; fd: cint; server_name: cstring; buf: cstring;
                 len: cint): cint {.cdecl, importc: "ei_reg_send", header: "ei.h".}
proc ei_reg_send_tmo*(ec: ptr EiCnode; fd: cint; server_name: cstring; buf: cstring;
                     len: cint; ms: cuint): cint {.cdecl, importc: "ei_reg_send_tmo",
    header: "ei.h".}
proc ei_rpc*(ec: ptr EiCnode; fd: cint; `mod`: cstring; fun: cstring; inbuf: cstring;
            inbuflen: cint; x: ptr EiBuff): cint {.cdecl, importc: "ei_rpc",
    header: "ei.h".}
proc ei_rpc_to*(ec: ptr EiCnode; fd: cint; `mod`: cstring; fun: cstring; buf: cstring;
               len: cint): cint {.cdecl, importc: "ei_rpc_to", header: "ei.h".}
proc ei_rpc_from*(ec: ptr EiCnode; fd: cint; timeout: cint; msg: ptr ErlangMsg;
                 x: ptr EiBuff): cint {.cdecl, importc: "ei_rpc_from",
                                       header: "ei.h".}
proc ei_publish*(ec: ptr EiCnode; port: cint): cint {.cdecl, importc: "ei_publish",
    header: "ei.h".}
proc ei_publish_tmo*(ec: ptr EiCnode; port: cint; ms: cuint): cint {.cdecl,
    importc: "ei_publish_tmo", header: "ei.h".}
proc ei_listen*(ec: ptr EiCnode; port: ptr cint; backlog: cint): cint {.cdecl,
    importc: "ei_listen", header: "ei.h".}
proc ei_xlisten*(ec: ptr EiCnode; adr: Erl_IpAddr; port: ptr cint; backlog: cint): cint {.
    cdecl, importc: "ei_xlisten", header: "ei.h".}
proc ei_accept*(ec: ptr EiCnode; lfd: cint; conp: ptr ErlConnect): cint {.cdecl,
    importc: "ei_accept", header: "ei.h".}
proc ei_accept_tmo*(ec: ptr EiCnode; lfd: cint; conp: ptr ErlConnect; ms: cuint): cint {.
    cdecl, importc: "ei_accept_tmo", header: "ei.h".}
proc ei_unpublish*(ec: ptr EiCnode): cint {.cdecl, importc: "ei_unpublish",
                                        header: "ei.h".}
proc ei_unpublish_tmo*(alive: cstring; ms: cuint): cint {.cdecl,
    importc: "ei_unpublish_tmo", header: "ei.h".}
proc ei_close_connection*(fd: cint): cint {.cdecl, importc: "ei_close_connection",
                                        header: "ei.h".}
proc ei_thisnodename*(ec: ptr EiCnode): cstring {.cdecl, importc: "ei_thisnodename",
    header: "ei.h".}
proc ei_thishostname*(ec: ptr EiCnode): cstring {.cdecl, importc: "ei_thishostname",
    header: "ei.h".}
proc ei_thisalivename*(ec: ptr EiCnode): cstring {.cdecl,
    importc: "ei_thisalivename", header: "ei.h".}
proc ei_self*(ec: ptr EiCnode): ptr ErlangPid {.cdecl, importc: "ei_self",
    header: "ei.h".}
##
##  settings
##

proc ei_set_compat_rel*(rel: cuint) {.cdecl, importc: "ei_set_compat_rel",
                                   header: "ei.h".}
proc ei_set_tracelevel*(a1: cint) {.cdecl, importc: "ei_set_tracelevel",
                                 header: "ei.h".}
proc ei_get_tracelevel*(): cint {.cdecl, importc: "ei_get_tracelevel", header: "ei.h".}
##
##  We have erl_gethost*() so we include ei versions as well.
##

when defined(VXWORKS):
  var h_errno* {.importc: "h_errno", header: "ei.h".}: cint
  ##
  ##  We need these definitions - if the user has SENS then he gets them
  ##  from netdb.h, otherwise we define them ourselves.
  ##
  ##  If you are getting "multiple definition" errors here,
  ##  make sure you have included <netdb.h> BEFORE "erl_interface.h"
  ##  or define HAVE_SENS in your CFLAGS.
  ##
  when not defined(HAVE_SENS) and
      not defined(HOST_NOT_FOUND): ##  just in case
    const
      h_addr* = h_addr_list[0]  ##  address, for backward compatiblity
    type
      Hostent* {.importc: "Hostent", header: "ei.h", bycopy.} = object
        h_name* {.importc: "h_name".}: cstring ##  official name of host
        h_aliases* {.importc: "h_aliases".}: cstringArray ##  alias list
        h_addrtype* {.importc: "h_addrtype".}: cint ##  host address type
        h_length* {.importc: "h_length".}: cint ##  length of address
        h_addr_list* {.importc: "h_addr_list".}: cstringArray ##  list of addresses from name server
        unused* {.importc: "unused".}: cuint ##  SENS defines this as ttl

    const
      HOST_NOT_FOUND* = 1
      TRY_AGAIN* = 2
      NO_RECOVERY* = 3
      NO_DATA* = 4
      NO_ADDRESS* = NO_DATA
proc ei_gethostbyname*(name: cstring): ptr Hostent {.cdecl,
    importc: "ei_gethostbyname", header: "ei.h".}
proc ei_gethostbyaddr*(`addr`: cstring; len: cint; `type`: cint): ptr Hostent {.cdecl,
    importc: "ei_gethostbyaddr", header: "ei.h".}
proc ei_gethostbyname_r*(name: cstring; hostp: ptr Hostent; buffer: cstring;
                        buflen: cint; h_errnop: ptr cint): ptr Hostent {.cdecl,
    importc: "ei_gethostbyname_r", header: "ei.h".}
proc ei_gethostbyaddr_r*(`addr`: cstring; length: cint; `type`: cint;
                        hostp: ptr Hostent; buffer: cstring; buflen: cint;
                        h_errnop: ptr cint): ptr Hostent {.cdecl,
    importc: "ei_gethostbyaddr_r", header: "ei.h".}
##  Encode/decode functions

proc ei_encode_version*(buf: cstring; index: ptr cint): cint {.cdecl,
    importc: "ei_encode_version", header: "ei.h".}
proc ei_x_encode_version*(x: ptr EiBuff): cint {.cdecl,
    importc: "ei_x_encode_version", header: "ei.h".}
proc ei_encode_long*(buf: cstring; index: ptr cint; p: clong): cint {.cdecl,
    importc: "ei_encode_long", header: "ei.h".}
proc ei_x_encode_long*(x: ptr EiBuff; n: clong): cint {.cdecl,
    importc: "ei_x_encode_long", header: "ei.h".}
proc ei_encode_ulong*(buf: cstring; index: ptr cint; p: culong): cint {.cdecl,
    importc: "ei_encode_ulong", header: "ei.h".}
proc ei_x_encode_ulong*(x: ptr EiBuff; n: culong): cint {.cdecl,
    importc: "ei_x_encode_ulong", header: "ei.h".}
proc ei_encode_double*(buf: cstring; index: ptr cint; p: cdouble): cint {.cdecl,
    importc: "ei_encode_double", header: "ei.h".}
proc ei_x_encode_double*(x: ptr EiBuff; dbl: cdouble): cint {.cdecl,
    importc: "ei_x_encode_double", header: "ei.h".}
proc ei_encode_boolean*(buf: cstring; index: ptr cint; p: cint): cint {.cdecl,
    importc: "ei_encode_boolean", header: "ei.h".}
proc ei_x_encode_boolean*(x: ptr EiBuff; p: cint): cint {.cdecl,
    importc: "ei_x_encode_boolean", header: "ei.h".}
proc ei_encode_char*(buf: cstring; index: ptr cint; p: char): cint {.cdecl,
    importc: "ei_encode_char", header: "ei.h".}
proc ei_x_encode_char*(x: ptr EiBuff; p: char): cint {.cdecl,
    importc: "ei_x_encode_char", header: "ei.h".}
proc ei_encode_string*(buf: cstring; index: ptr cint; p: cstring): cint {.cdecl,
    importc: "ei_encode_string", header: "ei.h".}
proc ei_encode_string_len*(buf: cstring; index: ptr cint; p: cstring; len: cint): cint {.
    cdecl, importc: "ei_encode_string_len", header: "ei.h".}
proc ei_x_encode_string*(x: ptr EiBuff; s: cstring): cint {.cdecl,
    importc: "ei_x_encode_string", header: "ei.h".}
proc ei_x_encode_string_len*(x: ptr EiBuff; s: cstring; len: cint): cint {.cdecl,
    importc: "ei_x_encode_string_len", header: "ei.h".}
proc ei_encode_atom*(buf: cstring; index: ptr cint; p: cstring): cint {.cdecl,
    importc: "ei_encode_atom", header: "ei.h".}
proc ei_encode_atom_as*(buf: cstring; index: ptr cint; p: cstring;
                       `from`: erlang_char_encoding; to: erlang_char_encoding): cint {.
    cdecl, importc: "ei_encode_atom_as", header: "ei.h".}
proc ei_encode_atom_len*(buf: cstring; index: ptr cint; p: cstring; len: cint): cint {.
    cdecl, importc: "ei_encode_atom_len", header: "ei.h".}
proc ei_encode_atom_len_as*(buf: cstring; index: ptr cint; p: cstring; len: cint;
                           `from`: erlang_char_encoding; to: erlang_char_encoding): cint {.
    cdecl, importc: "ei_encode_atom_len_as", header: "ei.h".}
proc ei_x_encode_atom*(x: ptr EiBuff; s: cstring): cint {.cdecl,
    importc: "ei_x_encode_atom", header: "ei.h".}
proc ei_x_encode_atom_as*(x: ptr EiBuff; s: cstring; `from`: erlang_char_encoding;
                         to: erlang_char_encoding): cint {.cdecl,
    importc: "ei_x_encode_atom_as", header: "ei.h".}
proc ei_x_encode_atom_len*(x: ptr EiBuff; s: cstring; len: cint): cint {.cdecl,
    importc: "ei_x_encode_atom_len", header: "ei.h".}
proc ei_x_encode_atom_len_as*(x: ptr EiBuff; s: cstring; len: cint;
                             `from`: erlang_char_encoding;
                             to: erlang_char_encoding): cint {.cdecl,
    importc: "ei_x_encode_atom_len_as", header: "ei.h".}
proc ei_encode_binary*(buf: cstring; index: ptr cint; p: pointer; len: clong): cint {.
    cdecl, importc: "ei_encode_binary", header: "ei.h".}
proc ei_encode_bitstring*(buf: cstring; index: ptr cint; p: cstring; bitoffs: cint;
                         bits: cint): cint {.cdecl, importc: "ei_encode_bitstring",
    header: "ei.h".}
proc ei_x_encode_binary*(x: ptr EiBuff; s: pointer; len: cint): cint {.cdecl,
    importc: "ei_x_encode_binary", header: "ei.h".}
proc ei_x_encode_bitstring*(x: ptr EiBuff; p: cstring; bitoffs: cint; bits: cint): cint {.
    cdecl, importc: "ei_x_encode_bitstring", header: "ei.h".}
proc ei_encode_pid*(buf: cstring; index: ptr cint; p: ptr ErlangPid): cint {.cdecl,
    importc: "ei_encode_pid", header: "ei.h".}
proc ei_x_encode_pid*(x: ptr EiBuff; pid: ptr ErlangPid): cint {.cdecl,
    importc: "ei_x_encode_pid", header: "ei.h".}
proc ei_encode_fun*(buf: cstring; index: ptr cint; p: ptr erlang_fun): cint {.cdecl,
    importc: "ei_encode_fun", header: "ei.h".}
proc ei_x_encode_fun*(x: ptr EiBuff; fun: ptr erlang_fun): cint {.cdecl,
    importc: "ei_x_encode_fun", header: "ei.h".}
proc ei_encode_port*(buf: cstring; index: ptr cint; p: ptr ErlangPort): cint {.cdecl,
    importc: "ei_encode_port", header: "ei.h".}
proc ei_x_encode_port*(x: ptr EiBuff; p: ptr ErlangPort): cint {.cdecl,
    importc: "ei_x_encode_port", header: "ei.h".}
proc ei_encode_ref*(buf: cstring; index: ptr cint; p: ptr ErlangRef): cint {.cdecl,
    importc: "ei_encode_ref", header: "ei.h".}
proc ei_x_encode_ref*(x: ptr EiBuff; p: ptr ErlangRef): cint {.cdecl,
    importc: "ei_x_encode_ref", header: "ei.h".}
##  int ei_encode_term(char *buf, int *index, void *t) EI_DEPRECATED_ATTR;
##  int ei_x_encode_term(ei_x_buff* x, void* t) EI_DEPRECATED_ATTR;

proc ei_encode_trace*(buf: cstring; index: ptr cint; p: ptr ErlangTrace): cint {.cdecl,
    importc: "ei_encode_trace", header: "ei.h".}
proc ei_x_encode_trace*(x: ptr EiBuff; p: ptr ErlangTrace): cint {.cdecl,
    importc: "ei_x_encode_trace", header: "ei.h".}
proc ei_encode_tuple_header*(buf: cstring; index: ptr cint; arity: cint): cint {.cdecl,
    importc: "ei_encode_tuple_header", header: "ei.h".}
proc ei_x_encode_tuple_header*(x: ptr EiBuff; n: clong): cint {.cdecl,
    importc: "ei_x_encode_tuple_header", header: "ei.h".}
proc ei_encode_list_header*(buf: cstring; index: ptr cint; arity: cint): cint {.cdecl,
    importc: "ei_encode_list_header", header: "ei.h".}
proc ei_x_encode_list_header*(x: ptr EiBuff; n: clong): cint {.cdecl,
    importc: "ei_x_encode_list_header", header: "ei.h".}
template ei_encode_empty_list*(buf, i: untyped): untyped =
  ei_encode_list_header(buf, i, 0)

proc ei_x_encode_empty_list*(x: ptr EiBuff): cint {.cdecl,
    importc: "ei_x_encode_empty_list", header: "ei.h".}
proc ei_encode_map_header*(buf: cstring; index: ptr cint; arity: cint): cint {.cdecl,
    importc: "ei_encode_map_header", header: "ei.h".}
proc ei_x_encode_map_header*(x: ptr EiBuff; n: clong): cint {.cdecl,
    importc: "ei_x_encode_map_header", header: "ei.h".}
##
##  ei_get_type() returns the type and "size" of the item at
##  buf[index]. For strings and atoms, size is the number of characters
##  not including the terminating 0. For binaries, size is the number
##  of bytes. For lists and tuples, size is the arity of the
##  object. For other types, size is 0. In all cases, index is left
##  unchanged.
##

proc ei_get_type*(buf: cstring; index: ptr cint; `type`: ptr cint; size: ptr cint): cint {.
    cdecl, importc: "ei_get_type", header: "ei.h".}
##  Step through buffer, decoding the given type into the buffer
##  provided. On success, 0 is returned and index is updated to point
##  to the start of the next item in the buffer. If the type of item at
##  buf[index] is not the requested type, -1 is returned and index is
##  not updated. The buffer provided by the caller must be sufficiently
##  large to contain the decoded object.
##

proc ei_decode_version*(buf: cstring; index: ptr cint; version: ptr cint): cint {.cdecl,
    importc: "ei_decode_version", header: "ei.h".}
proc ei_decode_long*(buf: cstring; index: ptr cint; p: ptr clong): cint {.cdecl,
    importc: "ei_decode_long", header: "ei.h".}
proc ei_decode_ulong*(buf: cstring; index: ptr cint; p: ptr culong): cint {.cdecl,
    importc: "ei_decode_ulong", header: "ei.h".}
proc ei_decode_double*(buf: cstring; index: ptr cint; p: ptr cdouble): cint {.cdecl,
    importc: "ei_decode_double", header: "ei.h".}
proc ei_decode_boolean*(buf: cstring; index: ptr cint; p: ptr cint): cint {.cdecl,
    importc: "ei_decode_boolean", header: "ei.h".}
proc ei_decode_char*(buf: cstring; index: ptr cint; p: cstring): cint {.cdecl,
    importc: "ei_decode_char", header: "ei.h".}
proc ei_decode_string*(buf: cstring; index: ptr cint; p: cstring): cint {.cdecl,
    importc: "ei_decode_string", header: "ei.h".}
proc ei_decode_atom*(buf: cstring; index: ptr cint; p: cstring): cint {.cdecl,
    importc: "ei_decode_atom", header: "ei.h".}
proc ei_decode_atom_as*(buf: cstring; index: ptr cint; p: cstring; destlen: cint;
                       want: erlang_char_encoding; was: ptr erlang_char_encoding;
                       result: ptr erlang_char_encoding): cint {.cdecl,
    importc: "ei_decode_atom_as", header: "ei.h".}
proc ei_decode_binary*(buf: cstring; index: ptr cint; p: pointer; len: ptr clong): cint {.
    cdecl, importc: "ei_decode_binary", header: "ei.h".}
proc ei_decode_bitstring*(buf: cstring; index: ptr cint; pp: cstringArray;
                         bitoffsp: ptr cuint; nbitsp: ptr cint): cint {.cdecl,
    importc: "ei_decode_bitstring", header: "ei.h".}
proc ei_decode_fun*(buf: cstring; index: ptr cint; p: ptr erlang_fun): cint {.cdecl,
    importc: "ei_decode_fun", header: "ei.h".}
proc free_fun*(f: ptr erlang_fun) {.cdecl, importc: "free_fun", header: "ei.h".}
proc ei_decode_pid*(buf: cstring; index: ptr cint; p: ptr ErlangPid): cint {.cdecl,
    importc: "ei_decode_pid", header: "ei.h".}
proc ei_decode_port*(buf: cstring; index: ptr cint; p: ptr ErlangPort): cint {.cdecl,
    importc: "ei_decode_port", header: "ei.h".}
proc ei_decode_ref*(buf: cstring; index: ptr cint; p: ptr ErlangRef): cint {.cdecl,
    importc: "ei_decode_ref", header: "ei.h".}
##  int ei_decode_term(const char *buf, int *index, void *t) EI_DEPRECATED_ATTR;

proc ei_decode_trace*(buf: cstring; index: ptr cint; p: ptr ErlangTrace): cint {.cdecl,
    importc: "ei_decode_trace", header: "ei.h".}
proc ei_decode_tuple_header*(buf: cstring; index: ptr cint; arity: ptr cint): cint {.
    cdecl, importc: "ei_decode_tuple_header", header: "ei.h".}
proc ei_decode_list_header*(buf: cstring; index: ptr cint; arity: ptr cint): cint {.cdecl,
    importc: "ei_decode_list_header", header: "ei.h".}
proc ei_decode_map_header*(buf: cstring; index: ptr cint; arity: ptr cint): cint {.cdecl,
    importc: "ei_decode_map_header", header: "ei.h".}
##
##  ei_decode_EiTerm() returns 1 if term is decoded, 0 if term is OK,
##  but not decoded here and -1 if something is wrong.  ONLY changes
##  index if term is decoded (return value 1)!
##

proc ei_decode_EiTerm*(buf: cstring; index: ptr cint; term: ptr EiTerm): cint {.cdecl,
    importc: "ei_decode_EiTerm", header: "ei.h".}
##
##  ei_print_term to print out a binary coded term
##

proc ei_print_term*(fp: ptr FILE; buf: cstring; index: ptr cint): cint {.cdecl,
    importc: "ei_print_term", header: "ei.h".}
proc ei_s_print_term*(s: cstringArray; buf: cstring; index: ptr cint): cint {.cdecl,
    importc: "ei_s_print_term", header: "ei.h".}
##
##  format to build binary format terms a bit like printf
##

proc ei_x_format*(x: ptr EiBuff; fmt: cstring): cint {.varargs, cdecl,
    importc: "ei_x_format", header: "ei.h".}
proc ei_x_format_wo_ver*(x: ptr EiBuff; fmt: cstring): cint {.varargs, cdecl,
    importc: "ei_x_format_wo_ver", header: "ei.h".}
proc ei_x_new*(x: ptr EiBuff): cint {.cdecl, importc: "ei_x_new", header: "ei.h".}
proc ei_x_new_with_version*(x: ptr EiBuff): cint {.cdecl,
    importc: "ei_x_new_with_version", header: "ei.h".}
proc ei_x_free*(x: ptr EiBuff): cint {.cdecl, importc: "ei_x_free", header: "ei.h".}
proc ei_x_append*(x: ptr EiBuff; x2: ptr EiBuff): cint {.cdecl,
    importc: "ei_x_append", header: "ei.h".}
proc ei_x_append_buf*(x: ptr EiBuff; buf: cstring; len: cint): cint {.cdecl,
    importc: "ei_x_append_buf", header: "ei.h".}
proc ei_skip_term*(buf: cstring; index: ptr cint): cint {.cdecl,
    importc: "ei_skip_term", header: "ei.h".}
## **************************************************************************
##
##   Hash types needed by registry types
##
## *************************************************************************

const
  EI_SMALLKEY* = 32

type
  ei_bucket* {.importc: "ei_bucket", header: "ei.h", bycopy.} = object
    rawhash* {.importc: "rawhash".}: cint
    key* {.importc: "key".}: cstring
    keybuf* {.importc: "keybuf".}: array[EI_SMALLKEY, char]
    value* {.importc: "value".}: pointer
    next* {.importc: "next".}: ptr ei_bucket

##  users of the package declare variables as pointers to this.

type
  ei_hash* {.importc: "ei_hash", header: "ei.h", bycopy.} = object
    tab* {.importc: "tab".}: ptr ptr ei_bucket
    hash* {.importc: "hash".}: proc (a1: cstring): cint {.cdecl.} ##  hash function for this table
    size* {.importc: "size".}: cint ##  size of table
    nelem* {.importc: "nelem".}: cint ##  nr elements
    npos* {.importc: "npos".}: cint ##  nr occupied positions
    freelist* {.importc: "freelist".}: ptr ei_bucket ##  reuseable freed buckets


## **************************************************************************
##
##   Registry defines, types, functions
##
## *************************************************************************
##  --------------------------------------------------------------------
##                                XXXXXXXXXXX
##  --------------------------------------------------------------------
##  registry object attributes

const
  EI_DIRTY* = 0x00000001
  EI_DELET* = 0x00000002
  EI_INT* = 0x00000010
  EI_FLT* = 0x00000020
  EI_STR* = 0x00000040
  EI_BIN* = 0x00000080

##  --------------------------------------------------------------------
##                                XXXXXXXXXXX
##  --------------------------------------------------------------------

type
  INNER_C_UNION_ei_681* {.importc: "no_name", header: "ei.h", bycopy, union.} = object 
    i* {.importc: "i".}: clong
    f* {.importc: "f".}: cdouble
    s* {.importc: "s".}: cstring
    p* {.importc: "p".}: pointer

  EiRegObj* {.importc: "EiRegObj", header: "ei.h", bycopy.} = object
    attr* {.importc: "attr".}: cint
    size* {.importc: "size".}: cint
    val* {.importc: "val".}: INNER_C_UNION_ei_681
    next* {.importc: "next".}: ptr EiRegObj

  EiReg* {.importc: "EiReg", header: "ei.h", bycopy.} = object
    freelist* {.importc: "freelist".}: ptr EiRegObj
    tab* {.importc: "tab".}: ptr ei_hash

  EiRegStat* {.importc: "EiRegStat", header: "ei.h", bycopy.} = object
    attr* {.importc: "attr".}: cint ##  object attributes (see above)
    size* {.importc: "size".}: cint ##  size in bytes (for STR and BIN) 0 for others

  EiRegTabstat* {.importc: "EiRegTabstat", header: "ei.h", bycopy.} = object
    size* {.importc: "size".}: cint ##  size of table
    nelem* {.importc: "nelem".}: cint ##  number of stored elements
    npos* {.importc: "npos".}: cint ##  number of occupied positions
    collisions* {.importc: "collisions".}: cint ##  number of positions with more than one element


proc ei_init*(): cint {.cdecl, importc: "ei_init", header: "ei.h".}
##  --------------------------------------------------------------------
##                                XXXXXXXXXXX
##  --------------------------------------------------------------------
##  FIXME move comments to source
##  open / close registry. On open, a descriptor is returned that must
##  be specified in all subsequent calls to registry functions. You can
##  open as many registries as you like.
##

proc ei_reg_open*(size: cint): ptr EiReg {.cdecl, importc: "ei_reg_open",
                                       header: "ei.h".}
proc ei_reg_resize*(oldreg: ptr EiReg; newsize: cint): cint {.cdecl,
    importc: "ei_reg_resize", header: "ei.h".}
proc ei_reg_close*(reg: ptr EiReg): cint {.cdecl, importc: "ei_reg_close",
                                       header: "ei.h".}
##  set values... these routines assign values to keys. If the key
##  exists, the previous value is discarded and the new one replaces
##  it.
##
##  BIN objects require an additional argument indicating the size in
##  bytes of the stored object. This will be used when the object is
##  backed up, since it will need to be copied at that time. Remember
##  also that pointers are process-space specific and it is not
##  meaningful to back them up for later recall. If you are storing
##  binary objects for backup, make sure that they are self-contained
##  (without references to other objects).
##
##  On success the function returns 0, otherwise a value
##  indicating the reason for failure will be returned.
##

proc ei_reg_setival*(reg: ptr EiReg; key: cstring; i: clong): cint {.cdecl,
    importc: "ei_reg_setival", header: "ei.h".}
proc ei_reg_setfval*(reg: ptr EiReg; key: cstring; f: cdouble): cint {.cdecl,
    importc: "ei_reg_setfval", header: "ei.h".}
proc ei_reg_setsval*(reg: ptr EiReg; key: cstring; s: cstring): cint {.cdecl,
    importc: "ei_reg_setsval", header: "ei.h".}
proc ei_reg_setpval*(reg: ptr EiReg; key: cstring; p: pointer; size: cint): cint {.cdecl,
    importc: "ei_reg_setpval", header: "ei.h".}
##  general set function (specifiy type via flags)
##  optional arguments are as for equivalent type-specific function,
##  i.e.:
##  ei_reg_setval(fd, path, EI_INT, int i);
##  ei_reg_setval(fd, path, EI_FLT, float f);
##  ei_reg_setval(fd, path, EI_STR, const char *s);
##  ei_reg_setval(fd, path, EI_BIN, const void *p, int size);
##

proc ei_reg_setval*(reg: ptr EiReg; key: cstring; flags: cint): cint {.varargs, cdecl,
    importc: "ei_reg_setval", header: "ei.h".}
##  get value of specific type object
##  warning: it may be difficult to detect errors when using these
##  functions, since the error values are returned "in band"
##

proc ei_reg_getival*(reg: ptr EiReg; key: cstring): clong {.cdecl,
    importc: "ei_reg_getival", header: "ei.h".}
proc ei_reg_getfval*(reg: ptr EiReg; key: cstring): cdouble {.cdecl,
    importc: "ei_reg_getfval", header: "ei.h".}
proc ei_reg_getsval*(reg: ptr EiReg; key: cstring): cstring {.cdecl,
    importc: "ei_reg_getsval", header: "ei.h".}
proc ei_reg_getpval*(reg: ptr EiReg; key: cstring; size: ptr cint): pointer {.cdecl,
    importc: "ei_reg_getpval", header: "ei.h".}
##  get value of any type object (must specify)
##  Retrieve a value from an object. The type of value expected and a
##  pointer to a large enough buffer must be provided. flags must be
##  set to the appropriate type (see type constants above) and the
##  object type must match. If (flags == 0) the pointer is *assumed* to
##  be of the correct type for the object. In any case, the actual
##  object type is always returned on success.
##
##  The argument following flags must be one of int*, double*, const
##  char** and const void**.
##
##  for BIN objects an int* is needed to return the size of the object, i.e.
##  int ei_reg_getval(EiReg *reg, const char *path, int flags, void **p, int *size);
##

proc ei_reg_getval*(reg: ptr EiReg; key: cstring; flags: cint): cint {.varargs, cdecl,
    importc: "ei_reg_getval", header: "ei.h".}
##  mark the object as dirty. Normally this operation will not be
##  necessary, as it is done automatically by all of the above 'set'
##  functions. However, if you modify the contents of an object pointed
##  to by a STR or BIN object, then the registry will not be aware of
##  the change. As a result, the object may be missed on a subsequent
##  backup operation. Use this function to set the dirty bit on the
##  object.
##

proc ei_reg_markdirty*(reg: ptr EiReg; key: cstring): cint {.cdecl,
    importc: "ei_reg_markdirty", header: "ei.h".}
##  remove objects. The value, if any, is discarded. For STR and BIN
##  objects, the object itself is removed using free().

proc ei_reg_delete*(reg: ptr EiReg; key: cstring): cint {.cdecl,
    importc: "ei_reg_delete", header: "ei.h".}
##  get information about an object

proc ei_reg_stat*(reg: ptr EiReg; key: cstring; obuf: ptr EiRegStat): cint {.cdecl,
    importc: "ei_reg_stat", header: "ei.h".}
##  get information about table

proc ei_reg_tabstat*(reg: ptr EiReg; obuf: ptr EiRegTabstat): cint {.cdecl,
    importc: "ei_reg_tabstat", header: "ei.h".}
##  dump to / restore from backup
##  fd is open descriptor to Erlang, mntab is Mnesia table name
##  flags here:

const
  EI_FORCE* = 0x00000001
  EI_NOPURGE* = 0x00000002

proc ei_reg_dump*(fd: cint; reg: ptr EiReg; mntab: cstring; flags: cint): cint {.cdecl,
    importc: "ei_reg_dump", header: "ei.h".}
proc ei_reg_restore*(fd: cint; reg: ptr EiReg; mntab: cstring): cint {.cdecl,
    importc: "ei_reg_restore", header: "ei.h".}
proc ei_reg_purge*(reg: ptr EiReg): cint {.cdecl, importc: "ei_reg_purge",
                                       header: "ei.h".}

# TODO: Ignore for now, would need to import gmp to Nim as well 
# ##  --------------------------------------------------------------------
# ##             Encoding/decoding bugnums to GNU MP format
# ##  --------------------------------------------------------------------
# ##  If the user included <gmp.h> we supply some more functions

# when defined(__GNU_MP_VERSION) and __GNU_MP_VERSION == 4 and
#     __GNU_MP_VERSION_MINOR >= 1:
#   proc ei_decode_bignum*(buf: cstring; index: ptr cint; obj: mpz_t): cint {.cdecl,
#       importc: "ei_decode_bignum", header: "ei.h".}
#   proc ei_encode_bignum*(buf: cstring; index: ptr cint; obj: mpz_t): cint {.cdecl,
#       importc: "ei_encode_bignum", header: "ei.h".}
#   proc ei_x_encode_bignum*(x: ptr EiBuff; obj: mpz_t): cint {.cdecl,
#       importc: "ei_x_encode_bignum", header: "ei.h".}

##  --------------------------------------------------------------------
##             Function definitions not documented FIXME
##  --------------------------------------------------------------------
##  FIXME replace this primitive type size code
##  #define EI_LONGLONG long long
##  #define EI_LONGLONG long long
##  #define EI_ULONGLONG unsigned long long

proc ei_decode_longlong*(buf: cstring; index: ptr cint; p: ptr clonglong): cint {.cdecl,
    importc: "ei_decode_longlong", header: "ei.h".}
proc ei_decode_ulonglong*(buf: cstring; index: ptr cint; p: ptr culonglong): cint {.cdecl,
    importc: "ei_decode_ulonglong", header: "ei.h".}
proc ei_encode_longlong*(buf: cstring; index: ptr cint; p: clonglong): cint {.cdecl,
    importc: "ei_encode_longlong", header: "ei.h".}
proc ei_encode_ulonglong*(buf: cstring; index: ptr cint; p: culonglong): cint {.cdecl,
    importc: "ei_encode_ulonglong", header: "ei.h".}
proc ei_x_encode_longlong*(x: ptr EiBuff; n: clonglong): cint {.cdecl,
    importc: "ei_x_encode_longlong", header: "ei.h".}
proc ei_x_encode_ulonglong*(x: ptr EiBuff; n: culonglong): cint {.cdecl,
    importc: "ei_x_encode_ulonglong", header: "ei.h".}
