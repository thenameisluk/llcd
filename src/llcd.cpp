#include "llcd.hpp"
#include "exception.hpp"

llcd::llcd::llcd(int height, int width,const char* name):context(height,width){
    //audio::audio audioMenager;
    try{
        video::initVideo(height,width,name);
        
    }catch(exception e){
        if(e.error_code<100){
            e.comunitace();
        }
    }
}

llcd::llcd& llcd::llcd::addMouseDownListener(std::function<void(vector2D,bool)> event){
    MouseDownListener = event;
    return *this;
};
llcd::llcd& llcd::llcd::addMouseUpListener(std::function<void(vector2D,bool)> event){
    MouseUpListener = event;
    return *this;
};
llcd::llcd& llcd::llcd::addMouseMoveListener(std::function<void(vector2D)> event){
    MouseMoveListener = event;
    return *this;
};
llcd::llcd& llcd::llcd::addKeyboardEventListener(std::function<void(input::KeyboardInput)> event){
    KeyboardEventListener = event;
    return *this;
};
llcd::llcd& llcd::llcd::addPicoButtonsListener(std::function<void(input::legacyInput)> event){
    LegacyButtonsListener = event;
    return *this;
};
llcd::llcd& llcd::llcd::addPspInputListener(std::function<void(input::PspInput)> event){
    PspInputListener = event;
    return *this;
};
llcd::llcd& llcd::llcd::addExitListener(std::function<bool()> event){
    exitListener = event;
    return *this;
}

llcd::llcd& llcd::llcd::addScene(scenes::scene s){
    s_menager.addScene(s);
    return *this;
};

void llcd::llcd::start(){
    
    while (true)
    {
        try{
            if(lastscene!=this->sceneNow){
                s_menager.start(this->sceneNow,context);
                lastscene = this->sceneNow;
            }
            s_menager.frame(this->sceneNow,context);
            video::emitVideo(context);
            eventChecker();
            
        }catch(exception e){
            e.comunitace();
            if(e.error_code==e_exit){
                if(exitListener())return;
            }
        }
        
    }
};