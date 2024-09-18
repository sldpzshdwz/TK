#ifndef guai_cpp
#define guai_cpp

#include"include1.h"
#include"chanshu.cpp"
//行军在maint里 
struct nod{
	int x,y,c;
}list[110000];int head,tail;
void jia(int &x){x++;if (x>=110000)x=1;}
void jiagetail(int x,int y,int c)//下面函数的工具 
{
	jia(tail);list[tail].x=x-1;list[tail].y=y;list[tail].c=c+1;
	jia(tail);list[tail].x=x+1;list[tail].y=y;list[tail].c=c+1;
	jia(tail);list[tail].x=x;list[tail].y=y-1;list[tail].c=c+1;
	jia(tail);list[tail].x=x;list[tail].y=y+1;list[tail].c=c+1;
}
int lx(int x1,int y1,int x2,int y2,int tt1)//为了一个地点而行走 ,tt1=0时输出行走方向，tt1=1时输出行走距离 
{
	head=1;tail=0;
	memset(lxs,63,sizeof(lxs));
	tail++;list[tail].x=x2;list[tail].y=y2;list[tail].c=0;
	int pp=0;
	while (head!=tail+1){
		int x=list[head].x,y=list[head].y,c=list[head].c;
		if (c<lxs[x][y]&&map[x][y]==0){
			lxs[x][y]=c;
			jiagetail(x,y,c);
		}
		jia(head);pp++;
	}
	//go(0,42);printf("%d\n        ",pp);
	int mint=ran(0,3),minn=1000000;
	for (int t=0;t<=3;t++){
		int tx=x1+dx[t],ty=y1+dy[t];
		if (lxs[tx][ty]<minn){
			minn=lxs[tx][ty];
			mint=t;
		}else
		if (lxs[tx][ty]==minn&&rand()%2==0){
			mint=t;
		}
	}
	if (tt1==0)return mint;
	else     return lxs[x1][y1];
}

void qiuxin()//行军路线 
{
	memset(xin,63,sizeof(xin));
	for (int zz=1;zz<=2;zz++){
		head=1;tail=1;
		for (int i=1;i<=gs;i++){
			if (g[i].xue>0){
				int x1=g[i].x1,y1=g[i].y1;
				int zhen=g[i].zhen,xue=g[i].xue,lei=g[i].lei,shu=g[i].shu,gong=g[i].gong;
				int yan=g[i].yan;
				if (zhen!=zz){
					jiagetail(x1,y1,0);
					if (lei>=100&&lei<=200)jiagetail(x1+1,y1,0);
				}
			}
		}
		while (head!=tail){
			int x=list[head].x,y=list[head].y,c=list[head].c;
			if (c<xin[x][y][zz]&&map[x][y]==0){
				xin[x][y][zz]=c;
				jiagetail(x,y,c);
			}
			jia(head);
		}
	}
}

