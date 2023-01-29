cmake_minimum_required(VERSION 3.12)
project(llcd VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

#include(pico_sdk_import.cmake)
#project(llcd)
#pico_sdk_init()

#add_library(llcd 
#src/llcd.cpp
#src/asci.cpp
#src/llcd3d.cpp
#src/pico/DEV_Config.cpp
#src/pico/LCD_1in14.cpp
#src/pico/Infrared.cpp
#src/PicoPwm.cpp
#)

#target_link_libraries(llcd PUBLIC pico_stdlib hardware_spi hardware_i2c hardware_pwm hardware_adc hardware_clocks hardware_pio)
#target_link_libraries(${X}_demo  llcd)
#
#pico_enable_stdio_usb(${X}_demo  1)
#pico_enable_stdio_uart(${X}_demo  0)
#
#pico_add_extra_outputs(${X}_demo )
#include_directories(./include/other)

set(SFML_STATIC_LIBRARIES TRUE)

add_subdirectory(libs/sfml/)

include_directories(include/)



set(llcd_common
    src/ctx.cpp 
    src/llcd.cpp
    src/data.cpp
    src/scenes.cpp
    src/objects.cpp
    src/event.cpp
    src/window.cpp
)



if(0)#picd

#include(pico_sdk_import.cmake)
#pico_sdk_init()

include_directories(include/pico/)

add_library(llcd STATIC 
    ${llcd_common}
    #platform specyfic 
    src/pico/DEV_Config.cpp
    src/pico/Infrared.cpp
    src/pico/LCD_1in14.cpp
    src/pico/PicoPwm.cpp
    src/pico/graphic.cpp
)

#target_link_libraries(llcd PUBLIC pico_stdlib hardware_spi hardware_i2c hardware_pwm hardware_adc hardware_clocks hardware_pio)

else()
add_library(llcd STATIC 
    ${llcd_common}
    #platform specyfic 
    src/desktop/graphicAndInput.cpp
)
endif()

target_link_libraries(llcd PUBLIC sfml-graphics sfml-window sfml-system)

target_include_directories(llcd PUBLIC
    include
)

add_executable(box demo/boxes.cpp)

target_link_libraries(box PUBLIC llcd)

add_executable(test demo/test.cpp)

target_link_libraries(test PUBLIC llcd)
