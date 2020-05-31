import macros
import typetraits
import tables
import hashes
import ei

import options
export options

type
  ErlAtom* = object
    n*: string
  ErlKindError* = object of ValueError ## raised by the ``to`` macro if the
                                        ## JSON kind is incorrect.
  ErlParsingError* = object of ValueError ## is raised for a JSON error

const AtomOk* = ErlAtom(n: "ok")
const AtomNil* = ErlAtom(n: "nil")
const AtomError* = ErlAtom(n: "error")
const AtomTrue* = ErlAtom(n: "true")
const AtomFalse* = ErlAtom(n: "false")

proc newErlAtom*(name: string): ErlAtom =
  result.n = name

type
  ErlTermKind* = enum ## possible JSON node types
    ENil,
    EBool,
    EChar,
    EInt32,
    EInt64,
    EDouble,
    EAtom,
    ## Erlang Types ##
    EString,
    EBinary,
    # EBitBinary,
    ## Erlang Types ##
    EPort,
    ERef,
    EPid,
    ## Composite ##
    EMap,
    EList,
    # ECharList,
    ETupleN

  ErlTerm* = ref ErlTermObj ## JSON node
  ErlTermObj* {.acyclic.} = object
    case kind*: ErlTermKind
    of ENil:
      nil
    of EBool:
      bval*: bool
    of EChar:
      cval*: char
    of EInt32:
      n32*: int32
    of EInt64:
      n64*: int64
    of EDouble:
      f64*: float64
    of EAtom:
      atm*: ErlAtom
    # Erlang Types
    of EString:
      str*: string
    of EBinary:
      bin*: seq[byte]
    # of EBitBinary:
      # bit*: seq[byte]
    # Erlang Types
    of EPort:
      eport*: ErlangPort
    of ERef:
      eref*: ErlangRef
    of EPid:
      epid*: ErlangPid
    # Composite
    of EMap:
      fields*: OrderedTable[ErlTerm, ErlTerm]
    of ETupleN:
      items*: seq[ErlTerm]
    of EList:
      elems*: seq[ErlTerm]
    # of ECharList:
      # chars*: seq[char]

proc newETerm*(s: bool): ErlTerm =
  ## Creates a new `EString ErlTerm`.
  result = ErlTerm(kind: EBool, bval: s)

proc newETerm*(n: int): ErlTerm =
  ## Creates a new `EInt ErlTerm`.
  result = ErlTerm(kind: EInt64, n64: n)

proc newETerm*(n: int32): ErlTerm =
  ## Creates a new `EInt ErlTerm`.
  result = ErlTerm(kind: EInt32, n32: n)

proc newETerm*(n: int64): ErlTerm =
  ## Creates a new `EInt ErlTerm`.
  result = ErlTerm(kind: EInt64, n64: n)

proc newETerm*(n: uint32): ErlTerm =
  ## Creates a new `EInt ErlTerm`.
  result = ErlTerm(kind: EInt32, n32: n.int32)

proc newETerm*(n: uint64): ErlTerm =
  ## Creates a new `EInt ErlTerm`.
  result = ErlTerm(kind: EInt64, n64: n.int64)

proc newETerm*(n: float64): ErlTerm =
  ## Creates a new `EFloat ErlTerm`.
  result = ErlTerm(kind: EDouble, f64: n)

proc newETerm*(s: ErlAtom): ErlTerm =
  ## Creates a new `EString ErlTerm`.
  result = ErlTerm(kind: EAtom, atm: s)

proc newETerm*(s: ErlangPid): ErlTerm =
  ## Creates a new `EString ErlTerm`.
  result = ErlTerm(kind: EPid, epid: s)

proc newETerm*(s: ErlangRef): ErlTerm =
  ## Creates a new `EString ErlTerm`.
  result = ErlTerm(kind: ERef, eref: s)

proc newETerm*(s: ErlangPort): ErlTerm =
  ## Creates a new `EString ErlTerm`.
  result = ErlTerm(kind: EPort, eport: s)

proc newETerm*(s: string): ErlTerm =
  ## Creates a new `EString ErlTerm`.
  result = ErlTerm(kind: EString, str: s)