void gl(int x,int y) //清理 
{
	go(x,y);printf(" ");
	map[x][y]=0;
}
void shabin(int i)//杀死士兵 ,清理残骸(士兵编号)
{	
	int lei=g[i].lei;gl(g[i].x1,g[i].y1);
	if (lei>=100&&lei<=200){
		gl(g[i].x1+1,g[i].y1);
	}
}
void xianbin(int i,char c)//显示士兵，前景颜色(士兵编号，颜色)
{
	int lei=g[i].lei;
	go(g[i].x1,g[i].y1);
	map[g[i].x1][g[i].y1]=1000+i;
	if (lei>=100&&lei<=200)map[g[i].x1+1][g[i].y1]=1000+i;
	char cs='0';
	if (g[i].zhen==1)cs='y';
	if (g[i].zhen==2)cs='p';
	if (g[i].t1>0&&g[i].zhen!=2){g[i].t1--;cs='r';}
	if (g[i].t1>0&&g[i].zhen==2){g[i].t1--;cs='g';}
	if (g[i].t2>0){g[i].t2--;cs='b';}
	if (g[i].lei==1||g[i].lei==2)mychar2(g[i].ggb,cs,c);
	if (g[i].lei==100)mycout2("金",cs,c);
	if (g[i].lei==101)mycout2("兵",cs,c);
	if (g[i].lei==102)mycout2("主",cs,c);
	if (g[i].lei==200)mycout2("建",cs,c);
} 
void kou(int i,int gg) //扣血 (第几个怪物攻击，第几个怪物被打)
{
	int zhen=g[i].zhen;
	if (g[gg].lei==100){
		g[gg].k[zhen]+=g[i].gong;
		g[gg].k[3-zhen]-=g[i].gong;
		if (g[gg].k[3-zhen]<=0)g[gg].zhen=zhen;
		g[gg].t1=1;
		return ;
	}
	g[gg].xue-=g[i].gong;
	g[gg].t1=1;
}
void binsiwang(int i)//士兵死亡 (士兵编号) 
{
	
	if (g[i].xue<=0){
		shabin(i);
		int lei=g[i].lei;
		for (int j=i;j<gs;j++){
			map[g[j+1].x1][g[j+1].y1]=0;
			if (g[j+1].lei>=100&&g[j+1].lei<=200){map[g[j+1].x1+1][g[j+1].y1]=0;}
			g[j]=g[j+1];
			map[g[j].x1][g[j].y1]=1000+j;
			if (g[j].lei>=100&&g[j].lei<=200){map[g[j].x1+1][g[j].y1]=1000+j;}
		}
		g[gs].xue=0;gs--;
	}
} 
int xunzhao(int i)//寻找该士兵身边的敌人 (士兵编号) 
{
	int x1=g[i].x1,y1=g[i].y1;
	int zhen=g[i].zhen,xue=g[i].xue,lei=g[i].lei,shu=g[i].shu,gong=g[i].gong;
	int yan=g[i].yan;
	int ret[5],retsum=0;
	for (int tt=0;tt<=3;tt++){
		int x=x1+dx[tt],y=y1+dy[tt];
		if (map[x][y]>=1000){
			int gg=map[x][y]-1000;
			if (g[gg].zhen!=zhen){
				retsum++;ret[retsum]=gg;
			}
		}
	}
	if (retsum==0)return -1;
	else return ret[rand()%retsum+1];
}
void ztl(int );
void easyztl(int );

