#pragma once
#include "picopwm.hpp"

#include <functional>
#include <vector>
#include <stdio.h>
#include  "llcd3D.hpp"
#include "notes.hpp"
//buttons (to-do)
#define b_A 15
#define b_B 17
#define b_up 2
#define b_dowm 18
#define b_left 16
#define b_right 20
#define b_ctrl 3
//size of screen
#define lcd_h 135
#define lcd_w 240
//colors
#define c_black 0
#define c_white 65535
//help types
#ifdef foo
#else
typedef u_int8_t uint8_t;
typedef u_int16_t uint16_t;
typedef u_int32_t uint32_t;
#endif

typedef u_int16_t* sprite;

typedef uint16_t color;
//swap_int
#define swap_int(a, b) { int16_t t; t = a; a = b; b = t;}
//notes
#define n_C 0
#define n_Ch 1
#define n_D 2
#define n_Dh 3
#define n_E 4
#define n_F 5
#define n_Fh 6
#define n_G 7
#define n_Gh 8
#define n_A 9
#define n_Ah 10
#define n_B 11



extern uint32_t note_list[12][9];

typedef struct { unsigned v1 : 4;unsigned v2 : 4; } uint4;

namespace llcd{
    class symbol{
        public:
            bool *arr;
            int16_t w;
            int16_t h;
            symbol(std::initializer_list<bool> array,int16_t s_w,int16_t s_h);
            symbol(std::initializer_list<std::initializer_list<bool>> array);
            symbol(const symbol& b);
            ~symbol();
            bool operator[](int index);
    };
    class image{
        //to-do 
    };
    //note
    class note{
        public:
            uint8_t n;
            uint8_t s;
            note(char n[2]);
            note(uint8_t note=1,uint8_t scale=3);
            uint32_t getFreqency();
    };
    //audio
    class audio{
        public:
            PicoPwm audio_pin;
            audio();
            void set(std::vector<note> nodes,uint16_t tempo=8,uint8_t scaleT=4,uint8_t ScaleB=3);
            void tick();
            void play(note n);
            void resume();
            void stop();
            void stopPlaying();
            uint16_t t = 0;
            uint8_t on  = 0;
            uint16_t ont = 0;
            uint8_t scaleTop = 0;
            uint8_t ScaleBottom = 0;
            bool setn = false;
            bool playing = false;
            uint8_t tempo = 4;
            std::vector<note> notes;
    };
    /// @brief turns rgb to color
    /// @param R from 0 to 255
    /// @param G from 0 to 255
    /// @param B from 0 to 255
    /// @return color
    constexpr color RGB(uint8_t R,uint8_t G,uint8_t B){
        return (((B & 0b11111000)<<8) + ((R & 0b11111100)<<3) + (G>>3));
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
            void drawLine(point2d p1,point2d p2,color c);
            void drawLine(int16_t x1,int16_t y1,int16_t x2,int16_t d2,color c);
            /// @brief draws straight line
            /// @param x position x
            /// @param y position y
            /// @param l lenght
            void drawLineUpDown(int16_t x,int16_t y,int16_t l);
            /// @brief draws straight line
            /// @param x position x
            /// @param y position y
            /// @param l lenght
            void drawLineLeftRight(int16_t x,int16_t y,int16_t l);
            /// @brief draw triangle
            /// @param x1 position
            /// @param y1 position
            /// @param x2 position
            /// @param y2 position
            /// @param x3 position
            /// @param y3 position
            /// @param c color
            void drawTriangle(int16_t x1,int16_t y1,int16_t x2,int16_t y2,int16_t x3,int16_t y3,color c);
            /// @brief draw triangle with insides
            /// @param x1 position
            /// @param y1 position
            /// @param x2 position
            /// @param y2 position
            /// @param x3 position
            /// @param y3 position
            /// @param c color
            void fillTriangle(int16_t x1,int16_t y1,int16_t x2,int16_t y2,int16_t x3,int16_t y3,color c);
			/**
			 * Draws a letter on the screen.
			 * 
			 * @param ch The character to draw.
			 * @param x The x-coordinate of the top-left corner of the letter.
			 * @param y The y-coordinate of the top-left corner of the letter.
			 * @param c The color of the letter.
			 * @param scale The size of the letter. Defaults to 1.
			 */
			void drawLetter(char ch,int16_t x,int16_t y,color c,int16_t scale=1);
			/**
			 * Draws a letter on the screen with the given parameters
			 * @param id The ID of the letter to be drawn
			 * @param x The x-coordinate of the letter
			 * @param y The y-coordinate of the letter
			 * @param c The color of the letter
			 * @param scale The scale of the letter (default is 1)
			 */
            void drawLetter(uint8_t id,int16_t x,int16_t y,color c,int16_t scale=1);
            /**
             * @brief Draws a sprite at the given coordinates
             * 
             * @param x The x coordinate of the sprite
             * @param y The y coordinate of the sprite
             * @param sprite A pointer to the sprite data
             */
            void drawSprite(int16_t x,int16_t y,void* sprite);
            /**
             * @brief Draws a sprite on the screen
             * 
             * @param x The x coordinate of the sprite
             * @param y The y coordinate of the sprite
             * @param height The height of the sprite
             * @param width The width of the sprite
             * @param pallet The color pallet of the sprite
             * @param pixels The pixel data of the sprite
             */
            void drawSprite(int16_t x,int16_t y,uint16_t height,uint16_t width,uint16_t* pallet,void* pixels);
            /**
             * @brief Draws a sprite at the given coordinates
             * 
             * @param x The x coordinate of the sprite
             * @param y The y coordinate of the sprite
             * @param sprite A pointer to the sprite to be drawn
             * @param scale The scale of the sprite
             */
            void drawSprite(int16_t x,int16_t y,void* sprite,uint8_t scale);
            /**
             * @brief Draws a sprite on the screen
             * 
             * @param x The x coordinate of the sprite
             * @param y The y coordinate of the sprite
             * @param height The height of the sprite
             * @param width The width of the sprite
             * @param pallet The color palette used for the sprite
             * @param pixels The pixel data for the sprite
             * @param scale The scale of the sprite
             */
            void drawSprite(int16_t x,int16_t y,uint16_t height,uint16_t width,uint16_t* pallet,void* pixels,uint8_t scale);




    };
    class  llcd{
        public:
            buttons b;
            ctx c;
            audio a;
            llcd(std::function<void(ctx&,buttons&,audio&)> f);
    };
}