/*
a great pice of code

coded and delivered by L team
code by luk the oop programmer
debbugged by zoz the glaceon

it may break everything it touches
or something i dont know why
some people state that but yes

also no touch touch credits
without premission but if
you want you can modify code
itself so yes
*/

#pragma once
#include "stdint.h"
#include "objects.hpp"
#include <functional>

namespace llcd{
    namespace input{
        extern std::function<void(uint32_t,uint32_t)> mouseDown;
        extern std::function<void(uint32_t,uint32_t)> mouseMove;
        extern std::function<void(uint32_t,uint32_t)> mouseUp;
        /// @brief input works on every platform all pico buttons
        enum legacyInput : uint8_t{
            lUp,lDown,lLeft,lRight,lA,lB
        };
        /// @brief keboard input
        enum KeyboardInput : uint8_t{
            kA,kB,kC//to-do
        };
        /// @brief psp input
        enum PspInput : uint8_t{
            pCircle,pSquare,pTriangle,pCross,pL1,pP1,pUp,pDown,pLeft,pRight,pStart,pSelect
        };
    }
}