proc newETerm*(s: seq[byte]): ErlTerm =
  ## Creates a new `EString ErlTerm`.
  result = ErlTerm(kind: EBinary, bin: s)

proc newETerm*(s: char): ErlTerm =
  ## Creates a new `EString ErlTerm`.
  result = ErlTerm(kind: EChar, cval: s)

proc newETuple*(): ErlTerm =
  ## Creates a new `JObject ErlTerm`
  result = ErlTerm(kind: ETupleN, items: @[])

proc newETuple*(items: seq[ErlTerm]): ErlTerm =
  ## Creates a new `JObject ErlTerm`
  result = ErlTerm(kind: ETupleN, items: items)

proc newEList*(): ErlTerm =
  ## Creates a new `JObject ErlTerm`
  result = ErlTerm(kind: EList, elems: @[])

proc newEList*(elems: seq[ErlTerm]): ErlTerm =
  ## Creates a new `JObject ErlTerm`
  result = ErlTerm(kind: EList, elems: @[])

proc newEMap*(): ErlTerm =
  ## Creates a new `JObject ErlTerm`
  result = ErlTerm(kind: EMap, fields: initOrderedTable[ErlTerm, ErlTerm](4))

proc newEAtom*(s: string): ErlTerm =
  ## Creates a new `ENil ErlTerm`.
  result = ErlTerm(kind: EAtom, atm: newErlAtom(s))

proc newENil*(): ErlTerm =
  ## Creates a new `ENil ErlTerm`.
  result = ErlTerm(kind: ENil)

proc getBool*(n: ErlTerm, default: bool = false): bool =
  ## Retrieves the string value of a `JString ErlTerm`.
  ##
  ## Returns ``default`` if ``n`` is not a ``JString``, or if ``n`` is nil.
  if n.isNil or n.kind != EBool: return default
  else: return n.bval

proc getChar*(n: ErlTerm, default: char = '\0'): char =
  ## Retrieves the string value of a `JString ErlTerm`.
  ##
  ## Returns ``default`` if ``n`` is not a ``JString``, or if ``n`` is nil.
  if n.isNil or n.kind != EChar: return default
  else: return n.cval

proc getInt32*(n: ErlTerm, default: int32 = 0): int32 =
  ## Retrieves the string value of a `JString ErlTerm`.
  ##
  ## Returns ``default`` if ``n`` is not a ``JString``, or if ``n`` is nil.
  if n.isNil: return default
  elif n.kind == EInt32: return n.n32
  elif n.kind == EInt64: return n.n64.int32 # possible overflow? 
  else: return default

proc getInt64*(n: ErlTerm, default: int64 = 0): int64 =
  ## Retrieves the string value of a `JString ErlTerm`.
  ##
  ## Returns ``default`` if ``n`` is not a ``JString``, or if ``n`` is nil.
  if n.isNil: return default
  elif n.kind == EInt32: return n.n32.int64
  elif n.kind == EInt64: return n.n64 # possible overflow? 
  else: return default

proc getFloat64*(n: ErlTerm, default: float64 = 0): float64 =
  ## Retrieves the string value of a `JString ErlTerm`.
  ##
  ## Returns ``default`` if ``n`` is not a ``JString``, or if ``n`` is nil.
  if n.isNil or n.kind != EDouble: return default
  else: return n.f64

proc getAtom*(n: ErlTerm, default: ErlAtom = AtomNil ): ErlAtom =
  ## Retrieves the string value of a `JString ErlTerm`.
  ##
  ## Returns ``default`` if ``n`` is not a ``JString``, or if ``n`` is nil.
  if n.isNil or n.kind != EAtom: return default
  else: return n.atm

proc getString*(n: ErlTerm, default: string = ""): string =
  ## Retrieves the string value of a `JString ErlTerm`.
  ##
  ## Returns ``default`` if ``n`` is not a ``JString``, or if ``n`` is nil.
  if n.isNil or n.kind != EString: return default
  else: return n.str

proc getBinary*(n: ErlTerm, default: seq[byte] = @[]): seq[byte] =
  ## Retrieves the string value of a `JString ErlTerm`.
  ##
  ## Returns ``default`` if ``n`` is not a ``JString``, or if ``n`` is nil.
  if n.isNil or n.kind != EBinary: return default
  else: return n.bin

