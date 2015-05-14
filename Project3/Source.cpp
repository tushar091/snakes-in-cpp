#include<iostream>
#include<random>
#include<ctime>
#include"windows.h"
int points;
int sp=100;
int level=0;
using namespace std;
void clearscreen();
int ri=0,le=0,up=0,down=0;
int main()
{
    char map[20][40]={' '};
    for(int i=0;i<20;i++)
    {
        map[i][0]=char(178);
		map[i][39]=char(178);
    }
    for(int i=0;i<40;i++)
    {
        map[0][i]=char(178);
        map[19][i]=char(178);
    }
	srand(time(0));
	int a=rand()%17 + 1;
	srand(time(0));
	int b=rand()%38 + 1;
	int x,y;
	x=9;
	y=19;
	
	map[a][b]= char(219);
	
	while(1)
	{
		clearscreen();
		//system("cls");
		map[x][y]= '*';
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 40; j++)
			{
				cout << map[i][j];
			}
		cout << endl;
		}
		if(GetAsyncKeyState(VK_DOWN))
		{
			ri=0;le=0;up=0;down=1;
		}
		else if(GetAsyncKeyState(VK_UP))
		{
			ri=0;le=0;up=1;down=0;
		}
		else if(GetAsyncKeyState(VK_RIGHT))
		{
			ri=1;le=0;up=0;down=0;
		}
		else if(GetAsyncKeyState(VK_LEFT))
		{
			ri=0;le=1;up=0;down=0;
		}
		Sleep(sp);
		map[x][y]=' ';
		if(ri==1)
		{
			++y;
			map[x][y]='*';
		}
		if(le==1)
		{
			--y;
			map[x][y]='*';
		}
		if(up==1)
		{
			--x;
			map[x][y]='*';
		}
		if(down==1)
		{
			++x;
			map[x][y]='*';
		}
		if(map[x][y]==map[a][b])
		{
			points++;
			srand(time(0));
			a=rand()%17 + 1;
			srand(time(0));
			b=rand()%38 + 1;
			map[a][b]= char(219);
			if(points==3){
				sp=sp-9;
				points=0;
				level++;
			}
			cout<< "Points : "<<points<< "level : " << level<<endl;
		}
		if(x==0||x==19||y==0||y==39)
		{
			cout<< "Game over... now go and sleep"<<endl;

			break;
		}

		
		
		
	}
	system("pause>nul");
    return 0;
}
void clearscreen()
{
    HANDLE hOut;
    COORD Position;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute( hOut, FOREGROUND_GREEN|FOREGROUND_BLUE );
    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}


