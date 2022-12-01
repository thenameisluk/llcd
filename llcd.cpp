//made by luktvpl on github
//no touchy touchy my credits
//licens mit

#include "include/DEV_Config.hpp"
#include "include/LCD_1in14.hpp"
#include "include/Infrared.hpp"
#include "llcd.hpp"
#include "hardware/clocks.h"
#include "hardware/pwm.h"


//notes list
uint32_t note_list[12][9] = {
    {16 ,	33 ,	65 ,	131 ,	262 ,	523 ,	1047 ,	2093 ,	4186},//c
    {17 ,	35 ,	69 ,	139 ,	277 ,	554 ,	1109 ,	2217 ,	4435},//c#
    {18 ,	37 ,	73 ,	147 ,	294 ,	587 ,	1175 ,	2349 ,	4699},//d
    {19 ,	39 ,	78 ,	156 ,	311 ,	622 ,	1245 ,	2489 ,	4978},//d#
    {21 ,	41 ,	82 ,	165 ,	330 ,	659 ,	1319 ,	2637 ,	5274},//e
    {22 ,	44 ,	87 ,	175 ,	349 ,	698 ,	1397 ,	2794 ,	5588},//f
    {23 ,	46 ,	93 ,	185 ,	370 ,	740 ,	1480 ,	2960 ,	5920},//f#
    {25 ,	49 ,	98 ,	196 ,	392 ,	784 ,	1568 ,	3136 ,	6272},//g
    {26 ,	52 ,	104 ,	208 ,	415 ,	831 ,	1661 ,	3322 ,	6645},//g#
    {28 ,	55 ,	110 ,	220 ,	440 ,	880 ,	1760 ,	3520 ,	7040},//a
    {29 ,	58 ,	117 ,	233 ,	466 ,	932 ,	1865 ,	3729 ,	7459},//a#
    {31 ,	62 ,	123 ,	247 ,	494 ,	988 ,	1976 ,	3951 ,	7902}//b
};

//note
llcd::note::note(uint8_t note,uint8_t scale){
    n=note;
    s=scale;
};
llcd::note::note(char n[2]){
    
};
uint32_t llcd::note::getFreqency(){
    return note_list[n][s];
};
//audio
llcd::audio::audio():audio_pin(27){

};
void llcd::audio::set(std::vector<note> nodes,uint16_t tempo,uint8_t scaleT,uint8_t ScaleB){
    this->notes=nodes;
    this->tempo=tempo;
    scaleTop = scaleT;
    ScaleBottom = ScaleB;
    setn = true;
    resume();
};

void llcd::audio::tick(){
    if(!setn)return;
    if(playing){
        if(ont==0){
            
            
            if(on+1>=notes.size()){
                on = 0;
            }else{
                on++;
            }
        }
        ont++;
        if(ont>=tempo){
            ont=0;
            stop();
        };
        if(ont>=(tempo/scaleTop)*ScaleBottom){
            stop();
        }else{
            play(notes[on]); 
        }
    }
};
void llcd::audio::play(note n){
    audio_pin.setFrequency(n.getFreqency());
    audio_pin.setDuty(1000);
};
void llcd::audio::resume(){
    if(setn)playing=true;
};
void llcd::audio::stop(){
    audio_pin.setDuty(0);
};
void llcd::audio::stopPlaying(){
    stop();
    playing=false;
};

//buttons
llcd::buttons::buttons(){
    //makes buttons clickable or something
    SET_Infrared_PIN(b_A);    
    SET_Infrared_PIN(b_B);
	SET_Infrared_PIN(b_up);
    SET_Infrared_PIN(b_dowm);
    SET_Infrared_PIN(b_left);
    SET_Infrared_PIN(b_right);
    SET_Infrared_PIN(b_ctrl);
};
bool llcd::buttons::isAPressed(){
    return DEV_Digital_Read(b_A)==0;
};
bool llcd::buttons::isBPressed(){
    return DEV_Digital_Read(b_B)==0;
};
bool llcd::buttons::isDownPressed(){
    return DEV_Digital_Read(b_dowm)==0;
};
bool llcd::buttons::isUpPressed(){
    return DEV_Digital_Read(b_up)==0;
};
bool llcd::buttons::isRightPressed(){
    return DEV_Digital_Read(b_right)==0;
};
bool llcd::buttons::isLeftPressed(){
    return DEV_Digital_Read(b_left)==0;
};
bool llcd::buttons::isCtrlPressed(){
    return DEV_Digital_Read(b_ctrl)==0;
};
//llcd
llcd::llcd::llcd(std::function<void(ctx&,buttons&,audio&)> f){
    if(DEV_Module_Init()!=0){
        printf("nonono");
    }
    LCD_1IN14_Init();
    //buttoms
    
    //runs as fast as it can
    while(1){
        f(c,b,a);
        LCD_1IN14_Display(c.img);
        a.tick();
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
void llcd::ctx::drawLine(point2d p1,point2d p2,color c){
    drawLine(p1.nX(),p1.nY(),p2.nX(),p2.nY(),c);
};
void llcd::ctx::drawLine(int16_t x1,int16_t y1,int16_t x2,int16_t y2,color c){
    int16_t dx = x2-x1;
    int16_t dy = y2-y1;
    if(abs(dx)<abs(dy)){
        if(x1>x2){
            swap(x1,x2);
            swap(y1,y2);
        }
        dx = x2-x1;
        dy = y2-y1;
        if(dy>0){
            for(int16_t i = 0;i<dy;i++){
                float  p = ((float)i/(float)dy)*(float)dx;
                drawPoint(x1+p,y1+i,c);
            }
        }else{
            dy = abs(dy);
            for(int16_t i = 0;i<dy;i++){
                float  p = ((float)i/(float)dy)*(float)dx;
                drawPoint(x1+p,y1-i,c);
            }
        }
        
    }else{
        if(y1>y2){
            swap(x1,x2);
            swap(y1,y2);
        }
        dx = x2-x1;
        dy = y2-y1;
        if(dx>0){
            for(int16_t i = 0;i<dx;i++){
                float p = ((float)i/(float)dx)*(float)dy;
                drawPoint(x1+i,y1+p,c);
            }
        }else{
            dx = abs(dx);
            for(int16_t i = 0;i<dx;i++){
                float p = ((float)i/(float)dx)*(float)dy;
                drawPoint(x1-i,y1+p,c);
            }
        }
        
    }
    
};
void llcd::ctx::drawTriangle(int16_t x1,int16_t y1,int16_t x2,int16_t y2,int16_t x3,int16_t y3,color c){
    drawLine(x1,y1,x2,y2,c);
    drawLine(x2,y2,x3,y3,c);
    drawLine(x3,y3,x1,y1,c);
};
void llcd::ctx::fillTriangle(int16_t x1,int16_t y1,int16_t x2,int16_t y2,int16_t x3,int16_t y3,color c){
    //to-do
};