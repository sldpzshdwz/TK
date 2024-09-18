#include"include1.h"
#include"chanshu.cpp"
#include"guai.cpp"
#include"maint.cpp"
//int x1,int y1,int xue,int lei,int shu,int zhen,int gong,char ggb
/*int x1,int y1,int xue,int shu,int zhen,int ggb,
int p1,int p2,int p3,int p4,int p5,int gxx,int gyy,int gbb*/

int main()
{
	memset(qian,0,sizeof(qian));
	srand(time(0));
	
	
	newj (42,2,5 ,100  ,1 ,'U' ,
		100,101,100,100,1,42,2,10000);
	newj (192,49,5 ,100  ,2 ,'U' ,
		100,101,100,100,1,192,49,10000);
	
	qian[1]=50000;
	qian[2]=-50000;
	youxi();
	huiche();
	return 0;
	return 0;
}
