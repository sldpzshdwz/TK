#ifndef include1_h
#define include1_h

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
#include<algorithm>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

using namespace std;
HWND hwnd=GetForegroundWindow();  
int ran(int x,int y){
	return rand()%(y-x+1)+x;
}
void go(int x,int y)
{
     COORD jump;
     jump.X= x;
     jump.Y= y;
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),jump);
}
bool check(char c){//检测某个按键是否按下(一定要大写！)
    if(!KEY_DOWN(c))return false;  
    else return true; 
}
void bs(char c,char t)
{
	int a1,a2,a3,a4,b1,b2,b3,b4;//windows指令可以用任意数据结构储存（也许） 
	if (c=='w') a1=FOREGROUND_INTENSITY,a2=FOREGROUND_RED,a3=FOREGROUND_GREEN,a4=FOREGROUND_BLUE;
	if (c=='r') a1=FOREGROUND_INTENSITY,a2=a3=a4=FOREGROUND_RED;
	if (c=='g') a1=FOREGROUND_INTENSITY,a2=a3=a4=FOREGROUND_GREEN;
	if (c=='b') a1=FOREGROUND_INTENSITY,a2=a3=a4=FOREGROUND_BLUE;
	if (c=='y') a1=FOREGROUND_INTENSITY,a2=FOREGROUND_RED,a3=a4=FOREGROUND_GREEN;
	if (c=='p') a1=FOREGROUND_INTENSITY,a2=FOREGROUND_RED,a3=a4=FOREGROUND_BLUE;
	if (c=='0') a1=FOREGROUND_RED,a2=FOREGROUND_GREEN,a3=a4=FOREGROUND_BLUE;//这样不会错，但很耗时间 ,不知道为什么，似乎是因为颜色的关系 
	
	if (t=='w') b1=BACKGROUND_INTENSITY,b2=BACKGROUND_RED,b3=BACKGROUND_GREEN,b4=BACKGROUND_BLUE;
	if (t=='r') b1=BACKGROUND_INTENSITY,b2=b3=b4=BACKGROUND_RED;
	if (t=='g') b1=BACKGROUND_INTENSITY,b2=b3=b4=BACKGROUND_GREEN;
	if (t=='b') b1=BACKGROUND_INTENSITY,b2=b3=b4=BACKGROUND_BLUE;
	if (t=='y') b1=BACKGROUND_INTENSITY,b2=BACKGROUND_RED,b3=b4=BACKGROUND_GREEN;
	if (t=='p') b1=BACKGROUND_INTENSITY,b2=BACKGROUND_RED,b3=b4=BACKGROUND_BLUE;
	if (t=='0') b1=b2=b3=b4=0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a1|a2|a3|a4|b1|b2|b3|b4);

}
void mycout(string ptt,char c)//各种颜色的输出 
{
	bs(c,'0');
	printf("%s",ptt.c_str());
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
}
void mychar(char p,char c)//各种颜色的输出 
{
	bs(c,'0');
	printf("%c",p);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
}
void mycout2(string ptt,char c,char t)//各种颜色的输出 
{
	bs(c,t);
	printf("%s",ptt.c_str());
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
}
void mychar2(char p,char c,char t)//各种颜色的输出 
{
	bs(c,t);
	printf("%c",p);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
}
void sl(char *p)
{
    while(1)
    {
        if((*p)!='\0') {printf("%c",*p);p++;}
        else break;
        Sleep(10);
    }
}
void ckdx(int x,int y){//列，行 
	char ss[1100];
	sprintf(ss,"mode con cols=%d lines=%d",x,y);
	system(ss);
}
void ShakeWindow(){   
    RECT rect;   
    
    GetWindowRect(hwnd,&rect);   
    MoveWindow(hwnd,rect.left+5,rect.top,rect.right-rect.left,rect.bottom-rect.top,TRUE);   
    Sleep(28);   
    GetWindowRect(hwnd,&rect);
    MoveWindow(hwnd,rect.left+5,rect.top-5,rect.right-rect.left,rect.bottom-rect.top,TRUE);   
    Sleep(28);   
    GetWindowRect(hwnd,&rect);
    MoveWindow(hwnd,rect.left,rect.top-5,rect.right-rect.left,rect.bottom-rect.top,TRUE);   
    Sleep(28);   
    GetWindowRect(hwnd,&rect);
    MoveWindow(hwnd,rect.left,rect.top,rect.right-rect.left,rect.bottom-rect.top,TRUE);   
    Sleep(28);   
}
void Movew(int x,int y){   
    RECT rect;   
    
    GetWindowRect(hwnd,&rect);   
    MoveWindow(hwnd,x,y,rect.right-rect.left,rect.bottom-rect.top,TRUE);   
    
}  

#endif
