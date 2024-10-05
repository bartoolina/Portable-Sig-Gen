add_library(ulog INTERFACE)

target_include_directories(printf INTERFACE
    ${LIBS_PATH}/ulog
)

target_sources(printf INTERFACE
    ${LIBS_PATH}/ulog/ulog.c
)