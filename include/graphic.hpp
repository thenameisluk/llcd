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
#include "ctx.hpp"

namespace llcd{
    namespace video{
        void initVideo(int width, int height,const char* name);
        void emitVideo(ctx& pixels);
        void deinitVideo();
    }
}

