cmake_minimum_required(VERSION 3.12)
include(pico_sdk_import.cmake)
project(llcd)
pico_sdk_init()


include_directories(./include)

add_library(llcd 
llcd.cpp
DEV_Config.cpp
LCD_1in14.cpp
Infrared.cpp
)
target_link_libraries(llcd PUBLIC pico_stdlib hardware_spi hardware_i2c hardware_pwm hardware_adc)


#boxes demo
add_executable(boxes_demo 
demo/boxes.cpp
)

target_link_libraries(boxes_demo  llcd)

pico_enable_stdio_usb(boxes_demo  1)
pico_enable_stdio_uart(boxes_demo  1)

pico_add_extra_outputs(boxes_demo )


#drawing demo
add_executable(draw_demo #add binary
demo/draw.cpp
)

target_link_libraries(draw_demo  llcd) #link 

pico_enable_stdio_usb(draw_demo  1)
pico_enable_stdio_uart(draw_demo  1)

pico_add_extra_outputs(draw_demo )
