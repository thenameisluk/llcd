#include "llcd.hpp"

color colors[] = {
    c_black,
    llcd::RGB(255,0,0),
    llcd::RGB(0,255,0),
    llcd::RGB(0,0,255),
    c_white
};
uint8_t x = 10;
uint8_t y = 10;
color col = 0;
bool pressed = false;

bool first = true;
int main(){
    lcd_h;
    lcd_w;
    llcd::llcd([](llcd::ctx& c,llcd::buttons& b){
        //clears white board
        if(first){
            first = false;
            c.fill(c_white);
        }
        //movement
        if(b.isLeftPressed()){
                if(x==0)x=lcd_w-1;
                else x-=2;
        }
        if(b.isRightPressed()){
                if(x==lcd_w-1)x=0;
                else x+=2;
        }
        if(b.isUpPressed()){
                if(y==0)x=lcd_h-1;
                else y-=2;
        }
        if(b.isDownPressed()){
                if(y==lcd_h-1)y=0;
                else y+=2;
        }
        //draws at cursors
        c.drawPoint(x,y,colors[col]);
        c.drawPoint(x+1,y,colors[col]);
        c.drawPoint(x,y+1,colors[col]);
        c.drawPoint(x+1,y+1,colors[col]);

        //change color
        if(b.isCtrlPressed()){
            if(!pressed){
                if(col>=5)col=0;
                else col++;
                pressed=true;
            }
        }else pressed=false;
    });
}