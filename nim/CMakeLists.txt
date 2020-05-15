idf_component_register(SRC_DIRS "_nimcache"
                    INCLUDE_DIRS ""
                    REQUIRES lwip newlib)

set(COMMON_WARNING_FLAGS "${COMMON_WARNING_FLAGS} -Wno-error=unused-label")