#include "snake.h"
#include <thread>
#include <windows.h>
#include <conio.h>
using namespace std;

int main()
{
    snake s;
    thread th([&]{
                    char ch;
                    while(ch=getch()){
                        int direction=s.getDir();
                        if(ch=='w'&&direction!=0)direction=2;
                        else if(ch=='a'&&direction!=1)direction=3;
                        else if(ch=='s'&&direction!=2)direction=0;
                        else if(ch=='d'&&direction!=3)direction=1;
                        s.setDir(direction);
                        Sleep(200);
                        fflush(stdin);
                    }
                }
              );

    while(1){
        s.frame();
		system("cls");
        s.show();
        Sleep(200);
    }
    th.join();

    return 0;
}
