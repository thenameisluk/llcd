#include "window.hpp"

llcd::windows::button::button(std::function<void()> f,AABB box,char c,color background,color textcolor,uint32_t textscale):function(f),box(box),c(c),background(background),textcolor(textcolor),textscale(textscale){

};

llcd::windows::buttonManager::buttonManager(){

};
void llcd::windows::buttonManager::draw(ctx& context){
    buttons.forEach([&](button& b){
        context.fillRect(b.box.position.x, b.box.position.y, b.box.size.x, b.box.size.y, b.background);
        context.drawLetter(b.c,b.box.position.x,b.box.position.y,b.textcolor,b.textscale);
    });
};
void llcd::windows::buttonManager::handleEvent(events::event e){
    buttons.forEach([&](button& b){
        if(e.type==events::eventType::mouseDown){
            if(b.box.isInside(vector2D(e.data.mouseDown.x,e.data.mouseDown.y))){
                b.function();
            }
        }
    });
};


//window
llcd::windows::window::window():box(vector2D(0,0),vector2D(0,0)),context(0,0){
    this->toClose = true;
    this->type = window::window_type::wNULL;
    this->eventHandler = events::event_handler();
    this->frame = [](window& w,ctx& context){};
    this->name = "broken";
}
llcd::windows::window::window(int32_t x,int32_t y,uint32_t w,uint32_t h,std::function<void(window&,ctx&)> frame,window_type type):type(type),box(vector2D(x,y),vector2D(w,h)),context(w,h){
    this->frame = frame;
    name = "nothing here";
    this->toClose = false;
};
void llcd::windows::window::close(){
    this->toClose = true;
};
void llcd::windows::window::tick(){
    this->frame(*this,context);
    this->buttons.draw(this->context);
}
//windowMenager
llcd::windows::windowMenager::windowMenager(color backgroundColor){
    this->backgroundColor = backgroundColor;
};
llcd::windows::windowMenager& llcd::windows::windowMenager::addWindow(window w){
    windows.push(w);
    return *this;
};
llcd::scenes::scene llcd::windows::windowMenager::getScene(){
    scenes::scene out([&](llcd::ctx& context){
        context.fill(this->backgroundColor);
        this->tick(context);
    });
    out.eventHandler.addAnyListener([&](events::event& event,llcd::ctx& context){
        this->handleEvent(event,context);
    });
    return out;
};
void llcd::windows::windowMenager::tick(ctx& context){
    context.fill(this->backgroundColor);
    windows.forEachDel([&context](window& w){
        w.tick();
        context.drawCtx(w.box.position.x,w.box.position.y,w.context);
        return (w.toClose||w.type==llcd::windows::window::window_type::wNULL);
    });
};
void llcd::windows::windowMenager::handleEvent(events::event event,ctx& context){
    if(windows.Size()==0)return;
    //first handling unsatiable windows
    while (windows[windows.Size()-1].type==llcd::windows::window::window_type::wUnstable){
        if(event.type == events::eventType::mouseDown){
            if(windows[windows.Size()-1].box.isInside(vector2D(event.data.mouseDown.x,event.data.mouseDown.y))){
                break;
            }else{
                windows[windows.Size()-1].toClose = true;
                windows.forEachDel([](window& w){
                    return (w.toClose||w.type==llcd::windows::window::window_type::wNULL);
                });
            }
        }else break;
    }
    //now handling mouse events
    if(event.type == events::eventType::mouseMove){
        for(uint32_t i = 0;i<windows.Size();i++){
            if(windows[i].box.isInside(vector2D(event.data.mouseMove.x,event.data.mouseMove.y))){
                event.data.mouseMove.x -=windows[i].box.position.x;
                event.data.mouseMove.y -=windows[i].box.position.y;
                windows[i].eventHandler.handleEvent(event,windows[i].context);
                break;
            }
        }
    }else if(event.type == events::eventType::mouseDown||event.type == events::eventType::mouseUp){
        int32_t toTop = -1;
        windows.forEach([&toTop,&event](window& w,uint32_t index){
            if(toTop!=-1)return;
            if(w.box.isInside(vector2D(event.data.mouseDown.x,event.data.mouseDown.y))){
                toTop = index;
            }
        });
        if(toTop!=-1){
            windows.putOnBottom(toTop);
            if(event.type == events::eventType::mouseDown){
                event.data.mouseDown.x -=windows[windows.Size()-1].box.position.x;
                event.data.mouseDown.y -=windows[windows.Size()-1].box.position.y;
            }else{
                event.data.mouseUp.x -=windows[windows.Size()-1].box.position.x;
                event.data.mouseUp.y -=windows[windows.Size()-1].box.position.y;
            }
            windows[windows.Size()-1].eventHandler.handleEvent(event,windows[windows.Size()-1].context);
            
        }
    }else{//handling other events
        windows[windows.Size()-1].eventHandler.handleEvent(event,windows[windows.Size()-1].context);
    }
    windows[windows.Size()-1].buttons.handleEvent(event);
};

llcd::windows::window llcd::getSimpleWindow(int32_t x,int32_t y,uint32_t w,uint32_t h,std::function<void(llcd::windows::window&,llcd::ctx&)> frame){
    return llcd::windows::window(x,y,w,h,frame,llcd::windows::window::window_type::wStatic);
};