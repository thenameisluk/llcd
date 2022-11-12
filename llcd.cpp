#include "include/DEV_Config.hpp"
#include "include/LCD_1in14.hpp"
#include "include/Infrared.hpp"
#include "llcd.hpp"
/*


DEV_Digital_Read(ctrl ) == 0;
LCD_1IN14_Display();//240,135


return 0;
*/
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

void llcd::ctx::fillRect(int16_t x,int16_t y,int16_t w,int16_t h,color c){
    for(uint16_t xm =  0;xm<w;xm++){
        for(uint16_t ym =  0;ym<h;ym++){
            drawPoint(x+xm,y+ym,c);
        }
    }
}
void llcd::ctx::drawRect(int16_t x,int16_t y,int16_t w,int16_t h,color c){
    for(uint16_t xm =  0;xm<w;xm++){
        for(uint16_t ym =  0;ym<h;ym++){
            drawPoint(x+xm,y+ym,c);
        }
    }
}
void llcd::ctx::drawPoint(int16_t x,int16_t y,color c){
    if(x<0||x>240||y<0||y>135)return;
    img[x+(y*240)] = c;
}
void llcd::ctx::fill(color c){
    for(uint16_t i = 0;i<32400;i++){
        img[i] = c;
    }
}