proc getRef*(n: ErlTerm): Option[ErlangRef] =
  ## Retrieves the string value of a `JString ErlTerm`.
  ##
  ## Returns ``default`` if ``n`` is not a ``JString``, or if ``n`` is nil.
  if n.isNil or n.kind != ERef: return none(ErlangRef)
  else: return some(n.eref)

proc getPid*(n: ErlTerm): Option[ErlangPid] =
  ## Retrieves the string value of a `JString ErlTerm`.
  ##
  ## Returns ``default`` if ``n`` is not a ``JString``, or if ``n`` is nil.
  if n.isNil or n.kind != EPid: return none(ErlangPid)
  else: return some(n.epid)

proc getPort*(n: ErlTerm): Option[ErlangPort] =
  ## Retrieves the string value of a `JString ErlTerm`.
  ##
  ## Returns ``default`` if ``n`` is not a ``JString``, or if ``n`` is nil.
  if n.isNil or n.kind != EPid: return none(ErlangPort)
  else: return some(n.eport)

proc getMap*(n: ErlTerm,
    default = initOrderedTable[ErlTerm, ErlTerm](4)):
        OrderedTable[ErlTerm, ErlTerm] =
  ## Retrieves the key, value pairs of a `JObject ErlTerm`.
  ##
  ## Returns ``default`` if ``n`` is not a ``JObject``, or if ``n`` is nil.
  if n.isNil or n.kind != EMap: return default
  else: return n.fields

proc getList*(n: ErlTerm, default: seq[ErlTerm] = @[]): seq[ErlTerm] =
  ## Retrieves the array of a `JArray ErlTerm`.
  ##
  ## Returns ``default`` if ``n`` is not a ``JArray``, or if ``n`` is nil.
  if n.isNil or n.kind != EList: return default
  else: return n.elems

proc getTuple*(n: ErlTerm, default: seq[ErlTerm] = @[]): seq[ErlTerm] =
  ## Retrieves the array of a `JArray ErlTerm`.
  ##
  ## Returns ``default`` if ``n`` is not a ``JArray``, or if ``n`` is nil.
  if n.isNil or n.kind != ETupleN: return default
  else: return n.items

proc hash*(a: ErlAtom): Hash =
  result = a.n.hash
  result = !$result

proc hash*(n: ErlangPid): Hash =
  result = !$(hash(n.node) !& hash(n.num) !& hash(n.serial) !& hash(n.creation))

proc hash*(n: ErlangRef): Hash =
  result = !$(hash(n.node) !& hash(n.n) !& hash(n.creation))

proc hash*(n: ErlangPort): Hash =
  result = !$(hash(n.node) !& hash(n.id) !& hash(n.creation))

proc hash*(n: OrderedTable[ErlTerm, ErlTerm]): Hash {.noSideEffect.}

proc hash*(n: ErlTerm): Hash =
  ## Compute the hash for a JSON node
  case n.kind
    of ENil:
      result = Hash(0)
    of EBool:
      result = hash(n.bval.int)
    of EChar:
      result = hash(n.cval)
    of EInt32:
      result = hash(n.n32)
    of EInt64:
      result = hash(n.n64)
    of EDouble:
      result = hash(n.f64)
    of EString:
      result = hash(n.str)
    of EBinary:
      result = hash(n.bin)
    of EAtom:
      result = hash(n.atm)
    of EPid:
      result = hash(n.epid)
    of ERef:
      result = hash(n.eref)
    of EPort:
      result = hash(n.eport)
    of EList:
      result = hash(n.elems)
    of ETupleN:
      result = hash(n.items)
    of EMap:
      result = hash(n.fields)


proc hash*(n: OrderedTable[ErlTerm, ErlTerm]): Hash =
  for key, val in n:
    result = result xor (hash(key) !& hash(val))
  result = !$result

proc addTuple*(father, child: ErlTerm) =
  ## Adds `child` to a JArray node `father`.
  assert father.kind == ETupleN 
  father.items.add(child)

proc addList*(father, child: ErlTerm) =
  ## Adds `child` to a JArray node `father`.
  assert father.kind == EList 
  father.elems.add(child)

