#include "include/DEV_Config.hpp"
#include "include/LCD_1in14.hpp"
#include "llcd.hpp"
/*


DEV_Digital_Read(ctrl ) == 0;
LCD_1IN14_Display();//240,135


return 0;
*/

llcd::llcd::llcd(std::function<void(ctx&)> f){
    if(DEV_Module_Init()!=0){
        printf("nonono");
    }
    LCD_1IN14_Init();
    uint16_t cl = 0;
    while(1){
        f(c);
        LCD_1IN14_Display(c.img);
        
    };
    DEV_Module_Exit();
}

void llcd::ctx::fillRect(uint16_t x,uint16_t y,uint16_t w,uint16_t h,color c){
    for(uint16_t xm =  0;xm<w;xm++){
        for(uint16_t ym =  0;ym<h;ym++){
            drawPoint(x+xm,y+ym,c);
        }
    }
}
void llcd::ctx::drawRect(uint16_t x,uint16_t y,uint16_t w,uint16_t h,color c){
    for(uint16_t xm =  0;xm<w;xm++){
        for(uint16_t ym =  0;ym<h;ym++){
            drawPoint(x+xm,y+ym,c);
        }
    }
}
void llcd::ctx::drawPoint(uint16_t x,uint16_t y,color c){
    if(x<0||x>240||y<0||y>135)return;
    img[x+(y*240)] = c;
}
void llcd::ctx::fill(color c){
    for(uint16_t i = 0;i<32400;i++){
        img[i] = c;
    }
}