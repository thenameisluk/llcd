#include "ctx.hpp"
#include <cmath>
#include <iostream>
//ctx class

#define swap_int(a, b) { int32_t t; t = a; a = b; b = t;}

llcd::ctx::ctx(int height, int width):height(height),width(width){

    img = new color[height*width];
    for(int32_t i = 0;i<width*height;i++){
        img[i] = 0;
    }
}

llcd::ctx::~ctx(){
    delete [] img;
}

void llcd::ctx::fillRect(int32_t x,int32_t y,uint32_t w,uint32_t h,color c){
    for(int32_t ix = 0;ix<w;ix++){
        for(int32_t iy = 0;iy<h;iy++){
            drawPoint(x+ix,y+iy,c);//maybe faster
        }
    }
};
void llcd::ctx::drawRect(int32_t x,int32_t y,uint32_t w,uint32_t h,color c){
    for(int32_t i = 0;i<w;i++){
        drawPoint(x+i,y,c);
        drawPoint(x+i,y+h-1,c);
    }
    for(int32_t i = 0;i<h;i++){
        drawPoint(x,y+i,c);
        drawPoint(x+w-1,y+i,c);
    }
};
void llcd::ctx::fill(color c){
    for(uint32_t i = 0;i<height*width;i++){
        img[i] = c;
    }
};
void llcd::ctx::drawPoint(int32_t x,int32_t y,color c){
    if(x>=width||x<0||y>=height||y<0)return;
    img[x+width*y] = c;
};
void llcd::ctx::drawLine(int32_t x1,int32_t y1,int32_t x2,int32_t y2,color c){
    int32_t dx = x2-x1;
    int32_t dy = y2-y1;
    if(abs(dx)<abs(dy)){
        if(x1>x2){
            swap_int(x1,x2);
            swap_int(y1,y2);
        }
        dx = x2-x1;
        dy = y2-y1;
        if(dy>0){
            for(int32_t i = 0;i<dy;i++){
                float  p = ((float)i/(float)dy)*(float)dx;
                drawPoint(x1+p,y1+i,c);
            }
        }else{
            dy = abs(dy);
            for(int32_t i = 0;i<dy;i++){
                float  p = ((float)i/(float)dy)*(float)dx;
                drawPoint(x1+p,y1-i,c);
            }
        }
        
    }else{
        if(y1>y2){
            swap_int(x1,x2);
            swap_int(y1,y2);
        }
        dx = x2-x1;
        dy = y2-y1;
        if(dx>0){
            for(int32_t i = 0;i<dx;i++){
                float p = ((float)i/(float)dx)*(float)dy;
                drawPoint(x1+i,y1+p,c);
            }
        }else{
            dx = abs(dx);
            for(int32_t i = 0;i<dx;i++){
                float p = ((float)i/(float)dx)*(float)dy;
                drawPoint(x1-i,y1+p,c);
            }
        }
        
    }
    
};
void llcd::ctx::drawTriangle(int32_t x1,int32_t y1,int32_t x2,int32_t y2,int32_t x3,int32_t y3,color c){
    drawLine(x1,y1,x2,y2,c);
    drawLine(x2,y2,x3,y3,c);
    drawLine(x3,y3,x1,y1,c);
};

void llcd::ctx::drawTwistLine(int32_t x1,int32_t y1,int32_t x2,int32_t y2,std::function<void(ctx&,int32_t,int32_t)> function){
    int32_t dx = x2-x1;
    int32_t dy = y2-y1;
    if(abs(dx)<abs(dy)){
        if(x1>x2){
            swap_int(x1,x2);
            swap_int(y1,y2);
        }
        dx = x2-x1;
        dy = y2-y1;
        if(dy>0){
            for(int32_t i = 0;i<dy;i++){
                float  p = ((float)i/(float)dy)*(float)dx;
                function(*this,x1+p,y1+i);
            }
        }else{
            dy = abs(dy);
            for(int32_t i = 0;i<dy;i++){
                float  p = ((float)i/(float)dy)*(float)dx;
                function(*this,x1+p,y1+i);
            }
        }
        
    }else{
        if(y1>y2){
            swap_int(x1,x2);
            swap_int(y1,y2);
        }
        dx = x2-x1;
        dy = y2-y1;
        if(dx>0){
            for(int32_t i = 0;i<dx;i++){
                float p = ((float)i/(float)dx)*(float)dy;
                function(*this,x1+i,y1+p);
            }
        }else{
            dx = abs(dx);
            for(int32_t i = 0;i<dx;i++){
                float p = ((float)i/(float)dx)*(float)dy;
                function(*this,x1+i,y1+p);
            }
        }
        
    }
};

