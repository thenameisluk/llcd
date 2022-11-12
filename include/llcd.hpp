#pragma once
#include <functional>
//buttons (to-do)
#define keyA 15
#define keyB 17
#define up 2
#define dowm 18
#define left 16
#define right 20
#define ctrl 3
//size of screen
#define lcd_h 135
#define lcd_w 240
//colors
#define c_black 0
#define c_white 65535
//help types
typedef uint16_t color;

namespace llcd{
    /// @brief turns rgb to color
    /// @param R from 0 to 255
    /// @param G from 0 to 255
    /// @param B from 0 to 255
    /// @return color
    constexpr color RGB(uint8_t R,uint8_t G,uint8_t B){
        return (((R & 0b11111000)<<8) + ((G & 0b11111100)<<3) + (B>>3));
    };
    class buttons{
        public:
            buttons();
            bool isAPressed();
            bool isBPressed();
            bool isDownPressed();
            bool isUpPressed();
            bool isRightPressed();
            bool isLeftPressed();
            bool isCtrlPressed();
    };
    class ctx{
        public:
            color img[32400] = {c_white};
            ctx(){

            }
            void fillRect(int16_t x,int16_t y,int16_t w,int16_t h,color c);
            void drawRect(int16_t x,int16_t y,int16_t w,int16_t h,color c);
            void fill(color c);
            void drawPoint(int16_t x,int16_t y,color c);
    };
    class  llcd{
        public:
            buttons b;
            ctx c;
            llcd(std::function<void(ctx&,buttons&)> f);
    };
}