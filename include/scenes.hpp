#pragma once
#include <functional>
#include <vector>
#include "ctx.hpp"
#include "exception.hpp"

namespace llcd{
    namespace scenes{
        class scene{
            public:
                std::function<void(ctx&)> start;
                std::function<void(ctx&)> frame;
                scene(std::function<void(ctx&)> frame);
                scene(std::function<void(ctx&)> start,std::function<void(ctx&)> frame);
        };
        class sceneManager{
            public:
                std::vector<scene> scenes;
                sceneManager();
                sceneManager(std::vector<scene> scenes);
                void addScene(scene scene);
                void start(uint32_t s,ctx& context);
                void frame(uint32_t s,ctx& context);
        };
    }
}