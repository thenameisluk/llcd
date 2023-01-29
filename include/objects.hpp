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
#include "functional"
#include "exception.hpp"
#include "ctx.hpp"

namespace llcd{
    template<typename T>
    class vector{
            uint32_t size;
            T** data = nullptr;
        public:
            
            vector();
            ~vector();
            vector(vector<T>& v);
            uint32_t Size();
            void push(T t);
            T& operator[](uint32_t i);
            /// @brief loops through the vector
            /// @param f gives element
            void forEach(std::function<void(T&)> f);
            void forEach(std::function<void(T&,uint32_t)> f);
            /// @brief loop throught the vector
            /// @param f gives element return true if element should be removed 
            void forEachDel(std::function<bool(T&)> f);
            void putOnTop(uint32_t i);
            void putOnBottom(uint32_t i);
    };
    #include "objects.tpp"
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
            float distance(vector2D& v);
            vector2D operator-(vector2D& v);
            vector2D operator+(vector2D& v);
    };
    /// @brief AABB colider
    class AABB{
        public:
            AABB(vector2D position,vector2D size);
            AABB(vector2D position,vector2D colisionPoint,vector2D size);
            vector2D position;
            vector2D colisionPoint;
            vector2D size;
            void move(vector2D delta);
            void setPosition(vector2D position);
            void setColisionPoint(vector2D colisionPoint);
            void setSize(vector2D size);
            bool isColiding(AABB& colider);
            bool isInside(vector2D point);
            void draw(ctx& context);
    };
    /// @brief sat colider
    class SAT{//to-do
        public:
            vector2D position;
            vector<vector2D> points;
            vector<uint32_t> triangles;
            SAT(vector2D position,vector<vector2D> points,vector<uint32_t> triangles);
            bool isColiding(SAT& colider);
            bool isColiding(AABB& colider);
            void draw(ctx& context);
        private:
            bool trianglesColision(vector2D p11,vector2D p12,vector2D p13,vector2D point);
            bool trinagleColision(vector2D p11,vector2D p12,vector2D p13,vector2D p21,vector2D p22,vector2D p23);
    };    
}


