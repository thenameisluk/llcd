//made by luktvpl on github
//no touchy touchy my credits
//licens mit
#ifdef foo
//pico
#include "../include/picopwm.hpp"
#include "hardware/clocks.h"
#include "hardware/pwm.h"
#include "../../include/pico/DEV_Config.hpp"
#include "../../include/pico/LCD_1in14.hpp"
#include "../../include/pico/Infrared.hpp"
#else
//other
#include "SFML/Graphics.hpp"
#endif
#include "llcd.hpp"

#ifdef foo
#else
#endif
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
    #ifdef foo
    //makes buttons clickable or something
    SET_Infrared_PIN(b_A);    
    SET_Infrared_PIN(b_B);
	SET_Infrared_PIN(b_up);
    SET_Infrared_PIN(b_dowm);
    SET_Infrared_PIN(b_left);
    SET_Infrared_PIN(b_right);
    SET_Infrared_PIN(b_ctrl);
    #else
    #endif
};
bool llcd::buttons::isAPressed(){
    #ifdef foo
    return DEV_Digital_Read(b_A)==0;
    #else
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Z));
    #endif
    
};
bool llcd::buttons::isBPressed(){
    #ifdef foo
    return DEV_Digital_Read(b_B)==0;
    #else
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::X));
    #endif
};
bool llcd::buttons::isDownPressed(){
    #ifdef foo
    return DEV_Digital_Read(b_dowm)==0;
    #else
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Down));
    #endif
};
bool llcd::buttons::isUpPressed(){
    #ifdef foo
    return DEV_Digital_Read(b_up)==0;
    #else
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Up));
    #endif
};
bool llcd::buttons::isRightPressed(){
    #ifdef foo
    return DEV_Digital_Read(b_right)==0;
    #else
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Right));
    #endif
};
bool llcd::buttons::isLeftPressed(){
    #ifdef foo
    return DEV_Digital_Read(b_left)==0;
    #else
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Left));
    #endif
};
bool llcd::buttons::isCtrlPressed(){
    #ifdef foo
    return DEV_Digital_Read(b_ctrl)==0;
    #else
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl));
    #endif
};
//llcd
llcd::llcd::llcd(std::function<void(ctx&,buttons&,audio&)> f){
    #ifdef foo
    if(DEV_Module_Init()!=0){
        printf("nonono");
    }
    LCD_1IN14_Init();
    #else
    sf::RenderWindow window(sf::VideoMode(lcd_w, lcd_h), "Pico");
    window.setFramerateLimit(24);
    sf::Texture texture;
    uint8_t* pixels = new uint8_t[lcd_w*lcd_h*4];
    uint32_t im[lcd_h*lcd_w];
    texture.create(lcd_w, lcd_h);
    #endif
    //buttoms
    
    //runs as fast as it can
    while(1){
        f(c,b,a);
        #ifdef foo
        LCD_1IN14_Display(c.img);
        #else
        sf::Event event;
        while (window.pollEvent(event)) {
            //exit
            if (event.type == sf::Event::Closed)
                return;
            
        }
        //converting colors
        for(int i = 0;i<lcd_w*lcd_h;i++){
            ((uint32_t*)pixels)[i] = llcd::RGB888(c.img[i]);
        }
        texture.update(pixels);
        sf::Sprite sprite(texture);
        window.clear();
        window.draw(sprite);
        window.display();
        #endif
        a.tick();
    };
}

