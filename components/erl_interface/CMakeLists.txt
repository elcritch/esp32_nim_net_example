idf_component_register(
  SRC_DIRS "src/connect" "src/decode" "src/encode" "src/epmd" "src/misc" "src/registry"
  INCLUDE_DIRS  "include" 
  PRIV_INCLUDE_DIRS  "src/connect" "src/decode" "src/encode" "src/epmd" "src/misc" "src/registry"
  REQUIRES lwip 
)

target_compile_options(${COMPONENT_LIB} PRIVATE -DHAVE_SOCKLEN_T)