proc addKeyValue*(obj: ErlTerm, key: ErlTerm, val: ErlTerm) =
  ## Sets a field from a `JObject`.
  assert obj.kind == EMap
  obj.fields[key] = val

proc `%`*[T](v: T): ErlTerm =
  ## Creates a new `EString ErlTerm`.
  result = newETerm(v)

proc `[]=`*(obj: ErlTerm, key: ErlTerm, val: ErlTerm) {.inline.} =
  ## Sets a field from a `JObject`.
  assert(obj.kind == EMap)
  obj.fields[key] = val

proc `%`*[T: object](o: T): ErlTerm =
  ## Construct ErlTerm from tuples and objects.
  result = newETerm()
  for k, v in o.fieldPairs: result[k] = %v

proc `%`*(o: ref object): ErlTerm =
  ## Generic constructor for JSON data. Creates a new `JObject ErlTerm`
  if o.isNil:
    result = newENil()
  else:
    result = %(o[])

proc `%`*(o: enum): ErlTerm =
  ## Construct a ErlTerm that represents the specified enum value as a
  ## string. Creates a new ``JString ErlTerm``.
  result = %($o)

proc toTerm(x: NimNode): NimNode {.compileTime.} =
  case x.kind
  of nnkBracket: # array
    if x.len == 0: return newCall(bindSym"newEList")
    result = newNimNode(nnkBracket)
    for i in 0 ..< x.len:
      result.add(toTerm(x[i]))
    result = newCall(bindSym("%", brOpen), result)
  of nnkTableConstr: # object
    if x.len == 0: return newCall(bindSym"newEMap")
    result = newNimNode(nnkTableConstr)
    for i in 0 ..< x.len:
      x[i].expectKind nnkExprColonExpr
      result.add newTree(nnkExprColonExpr, x[i][0], toTerm(x[i][1]))
    result = newCall(bindSym("%", brOpen), result)
  of nnkCurly: # empty object
    x.expectLen(0)
    result = newCall(bindSym"newEMap")
  of nnkNilLit:
    result = newCall(bindSym"newENil")
  of nnkPar:
    if x.len == 1: result = toTerm(x[0])
    else: result = newCall(bindSym("%", brOpen), x)
  else:
    result = newCall(bindSym("%", brOpen), x)

macro `%*`*(x: untyped): untyped =
  ## Convert an expression to a ErlTerm directly, without having to specify
  ## `%` for every element.
  result = toTerm(x)

proc `==`*(a, b: ErlTerm): bool =
  ## Check two nodes for equality
  if a.isNil:
    if b.isNil: return true
    return false
  elif b.isNil or a.kind != b.kind:
    return false
  else:
    case a.kind
    of ENil:
      result = true
    of EBool:
      result = a.bval == b.bval
    of EChar:
      result = a.cval == b.cval
    of EInt32:
      result = a.n32 == b.n32
    of EInt64:
      result = a.n64 == b.n64
    of EDouble:
      result = a.f64 == b.f64
    of EString:
      result = a.str == b.str
    of EBinary:
      result = a.bin == b.bin
    of EAtom:
      result = a.atm == b.atm
    of EPid:
      result = a.epid == b.epid
    of ERef:
      result = a.eref == b.eref
    of EPort:
      result = a.eport == b.eport
    of ETupleN:
      result = a.items == b.items
    of EList:
      result = a.elems == b.elems
    of EMap:
      # we cannot use OrderedTable's equality here as
      # the order does not matter for equality here.
      if a.fields.len != b.fields.len: return false
      for key, val in a.fields:
        if not b.fields.hasKey(key): return false
        if b.fields[key] != val: return false
      result = true


proc len*(n: ErlTerm): int =
  ## If `n` is a `JArray`, it returns the number of elements.
  ## If `n` is a `JObject`, it returns the number of pairs.
  ## Else it returns 0.
  case n.kind
  of EList: result = n.elems.len
  of EMap: result = n.fields.len
  else: discard

proc `[]`*(node: ErlTerm, name: ErlTerm): ErlTerm {.inline.} =
  ## Gets a field from a `JObject`, which must not be nil.
  ## If the value at `name` does not exist, raises KeyError.
  assert(not isNil(node))
  assert(node.kind == EMap)
  when defined(nimErlGet):
    if not node.fields.hasKey(name): return nil
  result = node.fields[name]

