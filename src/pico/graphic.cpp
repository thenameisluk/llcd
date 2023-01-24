#include "pico/LCD_1in14.hpp"
#include "graphic.hpp"
#include "exception.hpp"

#define lcd_h 135
#define lcd_w 240

void llcd::video::initVideo(int height, int width,const char* name){
    if(height!=lcd_h||width!=lcd_w) throw llcd::exception(e_video_initialation_error,"incorrect screen resolution try 135x240");
    if(DEV_Module_Init()!=0){
        throw llcd::exception(e_video_initialation_error,"cannot initialize lcd screen")
    }
    LCD_1IN14_Init();
}

void llcd::video::emitVideo(ctx& pixels){
    LCD_1IN14_Display(pixels.img);
}

void llcd::video::deinitVideo(){
    DEV_Module_Exit();
}