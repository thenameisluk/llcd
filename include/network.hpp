/*
a great pice of code

coded and delivered by L team
code by luk the oop programmer
debbugged by zoz the glaceon

it may break everything it touches
or something i dont know why
some people state that but yes

also no touch touch credits
without premission but if
you want you can modify code
itself so yes
*/
#pragma once
#include <stdint.h>
#include <functional>

namespace llcd{
    namespace networks{
        class wssClient{
            private:
                const char* host;
                uint32_t port;
                std::function<void(uint8_t*)> call;
                bool connected;
            public:
                wssClient(const char* ip,uint32_t port,std::function<void(uint8_t*)>){};
                void send(uint8_t* msg);
                void tick();
                bool isConnected(){return false;};
        };
    }
}