void llcd::ctx::drawCircle(int32_t x,int32_t y,uint32_t radius,color c){
    float len = 0;
    for(int32_t i = 0;i<radius;i++){
        len = sqrt((float(radius)*float(radius))-(float(i)*float(i)));
        mirrorDrawPoint(x,y,i,len,c);
        mirrorDrawPoint(x,y,len,i,c);
        if(i==len)return;
    }
};

void llcd::ctx::mirrorDrawPoint(int32_t x,int32_t y,uint32_t ox,uint32_t oy,color c){
    drawPoint(x+ox,y+oy,c);
    drawPoint(x+ox,y-oy,c);
    drawPoint(x-ox,y-oy,c);
    drawPoint(x-ox,y+oy,c);
}

void llcd::ctx::fillCircle(int32_t x,int32_t y,uint32_t radius,color c){
    float len = 0;
    for(int32_t i = 0;i<radius;i++){
        len = sqrt((float(radius)*float(radius))-(float(i)*float(i)));
        mirrorDrawPoint(x,y,i,len,c);
        mirrorDrawPoint(x,y,len,i,c);
        for(int32_t j = 0;j<len;j++){
            mirrorDrawPoint(x,y,i,j,c);
            mirrorDrawPoint(x,y,j,i,c);

        }
        if(i==len)return;
    }
};

void llcd::ctx::drawLineThick(int32_t x1,int32_t y1,int32_t x2,int32_t y2,uint32_t scale,color c){
    fillCircle(x1,y1,scale,c);
    fillCircle(x2,y2,scale,c);

    drawTwistLine(x1,y1,x2,y2,[&c,&scale](ctx& ctx,int32_t x,int32_t y){
        ctx.drawLineLeftRight(x-scale,y,(scale<<1)+1,c);
        ctx.drawLineUpDown(x,y-scale,(scale<<1)+1,c);
        ctx.drawPoint(x,y,RGB565(255,0,0));
    });
};

void llcd::ctx::drawLineLeftRight(int32_t x,int32_t y,int32_t l,color c){
    for(uint32_t i = 0;i<l;i++){
        drawPoint(x+i,y,c);
    }
}

void llcd::ctx::drawLineUpDown(int32_t x,int32_t y,int32_t l,color c){
    for(uint32_t i = 0;i<l;i++){
        drawPoint(x,y+i,c);
    }
}

void llcd::ctx::fillTriangle(int32_t x1,int32_t y1,int32_t x2,int32_t y2,int32_t x3,int32_t y3,color c){
    if(y3>y2){
        swap_int(y3,y2);
        swap_int(x3,x2);
    }
    if(y2>y1){
        swap_int(y2,y1);
        swap_int(x2,x1);
    }
    if(y1>y3){
        swap_int(y1,y3);
        swap_int(x1,x3);
    }
    float longLineX = x1;
    float DynamicLineX = x1;
    float longLineStep = float(x1-x3)/float(y1-y3);
    float shortLineStep = float(x1-x2)/float(y1-y2);
    int height = y3-y1;
    for(int32_t currentY = 0;currentY<height;currentY++){
        if(currentY+y1==y2)shortLineStep = float(x2-x3)/float(y2-y3);
        longLineX += longLineStep;
        DynamicLineX += shortLineStep;
        if(longLineX>DynamicLineX){
            drawLineLeftRight(DynamicLineX,currentY+y1,longLineX-DynamicLineX,c);
        }else{
            drawLineLeftRight(longLineX,currentY+y1,DynamicLineX-longLineX,c);
        }
    }

};
void llcd::ctx::drawLetter(char ch,int32_t x,int32_t y,color c,int32_t scale){
    //to-do
};

void llcd::ctx::drawSymbol(int32_t x,int32_t y,uint8_t*,color c,uint32_t scale){
    //to-do
};

void llcd::ctx::drawSprite(int32_t x,int32_t y,uint8_t* sprite,uint8_t* pallet,uint32_t scale){
    //to-do
};

//more advance
void llcd::ctx::NormalDrawSprite(int32_t x,int32_t y,uint32_t height,uint32_t width,uint8_t* pallet,uint8_t* pixels,uint32_t scale){
    //to-do
};
void llcd::ctx::RleDrawSprite(int32_t x,int32_t y,uint32_t height,uint32_t width,uint8_t* pallet,uint8_t* pixels,uint32_t scale){
    //to-do
};
void llcd::ctx::ExtentedRleDrawSprite(int32_t x,int32_t y,uint32_t height,uint32_t width,uint8_t* pallet,uint8_t* pixels,uint32_t scale){
    //to-do
};
void llcd::ctx::ExtentedDrawSprite(int32_t x,int32_t y,uint32_t height,uint32_t width,uint8_t* pallet,uint8_t* pixels,uint32_t scale){
    //to-do
};
void llcd::ctx::AdvancedRleDrawSprite(int32_t x,int32_t y,uint32_t height,uint32_t width,uint8_t* pallet,uint8_t* pixels,uint32_t scale){
    //to-do
};