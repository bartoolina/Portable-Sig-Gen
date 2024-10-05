cmake_minimum_required(VERSION 3.22)

# project(stm32hal)
add_library(stm32hal INTERFACE)

# Enable CMake support for ASM and C languages
enable_language(C ASM)

target_compile_definitions(stm32hal INTERFACE 
	USE_HAL_DRIVER 
	STM32G474xx
    $<$<CONFIG:Debug>:DEBUG>
)

target_include_directories(stm32hal INTERFACE
    ../../Core/Inc
    ../../Drivers/STM32G4xx_HAL_Driver/Inc
    ../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy
    ../../Drivers/CMSIS/Device/ST/STM32G4xx/Include
    ../../Drivers/CMSIS/Include
)

target_sources(stm32hal INTERFACE
    ../../Core/Src/main.c
    ../../Core/Src/app_freertos.c
    ../../Core/Src/gpio.c
    ../../Core/Src/usart.c
    ../../Core/Src/stm32g4xx_it.c
    ../../Core/Src/stm32g4xx_hal_msp.c
    ../../Core/Src/stm32g4xx_hal_timebase_tim.c
    ../../Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_uart.c
    ../../Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_uart_ex.c
    ../../Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal.c
    ../../Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_rcc.c
    ../../Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_rcc_ex.c
    ../../Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_flash.c
    ../../Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_flash_ex.c
    ../../Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_flash_ramfunc.c
    ../../Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_gpio.c
    ../../Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_exti.c
    ../../Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_dma.c
    ../../Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_dma_ex.c
    ../../Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_pwr.c
    ../../Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_pwr_ex.c
    ../../Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_cortex.c
    ../../Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_uart.c
    ../../Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_uart_ex.c
    ../../Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_tim.c
    ../../Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_tim_ex.c
    ../../Core/Src/system_stm32g4xx.c
    ../../Core/Src/sysmem.c
    ../../Core/Src/syscalls.c
    ../../startup_stm32g474xx.s
)

target_link_directories(stm32hal INTERFACE
)

target_link_libraries(stm32hal INTERFACE
)

# Validate that STM32CubeMX code is compatible with C standard
if(CMAKE_C_STANDARD LESS 11)
    message(ERROR "Generated code requires C11 or higher")
endif()


