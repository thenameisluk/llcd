#include "llcd.hpp"
#include  <vector>

/* />+
 0(1,1,-1)    1(1,1,1)
2(-1,1,-1)   3(-1,1,1)

 4(1,-1,-1)   5(1,-1,1)
6(-1,-1,-1)  7(-1,-1,1)
*/



llcd::point3d points[8] = {
    llcd::point3d(1,1,-1),
    llcd::point3d(1,1,1),
    llcd::point3d(-1,1,-1),
    llcd::point3d(-1,1,1),
    llcd::point3d(1,-1,-1),
    llcd::point3d(1,-1,1),
    llcd::point3d(-1,-1,-1),
    llcd::point3d(-1,-1,1)
};
llcd::point3d npoints[8];
uint8_t lines[12][2]{
    {0,1},
    {1,3},
    {3,2},
    {2,0},
    {4,5},
    {5,7},
    {6,7},
    {6,4},
    {0,4},
    {1,5},
    {2,6},
    {3,7}
};

std::vector<llcd::note> music = {
    E4, E4, F4, G4, G4, F4, E4, D4, C4, C4, D4, E4, E4, D4, D4, E4, E4, F4, G4, G4, F4, E4, D4, C4, C4, D4, E4, D4, C4, C4, D4, D4, E4, C4, D4, E4, F4, E4, C4, D4, E4, F4, E4, D4, C4, D4, G4, E4, E4, F4, G4, G4, F4, E4, D4, C4, C4, D4, E4, D4, C4, C4
};

llcd::m4x4 rotX = llcd::rotateX_Matrix(0.1);
llcd::m4x4 rotZ = llcd::rotateZ_Matrix(0.1);
llcd::m4x4 mv = llcd::move_Matrix(0,0,3);
llcd::m4x4 proj = llcd::Projection_Matrix();
bool first = true;
int main(){
    lcd_h;//26(27) - 13
    lcd_w;//48 - 24
    #ifdef foo
    stdio_init_all();
    #endif
    llcd::llcd([](llcd::ctx& c,llcd::buttons& b,llcd::audio& a){
        if(first){
            first=false;
            a.set(music,8);
        }
        c.fill(c_black);
        if(!b.isAPressed())for(uint8_t i = 0;i<8;i++)points[i] = rotX.multiplyP(points[i]);
        if(!b.isBPressed())for(uint8_t i = 0;i<8;i++)points[i] = rotZ.multiplyP(points[i]);
        for(uint8_t i = 0;i<8;i++){
            //d[i]++;
            npoints[i] = mv.multiplyP(points[i]);
            npoints[i] = proj.project(npoints[i]);
        }
        for(uint8_t i = 0;i<12;i++){
            c.drawLine(npoints[lines[i][0]],npoints[lines[i][1]],c_white);
        }
        c.drawRect(a.on*3,0,3,3,c_white);
        c.drawLetter('a',20,20,c_white,3);
    });

}