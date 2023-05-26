#include "point.h"
#include<stdio.h>
#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED
const int X=20;
const int Y=40;
point increase;
bool empt=true;
int graph[X+1][Y+1];
int dir[2][4]{
    1,0,-1,0,
    0,1,0,-1
};// down0   right1    up2  left3

#endif // GLOBAL_H_INCLUDED
