project(STM32_HAL)

set(STM32F4_HALDIR stm32f4xx-hal-driver)

set(STM32F4_SOURCES
    config/stm32f4xx_hal_conf.h

    ${STM32F4_HALDIR}/Inc/stm32f4xx_hal_def.h
    ${STM32F4_HALDIR}/Inc/stm32f4xx_hal.h
    ${STM32F4_HALDIR}/Src/stm32f4xx_hal.c

    ${STM32F4_HALDIR}/Inc/stm32f4xx_hal_can.h
    ${STM32F4_HALDIR}/Src/stm32f4xx_hal_can.c

    ${STM32F4_HALDIR}/Inc/stm32f4xx_hal_cortex.h
    ${STM32F4_HALDIR}/Src/stm32f4xx_hal_cortex.c

    ${STM32F4_HALDIR}/Inc/stm32f4xx_hal_flash_ex.h
    ${STM32F4_HALDIR}/Src/stm32f4xx_hal_flash_ex.c
    ${STM32F4_HALDIR}/Inc/stm32f4xx_hal_flash.h
    ${STM32F4_HALDIR}/Src/stm32f4xx_hal_flash.c

    ${STM32F4_HALDIR}/Inc/stm32f4xx_hal_gpio_ex.h
    ${STM32F4_HALDIR}/Inc/stm32f4xx_hal_gpio.h
    ${STM32F4_HALDIR}/Src/stm32f4xx_hal_gpio.c

    ${STM32F4_HALDIR}/Inc/stm32f4xx_hal_pcd_ex.h
    ${STM32F4_HALDIR}/Src/stm32f4xx_hal_pcd_ex.c
    ${STM32F4_HALDIR}/Inc/stm32f4xx_hal_pcd.h
    ${STM32F4_HALDIR}/Src/stm32f4xx_hal_pcd.c

    ${STM32F4_HALDIR}/Inc/stm32f4xx_hal_rcc.h
    ${STM32F4_HALDIR}/Src/stm32f4xx_hal_rcc.c
    ${STM32F4_HALDIR}/Inc/stm32f4xx_hal_rcc_ex.h
    ${STM32F4_HALDIR}/Src/stm32f4xx_hal_rcc_ex.c

    ${STM32F4_HALDIR}/Inc/stm32f4xx_hal_pwr.h
    ${STM32F4_HALDIR}/Src/stm32f4xx_hal_pwr.c
    ${STM32F4_HALDIR}/Inc/stm32f4xx_hal_pwr_ex.h
    ${STM32F4_HALDIR}/Src/stm32f4xx_hal_pwr_ex.c

    ${STM32F4_HALDIR}/Inc/stm32f4xx_hal_tim_ex.h
    ${STM32F4_HALDIR}/Src/stm32f4xx_hal_tim_ex.c
    ${STM32F4_HALDIR}/Inc/stm32f4xx_hal_tim.h
    ${STM32F4_HALDIR}/Src/stm32f4xx_hal_tim.c

    ${STM32F4_HALDIR}/Inc/stm32f4xx_ll_usb.h
    ${STM32F4_HALDIR}/Src/stm32f4xx_ll_usb.c

    src/cmsis/system_stm32f4xx.c
    ${STM32F4_HALDIR}/Inc/Legacy/stm32_hal_legacy.h

    include/cmsis/cmsis_compiler.h
    include/cmsis/cmsis_device.h
    include/cmsis/cmsis_gcc.h
    include/cmsis/cmsis_version.h
    include/cmsis/core_cm4.h
    include/cmsis/device/stm32f4xx.h
    include/cmsis/device/stm32f407xx.h
    include/cmsis/device/stm32f413xx.h
    include/cmsis/device/system_stm32f4xx.h
)

set(INCLUDE_DIRS
    include/
    include/cmsis
    include/cmsis/device
    config/
)

add_library(STM32_HAL_STM32F413xx STATIC ${STM32F4_SOURCES})
target_include_directories(STM32_HAL_STM32F413xx PUBLIC ${INCLUDE_DIRS} ${STM32F4_HALDIR}/Inc)
target_compile_options(STM32_HAL_STM32F413xx PRIVATE ${CPUFLAGS_F4} -Wno-unused-parameter)
target_compile_definitions(STM32_HAL_STM32F413xx PUBLIC STM32F413xx)
