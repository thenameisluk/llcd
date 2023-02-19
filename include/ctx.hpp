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
#include <stdint.h>
#include <functional>


typedef uint16_t color;

namespace llcd{
    typedef struct{
        uint8_t r;
        uint8_t g;
        uint8_t b;
    } RGB;
    constexpr color RGB565(uint8_t R,uint8_t G,uint8_t B){
        return (((B & 0b11111000)<<8) + ((R & 0b11111100)<<3) + (G>>3));
    };
    constexpr uint32_t RGB888(color rgb565){
        return ((((uint32_t)(((rgb565&0b1111100000000000)>>11)*8)<<16)+((uint32_t)((rgb565&0b0000000000011111)*8)<<8)+((uint32_t)(((rgb565&0b0000011111100000)>>5)*4))))+(255<<24);
    };
    constexpr uint32_t RGB888(uint8_t R,uint8_t G,uint8_t B){
        return RGB888(RGB565(R,G,B));
    };
    constexpr RGB revert(uint16_t color){
        return RGB{uint8_t(((color & 0b1111100000000000)>>11)*8),uint8_t((color & 0b0000000000011111)*4),uint8_t(((color & 0b0000011111100000)>>5)*8)};
    }
    class ctx{
            int height;
            int width;
        public:
            //if you touch this you die
            color* img;
            ctx(int width, int height);
            ctx(ctx& cp);
            ~ctx();
            //size manipilation
            //entier screen
            void fill(color c);
            //points
            void drawPoint(int32_t x,int32_t y,color c);
            //rectangles
            void fillRect(int32_t x,int32_t y,uint32_t w,uint32_t h,color c);
            void drawRect(int32_t x,int32_t y,uint32_t w,uint32_t h,color c);
            //circle
            void drawCircle(int32_t x,int32_t y,uint32_t radius,color c);
            void fillCircle(int32_t x,int32_t y,uint32_t radius,color c);
            //lines
            void drawLine(int32_t x1,int32_t y1,int32_t x2,int32_t y2,color c);
            void drawLineThick(int32_t x1,int32_t y1,int32_t x2,int32_t y2,uint32_t scale,color c);
            void drawLineUpDown(int32_t x,int32_t y,int32_t l,color c);
            void drawLineLeftRight(int32_t x,int32_t y,int32_t l,color c);
            //other ctx
            void drawCtx(int32_t x,int32_t y,ctx& context);
            //triangle
            void drawTriangle(int32_t x1,int32_t y1,int32_t x2,int32_t y2,int32_t x3,int32_t y3,color c);
            void fillTriangle(int32_t x1,int32_t y1,int32_t x2,int32_t y2,int32_t x3,int32_t y3,color c);
            //symbols
            void drawSymbol(int32_t x,int32_t y,uint8_t*,color c,uint32_t scale);
            //sprites
            void drawSprite(int32_t x,int32_t y,uint8_t* sprite,uint8_t* pallet,uint32_t scale);
            //letters
            void drawLetter(char ch,int32_t x,int32_t y,color c,int32_t scale=1);
            void print(const char* text,int32_t x,int32_t y,color c,uint32_t scale=1);
            void print(int32_t number,int32_t x,int32_t y,color c,uint32_t scale=1);
        private:
            //helpfull
            void drawTwistLine(int32_t x1,int32_t y1,int32_t x2,int32_t y2,std::function<void(ctx&,int32_t,int32_t)> function);
            void mirrorDrawPoint(int32_t x,int32_t y,uint32_t ox,uint32_t oy,color c);
            //it asumes you know what your doing
            //but you don't know
            void NormalDrawSprite(int32_t x,int32_t y,uint32_t height,uint32_t width,uint8_t* pallet,uint8_t* pixels,uint32_t scale);
            void RleDrawSprite(int32_t x,int32_t y,uint32_t height,uint32_t width,uint8_t* pallet,uint8_t* pixels,uint32_t scale);
            void ExtentedRleDrawSprite(int32_t x,int32_t y,uint32_t height,uint32_t width,uint8_t* pallet,uint8_t* pixels,uint32_t scale);
            void ExtentedDrawSprite(int32_t x,int32_t y,uint32_t height,uint32_t width,uint8_t* pallet,uint8_t* pixels,uint32_t scale);
            //don't you even think about touching that
            void AdvancedRleDrawSprite(int32_t x,int32_t y,uint32_t height,uint32_t width,uint8_t* pallet,uint8_t* pixels,uint32_t scale);
    };
}