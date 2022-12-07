#include "llcd3D.hpp"
llcd::m4x4 llcd::Projection_Matrix(float zC,float zF,float fov){
    m4x4 out;
    float aspectRatio = (float)lcd_h/(float)lcd_w;
    float radFov = (float)1/tanf(fov*0.5f/(float)180*3.14159f);
    out.m[0][0] = aspectRatio * radFov;
    out.m[1][1] = radFov;
    out.m[2][2] = zF / (zF - zF);
    out.m[3][2] = (-zF * zC) / (zF - zC);
    out.m[2][3] = 1.0f;
    out.m[3][3] = 0.0f;
    return out;
}
llcd::m4x4 llcd::move_Matrix(float x,float y,float z){
    m4x4 out;
    out.m[0][0]=1.0f;
    out.m[1][1]=1.0f;
    out.m[2][2]=1.0f;
    out.m[3][3]=1.0f;
    out.m[3][0]=x;
    out.m[3][1]=y;
    out.m[3][2]=z;
    return out;
};
llcd::m4x4 llcd::scale_Matrix(float sX,float sY,float sZ){
    m4x4 out;
    out.m[0][0]=sX;
    out.m[1][1]=sY;
    out.m[2][2]=sZ;
    out.m[3][3]=1;
    return out;
};
llcd::m4x4 llcd::rotateX_Matrix(float degre){
    m4x4 out;
    out.m[0][0] = 1;
    out.m[1][1] = cosf(degre * 0.5f);
    out.m[1][2] = sinf(degre * 0.5f);
    out.m[2][1] = -sinf(degre * 0.5f);
    out.m[2][2] = cosf(degre * 0.5f);
    out.m[3][3] = 1;
    return out;
};
llcd::m4x4 llcd::rotateY_Matrix(float degre){
    //to-do
    return m4x4();
};
llcd::m4x4 llcd::rotateZ_Matrix(float degre){
    m4x4 out;
    out.m[0][0] = cosf(degre);
    out.m[0][1] = sinf(degre);
    out.m[1][0] = -sinf(degre);
    out.m[1][1] = cosf(degre);
    out.m[2][2] = 1;
    out.m[3][3] = 1;
    return out;
};