proc `[]`*(node: ErlTerm, index: int): ErlTerm {.inline.} =
  ## Gets the node at `index` in an Array. Result is undefined if `index`
  ## is out of bounds, but as long as array bound checks are enabled it will
  ## result in an exception.
  assert(not isNil(node))
  assert(node.kind == EList)
  return node.elems[index]

proc hasKey*(node: ErlTerm, key: ErlTerm): bool =
  ## Checks if `key` exists in `node`.
  assert(node.kind == EMap)
  result = node.fields.hasKey(key)

proc contains*(node: ErlTerm, key: ErlTerm): bool =
  ## Checks if `key` exists in `node`.
  assert(node.kind == EMap)
  node.fields.hasKey(key)

proc contains*(node: ErlTerm, val: ErlTerm): bool =
  ## Checks if `val` exists in array `node`.
  assert(node.kind == EList)
  find(node.elems, val) >= 0

proc `{}`*(node: ErlTerm, keys: varargs[ErlTerm]): ErlTerm =
  ## Traverses the node and gets the given value. If any of the
  ## keys do not exist, returns ``nil``. Also returns ``nil`` if one of the
  ## intermediate data structures is not an object.
  ##
  ## This proc can be used to create tree structures on the
  ## fly (sometimes called `autovivification`:idx:):
  ##
  ## .. code-block:: nim
  ##   myjson{"parent", "child", "grandchild"} = newJInt(1)
  ##
  result = node
  for key in keys:
    if isNil(result) or result.kind != EMap:
      return nil
    result = result.fields.getOrDefault(key)

proc `{}`*(node: ErlTerm, index: varargs[int]): ErlTerm =
  ## Traverses the node and gets the given value. If any of the
  ## indexes do not exist, returns ``nil``. Also returns ``nil`` if one of the
  ## intermediate data structures is not an array.
  result = node
  for i in index:
    if isNil(result) or result.kind != EList or i >= node.len:
      return nil
    result = result.elems[i]

proc getOrDefault*(node: ErlTerm, key: ErlTerm): ErlTerm =
  ## Gets a field from a `node`. If `node` is nil or not an object or
  ## value at `key` does not exist, returns nil
  if not isNil(node) and node.kind == EMap:
    result = node.fields.getOrDefault(key)

proc `{}`*(node: ErlTerm, key: ErlTerm): ErlTerm =
  ## Gets a field from a `node`. If `node` is nil or not an object or
  ## value at `key` does not exist, returns nil
  node.getOrDefault(key)

proc `{}=`*(node: ErlTerm, keys: varargs[ErlTerm], value: ErlTerm) =
  ## Traverses the node and tries to set the value at the given location
  ## to ``value``. If any of the keys are missing, they are added.
  var node = node
  for i in 0..(keys.len-2):
    if not node.hasKey(keys[i]):
      node[keys[i]] = newEMap()
    node = node[keys[i]]
  node[keys[keys.len-1]] = value

proc delete*(obj: ErlTerm, key: ErlTerm) =
  ## Deletes ``obj[key]``.
  assert(obj.kind == EMap)
  if not obj.fields.hasKey(key):
    raise newException(KeyError, "key not in object")
  obj.fields.del(key)

proc copy*(p: ErlTerm): ErlTerm =
  ## Performs a deep copy of `a`.
  case p.kind
  of ENil:
    result = newENil()
  of EBool:
    result = newETerm(p.bval)
  of EChar:
    result = newETerm(p.cval)
  of EInt32:
    result = newETerm(p.n32)
  of EInt64:
    result = newETerm(p.n64)
  of EDouble:
    result = newETerm(p.f64)
  of EString:
    result = newETerm(p.str)
  of EBinary:
    result = newETerm(p.bin)
  of EAtom:
    result = newETerm(p.atm)
  of EPid:
    result = newETerm(p.epid)
  of ERef:
    result = newETerm(p.eref)
  of EPort:
    result = newETerm(p.eport)
  of ETupleN:
    result = newETuple()
    for i in items(p.elems):
      result.elems.add(copy(i))
  of Emap:
    result = newEMap()
    for key, val in pairs(p.fields):
      result.fields[key] = copy(val)
  of EList:
    result = newEList()
    for i in items(p.elems):
      result.elems.add(copy(i))

