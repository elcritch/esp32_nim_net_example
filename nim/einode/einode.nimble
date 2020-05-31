# Package

version       = "0.1.0"
author        = "Jaremy Creechley"
description   = "A new awesome nimble package"
license       = "Apache-2.0"
srcDir        = "src"

# Dependencies

requires "nim >= 1.2.0"

# Tests
proc configTest() =
  --app:lib
  --noMain
  --verbosity:2
  --forceBuild
  --parallelBuild:0
  --hint[Conf]:off
  --hint[Processing]:off
  --hint[GCStats]:off
  --hint[GlobalVar]:off
  --checks:off
  --path:"."

  if getEnv("NIMLER_BUILD_RELEASE") == "1":
    --define:release

  if getEnv("NIMLER_BUILD_ARM64") == "1":
    --gcc.exe:"aarch64-linux-gnu-gcc"
    --gcc.linkerexe:"aarch64-linux-gnu-ld"
    --cpu:arm64
    --os:linux

  switch("gc", getEnv("NIMLER_BUILD_GC", "arc"))


task test_all, "run tests":
  exec("elixir test_all.exs")

task build_init_api, "build nif":
  configTest()
  switch("out", "tests/init_api/nif.so")
  setCommand("compile", "tests/init_api/nif")


