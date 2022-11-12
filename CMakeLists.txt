cmake_minimum_required(VERSION 3.12)
include(pico_sdk_import.cmake)
project(llcd)
pico_sdk_init()


include_directories(./include)

add_library(llcd 
llcd.cpp
DEV_Config.cpp
LCD_1in14.cpp
)


add_executable(llcd_test 
llcd_Test.cpp
)
target_link_libraries(llcd PUBLIC pico_stdlib hardware_spi hardware_i2c hardware_pwm hardware_adc)
target_link_libraries(llcd_test llcd)

# enable usb output, disable uart output
pico_enable_stdio_usb(llcd_test 1)
pico_enable_stdio_uart(llcd_test 1)

pico_add_extra_outputs(llcd_test)
