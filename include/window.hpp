#pragma once
#include "event.hpp"
#include <vector>
#include "scenes.hpp"
#include "objects.hpp"
#include "event.hpp"

namespace llcd{
    namespace windows{
        class button{
            public:
                std::function<void()> function;
                AABB box;
                char c;
                color background;
                color textcolor;
                uint32_t textscale;
                button(std::function<void()> f,AABB box,char c,color background,color textcolor,uint32_t textscale);
        };
        class buttonManager{
            public:
                vector<button> buttons;
                buttonManager();
                void draw(ctx& context);
                void handleEvent(events::event e);
        };
        class window{
            public:
                events::event_handler eventHandler;
                std::function<void(window&,ctx&)> frame;
                AABB box;
                buttonManager buttons;
                enum window_type{
                    wNULL,wUnstable,wStatic,wDynamic
                }   type;
                window();
                window(int32_t x,int32_t y,uint32_t w,uint32_t h,std::function<void(window&,ctx&)> frame,window_type type = wStatic);
                const char* name;
                ctx context;
                void close();
                void tick();
                
                bool toClose;
        };
        class windowMenager{
            public:
                color backgroundColor;
                vector<window> windows;
                windowMenager(color backgroundColor=0);
                windowMenager& addWindow(window w);
                scenes::scene getScene();
                void tick(ctx& context);
                void handleEvent(events::event event,ctx& context);
        };
    }
    windows::window getSimpleWindow(int32_t x,int32_t y,uint32_t w,uint32_t h,std::function<void(windows::window&,ctx&)> frame);
}