#ifndef wolf_cpp
#define wolf_cpp

#include"include1.h"
#include"chanshu.cpp"
#include"guai.cpp"

using namespace std;
void kangchangjuqing()
{
	go(70,20);sl("（回车继续）");huiche();
	go(80,22);sl("开始战斗吧！！！（回车继续）");huiche();
}
int main()
{
	
	srand(time(0));
	ckdx(ddlie+1,ddhang);
	Movew(0,0);
	
	kangchangjuqing();	
	
	
}

#endif
