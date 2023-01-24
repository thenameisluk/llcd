#include "llcd.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>

sf::RenderWindow* window;

uint8_t* pixele;
uint64_t pcount;

bool initialized_video  = false;
uint32_t h,w;

std::function<void(uint32_t,uint32_t)> llcd::input::mouseDown = [](int32_t x,int32_t y){};
std::function<void(uint32_t,uint32_t)> llcd::input::mouseUp = [](int32_t x,int32_t y){};
std::function<void(uint32_t,uint32_t)> llcd::input::mouseMove = [](int32_t x,int32_t y){};

sf::Texture* texture;
sf::Sprite* sprite;

void llcd::video::initVideo(int height, int width,const char* name){
    h = height;
    w = width;
    pcount = width*height;

    texture  = new sf::Texture();
    texture->create(width,height);
    sprite = new sf::Sprite(*texture);

    pixele = new uint8_t[width*height*4];
    window = new sf::RenderWindow(sf::VideoMode(width, height), name);
    window->setFramerateLimit(24);
    initialized_video = true;
};
uint32_t lastX,lastY;
void llcd::video::emitVideo(ctx& context){
    if(!initialized_video)throw exception(e_video_initialation_error,"not initialized video");
    for(int i = 0;i<pcount;i++){
        ((uint32_t*)(pixele))[i] = RGB888(context.img[i]);
    }
    
    texture->update((sf::Uint8*)(pixele));

    sprite->setTexture(*texture);

    window->draw(*sprite);

    window->display();
    
};

void llcd::llcd::eventChecker(){
    sf::Event event;
    while (window->pollEvent(event)) {
        //exit
        if (event.type == sf::Event::Closed)
            throw exception(e_exit,"someone tried to close the windows");
        if (event.type == sf::Event::MouseButtonPressed) MouseDownListener(vector2D(lastX,lastY),true);
        if (event.type == sf::Event::MouseButtonReleased) MouseUpListener(vector2D(lastX,lastY),true);
        if (event.type == sf::Event::MouseMoved) {
            MouseMoveListener(vector2D(event.mouseMove.x,event.mouseMove.y));
            lastX = event.mouseMove.x;
            lastY = event.mouseMove.y;
        }
    }
}

void llcd::video::deinitVideo(){
    delete window;
    delete [] pixele;
};
