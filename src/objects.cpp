#include "objects.hpp"
#include "cmath"


//
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
float llcd::vector2D::distance(vector2D& v){
    int32_t ydist;
    int32_t xdist;
    if(y>v.y)ydist=y-v.y;
    else ydist=v.y-y;
    if(x>v.x)xdist=x-v.x;
    else xdist=v.x-x;
    return sqrt(pow(xdist,2)+pow(ydist,2));
}
llcd::vector2D llcd::vector2D::operator-(vector2D& v){
    return vector2D(x-v.x,y-v.y);
};
llcd::vector2D llcd::vector2D::operator+(vector2D& v){
    return vector2D(x+v.x,y+v.y);
};
//aabb
llcd::AABB::AABB(vector2D position,vector2D size){
    this->position = position;
    this->colisionPoint = vector2D(0,0);
    this->size = size;
};
llcd::AABB::AABB(vector2D position,vector2D colisionPoint,vector2D size){
    this->position = position;
    this->colisionPoint = colisionPoint;
    this->size = size;
};
void llcd::AABB::move(vector2D delta){
    position = position+delta;
};
void llcd::AABB::setPosition(vector2D position){
    this->position = position;
};
void llcd::AABB::setColisionPoint(vector2D colisionPoint){
    this->colisionPoint = colisionPoint;
}
void llcd::AABB::setSize(vector2D size){
    this->size = size;
};
bool llcd::AABB::isColiding(AABB& colider){
    vector2D  colistionStart1 = position+colisionPoint;
    vector2D  colistionEnd1 = position+colisionPoint+size;
    vector2D  colistionStart2 = colider.position+colider.colisionPoint;
    vector2D  colistionEnd2 = colider.position+colider.colisionPoint+colider.size;
    return (colistionStart1.x<=colistionEnd2.x && colistionEnd1.x>=colistionStart2.x && colistionStart1.y<=colistionEnd2.y && colistionEnd1.y>=colistionStart2.y);
};
bool llcd::AABB::isInside(vector2D point){
    vector2D  colistionStart1 = position+colisionPoint;
    vector2D  colistionEnd1 = position+colisionPoint+size;
    return (point.x>=colistionStart1.x && point.x<=colistionEnd1.x && point.y>=colistionStart1.y && point.y<=colistionEnd1.y);
};
void llcd::AABB::draw(ctx& context){
    context.drawRect(position.x-colisionPoint.x,position.y-colisionPoint.y,size.x,size.y,llcd::RGB565(255,0,0));
};

//sat