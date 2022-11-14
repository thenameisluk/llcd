#include "include/DEV_Config.hpp"
#include "include/LCD_1in14.hpp"
#include "include/Infrared.hpp"
#include "llcd.hpp"

//other functions
bool llcd::boxColide(int16_t sx1,int16_t sy1,int16_t ex1,int16_t ey1,int16_t sx2,int16_t sy2,int16_t ex2,int16_t ey2){
    //to-do
    return false;
};
//buttons
llcd::buttons::buttons(){
    //makes buttons clickable or something
    SET_Infrared_PIN(keyA);    
    SET_Infrared_PIN(keyB);
	SET_Infrared_PIN(up);
    SET_Infrared_PIN(dowm);
    SET_Infrared_PIN(left);
    SET_Infrared_PIN(right);
    SET_Infrared_PIN(ctrl);
};
bool llcd::buttons::isAPressed(){
    return DEV_Digital_Read(keyA)==0;
};
bool llcd::buttons::isBPressed(){
    return DEV_Digital_Read(keyB)==0;
};
bool llcd::buttons::isDownPressed(){
    return DEV_Digital_Read(dowm)==0;
};
bool llcd::buttons::isUpPressed(){
    return DEV_Digital_Read(up)==0;
};
bool llcd::buttons::isRightPressed(){
    return DEV_Digital_Read(right)==0;
};
bool llcd::buttons::isLeftPressed(){
    return DEV_Digital_Read(left)==0;
};
bool llcd::buttons::isCtrlPressed(){
    return DEV_Digital_Read(ctrl)==0;
};
//llcd
llcd::llcd::llcd(std::function<void(ctx&,buttons&)> f){
    if(DEV_Module_Init()!=0){
        printf("nonono");
    }
    LCD_1IN14_Init();
    //buttoms
    
    //runs as fast as it can
    while(1){
        f(c,b);
        LCD_1IN14_Display(c.img);
    };
    DEV_Module_Exit();
}
//ctx
void llcd::ctx::fillRect(int16_t x,int16_t y,uint8_t w,uint8_t h,color c){
    for(int16_t ix = 0;ix<w;ix++){
        for(int16_t iy = 0;iy<h;iy++){
            drawPoint(x+ix,y+iy,c);//maybe faster
        }
    }
};
void llcd::ctx::drawRect(int16_t x,int16_t y,uint8_t w,uint8_t h,color c){
    for(int16_t i = 0;i<w;i++){
        drawPoint(x+i,y,c);
        drawPoint(x+i,y+h-1,c);
    }
    for(int16_t i = 0;i<h;i++){
        drawPoint(x,y+i,c);
        drawPoint(x+w-1,y+i,c);
    }
};
void llcd::ctx::drawImage(color* img,int16_t x,int16_t y,uint8_t w,uint8_t h,uint8_t scale){
    //to-do
    //3 variants (color+transparent,color,symbol)
};
void llcd::ctx::fill(color c){
    for(uint16_t i = 0;i<32400;i++){
        img[i] = c;
    }
};
void llcd::ctx::drawPoint(int16_t x,int16_t y,color c){
    if(x>=lcd_w||x<0||y>=lcd_h||y<0)return;
    img[x+lcd_w*y] = c;
};
void llcd::ctx::drawLine(int16_t x,int16_t y,int16_t dx,int16_t dy,color c){
    //to-do
};
void llcd::ctx::drawTriangle(int16_t x1,int16_t y1,int16_t x2,int16_t y2,int16_t x3,int16_t y3,color c){
    //to-do
};