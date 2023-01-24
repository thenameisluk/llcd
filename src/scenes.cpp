#include "scenes.hpp"

llcd::scenes::scene::scene(std::function<void(ctx&)> frame):start([](ctx& n){}),frame(frame){};
llcd::scenes::scene::scene(std::function<void(ctx&)> start,std::function<void(ctx&)> frame):start(start),frame(frame){};

llcd::scenes::sceneManager::sceneManager(){};
llcd::scenes::sceneManager::sceneManager(std::vector<scene> scenes):scenes(scenes){
    
};
void llcd::scenes::sceneManager::addScene(scene scene){
    scenes.push_back(scene);
};
void llcd::scenes::sceneManager::start(uint32_t s,ctx& context){
    if(scenes.size()>s){
        scenes[s].start(context);
    }else{
        throw exception(004,"to hi scene number");
    }
};
void llcd::scenes::sceneManager::frame(uint32_t s,ctx& context){
    if(scenes.size()>s){
        scenes[s].frame(context);
    }else{
        throw exception(004,"to hi scene number");
    }
};

void llcd::scenes::sceneManager::handleEvent(uint32_t s,events::event event,ctx& context){
    if(scenes.size()>s){
        scenes[s].eventHandler.handleEvent(event,context);
    }else{
        throw exception(004,"to hi scene number");
    }
};