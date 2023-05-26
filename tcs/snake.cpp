#include "snake.h"
#include "global.h"
#include <windows.h>
#include <memory.h>
#include <time.h>
#include <iostream>

auto snake::checkFood() -> void{
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

auto snake::checkOver() -> void{
    int x=body.back().x,y=body.back().y;
    x+=dir[0][direction];
    y+=dir[1][direction];

    if(x==0)x=X;
    else if(x==X+1)x=1;
    if(y==0)y=Y;
	else if(y==Y+1)y=1;

	if(graph[x][y]==true)
	{
	    std::cout<<"game over!"<<std::endl;
		exit(0);
	}
}

auto snake::generat() -> void{
    srand(time(NULL));
	int x=rand()%X+1,y=rand()%Y+1;
	while(graph[x][y])
		x=rand()%X+1,y=rand()%Y+1;
	increase={x,y};
	empt=false;
}

auto snake::frame() -> void{
    checkFood();
	body.erase(body.begin());
	checkOver();
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

}

auto snake::show() -> void{
    HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
    for(int i=0;i<=X;i++)
    {

        WORD wColor = ((8 & 0x0F) << 4) + (8 & 0x0F);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
        SetConsoleCursorPosition(handle,{0,i});
        std::cout<<" ";
        wColor = ((8 & 0x0F) << 4) + (8 & 0x0F);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
        SetConsoleCursorPosition(handle,{Y+1,i});
        std::cout<<" ";
    }
    for(int i=0;i<=Y;i++)
    {

        WORD wColor = ((8 & 0x0F) << 4) + (8 & 0x0F);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
        SetConsoleCursorPosition(handle,{i,0});
        std::cout<<" ";
        wColor = ((8 & 0x0F) << 4) + (8 & 0x0F);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
        SetConsoleCursorPosition(handle,{i,X+1});
        std::cout<<" ";
    }


    SetConsoleTextAttribute(handle,FOREGROUND_RED);
    for(auto &i:body){
        SetConsoleCursorPosition(handle,{i.y,i.x});
        std::cout<<"*";
    }
    SetConsoleCursorPosition(handle,{increase.y,increase.x});
    std::cout<<"#";
    memset(graph,0,sizeof graph);
}
