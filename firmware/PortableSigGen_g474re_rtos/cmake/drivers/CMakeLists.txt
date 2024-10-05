add_library(drivers INTERFACE)

target_include_directories(drivers INTERFACE
    ${DRIVERS_PATH}/hw_button
)

target_sources(drivers INTERFACE
    ${DRIVERS_PATH}/hw_button/hw_button.c
)