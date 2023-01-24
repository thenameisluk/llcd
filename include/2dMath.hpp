#pragma once
#include "objects.hpp"
#include "cmath"

namespace llcd{
    float degreesToRadians(float degrees){
        return degrees * (M_PI / 180.0f);
    };
    fvector2D rotateAround(fvector2D v,fvector2D center,int32_t degrees){
        float angle = degreesToRadians(degrees);
        fvector2D v2(v.x-center.x,v.y-center.y);
        fvector2D v3(v2.x*cos(angle)-v2.y*sin(angle),v2.x*sin(angle)+v2.y*cos(angle));
        return fvector2D(v3.x+center.x,v3.y+center.y);
    };
    fvector2D rotateAround(fvector2D v,fvector2D center,float angle){
        fvector2D v2(v.x-center.x,v.y-center.y);
        fvector2D v3(v2.x*cos(angle)-v2.y*sin(angle),v2.x*sin(angle)+v2.y*cos(angle));
        return fvector2D(v3.x+center.x,v3.y+center.y);
    };
    fvector2D scaleAround(fvector2D v,fvector2D center,float scale){
        fvector2D v2(v.x-center.x,v.y-center.y);
        fvector2D v3(v2.x*scale,v2.y*scale);
        return fvector2D(v3.x+center.x,v3.y+center.y);
    };
}