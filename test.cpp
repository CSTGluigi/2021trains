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
#define X 10
#define Y 20

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
bool empty=true;
int graph[X+1][Y+1];
bool check(){
	int x=body.back().x,y=body.back().y;
    x+=dir[0][direction];
    if(x%X+1==0)x=1;
    y+=dir[1][direction];
    if(y%Y+1==0)y=1;
	if(!empty&&x==increase.x&&y==increase.y)
	{
		body.push_back(increase);
		empty=true;
		return true;	
	}
	if(graph[x][y]==true)
	{
		printf("game over");
		assert(false);
		exit(0);
	}
}
void transform(){
	if(check())return;
	body.erase(body.begin());
	int x=body.back().x,y=body.back().y;
    x+=dir[0][direction];
    if(x%(X+1)==0)x=1;
    y+=dir[1][direction];
    if(y%(Y+1)==0)y=1;
    body.push_back({x,y});
    for(auto &i:body)graph[i.x][i.y]=true;
}
void generat(){
	srand(time(NULL));
	int x=rand()%X+1,y=rand()%Y+1;
	while(graph[x][y])
		x=rand()%X+1,y=rand()%Y+1;
	increase={x,y};
	empty=false;
}
void show(){
	
    for(int i=1;i<=X;i++,printf("\n"))
    for(int j=1;j<=Y;j++){
        if(i==increase.x&&j==increase.y&&!empty)printf("#");
		else if(graph[i][j]){
			
			printf("*");
        }
		else printf(" ");
    }
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
    int i=0;
    while(1){
        transform();
        if(i%20==0){
			generat();
    		i=0;
		}
		i+=1;
		system("cls");
        show();
        Sleep(200);
    }
    th.join();
    return 0;
}

