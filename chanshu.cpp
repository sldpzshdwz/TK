#ifndef chanshu_cpp
#define chanshu_cpp
#include"include1.h"
#define ddhang 51
#define ddlie  195
// 42-193            152
// 1-49 ��ͼ��Χ     49
#define ztailan 40
int map[1100][1100],tk;
int qian[4],qianj[4];//Ǯ��Ǯ�����ٶ� 
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
//1000+�� 
bool ky[1100];//��ˢ�µļ��� 
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
// 1-49 ��ͼ��Χ 
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
	int x1,y1,yan;//���꣬�ӳ�
	int xue,lei,shu,gong;//Ѫ�����࣬�ٶȣ�����
	int zhen;//������Ӫ ��1�ң�2-10�� 
	int t1,t2,t3,t4,k[3],gxx,gyy;//����������¼���罨����gxx gyy����������λ�� 
	int p1,p2,p3,p4,p5;//p5�����ٶ� 
	int newggb;
	int ggb;
	string c;//��������� 
	guai(){yan=rand()%1000000;xue=0;lei=1;
		t1=0;t2=0;t3=0;t4=0;
		ggb='T';
	}
}g[110000];int gs=0;//���ֻ��� 
//����˵����1-99ʿ����100-200����
/*
	1����ս����
	2�������� (��99��)
	
	100,��� 
	101,��Ӫ 
	102,������ 
	200�����ڽ��� 
*/ 
int xin[1100][1100][11];//�о�·�ߣ�1�ң�2��,���౸�� 
int lxs[1100][1100];//Ϊ����lx��׼�� 
bool shuchu;
int xianshi=1;//���״̬������ʾ��� 
char aj[6][30];//���� 

bool jw[257];//��λ�Ƿ񳤰� 
int jb[6];//���ӵĲɽ�Ƽ��ӳ� 
int jinenggainv[11][1100];//jinenggainv[x][0]Ϊ���� 
struct jineng1
{
	int jilei;//�������� 
	int xue,lei,shu,gong,qian;//Ѫ�����࣬�ٶȣ�����
	int ggb;
	int shuliang;
	string c;//��������� 
	string cc1,cc2;//���ܵĽ��� 
	
}jineng[6][1100];
jineng1 jilu[11][11];

double gongjia[6],xuejia[6],qianjia[6],shujia[6];







/*
	ע�⣺ 1����ʵ��֤���� switch..case�ṹ�������ڸı���ɫ�������
			���룺
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
	ע�⣺ 2��������ֵ�ʱ��ԼΪ��ĸ��4�� 
*/
#endif
