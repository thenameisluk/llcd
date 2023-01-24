#pragma once
#include <vector>
#include <cmath>
#include "stdio.h"

#ifdef foo
#else
typedef u_int8_t uint8_t;
typedef u_int16_t uint16_t;
typedef u_int32_t uint32_t;
#endif

#define lcd_h 135
#define lcd_w 240



namespace llcd{
    
    class point3d{
        public:
            float x=0;
            float y=0;
            float z=0;
            point3d(){

            };
            point3d(float x,float y,float z):x(x),y(y),z(z){

            };//:x(x),y(y),z(z);
            int16_t nX(){
                return round(((x*0.5f)+0.5)*(float)lcd_w);
            };
            int16_t nY(){
                return round(((y*0.5f)+0.5)*(float)lcd_h);
            };

    };
    class point2d{
        public:
            float x=0;
            float y=0;
            point2d(){

            };
            point2d(float x,float y):x(x),y(y){

            };
            point2d(point3d p):x(p.x),y(p.y){

            };
            int16_t nX(){
                return round(((x*0.5f)+0.5)*(float)lcd_w);
            };
            int16_t nY(){
                return round(((y*0.5f)+0.5)*(float)lcd_h);
            };
    };
    
    class m4x4{
        public:
            /// @brief [wysokość][boki]
            float m[4][4];
            m4x4(){
                for(int i = 0;i<4;i++){
                    for(int i2 = 0;i2<4;i2++){
                        m[i][i2]=0;
                    }
                }
            }
            m4x4& multiply(m4x4 matrix2){
                m[0][0] = m[0][0]*matrix2.m[0][0]+m[1][0]*matrix2.m[0][1]+m[2][0]*matrix2.m[0][2]+m[3][0]*matrix2.m[0][3];
                m[0][1] = m[0][1]*matrix2.m[0][0]+m[1][1]*matrix2.m[0][1]+m[2][1]*matrix2.m[0][2]+m[3][1]*matrix2.m[0][3];
                m[0][2] = m[0][2]*matrix2.m[0][0]+m[1][2]*matrix2.m[0][1]+m[2][2]*matrix2.m[0][2]+m[3][2]*matrix2.m[0][3];
                m[0][3] = m[0][3]*matrix2.m[0][0]+m[1][3]*matrix2.m[0][1]+m[2][3]*matrix2.m[0][2]+m[3][3]*matrix2.m[0][3];

                m[1][0] = m[0][0]*matrix2.m[1][0]+m[1][0]*matrix2.m[1][1]+m[2][0]*matrix2.m[1][2]+m[3][0]*matrix2.m[1][3];
                m[1][1] = m[0][1]*matrix2.m[1][0]+m[1][1]*matrix2.m[1][1]+m[2][1]*matrix2.m[1][2]+m[3][1]*matrix2.m[1][3];
                m[1][2] = m[0][2]*matrix2.m[1][0]+m[1][2]*matrix2.m[1][1]+m[2][2]*matrix2.m[1][2]+m[3][2]*matrix2.m[1][3];
                m[1][3] = m[0][3]*matrix2.m[1][0]+m[1][3]*matrix2.m[1][1]+m[2][3]*matrix2.m[1][2]+m[3][3]*matrix2.m[1][3];

                m[2][0] = m[0][0]*matrix2.m[2][0]+m[1][0]*matrix2.m[2][1]+m[2][0]*matrix2.m[2][2]+m[3][0]*matrix2.m[2][3];
                m[2][1] = m[0][1]*matrix2.m[2][0]+m[1][1]*matrix2.m[2][1]+m[2][1]*matrix2.m[2][2]+m[3][1]*matrix2.m[2][3];
                m[2][2] = m[0][2]*matrix2.m[2][0]+m[1][2]*matrix2.m[2][1]+m[2][2]*matrix2.m[2][2]+m[3][2]*matrix2.m[2][3];
                m[2][3] = m[0][3]*matrix2.m[2][0]+m[1][3]*matrix2.m[2][1]+m[2][3]*matrix2.m[2][2]+m[3][3]*matrix2.m[2][3];

                m[3][0] = m[0][0]*matrix2.m[3][0]+m[1][0]*matrix2.m[3][1]+m[2][0]*matrix2.m[3][2]+m[3][0]*matrix2.m[3][3];
                m[3][1] = m[0][1]*matrix2.m[3][0]+m[1][1]*matrix2.m[3][1]+m[2][1]*matrix2.m[3][2]+m[3][1]*matrix2.m[3][3];
                m[3][2] = m[0][2]*matrix2.m[3][0]+m[1][2]*matrix2.m[3][1]+m[2][2]*matrix2.m[3][2]+m[3][2]*matrix2.m[3][3];
                m[3][3] = m[0][3]*matrix2.m[3][0]+m[1][3]*matrix2.m[3][1]+m[2][3]*matrix2.m[3][2]+m[3][3]*matrix2.m[3][3];
                return  *this;
            };
            point3d project(point3d p){
                point3d o;
                o.x = p.x * m[0][0] + p.y * m[1][0] + p.z * m[2][0] + m[3][0];
		        o.y = p.x * m[0][1] + p.y * m[1][1] + p.z * m[2][1] + m[3][1];
		        o.z = p.x * m[0][2] + p.y * m[1][2] + p.z * m[2][2] + m[3][2];
		        float deph = p.x * m[0][3] + p.y * m[1][3] + p.z * m[2][3] + m[3][3];
                if(deph!=0){
                    o.x /= deph; o.y /= deph; o.z /= deph;
                }
                return o;
            };
            point3d multiplyP(point3d p){
                point3d o;
                o.x = p.x * m[0][0] + p.y * m[1][0] + p.z * m[2][0] + m[3][0];
		        o.y = p.x * m[0][1] + p.y * m[1][1] + p.z * m[2][1] + m[3][1];
		        o.z = p.x * m[0][2] + p.y * m[1][2] + p.z * m[2][2] + m[3][2];
                return o;
            };
    };
    m4x4 Projection_Matrix(float zC=0.1,float zF=100,float fov=90);
    m4x4 move_Matrix(float x,float y,float z);
    m4x4 scale_Matrix(float sX,float sY,float sZ);
    m4x4 rotateX_Matrix(float degre);
    m4x4 rotateY_Matrix(float degre);
    m4x4 rotateZ_Matrix(float degre);
    class object3D{
        
    };
    class sceen3D{
        public:
            std::vector<object3D> objects;
            point3d light;
            sceen3D();
    };
}