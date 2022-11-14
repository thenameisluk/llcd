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
    /// @brief check if 2d boxes are coliding
    /// @param sx1 <\ x
    /// @param sy1 <\ y
    /// @param ex1 \> x
    /// @param ey1 \> y
    /// @param sx2 <\ x
    /// @param sy2 <\ y
    /// @param ex2 \> x
    /// @param ey2 \> y
    /// @return if colide
    bool boxColide(int16_t sx1,int16_t sy1,int16_t ex1,int16_t ey1,int16_t sx2,int16_t sy2,int16_t ex2,int16_t ey2);
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
            /// @brief draws retangle with insides
            /// @param x x position
            /// @param y x position
            /// @param w width
            /// @param h heigth
            /// @param c color
            void fillRect(int16_t x,int16_t y,uint8_t w,uint8_t h,color c);
            /// @brief draws redtangle without insides
            /// @param x x position
            /// @param y y position
            /// @param w width
            /// @param h heigth
            /// @param c color
            void drawRect(int16_t x,int16_t y,uint8_t w,uint8_t h,color c);
            /// @brief draws image
            /// @param img image pointer
            /// @param x x position
            /// @param y y position
            /// @param w width
            /// @param h heigth
            /// @param scale how big it will be
            void drawImage(color* img,int16_t x,int16_t y,uint8_t w,uint8_t h,uint8_t scale = 1);
            /// @brief fills frame with color
            /// @param c color
            void fill(color c);
            /// @brief draws point on frame
            /// @param x x position
            /// @param y y position
            /// @param c color
            void drawPoint(int16_t x,int16_t y,color c);
            /// @brief draws line from point to point
            /// @param x start x position
            /// @param y start y position
            /// @param dx end x position
            /// @param dy end y position
            /// @param c color
            void drawLine(int16_t x,int16_t y,int16_t dx,int16_t dy,color c);
            /// @brief draw triangle
            /// @param x1 position
            /// @param y1 position
            /// @param x2 position
            /// @param y2 position
            /// @param x3 position
            /// @param y3 position
            /// @param c color
            void drawTriangle(int16_t x1,int16_t y1,int16_t x2,int16_t y2,int16_t x3,int16_t y3,color c);
    };
    class  llcd{
        public:
            buttons b;
            ctx c;
            llcd(std::function<void(ctx&,buttons&)> f);
    };
}