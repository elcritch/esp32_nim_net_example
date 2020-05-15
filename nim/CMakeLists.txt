idf_component_register(SRC_DIRS "_nimcache"
                    INCLUDE_DIRS ""
                    REQUIRES lwip newlib)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-error=unused-label")