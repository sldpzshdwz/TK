#include<ctime>
#include<conio.h>
#include<iostream>
#include<cstring>
#include<windows.h>
#include<stdlib.h>
#include<cstdio>
#include<cstdlib>
#include<fstream>
#include<stdio.h>
using namespace std;
void go(int x,int y)
{
     COORD jump;
     jump.X= x;
     jump.Y= y;
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),jump);
}
int main()
{
	while (1){
		int tx,ty;
		tx=clock();
		
		for (int i=1;i<=48;i+=2)
			for (int j=1;j<=48;j++)
				{
					go(i,j);printf("ºº");
				}
		ty=clock();
		if (ty-tx<=10)Sleep(10-(ty-tx));
		go(0,50);printf("×÷Õß£ºÀîÔó¸Õ");
		go(0,49);printf("%d     ",ty-tx);
		
		
	}
	return 0;
}
