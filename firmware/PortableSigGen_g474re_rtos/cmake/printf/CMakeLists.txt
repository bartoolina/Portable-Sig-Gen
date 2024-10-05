add_library(printf INTERFACE)

target_include_directories(printf INTERFACE
    ${LIBS_PATH}/printf
)

target_sources(printf INTERFACE
    ${LIBS_PATH}/printf/printf.c
)