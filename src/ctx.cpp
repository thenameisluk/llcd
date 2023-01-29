#include "ctx.hpp"
#include "ascii.hpp"
#include <cmath>
#include <iostream>
//ctx class

#define swap_int(a, b) { int32_t t; t = a; a = b; b = t;}

llcd::ctx::ctx(int width, int height):height(height),width(width){

    img = new color[height*width];
    for(int32_t i = 0;i<width*height;i++){
        img[i] = 0;
    }
}
llcd::ctx::ctx(ctx& cp){
    height = cp.height;
    width = cp.width;
    img = new color[height*width];
    for(int32_t i = 0;i<width*height;i++){
        img[i] = cp.img[i];
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
    

    if (y1 > y2) {
    std::swap(x1, x2);
    std::swap(y1, y2);
    }
    if (y2 > y3) {
    std::swap(x2, x3);
    std::swap(y2, y3);
    }
    if (y1 > y2) {
    std::swap(x1, x2);
    std::swap(y1, y2);
    }
    //1<2<3
    float x1ToX2 = float(x2-x1)/float(y2-y1);
    float x2ToX3 = float(x3-x2)/float(y3-y2);
    float x1ToX3 = float(x3-x1)/float(y3-y1);

    bool x1tox2S = true;
    float currentLX = x1;
    float currentSX = x1;
    if(y1==y2)currentSX = x2;

    for(int32_t currentY = y1;currentY<=y3;currentY++){
        if(currentY == y2) x1tox2S = false;
        if(currentLX<currentSX) drawLineLeftRight(currentLX,currentY,currentSX-currentLX,c);
        else drawLineLeftRight(currentSX,currentY,currentLX-currentSX,c);
        if(x1tox2S)currentSX += x1ToX2;
        else currentSX += x2ToX3;
        currentLX += x1ToX3;
    }

};
void llcd::ctx::drawLetter(char ch,int32_t x,int32_t y,color c,int32_t scale){
    uint8_t id = (uint8_t)ch-' ';
    for(uint8_t i=0;i<5;i++){
        for(uint8_t j=0;j<5;j++){
            if(characters[id][j][i])fillRect(x+i*scale,y+j*scale,scale,scale,c);
        }
    }
};

void llcd::ctx::drawCtx(int32_t x,int32_t y,ctx& context){
    for(int32_t ix = 0;ix<context.width;ix++){
        for(int32_t iy = 0;iy<context.height;iy++){
            drawPoint(x+ix,y+iy,context.img[ix+context.width*iy]);
        }
    }
}

void llcd::ctx::print(const char* text,int32_t x,int32_t y,color c,uint32_t scale){
    uint32_t place = 0;
    uint32_t line = 0;
    while (text[place]!='\0'){
        
        if(text[place]=='\n'){
            line++;
            continue;
        }else drawLetter(text[place],x+6*place*scale,y+line*scale*6,c,scale);
        place++;
    }
};

void llcd::ctx::print(int32_t number,int32_t x,int32_t y,color c,uint32_t scale){
    bool negative = false;
    if(number<0){
        negative = true;
        number = -number;
    }
    uint32_t numlenght = 0;
    int32_t temp = number;
    do{   
        temp -= temp%10;
        temp /= 10;
        numlenght++;
    }while (temp!=0);
    numlenght+=negative;
    char* txt = new char[numlenght+1];
    txt[numlenght] = '\0';
    
    if(negative){
        txt[0] = '-';
    }
    uint32_t itnumlenght= numlenght-1;
    while(number!=0){
        txt[itnumlenght] = number%10+'0';
        number /= 10;
        itnumlenght--;
    }
    print(txt,x,y,c,scale);
    delete[] txt;

    
}

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