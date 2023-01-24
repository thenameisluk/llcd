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

llcd::llcd& llcd::llcd::addExitListener(std::function<bool()> listener){
    exitListener = listener;
    return *this;
}

llcd::llcd& llcd::llcd::addScene(scenes::scene s){
    s_menager.addScene(s);
    return *this;
};

void llcd::llcd::triggerEvent(events::event event){
    eventHandler.handleEvent(event,context);
}

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