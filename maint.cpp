#include"guai.cpp"

bool diannao[11];//哪个是电脑 
bool xingdong(int tk,int shu)// 士兵是否应当行动
{
	int p=100/shu,psy=100-p*shu;
	int bf=shu-psy,ef=psy;
	int ntk=tk%100;
	if (ntk<=bf*p){
		if (ntk%p==0)return true;else return false;
	}else{
		ntk-=bf*p;
		if (ntk%(p+1)==0)return true;else return false;
	}
} 
void xinjun()//士兵行动 
{
	int tx,ty,ttx,tty;
	
	qiuxin();

	for (int i=1;i<=gs;i++){
		binsiwang(i);
	}

	
	for (int i=1;i<=gs;i++){

		ztl(1);ztl(2);
		if (g[i].xue>0){
			gl(g[i].x1,g[i].y1);
			if (g[i].lei>=100&&g[i].lei<=200){
				gl(g[i].x1+1,g[i].y1);
			}
			int x1=g[i].x1,y1=g[i].y1;
			int zhen=g[i].zhen,xue=g[i].xue,lei=g[i].lei,shu=g[i].shu,gong=g[i].gong;
			int yan=g[i].yan;
			if ((tk+yan)%5==0){
				if (lei==1){
					int drbh=xunzhao(i);
					if (drbh!=-1)kou(i,drbh);
				}
			}
			if (xingdong(tk+yan,shu)){
				if (lei==1){
					int drbh=xunzhao(i);
					if (drbh==-1){
						int mint=0,mint1=xin[1][1][1];
						for (int tt=0;tt<=3;tt++){
							int x=x1+dx[tt],y=y1+dy[tt];
							if (map[x][y]==0&&(xin[x][y][zhen]<mint1)||(xin[x][y][zhen]==mint1&&rand()%4>1)){
								mint=tt;mint1=xin[x][y][zhen];
							}
						}
						if (mint1==xin[1][1][1]){mint=rand()%4;int jss=0;while (map[x1+dx[mint]][y1+dy[mint]]!=0&&jss<=100)jss++,mint=rand()%4;}
						int x=x1+dx[mint],y=y1+dy[mint];
						if (map[x][y]==0){
							g[i].x1=x;g[i].y1=y;
						}
					}
				}
				else
				if (lei==2){
					if (g[i].gxx==x1&&g[i].gyy==y1){
						if (map[x1+1][y1]==0){
							g[i].lei=200;
						}
					}
					else {
						int tt=0;tt=lx(x1,y1,g[i].gxx,g[i].gyy,0);
						if (map[x1+dx[tt]][y1+dy[tt]]==0){
							g[i].x1=x1+dx[tt];g[i].y1=y1+dy[tt];
						}
					}
				}
				else
				if (lei==200){
					if (g[i].p5<=0){
						g[i].xue=g[i].p1;
						g[i].lei=g[i].p2;
						g[i].shu=g[i].p3;
						g[i].gong=g[i].p4;
						g[i].ggb=g[i].newggb;
					}
					else{g[i].p5--;if (g[i].p5==2)g[i].t2=1;}
				}
				else
				if (lei==100){
					qian[zhen]+=g[i].ggb;
					qianj[zhen]+=g[i].ggb;
				}
			}
			
			
			xianbin(i,'0');
		}
		else{
			gl(g[i].x1,g[i].y1);
			if (g[i].lei>=100&&g[i].lei<=200){
				gl(g[i].x1+1,g[i].y1);
			}
		}
	}

}
bool cmp(jineng1 a1,jineng1 a2)
{
	return a1.qian<a2.qian;
}
void cch()//初始化 速度不能为0！ 
{
	for (int e=1;e<=2;e++){
		int gl=0;
		
		gl++;jineng[e][gl ].xue=100;  jineng[e][gl ].gong=40;    jineng[e][gl ].shu=33; jineng[e][gl ].lei=1;  jineng[e][gl ].ggb='L'; jineng[e][gl ].qian=400; jineng[e][gl ].c="豺狼人";  jineng[e][gl ].jilei=1; jineng[e][gl ].shuliang=1;
		gl++;jineng[e][gl ].xue=52;   jineng[e][gl ].gong=20;    jineng[e][gl ].shu=35; jineng[e][gl ].lei=1;  jineng[e][gl ].ggb='i'; jineng[e][gl ].qian=500; jineng[e][gl ].c="民兵";  jineng[e][gl ].jilei=1; jineng[e][gl ].shuliang=3;
		gl++;jineng[e][gl ].xue=750;  jineng[e][gl ].gong=10;    jineng[e][gl ].shu=20; jineng[e][gl ].lei=1;  jineng[e][gl ].ggb='M'; jineng[e][gl ].qian=600; jineng[e][gl ].c="巨石";    jineng[e][gl ].jilei=1; jineng[e][gl ].shuliang=1;
		gl++;jineng[e][gl ].xue=78;   jineng[e][gl ].gong=24;    jineng[e][gl ].shu=50; jineng[e][gl ].lei=1;  jineng[e][gl ].ggb='u'; jineng[e][gl ].qian=600; jineng[e][gl ].c="轻骑";  jineng[e][gl ].jilei=1; jineng[e][gl ].shuliang=2;
		gl++;jineng[e][gl ].xue=10;   jineng[e][gl ].gong=80;    jineng[e][gl ].shu=40; jineng[e][gl ].lei=1;  jineng[e][gl ].ggb=','; jineng[e][gl ].qian=2000;jineng[e][gl ].c="蜘蛛";  jineng[e][gl ].jilei=1; jineng[e][gl ].shuliang=16;
		for (int i=1;i<=4;i++){
			gl++;jineng[e][gl ]=jineng[e][i  ];
			jineng[e][gl ].qian*=2;jineng[e][gl ].shuliang*=2;
			gl++;jineng[e][gl ]=jineng[e][i  ];
			jineng[e][gl ].qian*=3;jineng[e][gl ].shuliang*=3;
		}
		gl++;jineng[e][gl ].xue=0;   jineng[e][gl ].gong=18;    jineng[e][gl ].shu=0;  jineng[e][gl ].qian=800;  jineng[e][gl ].c="钢剑术";  jineng[e][gl ].jilei=2; jineng[e][gl ].cc1="以后训练士兵的攻击力增加18%           "; 
		gl++;jineng[e][gl ].xue=41;  jineng[e][gl ].gong=0;     jineng[e][gl ].shu=0;  jineng[e][gl ].qian=1600; jineng[e][gl ].c="镶皮甲";  jineng[e][gl ].jilei=2; jineng[e][gl ].cc1="以后训练士兵的防御力增加41%           ";
		gl++;jineng[e][gl ].xue=0;   jineng[e][gl ].gong=0;     jineng[e][gl ].shu=40; jineng[e][gl ].qian=1200; jineng[e][gl ].c="迅捷！";  jineng[e][gl ].jilei=2; jineng[e][gl ].cc1="以后训练士兵的速度加40%（不能超过100）";
		
		jineng[e][1001].xue=100;   jineng[e][1001].gong=0;     jineng[e][1001].shu=1 ;   jineng[e][1001].lei=1001;jineng[e][1001].ggb=' '; jineng[e][1001].qian=3000;
		jineng[e][1002].xue=100;   jineng[e][1002].gong=0;     jineng[e][1002].shu=1 ;   jineng[e][1002].lei=1002;jineng[e][1002].ggb=' '; jineng[e][1002].qian=5000;
		
		jinenggainv[e][0]=gl;
		for (int i=1;i<=jinenggainv[e][0];i++){jinenggainv[e][i]=i;}
		sort(jineng[e]+1,jineng[e]+gl+1,cmp);
	}
	aj[1][1]='U',aj[1][2]='I',aj[1][3]='O',aj[1][4]='P',aj[1][5]='J',aj[1][6]='K';
	aj[2][1]='1',aj[2][2]='2',aj[2][3]='3',aj[2][4]='4',aj[2][5]='5',aj[2][6]='6';
	
	
	for (int i=1;i<=2;i++)gongjia[i]=xuejia[i]=qianjia[i]=shujia[i]=1.0;
}
//newg(int x1,int y1,int xue,int lei,int shu,int zhen,int gong,int ggb)