bool newg(int x1,int y1,int xue,int lei,int shu,int zhen,int gong,int ggb)//（ggb为怪物的样貌） 
{
	if (map[x1][y1]!=0)return false;
	if (x1>193||x1<42||y1<1||y1>49)return false;
	if (lei>=100&&lei<=200&& map[x1+1][y1]!=0)return false;
	gs++;
	g[gs].x1=x1;g[gs].y1=y1;g[gs].xue=xue;g[gs].lei=lei;g[gs].shu=shu;g[gs].zhen=zhen;g[gs].gong=gong;
	g[gs].ggb=ggb;
	map[x1][y1]=1000+gs;
	if (lei>=100&&lei<=200){
		if (lei==100 ){
			if (zhen==3)g[gs].k[1]=g[gs].k[2]=xue/2;
			if (zhen==2)g[gs].k[1]=0,g[gs].k[2]=xue;
			if (zhen==1)g[gs].k[1]=xue,g[gs].k[2]=0;
		}
		map[x1+1][y1]=1000+gs;
	}
	return true;
}
bool newj(int x1,int y1,int xue,int shu,int zhen,int ggb,int p1,int p2,int p3,int p4,int p5,int gxx,int gyy,int newggb)//建筑工人 
{
	if (map[x1][y1]!=0)return false;
	if (x1>193||x1<42||y1<1||y1>49)return false;
	gs++;
	g[gs].x1=x1;g[gs].y1=y1;g[gs].xue=xue;g[gs].lei=2;g[gs].shu=shu;g[gs].zhen=zhen;g[gs].gong=0;
	g[gs].ggb=ggb;
	g[gs].p1=p1;g[gs].p2=p2;g[gs].p3=p3;g[gs].p4=p4;g[gs].p5=p5;g[gs].gxx=gxx;g[gs].gyy=gyy;
	g[gs].newggb=newggb;
	map[x1][y1]=1000+gs;
	return true;
}
/*
void Dbin(int zhong,int ownzhen){
	for (int i=1;i<=gs;i++){
		int x1=g[i].x1,y1=g[i].y1;
		int zhen=g[i].zhen,xue=g[i].xue,lei=g[i].lei,shu=g[i].shu,gong=g[i].gong;
		int yan=g[i].yan,ttkk=0;
		if (zhen==ownzhen&&lei==101){
			g[i].t1=1;
			
			int xue=jineng[ownzhen][zhong].xue,lei=jineng[ownzhen][zhong].lei,shu=jineng[ownzhen][zhong].shu,gong=jineng[ownzhen][zhong].gong,ggb=jineng[ownzhen][zhong].ggb;
			while (!newg(ran(x1-6,x1+6),ran(y1-6,y1+6),
			xue,lei,shu,zhen,gong,ggb)){ttkk++;if(ttkk>10000)break;}
		}
	}
}
*/
void Dbin(int ownzhen,int zhong){
	for (int i=1;i<=gs;i++){
		int x1=g[i].x1,y1=g[i].y1;
		int zhen=g[i].zhen,xue=g[i].xue,lei=g[i].lei,shu=g[i].shu,gong=g[i].gong;
		int yan=g[i].yan,ttkk=0;
		if (zhen==ownzhen&&lei==101){
			g[i].t1=1;
			
			int xue=jilu[ownzhen][zhong].xue,lei=jilu[ownzhen][zhong].lei,shu=jilu[ownzhen][zhong].shu,gong=jilu[ownzhen][zhong].gong,ggb=jilu[ownzhen][zhong].ggb;
			while (!newg(ran(x1-6,x1+6),ran(y1-6,y1+6),
			xue,lei,shu,zhen,gong,ggb)){ttkk++;if(ttkk>10000)break;}
		}
	}
}
void Djian(int zhong,int ownzhen,int md_x,int md_y)
{
	int minn=9999999,minx,miny;
	for (int i=1;i<=gs;i++){
		int x1=g[i].x1,y1=g[i].y1;
		int op=map[x1][y1];map[x1][y1]=0;
		int zhen=g[i].zhen,xue=g[i].xue,lei=g[i].lei,shu=g[i].shu,gong=g[i].gong;
		int yan=g[i].yan;
		if (zhen==ownzhen&&lei==102){
			lx(x1,y1,md_x,md_y,1);
			if (minn>lx(x1,y1,md_x,md_y,1)){
				minn=lx(x1,y1,md_x,md_y,1);
				minx=x1;miny=y1;
			}
		}
		map[x1][y1]=op;
	}
	if (minn==9999999)return ;
//	int x1,int y1,
//	int xue,int shu,int zhen,int ggb,int p1,int p2,int p3,
//	int p4,int p5,int gxx,int gyy,int newggb
	int xue=jineng[ownzhen][99].xue    ,shu=jineng[ownzhen][99].shu   ,zhen=ownzhen    ,ggb=jineng[ownzhen][99].ggb;
	int p1=jineng[ownzhen][zhong].xue  ,p2=jineng[ownzhen][zhong].lei ,p3=jineng[ownzhen][zhong].shu;
	int p4=jineng[ownzhen][zhong].gong ,gxx=md_x,gyy=md_y          ,newggb=jineng[ownzhen][zhong].ggb;
	int ttkk=0;
	while (!newj(ran(minx-2,minx+2),ran(miny-2,miny+2),
	xue,shu,zhen,ggb,p1,p2,p3,
	p4,10,gxx,gyy,newggb)){ttkk++;if(ttkk>10000)break;}
}
#endif
