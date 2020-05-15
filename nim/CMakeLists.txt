
idf_component_register(SRC_DIRS "_nimcache"
                    INCLUDE_DIRS ""
                    REQUIRES lwip newlib)

# set(C_COMPILE_OPTIONS "${C_COMPILE_OPTIONS} -Wno-error=unused-label")
# list(APPEND C_COMPILE_OPTIONS "-Wno-error=unused-label ")
idf_build_set_property(C_COMPILE_OPTIONS -Wno-error=unused-label -Wno-error=parentheses APPEND)

