#include "objects.hpp"

llcd::fvector2D::fvector2D():x(0),y(0){};
llcd::fvector2D::fvector2D(float x,float y):x(x),y(y){};
bool llcd::fvector2D::operator==(fvector2D& v){
    return x==v.x && y==v.y;
};
bool llcd::fvector2D::operator!=(fvector2D& v){
    return x!=v.x || y!=v.y;
};
llcd::fvector2D llcd::fvector2D::operator-(fvector2D& v){
    return fvector2D(x-v.x,y-v.y);
};
llcd::fvector2D llcd::fvector2D::operator+(fvector2D& v){
    return fvector2D(x+v.x,y+v.y);
};

llcd::vector2D::vector2D():x(0),y(0){};
llcd::vector2D::vector2D(uint32_t x,uint32_t y):x(x),y(y){};
llcd::vector2D::vector2D(fvector2D& v){
    x=v.x;
    y=v.y;
};
bool llcd::vector2D::operator==(vector2D& v){
    return x==v.x && y==v.y;
};
bool llcd::vector2D::operator!=(vector2D& v){
    return x!=v.x || y!=v.y;
};
llcd::vector2D llcd::vector2D::operator-(vector2D& v){
    return vector2D(x-v.x,y-v.y);
};
llcd::vector2D llcd::vector2D::operator+(vector2D& v){
    return vector2D(x+v.x,y+v.y);
};
//aabb

//to-do

//sat

//to-do