#include <iostream>
#include<windows.h>
#include<vector>
#include<memory.h>
#include<time.h>
#include<cstdlib>
#include<thread>
#include<assert.h>
#include <conio.h>
using namespace std;
#define X 30
#define Y 120

struct point{
    int x,y;
};
int dir[2][4]{
    1,0,-1,0,
    0,1,0,-1
};// down0   right1    up2  left3
int direction=0;
vector<point>body;
point increase;
bool empt=true;
int graph[X+1][Y+1];
void check_food(){
	int x=body.back().x,y=body.back().y;
    x+=dir[0][direction];
    y+=dir[1][direction];

    if(x==0)x=X;
    else if(x==X+1)x=1;
    if(y==0)y=Y;
	else if(y==Y+1)y=1;

	if(!empt&&x==increase.x&&y==increase.y)
	{
		body.push_back(increase);
		empt=true;
	}

}
void check_over(){
	int x=body.back().x,y=body.back().y;
    x+=dir[0][direction];
    y+=dir[1][direction];

    if(x==0)x=X;
    else if(x==X+1)x=1;
    if(y==0)y=Y;
	else if(y==Y+1)y=1;

	if(graph[x][y]==true)
	{
		printf("game over");
		exit(0);
	}

}
void generat(){
	srand(time(NULL));
	int x=rand()%X+1,y=rand()%Y+1;
	while(graph[x][y])
		x=rand()%X+1,y=rand()%Y+1;
	increase={x,y};
	empt=false;
}
void transform(){
	check_food();
	body.erase(body.begin());
	int x=body.back().x,y=body.back().y;
    x+=dir[0][direction];
    y+=dir[1][direction];
    if(x==0)x=X;
    else if(x==X+1)x=1;
    if(y==0)y=Y;
	else if(y==Y+1)y=1;
    body.push_back({x,y});
    for(auto &i:body)graph[i.x][i.y]=true;
    if(empt)generat();
    check_over();
}

void show(){
    HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
    for(auto &i:body){
        SetConsoleCursorPosition(handle,{i.y,i.x});
        printf("*");
    }
    SetConsoleCursorPosition(handle,{increase.y,increase.x});
    printf("#");
    memset(graph,0,sizeof graph);
}
void init(){
    body.push_back({7,7});
    body.push_back({8,7});
}
void monitor(){
	char ch;
	while(ch=getch()){
		if(ch=='w'&&direction!=0)direction=2;
		else if(ch=='a'&&direction!=1)direction=3;
		else if(ch=='s'&&direction!=2)direction=0;
		else if(ch=='d'&&direction!=3)direction=1;
	}
}
int main() {
	thread th(monitor);
    init();
    while(1){
        transform();
		system("cls");
        show();
        Sleep(200);
    }
    th.join();
    return 0;
}