void shenchengjianzhu(int jianzhushu,int jianzhulei,int x1,int x2,int y1,int y2)
{
	int jianzhu=0;
	while (jianzhu<jianzhushu){
		int x,y;
		if (x1==-1)x=ran(42,120),y=ran(1,49);
		else       x=ran(x1,x2),y=ran(y1,y2);
		if (map[x][y]==0&&map[x+1][y]==0){
			jianzhu++;
			if (jianzhulei==100&&ran(1,3)!=1){
				newg(x    ,y   ,1000,jianzhulei,100,3,1,1);
				newg(234-x,50-y,1000,jianzhulei,100,3,1,1);
			}else{
				newg(x    ,y   ,1000,jianzhulei,100,1,1,1);
				newg(234-x,50-y,1000,jianzhulei,100,2,1,1);
			}
		}
	}
}
void shuijiditu()
{
	qingmap();
	//117.5为中线 25为中线 
	for (int i=42;i<=193;i++){
		for (int j=1;j<=49;j++){
			if (i<=117.5){
				if (ran(1,6)==1)map[i][j]=1;else map[i][j]=0;
			}
			else map[i][j]=map[int(117.5-(i-117.5))][int (25-(j-25))];
		}
	}
	shuchuditu();
	shenchengjianzhu(3,101,-1,-1,-1,-1);
	shenchengjianzhu(15,100,-1,-1,-1,-1);
	shenchengjianzhu(1,102,-1,-1,-1,-1);
}
char ss[1100];
void duruditu()
{
	qingmap();
	freopen("map.tk","r",stdin);
	gets(ss+1);
	for (int i=1;i<=49;i++){
		gets(ss+1);
		for (int j2=3;j2<=154;j2++){
			int j=j2-2;
			if (ss[j2]=='*'){
				map[j+41][i]=1;
			}
		}
	}
	shuchuditu();
	shenchengjianzhu(3,101,42,193,1,24);
	shenchengjianzhu(15,100,-1,-1,-1,-1);
	shenchengjianzhu(1,102,42,193,1,24);
	fclose(stdin);
}
/*
void chubin()
{

	int pt;
	
	if (check(aj[1][1])&&jw[aj[1][1]]==false){
		if (qian[1]>=bqian[1][1]){
			Dbin(1,1);
			qian[1]-=bqian[1][1];
			jw[aj[1][1]]=true;
		}
	}
	if (check(aj[1][2])&&jw[aj[1][2]]==false){
		if (qian[1]>=bqian[1][2]){
			Dbin(2,1);
			qian[1]-=bqian[1][2];
			jw[aj[1][2]]=true;
		}
	}
	if (check(aj[1][3])&&jw[aj[1][3]]==false){
		if (qian[1]>=bqian[1][3]){
			Dbin(3,1);
			qian[1]-=bqian[1][3];
			jw[aj[1][3]]=true;
		}
	}
	if (check(aj[1][4])&&jw[aj[1][4]]==false){
		if (qian[1]>=bqian[1][4]){
			Dbin(4,1);
			qian[1]-=bqian[1][4];
			jw[aj[1][4]]=true;
		}
	}
}*/
void qingzt()//清空状态栏
{
		for (int i=2;i<=49;i++){go(0,i);printf("                                        ");}
}
int lztl=0,maxx;
//jineng jilu[11][11];当前技能状态 (在参数里)
bool gengxin[11];
int diannaochubin[11];
void ztl(int zhenyin)
{	
	int dianl=0;
	if (diannao[zhenyin]){dianl=1;}
	int wt=0;//第一行的位置 
	if (zhenyin==2)wt=19;
	if (dianl==0){
		for (int i=1;i<=5;i++){
			if (check(aj[zhenyin][i])&&jw[aj[zhenyin][i]]==false||check(aj[zhenyin][i]+48)&&jw[aj[zhenyin][i]+48]==false){
				if (qian[zhenyin]>=jilu[zhenyin][i].qian){
					if (jilu[zhenyin][i].jilei==1)for (int j=1;j<=jilu[zhenyin][i].shuliang;j++)Dbin(zhenyin,i);
					if (jilu[zhenyin][i].jilei==2){xuejia[zhenyin]+=jilu[zhenyin][i].xue/100.0;gongjia[zhenyin]+=jilu[zhenyin][i].gong/100.0;shujia[zhenyin]+=jilu[zhenyin][i].shu/100.0;}
					qian[zhenyin]-=jilu[zhenyin][i].qian;
					//jw[aj[zhenyin][i]]=true;
					gengxin[zhenyin]=true;
				}
				break;
			}
		}
	}
	else{
		int i=diannaochubin[zhenyin];
		if (qian[zhenyin]>=jilu[zhenyin][i].qian){
			if (jilu[zhenyin][i].jilei==1)for (int j=1;j<=jilu[zhenyin][i].shuliang;j++)Dbin(zhenyin,i);
			if (jilu[zhenyin][i].jilei==2){xuejia[zhenyin]+=jilu[zhenyin][i].xue/100.0;gongjia[zhenyin]+=jilu[zhenyin][i].gong/100.0;shujia[zhenyin]+=jilu[zhenyin][i].shu/100.0;}
			qian[zhenyin]-=jilu[zhenyin][i].qian;
			//jw[aj[zhenyin][i]]=true;
			gengxin[zhenyin]=true;
			diannaochubin[zhenyin]=ran(1,5); 
		}
	}
	if (gengxin[zhenyin]){
		for (int i=1;i<=5;i++){
			int ll=1,rr=1;
			for (int ii=1;ii<=jinenggainv[zhenyin][0];ii++){
				if (jineng[zhenyin][ii].qian<=qian[zhenyin]+qianj[zhenyin]*45)ll=ii;
				if (jineng[zhenyin][ii].qian<=qian[zhenyin]+qianj[zhenyin]*75)rr=ii;
			}
			jilu[zhenyin][i]=jineng[zhenyin][ran(ll,rr)];
			if (jilu[zhenyin][i].jilei==1) {
				jilu[zhenyin][i].qian=ran(int(jilu[zhenyin][i].qian*0.8*qianjia[zhenyin]),int(jilu[zhenyin][i].qian*1.2*qianjia[zhenyin]));
				jilu[zhenyin][i].gong=ran(int(jilu[zhenyin][i].gong*0.8*gongjia[zhenyin]),int(jilu[zhenyin][i].gong*1.2*gongjia[zhenyin]));
				jilu[zhenyin][i].xue =ran(int(jilu[zhenyin][i].xue *0.8*xuejia [zhenyin]),int(jilu[zhenyin][i].xue *1.2*xuejia [zhenyin]));
				jilu[zhenyin][i].shu =int(jilu[zhenyin][i].shu*shujia[zhenyin]);if (jilu[zhenyin][i].shu>100)jilu[zhenyin][i].shu=100;
			}
		}
		int pt;
		
		for (int i=1;i<=5;i++){
			if (jilu[zhenyin][i].jilei==1){
				//string ssl;if (jilu[zhenyin][i].shuliang!=1){ssl[0]='*';ssl[1]='0'+jilu[zhenyin][i].shuliang%10;if (jilu[zhenyin][i].shuliang>=10)ssl[2]='0'+jilu[zhenyin][i].shuliang/10;}
				go(0,wt+3*i); printf("%c.%s*%d %5d元                \n攻击：%4d 速度：%3d 血量：%5d    ",aj[zhenyin][i],jilu[zhenyin][i].c.c_str(),jilu[zhenyin][i].shuliang,jilu[zhenyin][i].qian,jilu[zhenyin][i].gong,jilu[zhenyin][i].shu,jilu[zhenyin][i].xue);
			}
			if (jilu[zhenyin][i].jilei==2){
				go(0,wt+3*i); printf("%c.%s %5d元  \n %s",aj[zhenyin][i],jilu[zhenyin][i].c.c_str(),jilu[zhenyin][i].qian,jilu[zhenyin][i].cc1.c_str());
			}
		}
		gengxin[zhenyin]=false;
		
		go(0,wt+18);
		printf("攻击力加成：%d%% 血量加成：%d%%\n钱加成：%d%% 速度加成：%d%%",int (gongjia[zhenyin]*100),int (xuejia[zhenyin]*100),int (qianjia[zhenyin]*100),int(shujia[zhenyin]*100));
	}
	if (dianl==0){
		if (zhenyin==1) for (int i='A';i<='Z';i++)if (check(i))jw[i]=true;else jw[i]=false;
		if (zhenyin==2){for (int i='1';i<='9';i++)if (check(i))jw[i]=true;else jw[i]=false;
						for (int i=96;i<=105 ;i++)if (check(i))jw[i]=true;else jw[i]=false;
		}
	}
	
	
}



void youxi()
{
	ckdx(ddlie+1,ddhang);
	Movew(0,0);
	shuijiditu();
	cch();
	diannaochubin[1]=diannaochubin[2]=1;
	//diannao[1]=diannao[2]=true;
	
	gengxin[1]=gengxin[2]=true;
	go(0,50);printf("作者：李泽刚");		
	go(0,0);printf("你的钱：                   ");
	go(0,1);printf("敌人的钱：                 ");
	shuchu=true;
	xianshi=1;
	while (1){ 
		//if (tk%10==0)Djian(101,1,ran(43,192),ran(2,49));
		maxx=0;
		int tx,ty;
		tx=clock();
		xinjun();
		jia(tk);
		
		ty=clock();
		if (ty-tx<=300)Sleep(300-(ty-tx));

		go(0,49);printf("%d    ",ty-tx);ztl(1);ztl(2);
		go(10,0);printf("%d(+%d)    ",qian[1],qianj[1]);ztl(1);ztl(2);
		go(10,1);printf("%d(+%d)    ",qian[2],qianj[2]);ztl(1);ztl(2);
		memset(qianj,0,sizeof(qianj));
	}
}