type
  ErlStream* = ref ErlStreamObj
    ## A stream that encapsulates a string.
    ##
    ## **Note:** Not available for JS backend.
  ErlStreamObj* = object
    ## A string stream object.
    ##
    ## **Note:** Not available for JS backend.
    data*: string ## A string data.
                  ## This is updated when called `writeLine` etc.
    pos*: cint

proc newErlStream*(capacity: int): ErlStream =
  new(result)
  result.data = newString(capacity)
  # zeroMem(addr(result.data), capacity) 
  # echo "newErlStream: capacity: " & $capacity
  # echo "newErlStream: repr: " & $len(result.data)
  # for i in 0..<capacity:
    # result.data.add("a")
  result.pos = 0

proc ensureAvailable*(ss: ErlStream, count: int) =
  # echo "ensureAvailable:ss: size: " & $len(ss.data) & " pos: " & $ss.pos & " for count: " & $count
  if count >= ss.data.len() - ss.pos:
    # echo "ensureAvailable:ss: expand to: "  & $(2*ss.data.len())
    var ydata = newString(2 * ss.data.len())
    copyMem(addr(ydata), addr(ss.data), ss.pos) 
    ss.data = ydata

proc `addr`*(ss: var ErlStream): cstring =
  return cstring(ss.data)

proc indexAddr*(ss: var ErlStream): ptr cint =
  return addr(ss.pos)

proc available*(ss: var ErlStream): int =
  return len(ss.data) - ss.pos 

proc hasAvailable*(ss: var ErlStream, bytes: int): bool =
  return (len(ss.data) - ss.pos) >= bytes

proc termsToBinary*(ss: var ErlStream, node: ErlTerm) =
  ## Converts `ErlTerm` to its Erlang Term Representation
  
  # This should be enough for any fixed sized
  # variable lengths like binaries are checked for their length
  const minFree = 16
  const minFreeStruct = 24

  # echo "termsToBinary: " & repr(node.kind)
  ss.ensureAvailable(minFree)

  case node.kind:
  of EList:
    var vals: seq[ErlTerm] = node.getList()
    if ei_encode_list_header(addr(ss), indexAddr(ss), vals.len.cint) != 0:
      raise newException(ErlKindError, "list encode error")
    for child in node.elems:
      ss.termsToBinary(child)
  of EMap:
    var vals: OrderedTable[ErlTerm, ErlTerm] = node.getMap()
    ss.ensureAvailable(8)
    if ei_encode_map_header(addr(ss), indexAddr(ss), vals.len.cint) != 0:
      raise newException(ErlKindError, "map encode error")
    for child in node.elems:
      ss.termsToBinary(child)
  of ETupleN:
    var vals: seq[ErlTerm] = node.getTuple()
    if ei_encode_tuple_header(addr(ss), indexAddr(ss), vals.len.cint) != 0:
      raise newException(ErlKindError, "list encode error")
    for child in vals:
      ss.termsToBinary(child)
  of EString:
    var val: string = node.str
    ss.ensureAvailable(len(val)+minFree)
    if ei_encode_string_len(addr(ss), indexAddr(ss), cstring(val), val.len.cint) != 0:
      raise newException(ErlKindError, "string encode error")
  of EBinary:
    var val: seq[byte] = node.bin
    ss.ensureAvailable(len(val)+minFree)
    var valAddr: cstring = cast[cstring](addr(val[0]))
    if ei_encode_string_len(addr(ss), indexAddr(ss), valAddr, val.len.cint) != 0:
      raise newException(ErlKindError, "string encode error")
  of EAtom:
    var val = node.getAtom()
    ss.ensureAvailable(len(val.n)+minFree)
    if ei_encode_atom_len(addr(ss), indexAddr(ss), val.n, val.n.len.cint) != 0:
      raise newException(ErlKindError, "string encode error")
  of ERef:
    var val = node.eref
    ss.ensureAvailable(minFreeStruct)
    if ei_encode_ref(addr(ss), indexAddr(ss), addr(val)) != 0:
      raise newException(ErlKindError, "string encode error")
  of EPid:
    var val = node.epid
    ss.ensureAvailable(minFreeStruct)
    if ei_encode_pid(addr(ss), indexAddr(ss), addr(val)) != 0:
      raise newException(ErlKindError, "pid encode error")
  of EPort:
    var val = node.eport
    ss.ensureAvailable(minFreeStruct)
    if ei_encode_port(addr(ss), indexAddr(ss), addr(val)) != 0:
      raise newException(ErlKindError, "port encode error")
  of EInt32:
    var val = node.getInt32()
    if ei_encode_long(addr(ss), indexAddr(ss), val) != 0:
      raise newException(ErlKindError, "int32 encode error")
  of EInt64:
    var val = node.getInt64()
    if ei_encode_longlong(addr(ss), indexAddr(ss), val) != 0:
      raise newException(ErlKindError, "int64 encode error")
  of EDouble:
    var val = node.getFloat64()
    if ei_encode_double(addr(ss), indexAddr(ss), val) != 0:
      raise newException(ErlKindError, "float encode error")
  of EChar:
    var val = node.getChar()
    if ei_encode_boolean(addr(ss), indexAddr(ss), val.cint) != 0:
      raise newException(ErlKindError, "float encode error")
  of EBool:
    var val = node.getBool()
    if ei_encode_boolean(addr(ss), indexAddr(ss), val.cint) != 0:
      raise newException(ErlKindError, "float encode error")
  of ENil:
    ss.termsToBinary(newETerm(AtomNil))

