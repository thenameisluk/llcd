#include "llcd.hpp"
#include <iostream>
#define lcd_h 500
#define lcd_w 500

using namespace llcd;

llcd::llcd gra(lcd_h,lcd_w,"ksztalty");

int main(){
    gra.eventHandler.addMouseMoveListener([](vector2D pos,llcd::ctx& context){
            std::cout << pos.x << ", " << pos.y << std::endl;
    });

    gra.addScene(llcd::scenes::scene([](ctx& c){
        c.fill(RGB565(0,0,0));
        c.drawCircle(30,30,20,RGB565(255,255,255));
        c.fillCircle(30,60,20,RGB565(255,255,255));
        c.fillTriangle(20,344,444,400,200,234,RGB565(255,255,255));
        c.drawTriangle(20,344,444,400,200,234,RGB565(255,0,0));
        c.drawLineThick(100,100,150,130,6,RGB565(255,255,255));
    }));
    
    gra.start();
    
}