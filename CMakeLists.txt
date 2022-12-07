cmake_minimum_required(VERSION 3.12)


if(0)#pico build
add_definitions(-Dfoo)
include(pico_sdk_import.cmake)
project(llcd)
pico_sdk_init()


include_directories(./include)
include_directories(./include/pico)

add_library(llcd 
src/llcd.cpp
src/llcd3d.cpp
src/pico/DEV_Config.cpp
src/pico/LCD_1in14.cpp
src/pico/Infrared.cpp
src/PicoPwm.cpp
)

target_link_libraries(llcd PUBLIC pico_stdlib hardware_spi hardware_i2c hardware_pwm hardware_adc hardware_clocks hardware_pio)


function(buildLlcd X)#${X}
    add_executable(${X}_demo 
    demo/${X}.cpp
    )

    target_link_libraries(${X}_demo  llcd)

    pico_enable_stdio_usb(${X}_demo  1)
    pico_enable_stdio_uart(${X}_demo  0)

    pico_add_extra_outputs(${X}_demo )
endfunction()

else()#other
project(llcd VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)

set(A boxes)
set(B draw)
set(C snake)
set(D 3d)

add_subdirectory(libs/sfml/)

include_directories(./include)
include_directories(./include/other)

add_library(llcd src/llcd.cpp src/llcd3d.cpp src/PicoPwm.cpp src/other/toot.cpp)
target_link_libraries(llcd PUBLIC sfml-graphics sfml-window sfml-system)
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
if (OPENGL_FOUND)
  target_link_libraries(llcd PUBLIC ${OPENGL_LIBRARIES})
endif()

function(buildLlcd X)
    add_executable(${X}_demo 
    demo/${X}.cpp
    )

    target_link_libraries(${X}_demo PUBLIC llcd)
endfunction()

endif()

buildLlcd(boxes)
buildLlcd(draw)
buildLlcd(snake)
buildLlcd(3d)