proc termToBinary*(node: ErlTerm; capacity: int = 128): ErlStream =
  var ss = newErlStream(capacity)

  # echo "ei_encode_version"
  # echo "ei_encode_version:repr: " & repr(ss)
  # echo "ei_encode_version:len(data): " & $len(cstring(ss.data))

  if ei_encode_version(addr(ss), indexAddr(ss)) != 0:
    raise newException(ErlKindError, "version encode error")

  # echo "termToBinary"
  termsToBinary(ss, node)
  # echo "termToBinary: done"
  return ss

proc binaryToTerms*(ss: var ErlStream): ErlTerm =

  # Returns the type in *type and size in *size of the encoded term. For strings and atoms, 
  # size is the number of characters not including the terminating NULL. For binaries and
  # bitstrings, *size is the number of bytes. For lists, tuples and maps, *size is the arity
  # of the object. For other types, *size is 0. In all cases, index is left unchanged.

  var erlType: cint = 0
  var erlSize: cint = 0

  if ei_get_type(addr(ss), indexAddr(ss), erlType.addr, erlSize.addr) != 0:
    raise newException(ErlKindError, "error parsing kind")

  case ErlExtTypes(erlType):
  of ERL_CACHED_ATOM:
    raise newException(ErlKindError, "invalid type for c-nodes")
  of ERL_NEW_CACHE:
    raise newException(ErlKindError, "invalid type for c-nodes")
  of NEW_FLOAT_EXT:
    var val: float
    if ei_decode_double(addr(ss), indexAddr(ss), addr(val)) != 0:
      raise newException(ErlKindError, "error parsing float")
    result = newETerm(val)
  of ERL_BIT_BINARY_EXT:
    raise newException(ValueError, "not implemented yet")
  of ERL_NEW_PID_EXT:
    var val: ErlangPid
    if ei_decode_pid(addr(ss), indexAddr(ss), addr(val)) != 0:
      raise newException(ErlKindError, "error parsing pid")
    result = newETerm(val)
  of ERL_NEW_PORT_EXT:
    var val: ErlangPort
    if ei_decode_port(addr(ss), indexAddr(ss), addr(val)) != 0:
      raise newException(ErlKindError, "error parsing port")
    result = newETerm(val)
  of ERL_SMALL_INTEGER_EXT:
    var val: clong
    if ei_decode_long(addr(ss), indexAddr(ss), addr(val)) != 0:
      raise newException(ErlKindError, "error parsing ints")
    result = newETerm(val.int32)
  of ERL_INTEGER_EXT:
    var val: clonglong
    if ei_decode_longlong(addr(ss), indexAddr(ss), addr(val)) != 0:
      raise newException(ErlKindError, "error parsing ints")
    result = newETerm(val.int64)
  of ERL_FLOAT_EXT:
    var val: cdouble
    if ei_decode_double(addr(ss), indexAddr(ss), addr(val)) != 0:
      raise newException(ErlKindError, "error parsing ref")
    result = newETerm(val)
  of ERL_ATOM_EXT, ERL_ATOM_UTF8_EXT, ERL_SMALL_ATOM_EXT, ERL_SMALL_ATOM_UTF8_EXT:
    var val = newString(MAXATOMLEN_UTF8+1)
    var atm: ErlAtom
    if ei_decode_atom(addr(ss), indexAddr(ss), cstring(val)) != 0:
      raise newException(ErlKindError, "error parsing atom")
    atm.n = $cstring(val)
    result = newETerm(atm)
  of ERL_REFERENCE_EXT, ERL_NEW_REFERENCE_EXT, ERL_NEWER_REFERENCE_EXT:
    var val: ErlangRef
    if ei_decode_ref(addr(ss), indexAddr(ss), addr(val)) != 0:
      raise newException(ErlKindError, "error parsing ext")
    result = newETerm(val)
  of ERL_PORT_EXT:
    var val: ErlangPort
    if ei_decode_port(addr(ss), indexAddr(ss), addr(val)) != 0:
      raise newException(ErlKindError, "error parsing port")
    result = newETerm(val)
  of ERL_PID_EXT:
    var val: ErlangPid
    if ei_decode_pid(addr(ss), indexAddr(ss), addr(val)) != 0:
      raise newException(ErlKindError, "error parsing pid")
    result = newETerm(val)
  of ERL_SMALL_TUPLE_EXT, ERL_LARGE_TUPLE_EXT:
    var arity: cint
    if ei_decode_tuple_header(addr(ss), indexAddr(ss), addr(arity)) != 0:
      raise newException(ErlKindError, "error parsing tuple")
    result = newETuple()
    for i in 1..arity:
      # echo "erl_small_tuple_ext: " & $i
      result.addTuple(binaryToTerms(ss))
  of ERL_NIL_EXT:
    if ei_skip_term(addr(ss), indexAddr(ss)) != 0:
      raise newException(ErlKindError, "error parsing ref")
    result = newENil()
  of ERL_STRING_EXT:
    var val = newString(erlSize.int)
    if ei_decode_string(addr(ss), indexAddr(ss), cstring(val)) != 0:
      raise newException(ErlKindError, "error parsing string")
    result = newETerm($val)
  of ERL_LIST_EXT:
    var arity: cint
    if ei_decode_list_header(addr(ss), indexAddr(ss), addr(arity)) != 0:
      raise newException(ErlKindError, "error parsing tuple")
    result = newEList()
    for i in 1..arity:
      result.addList(binaryToTerms(ss))
  of ERL_MAP_EXT:
    var arity: cint
    if ei_decode_map_header(addr(ss), indexAddr(ss), addr(arity)) != 0:
      raise newException(ErlKindError, "error parsing map")
    result = newEMap()
    for i in 1..arity:
      var k = binaryToTerms(ss)
      var v = binaryToTerms(ss)
      result.addKeyValue(k, v)
  of ERL_BINARY_EXT:
    var val = newSeq[byte](erlSize.int)
    if ei_decode_string(addr(ss), indexAddr(ss), cast[cstring](addr(val[0]))) != 0:
      raise newException(ErlKindError, "error parsing binary")
    result = newETerm(val)
  of ERL_SMALL_BIG_EXT, ERL_LARGE_BIG_EXT:
    raise newException(ErlKindError, "error parsing kind")
  of ERL_NEW_FUN_EXT, ERL_FUN_EXT:
    raise newException(ErlKindError, "error parsing kind")
  of ERL_EXPORT_EXT:
    raise newException(ErlKindError, "error parsing kind")

proc binaryToTerms*(emsg: EiBuff): ErlTerm =
  var ss = new(ErlStream)
  ss.data = newString(emsg.buffsz)
  copyMem(cstring(ss.data), emsg.buff, emsg.buffsz)
  ss.pos = 0

  var version: cint = 0
  # Check for version
  discard ei_decode_version(addr(ss), indexAddr(ss), addr(version))
    
  binaryToTerms(ss)

