import os

task prepare, "Compile to C code":
  #echo selfExe()
  mkDir(".\\nimcache")
  let nimbasepath = selfExe().splitFile.dir.parentDir / "lib" / "nimbase.h"
  cpFile(nimbasepath,"nimcache"/"nimbase.h")
  let file = paramStr(2)
  exec("nim c --gc:arc --define:debug --define:useMalloc --os:freertos --no_main --cpu:esp --nimcache:nimcache --compileonly --genscript --define:no_signal_handler --debugger:native --threads:on --tls_emulation:off " & file)
