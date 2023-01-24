#include "llcd.hpp"
#define lcd_h 500
#define lcd_w 500
#define boxn = 100
int32_t Rbase = 234;
uint32_t randon(){
    uint32_t x = Rbase;
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
    Rbase = x;
    return x;
}

uint32_t r(uint32_t v){
    return (randon()%v);
}

class box{
    public:
    int32_t x,y,w,h;
    int32_t vx,vy;
    color c;
        box(){

        };
        void set(uint32_t dx,uint32_t dy,uint32_t dw,uint32_t dh,int32_t dvx,int32_t dvy,color dc){
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

llcd::llcd gra(lcd_h,lcd_w,"prostokoty");

int main(){
    for(uint8_t i = 0;i<75;i++){
        boxes[i].set(r(lcd_w-70),r(lcd_h-70),r(70)+10,r(70)+10,r(6),r(6),llcd::RGB565(r(254),r(254),r(254)));
    }

    gra.eventHandler.addMouseDownListener([](llcd::vector2D pos,bool left){
        gra.sceneNow = !gra.sceneNow;//make 0->1 or anyother->0
    });

    //adding scenes gives it if from 0 to 2^32-1
    //starting from zero something like push_back in vector 
    gra.addScene(llcd::scenes::scene([](llcd::ctx& c){//adding scene 0
        
        c.fill(llcd::RGB565(0,0,0));//black background
        for(uint8_t i = 0;i<75;i++){
            c.fillRect(boxes[i].x,boxes[i].y,boxes[i].w,boxes[i].h,boxes[i].c);//drawing box
            boxes[i].move();//moving box
        }
    })).addScene(llcd::scenes::scene([](llcd::ctx& c){//adding scene 1
        
        c.fill(llcd::RGB565(255,255,255));//white backgroung

    })).start();
}