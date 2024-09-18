#ifndef chanshu_cpp
#define chanshu_cpp
#include"include1.h"
#define ddhang 51
#define ddlie  195
// 42-193            152
// 1-49 地图范围     49
#define ztailan 40
int map[1100][1100],tk;
int qian[4],qianj[4];//钱，钱增加速度 
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
//1000+人 
bool ky[1100];//可刷新的技能 
void qingmap()
{
	memset(map,0,sizeof(map));
	for (int i=0;i<ddhang;i++){
		go(ztailan,i);printf("||");map[ztailan][i]=1;map[ztailan+1][i]=1;
		go(ddlie-1,i);printf("*");map[ddlie-1][i]=1;
	}
	for (int i=40;i<ddlie;i++){
		go(i,0);printf("*");map[i][0]=1;
		go(i,ddhang-1);printf("*");map[i][ddhang-1]=1;
	}
}
// 42-193
// 1-49 地图范围 
void shuchuditu()
{
	for (int i=42;i<=193;i++){
		for (int j=1;j<=49;j++){
			go(i,j);
			if (map[i][j]==1)printf("*");else printf(" ");
		}
	}
}



char cc;
void huiche() 
{
	cc=' ';while (cc!='\n'){cc=getchar();}	
}
struct guai
{
	int x1,y1,yan;//坐标，延迟
	int xue,lei,shu,gong;//血，种类，速度，攻击
	int zhen;//所属阵营 ，1我，2-10敌 
	int t1,t2,t3,t4,k[3],gxx,gyy;//特殊能力记录，如建筑，gxx gyy建筑工建筑位置 
	int p1,p2,p3,p4,p5;//p5建筑速度 
	int newggb;
	int ggb;
	string c;//怪物的名字 
	guai(){yan=rand()%1000000;xue=0;lei=1;
		t1=0;t2=0;t3=0;t4=0;
		ggb='T';
	}
}g[110000];int gs=0;//兵种花费 
//种类说明：1-99士兵，100-200建筑
/*
	1，近战兵种
	2，建筑工 (第99种)
	
	100,金矿 
	101,兵营 
	102,主基地 
	200，正在建造 
*/ 
int xin[1100][1100][11];//行军路线，1我，2敌,其余备用 
int lxs[1100][1100];//为函数lx做准备 
bool shuchu;
int xianshi=1;//左端状态栏的显示情况 
char aj[6][30];//按键 

bool jw[257];//键位是否长按 
int jb[6];//各队的采金科技加成 
int jinenggainv[11][1100];//jinenggainv[x][0]为总数 
struct jineng1
{
	int jilei;//技能类型 
	int xue,lei,shu,gong,qian;//血，种类，速度，攻击
	int ggb;
	int shuliang;
	string c;//怪物的名字 
	string cc1,cc2;//技能的介绍 
	
}jineng[6][1100];
jineng1 jilu[11][11];

double gongjia[6],xuejia[6],qianjia[6],shujia[6];







/*
	注意： 1，经实验证明， switch..case结构不能用于改变颜色，会出错
			代码：
	char c=1;
	switch (c){
		case 2: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);}
		case 1: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);}
		case 3: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);}
		case 4: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);}
		case 5: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);}
		case 6: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);}
		case 7: {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);}
	}
	
	printf("112312"); 
*/
/*
	注意： 2，输出文字的时间约为字母的4倍 
*/
#endif
