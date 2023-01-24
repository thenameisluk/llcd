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
#include "stdint.h"
#include <vector>

namespace llcd{
    //float vector 2D
    class fvector2D{
        public:
            float x;
            float y;
            fvector2D();
            fvector2D(float x,float y);
            bool operator==(fvector2D& v);
            bool operator!=(fvector2D& v);
            fvector2D operator-(fvector2D& v);
            fvector2D operator+(fvector2D& v);
    };
    //point in 2d space
    class vector2D{
        public:
            uint32_t x;
            uint32_t y;
            vector2D();
            vector2D(uint32_t x,uint32_t y);
            vector2D(fvector2D& v);
            bool operator==(vector2D& v);
            bool operator!=(vector2D& v);
            vector2D operator-(vector2D& v);
            vector2D operator+(vector2D& v);
    };
    /// @brief AABB colider
    class AABB{
        public:
            AABB(vector2D position,vector2D size);
            vector2D position;
            vector2D size;
            bool isColiding(AABB& colider,vector2D myPositon = vector2D(),vector2D itPosition = vector2D());
    };
    /// @brief sat colider
    class SAT{
        public:
            std::vector<vector2D> points;
            std::vector<uint32_t> triangles;
            SAT(std::vector<vector2D> points,std::vector<uint32_t> triangles);
            bool isColiding(SAT& colider,vector2D myPositon = vector2D(),vector2D itPosition = vector2D());
            bool isColiding(AABB& colider,vector2D myPositon = vector2D(),vector2D itPosition = vector2D());
        private:
            bool trinagleColision(vector2D p1,vector2D p2,vector2D p3);
    };    
}


