#pragma once
#include "event.hpp"
#include <vector>
#include "scenes.hpp"

namespace llcd{
    namespace windows{
        class window{
            public:
                events::event_handler eventHandler;
                window();
                const char* name;
                int32_t x,y;
                uint32_t h,w;
                ctx context;
                enum window_type{
                    wStatic,wDynamic,wDynamicNamed
                }   type;
        };
        class windowMenager{
            public:
                std::vector<window> windows;
                windowMenager();
                void addWindow(window w);
                scenes::scene getScene();
            private:
                void renderWindow(window& w,ctx& context);
        };
    }
}