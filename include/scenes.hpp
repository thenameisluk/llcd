#pragma once
#include <functional>
#include <vector>
#include "ctx.hpp"
#include "exception.hpp"
#include "event.hpp"

namespace llcd{
    namespace scenes{
        class scene{
            public:
                std::function<void(ctx&)> start;
                std::function<void(ctx&)> frame;
                scene(std::function<void(ctx&)> frame);
                scene(std::function<void(ctx&)> start,std::function<void(ctx&)> frame);
                events::event_handler eventHandler;
        };
        class sceneManager{
            public:
                std::vector<scene> scenes;
                sceneManager();
                sceneManager(std::vector<scene> scenes);
                void addScene(scene scene);
                void handleEvent(uint32_t s,events::event event,ctx& context);
                void start(uint32_t s,ctx& context);
                void frame(uint32_t s,ctx& context);
        };
    }
}