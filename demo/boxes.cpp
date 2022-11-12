#include "llcd.hpp"
#define boxn = 100
int32_t Rbase = 234;
uint8_t randon(){
    uint32_t x = Rbase;
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
    Rbase = x;
    return x;
}

uint8_t r(uint8_t v){
    return (randon()%v)+1;
}

class box{
    public:
    uint8_t x,y,w,h;
    int8_t vx,vy;
    color c;
        box(){

        };
        void set(uint8_t dx,uint8_t dy,uint8_t dw,uint8_t dh,int8_t dvx,int8_t dvy,color dc){
            x = dx;
            y = dy;
            w  =dw;
            h =dh;
            vx =dvx;
            vy = dvy;
            c =dc;
        }
        void move(){
            if(x+w+vx>lcd_w||x+vx<0){
                vx = vx*-1;
            }else{
                x+=vx;
            }
            if(y+h+vy>lcd_h||y+vy<0){
                vy = vy*-1;
            }else{
                y+=vy;
            }
        };

};

box boxes[75];

int main(){
    for(uint8_t i = 0;i<75;i++){
        boxes[i].set(r(lcd_w-30),r(lcd_h-30),r(25)+5,r(25)+5,r(3),r(3),llcd::RGB(r(254),r(254),r(254)));
    }
    llcd::llcd([](llcd::ctx& c,llcd::buttons& b){
        c.fill(c_black);
        for(uint8_t i = 0;i<75;i++){
            c.drawRect(boxes[i].x,boxes[i].y,boxes[i].w,boxes[i].h,boxes[i].c);
            if(!b.isBPressed())boxes[i].move();
        }
    });
}
