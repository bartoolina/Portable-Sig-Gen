add_library(systemview STATIC)

enable_language(C ASM)

target_include_directories(systemview PUBLIC
    ${LIBS_PATH}/SystemView/Config
    ${LIBS_PATH}/SystemView/FreeRTOSV11
    ${LIBS_PATH}/SystemView/SEGGER
)

target_sources(systemview PRIVATE
    ${LIBS_PATH}/SystemView/SEGGER/SEGGER_SYSVIEW.c
    ${LIBS_PATH}/SystemView/SEGGER/SEGGER_RTT.c
    ${LIBS_PATH}/SystemView/SEGGER/SEGGER_RTT_printf.c
    ${LIBS_PATH}/SystemView/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.c
    ${LIBS_PATH}/SystemView/Config/SEGGER_SYSVIEW_Config_FreeRTOS.c
    ${LIBS_PATH}/SystemView/FreeRTOSV11/SEGGER_SYSVIEW_FreeRTOS.c
    ${LIBS_PATH}/SystemView/SEGGER/SEGGER_RTT_ASM_ARMv7M.S
)
