#include<bits/stdc++.h>
#include<conio.h>
#define mp make_pair
#include<fstream>
#include<windows.h>
using namespace std;
int mny[]={1,4,10,60,250,800};
int expr[]={1,2,5,13,47,123};
int am[]={2,7,20,100,400,1000};
int enoexp[]={0,25,90,750,2400,7500,2147483647};
int costjv[]={40,150,500,1600,10000,40000}; 
string s[]={"骷髅","野蛮人","弓箭手","骑兵","机枪手","坦克"};
pair<int,int> take[6][6]={{{1,1},{1,3},{1,10},{1,40},{1,1000},{1,600}},{{3,1},{1,1},{4,11},{1,20},{1,100},{1,258}},{{10,1},{11,4},{1,1},{3,4},{2,53},{1,124}},{{40,1},{20,1},{4,3},{1,1},{1,23},{1,59}},{{1000,1},{80,1},{53,2},{23,1},{1,1},{1,5}},{{600,1},{258,1},{124,1},{59,1},{5,1},{1,1}}};
int mmax[6][6]={{15,0,0,0,0,0},{20,12,0,0,0,0},{30,20,12,0,0,0},{70,50,30,12,0,0},{200,120,90,52,31,0},{10000,10000,10000,10000,10000,10000}};
int mmin[6][6]={{10,0,0,0,0,0},{15,8,0,0,0,0},{20,15,10,0,0,0},{60,35,20,10,0,0},{150,100,60,30,20,0},{580,350,120,70,40,20}};
struct Monster{
	int a[6];
	int gsp;
	Monster(){}
	inline void init(int level){
		if(level==5) gsp=rand()%5+1;
		else if(level==6) gsp=rand()%10+5;
		else gsp=0;
		for(int i=0;i<level;++i) a[i]=max(mmin[level-1][i],rand()%mmax[level-1][i]); 
	}
	inline bool die(int level){
		for(int i=0;i<level;++i) if(a[i]!=0) return 0;
		return 1;
	}
};
struct Player{
	int level,exp,money;
	int fj,gsp;
	bool openkx;
	int a[6];
	int add[6];
	Player(){}
	bool isqj,ishh;
	inline void init(){
		a[0]=200;
		add[0]=5;
		isqj=1;
		ishh=1;
		level=1;
		exp=0;
		money=100;
		fj=0;
		gsp=0;
	}
	inline void show(){
		cout<<"------------------------------------------------------\n";
		cout<<"Money: "<<money<<"\nlevel: "<<level<<"\nexp: "<<exp<<endl; 
		cout<<"我方：\n";
		if(level>=5){
			cout<<"飞机:"<<fj<<"  高射炮:"<<gsp<<endl;
		}
		for(int i=0;i<level;++i) cout<<s[i]<<"\t\t";
		cout<<endl;
		for(int i=0;i<level;++i) cout<<a[i]<<"\t\t";
		cout<<endl;
		cout<<"------------------------------------------------------\n";
	}
	inline void _show(Monster t){
		cout<<"------------------------------------------------------\n";
		cout<<"我方：\n";
		if(level>=5){
			cout<<"飞机:"<<fj<<"  高射炮:"<<gsp<<endl;
		}
		for(int i=0;i<level;++i) cout<<s[i]<<"\t\t";
		cout<<endl;
		for(int i=0;i<level;++i) cout<<a[i]<<"\t\t";
		cout<<endl;
		cout<<"------------------------------------------------------\n";
		cout<<"敌方：\n";
		if(level>=5){
			cout<<"高射炮:"<<t.gsp<<endl;
		}
		for(int i=0;i<level;++i) cout<<s[i]<<"\t\t";
		cout<<endl;
		for(int i=0;i<level;++i) cout<<t.a[i]<<"\t\t";
		cout<<endl;
		cout<<"------------------------------------------------------\n";
	}
	inline bool die(){
		for(int i=0;i<level;++i) if(a[i]) return 0;
		return 1;
	}
	inline void fight(){
		cout<<"------------------------------------------------------\n";
		cout<<"您开始了战斗\n";
		system("pause");
		Monster N;
		bool taop=0;
		N.init(level);
		for(int i=0;i<level;++i) a[i]+=add[i]; 
		if(openkx){
			cout<<"是否使用空袭?是：输入1   否：输入0\n";
			int t;
			cin>>t;
			while(t<0 or t>1){
				cout<<"again!\n";
				cin>>t;
			} 
			if(t){
				if(N.gsp>fj){
					cout<<"由于对方的高射炮大于你的飞机数，空袭失败,飞机减少2/3！\n";
					fj=fj/3;
				}else{
					cout<<"空袭成功,飞机减少1/3！\n";
					fj=fj*2/3;
					for(int i=0;i<6;++i) a[i]=a[i]*2/5;
				}
			}
		}
		while(1){
			if(die()){
				cout<<"骚年，你都没有人了还来打架？？？\n";
				break;
			}
			if(isqj){
				cout<<"是否全局逃跑？逃跑输入1，否则输入0。逃跑时每一只部队都减少它的1/3\n";
				int ttttt;
				cin>>ttttt;
				if(ttttt){
					for(int i=0;i<level;++i) a[i]=a[i]*2/3;
					taop=1;
					break;
				}			
			}
			_show(N);
			cout<<"您要用第几只部队出阵？\n";
			int t;
			cin>>t;
			while(t<1 or t>level or !a[t-1]){
				cout<<"输入错误。请再一次输入\n"; 
				cin>>t;
			}
			--t;
			int df=rand()%level;
			while(!N.a[df]) df=rand()%level;
			++df;
			cout<<"敌方使用了第"<<df<<"号部队\n";
			--df;
/*			#ifdef LOCAL
				cout<<"我方:"<<s[t]<<" 敌方:"<<s[df]<<"  "<<a[t]<<" "<<N.a[df]<<" "<<take[t][df].first<<" "<<take[t][df].second<<" "<<a[t]/take[t][df].first<<" "<<N.a[df]/take[t][df].second<<endl;
			#endif 
*/			if(ishh){
				cout<<"请问是否逃跑？逃跑回合输入1，否则输入0。逃跑有80%的概率成功，否则此部队全军覆没！！！\n";
				int ttt;
				cin>>ttt;
				if(ttt){
					int t=rand()%10;
					if(t<8){
						cout<<"恭喜你，逃跑成功！！！\n";
						continue;
					}else{
						cout<<"很遗憾，逃跑失败\n";
						a[t]=0;
						continue;
					}
				} 			
			}
			int mys=a[t]/take[t][df].first;
			int dfs=N.a[df]/take[t][df].second;
			if(mys>dfs){
				cout<<"恭喜你，你嬴了!!!\n";
				a[t]-=N.a[df]*take[t][df].first/take[t][df].second;
				exp+=N.a[df]*expr[df];
				money+=am[df]*N.a[df];
				N.a[df]=0;
			}else if(mys==dfs){
				cout<<"两败俱伤\n";
				a[t]=0;
				exp+=N.a[df]*expr[df];
				money+=am[df]*N.a[df];
				N.a[df]=0;
			}else{
				cout<<"很遗憾，你输了\n";
				exp+=mys*take[t][df].second*expr[df];
				money+=mys*take[t][df].second*am[df];
				N.a[df]-=a[t]*take[t][df].second/take[t][df].first;
				a[t]=0;
			}
			if(die()) break;
			if(N.die(level)) break;
		}
		cout<<"------------------------------------------------------\n";
		if(die()){
			cout<<"骚年，你输了，下次再来\n";
			while(exp>=enoexp[level]){
				system("cls");
				cout<<"level up!\n";
				exp-=enoexp[level];	
				++level;
				a[level-1]=150;
				add[level-1]=5;
				show();
			}
			return; 
		}else if(N.die(level)){
			cout<<"恭喜你，你赢了\n";
			while(exp>=enoexp[level]){
				system("cls");
				cout<<"level up!\n";
				exp-=enoexp[level];	
				++level;
				a[level-1]=150;
				add[level-1]=5;
				show();
			}
		}else{
			cout<<"当个逃兵很光荣吗????????????????????????????????????\n";
			while(exp>=enoexp[level]){
				system("cls");
				cout<<"level up!\n";
				exp-=enoexp[level];	
				++level;
				a[level-1]=150;
				add[level-1]=5;
				show();
			}
		}
	}
	inline void shop(){
		show();
		cout<<endl; 
		cout<<"--------------------------------------------------------\n商品：\n Name:\t\t";
		for(int i=0;i<level;++i) cout<<s[i]<<"\t\t";
		cout<<endl<<" Cost:\t\t";
		for(int i=0;i<level;++i) cout<<mny[i]<<"\t\t";
		cout<<endl;
		cout<<"--------------------------------------------------------\n\n";
		cout<<"What do you want to buy and how many?\n";
		cout<<"输入 :     序号 数量\n";
		cout<<"假设你要买2个野蛮人：\n";
        cout<<"输入:        1 2\n";
        cout<<"第1个数位序号，第2个数为买的个数\n";
        cout<<"第一个数输入-1:退出(此时仍然要输入第2个数！！！)";
		int t1,t2;
		cin>>t1>>t2;
		while((t1<1 or t1>level) and t1!=-1){
			cout<<"again!!!\n";
			cin>>t1>>t2;
		}
		if(t1==-1) return; 
		--t1;
		if(t2*mny[t1]>money){
			cout<<"你没有那么多钱\n";
			return;
		}
		cout<<"购买成功！！！\n";
		money-=t2*mny[t1];
		a[t1]+=t2;
	}
	inline void kxxl(){
		show();
		cout<<"商品名称：\n轰炸机：空袭专用     高射炮：反空袭\n ";
		cout<<"价格：    \n2000                 3500\n";
		cout<<"输入要买的商品的序号（从1开始）和购买数量，不想买输入-1 0\n";
		int t1,t2;
		cin>>t1>>t2;
		if(t1==-1) return;
		while((t1<1 or t1>2) and t1!=-1){
			cout<<"again!\n";
			cin>>t1>>t2;
		}
		if(t1==-1) return;
		if(t1==1){
			if(money<2000*t2){
				cout<<"钱不够\n";
				return;
			}else{
				cout<<"OK\n";
				money-=2000*t2;
				fj+=t2;
			}
		}
		if(t1==2){
			if(money<3500*t2){
				cout<<"钱不够\n";
				return;
			}else{
				cout<<"OK\n";
				money-=3500*t2;
				fj+=t2;
			}
		}
	}
	inline void addjy(){
		cout<<"--------------------------------------------------------\n Name:\t\t";
		for(int i=0;i<level;++i) cout<<s[i]<<"军营\t\t";
		cout<<endl<<" Cost:\t\t";
		for(int i=0;i<level;++i) cout<<costjv[i]<<"\t\t";
		cout<<endl;
		cout<<"输入你想升级的军营的序号（从1开始）-1:退出\n";
		int t;
		cin>>t;
		while((t<1 or t>level) and t!=-1){
			cout<<"again!\n";
			cin>>t;
		}
		if(t==-1) return;
		--t;
		if(money<costjv[t]){
			cout<<"你没有那么多钱\n";
			return;
		}
		cout<<"购买成功！！！\n";
		money-=costjv[t];
		add[t]+=5;
	}
	inline void set(){
		cout<<"1:开/关全局逃跑 2:开/关回合逃跑 -1:退出";
		int t;
		cin>>t;
		while(t!=1 and t!=2 and t!=-1){
			cout<<"again!\n";
			cin>>t;
		}
		if(t==-1) return;
		if(t==1) isqj=1-isqj;
		else ishh=1-ishh;
		cout<<"OK!\n";
		set();
	}
	inline void jj(){
		cout<<"--------------------------------------------------------\n";
		cout<<"level 1 骷髅:人海战术的最佳选择\n\nlevel 2 野蛮人:玩过皇室战争的人都知道（单伤）\n\nlevel 3 弓箭手:单伤，远程\n\nlevel 4 骑兵:类似于皇室战争中的王子，单伤\n\nlevel 5 机枪手:群伤，克人海(骷髅们)\n\nlevel 6 坦克：肉盾，碾压一切\n\n";
		cout<<"--------------------------------------------------------\n";
	}
}player;
int openmh=0;
struct zbg{
	zbg(){}
	char c[16][16];
	long long a[16][16];
	const long long n=16;
	long long x,y,tx,ty;
	long long money=1000;
	long long healthy=380;
	vector<pair<long long,long long> >bombs;
	inline void go(){
	    cout<<"Game over!\n";
	    exit(0);
	}
	struct zb{
	    long long x,y;
	    long long healthy;
	    long long money;
	    long long bos;
	};
	vector<zb> zbs;
	vector<pair<pair<long long,long long>,long long> >zds;
	long long dx[4]={1,-1,0,0};
	long long dy[4]={0,0,1,-1};
	long long at=10;
	inline void sczb(){
	    zb t;
	    t.x=rand()%n;
	    t.y=rand()%n;
	    while(c[t.x][t.y]!='.') t.x=rand()%n,t.y=rand()%n;
	    t.healthy=150;
	    t.money=(rand()%200+50);
	    t.bos=0;
	    zbs.push_back(t);
	//  cout<<t.x<<' '<<t.y<<endl;
	    c[t.x][t.y]='z';
	}
	inline void print(){
	    cout<<"p:商店 b：放炸弹 f:点爆炸弹 o:开门 c：关门 上下左右键跑 e:删除方块 \nZ:大僵尸 z:小僵尸 打僵尸可获得钱，大僵尸多，小僵尸少 $:死尸，过一会自动删除\nWASD发射子弹 子弹2元一个\n";
	    cout<<"r:返回战争世界";
		cout<<"制作人：洛谷万岁\n";
	    cout<<"有彩蛋！\n";
	    if(c[x][y]=='.') c[x][y]='@';
	    for(long long i=0;i<zbs.size();++i){
	        if(zbs[i].bos==0) c[zbs[i].x][zbs[i].y]='z';
	        else c[zbs[i].x][zbs[i].y]='Z';
	    }
	    for(long long i=0;i<n;++i){
	        for(long long j=0;j<n;++j){
	            cout<<c[i][j];
	            if(c[i][j]=='$'){
	                if(rand()%30==1) c[i][j]='.';
	            }
	        }
	        cout<<endl;
	    }
	    cout<<"Money: "<<money<<endl;
	    cout<<"Healthy: "<<healthy<<endl;
	    cout<<"Attect: "<<at<<endl;
	    cout<<"X :"<<x<<' '<<"Y: "<<y<<endl;
	    cout<<"Zonbies: \n";
	    for(long long i=0;i<zbs.size();++i) cout<<zbs[i].healthy<<' '<<zbs[i].x<<' '<<zbs[i].y<<' '<<zbs[i].money<<endl;
	    cout<<endl;
	}
	inline void scjg(){
	    system("cls");
	    cout<<"巨怪出现！"; 
	    system("pause");
	    zb t;
	    t.x=rand()%n;
	    t.y=rand()%n;
	    while(c[t.x][t.y]!='.') t.x=rand()%n,t.y=rand()%n;
	    t.healthy=2000+rand()%1000+300;
	    t.money=(rand()%600+222);
	    t.bos=1;
	    zbs.push_back(t);
	//  cout<<t.x<<' '<<t.y<<endl;
	    c[t.x][t.y]='Z';
	}
	inline void mvzd(pair<pair<long long,long long>,long long>& t){
	    if(t.first.first+dx[t.second]<0||t.first.first+dx[t.second]==n||t.first.second+dy[t.second]==0||t.first.second+dy[t.second]==n){
	        c[t.first.first][t.first.second]='.';
	        return;
	    }
	    if(c[t.first.first+dx[t.second]][t.first.second+dy[t.second]]!='.'){
	        if(c[t.first.first+dx[t.second]][t.first.second+dy[t.second]]=='z'){
	            for(long long i=0;i<zbs.size();++i){
	                if(zbs[i].x==t.first.first+dx[t.second]&&zbs[i].y==t.first.second+dy[t.second]){
	                    zbs[i].healthy-=(17+at);
	                    if(zbs[i].healthy<=0){
	                        money+=zbs[i].money;
	                        c[zbs[i].x][zbs[i].y]='.';
	                        zbs.erase(zbs.begin()+i);
	                    } 
	                }
	            }
	            return;
	        }
	        c[t.first.first][t.first.second]='.';
	        return;
	    }
	    swap(c[t.first.first+dx[t.second]][t.first.second+dy[t.second]],c[t.first.first][t.first.second]);
	    t.first.first+=dx[t.second];
	    t.first.second+=dy[t.second];
	    return;
	}
	inline void move(long long tt){
	    long long i,j,Tx,Ty,A,B,C,D;
	    pair<long long,long long> w[4];
	    string s;
	    bool att=0;
	    for(i=0;i<4;++i){
	        Tx=x+dx[i];
	        Ty=y+dy[i];
	        if(Tx<0||Tx==n||Ty<0||Ty==n) continue;
	        if(Tx==zbs[tt].x&&Ty==zbs[tt].y){
	            healthy-=(rand()%20+5);
	            att=1;
	        }
	        if(healthy<=0){
	            go();
	        }
	    }
	//  cout<<"E : "<<tt<<' '<<zbs[tt].x<<' '<<zbs[tt].y<<endl;
	    if(att) return;
	    bool mv=0;
	    A=x-zbs[tt].x;
	    B=zbs[tt].x-x;
	    C=y-zbs[tt].y;
	    D=zbs[tt].y-y;
	    w[0]=mp(A,0);
	    w[1]=mp(B,1);
	    w[2]=mp(C,2);
	    w[3]=mp(D,3);
	//  cout<<"E2: "<<A<<' '<<B<<' '<<C<<' '<<D<<endl;
	    sort(w,w+4);
	    reverse(w,w+4);
	//  cout<<w[0].first<<' '<<w[0].second<<' '<<w[1].first<<' '<<w[1].second<<endl;
	    for(i=0;i<2&&!mv;++i){
	        if(zbs[tt].x+dx[i]<0||zbs[tt].x+dx[i]>=n||zbs[tt].y+dy[i]<0||zbs[tt].y+dy[i]>=n) continue;
	        if(c[zbs[tt].x+dx[w[i].second]][zbs[tt].y+dy[w[i].second]]!='.') continue;
	//      cout<<"OK"<<i<<endl;
	//      cout<<w[i].first<<' '<<w[i].second<<endl;
	        if(w[i].second==0) zbs[tt].x++,swap(c[zbs[tt].x][zbs[tt].y],c[zbs[tt].x-1][zbs[tt].y]),mv=1;
	        if(w[i].second==1) zbs[tt].x--,swap(c[zbs[tt].x][zbs[tt].y],c[zbs[tt].x+1][zbs[tt].y]),mv=1;
	        if(w[i].second==2) zbs[tt].y++,swap(c[zbs[tt].x][zbs[tt].y],c[zbs[tt].x][zbs[tt].y-1]),mv=1;
	        if(w[i].second==3) zbs[tt].y--,swap(c[zbs[tt].x][zbs[tt].y],c[zbs[tt].x][zbs[tt].y+1]),mv=1;
	//      system("cls");
	//      prlong long();
	    }
	//  cout<<"OK"<<endl;
	}
	inline void shop(){
	    system("cls");
	    cout<<"1.增加攻击力\n";
	    cout<<"2.增加血量\n"; 
	    cout<<"3.增加僵尸\n";
	    cout<<"4.退出\n"; 
	    long long kind;
	    cin>>kind;
	    if(kind==1){
	        cout<<"输入增加的攻击力，每一个攻击力9元\n";
	        long long mny;
	        cin>>mny;
	        if(money<mny*9){
	            cout<<"钱不够\n";
	            shop();
	            return;
	        } 
	        money-=mny*9;
	        at+=mny;
	        shop();
	        return;
	    }else if(kind==2){
	        cout<<"输入增加的攻击力，每一个血量2元\n";
	        long long mny;
	        cin>>mny;
	        if(money<mny*2){
	            cout<<"钱不够\n";
	            shop();
	            return;
	        }
	        money-=mny*2;
	        healthy+=mny;
	        shop();
	        return;
	    }else if(kind==3){
	        cout<<"30元，随机放置，僵尸可掉钱\n";
	        bool by=0;
	        cout<<"买选1，不买选0\n";
	        cin>>by;
	        if(!by) shop();
	        if(money<30){
	            cout<<"钱不够\n";
	            shop();
	            return;
	        } 
	        money-=30;
	        sczb();
	        shop(); 
	        return;
	    }else{
	        return;
	    }
	} 
	inline Player gd(Player a){
		money=a.money;
		char ch;
	    bool fd=0;
	    long long i,j,k;
	    for(i=0;i<n;++i) for(j=0;j<n;++j) c[i][j]='.';
	    x=4;
	    y=9;
	    c[x][y]='@';
	    c[3][7]='-';
	    c[3][8]='-';
	    c[3][9]='-';
	    c[3][10]='-';
	    c[3][11]='-';
	    c[4][11]='|';
	    c[5][11]='-';
	    c[5][10]='-';
	    c[5][9]='-';
	    c[5][8]='-';
	    c[5][7]='-';
	    c[4][6]='+';
	    c[5][6]='-';
	    c[3][6]='-';
	    zbs.clear();
	    while(1){
	        system("cls");
	        print();
	//      cout<<zbs.size()<<endl;
	        if(!fd&&c[x][y]!='@'){
	            cout<<"How clever you are!\n";
	            cout<<"彩蛋出现!\n";
	            system("pause");
	            money+=10000;
	            at+=30;
	            healthy+=1000;
	            fd=1;
	            continue;
	        }
	        if(rand()%300==32){
	            scjg();
	            continue;
	        } 
	        if(rand()%80==1){
	            sczb();
	            continue;
	        }
	        tx=x,ty=y;
	        ch=getch();
	        if(ch==72||ch==80||ch==75||ch==77){
	            if(ch==72) tx--;
	            else if(ch==80) tx++;
	            else if(ch==75) ty--;
	            else if(ch==77) ty++;
	            if(tx==n) continue;
	            if(ty==n) continue;
	            if(tx==-1) continue;
	            if(ty==-1) continue;
	            if(c[tx][ty]=='.') swap(c[x][y],c[tx][ty]),x=tx,y=ty;
	            if(c[tx][ty]=='z'||c[tx][ty]=='Z'){
	                for(j=0;j<zbs.size();++j) if(zbs[j].x==tx&&zbs[j].y==ty){
	                    zbs[j].healthy-=(rand()%30+at);
	                    if(zbs[j].healthy<=0){
	                        c[zbs[j].x][zbs[j].y]='$';
	                        money+=zbs[i].money;
	                        zbs.erase(zbs.begin()+j);
	                    }
	                }
	                continue;
	            }
	            continue;
	        }
	        if(ch==111){
	            c[5][6]='+';
	            c[4][6]='.';
	            c[5][5]='-';
	            c[5][4]='+';
	            continue;
	        }
	        if(ch==99){
	            c[5][6]='-';
	            c[5][5]='.';
	            c[5][4]='.';
	            c[4][6]='+';
	            continue;
	        }
	        if(ch==98){
	            if(money<150){
	                cout<<"Money is not Enough\n";
	                system("pause");
	                continue;
	            }
	//          bombs.push_back(mp(x,y));
	            bool ok=0;
	            for(i=0;i<4;++i){
	                if(x+dx[i]<n&&x+dx[i]>=0&&y+dy[i]<n&&y+dy[i]>=0&&c[x+dx[i]][y+dy[i]]=='.'){
	                    x=x+dx[i];
	                    y=y+dy[i];
	                    c[x][y]='@';
	                    c[x-dx[i]][y-dy[i]]='.';
	                    ok=1;
	                    break;
	                }
	            }
	            if(!ok){
	                cout<<"Can not put the bomb\n";
	                system("pause");
	//              bombs.pop_back();
	                continue;
	            }else{
	                c[x-dx[i]][y-dy[i]]='#';
	                money-=150;
	            }
	            continue;
	        }
	        if(ch==101){
	            long long a,b;
	            cout<<"输入要打掉的方块的坐标(不能是僵尸)\n";
	            cin>>a>>b;
	            if(money<20){
	                cout<<"Can not erase the cub\n";
	                system("pause");
	                continue;
	            }
	            c[a][b]='.';
	            money-=20;
	            continue;
	        }
	        if(ch==102){
	            long long xx,yy,t;
	            cout<<"输入要引爆的炸弹的位置\n";
	            cin>>xx>>yy;
	            if(c[xx][yy]!='#'){
	                cout<<"Wrong Input\n";
	                system("pause");
	                continue;
	            }
	
	//          bombs.erase(bombs.begin()+t);
	            for(i=xx-2;i<=xx+2;++i){
	                for(j=yy-2;j<=yy+2;++j){
	                    if(i<0||x>n-1||j<0||j>n-1) continue;
	                    if(c[i][j]=='z'){
	                        for(k=0;k<zbs.size();k++){
	                            if(zbs[k].x==i&&zbs[k].y==j){
	                                zbs[k].healthy-=100;
	                                if(zbs[k].healthy<=0){
	                                    money+=zbs[k].money;
	                                    c[zbs[k].x][zbs[k].y]='$';
	                                    zbs.erase(zbs.begin()+k);
	                                    k--;
	                                }
	                            }
	                        }
	                    }else if(c[i][j]=='@'){
	                        if(healthy<=100){
	                            go();
	                        }
	                        healthy-=100;
	                    }else{
	                        c[i][j]='.';
	                    }
	                }
	            }
	            continue;
	        }
	        if(ch==112){
	            shop();
	            continue;
	        }
	        if(ch==115){
	            if(money<2) continue;
	            if(c[x+dx[0]][y+dy[0]]=='z'||c[x+dx[0]][y+dy[0]]=='Z'){
	                for(i=0;i<zbs.size();++i){
	                    if(zbs[i].x==x+dx[0]&&zbs[i].y==y+dy[0]){
	                        zbs[i].healthy-=(22+at);
	                        if(zbs[i].healthy<=0){
	                            money+=zbs[i].money;
	                            c[zbs[i].x][zbs[i].y]='$';
	                            zbs.erase(zbs.begin()+i);
	                        }
	                    }
	                }
	            }
	            money-=2;
	            if(c[x+dx[0]][y+dy[0]]!='.') continue;
	            c[x+dx[0]][y+dy[0]]='`';
	            zds.push_back(mp(mp(x+dx[0],y+dy[0]),0));
	            continue;
	        }
	        if(ch==100){
	            if(money<2) continue;
	            if(c[x+dx[2]][y+dy[2]]=='z'||c[x+dx[2]][y+dy[2]]=='Z'){
	                for(i=0;i<zbs.size();++i){
	                    if(zbs[i].x==x+dx[2]&&zbs[i].y==y+dy[2]){
	                        zbs[i].healthy-=(22+at);
	                        if(zbs[i].healthy<=0){
	                            money+=zbs[i].money;
	                            c[zbs[i].x][zbs[i].y]='$';
	                            zbs.erase(zbs.begin()+i);
	                        }
	                    }
	                }
	            }
	            money-=2;
	            if(c[x+dx[2]][y+dy[2]]!='.') continue;
	            c[x+dx[2]][y+dy[2]]='`';
	            zds.push_back(mp(mp(x+dx[2],y+dy[2]),2));
	            continue;
	        }
	        if(ch==119){
	            if(money<2) continue;
	            money-=2;
	            if(c[x+dx[1]][y+dy[1]]!='.') continue;
	            if(c[x+dx[1]][y+dy[1]]=='z'||c[x+dx[1]][y+dy[1]]=='Z'){
	                for(i=0;i<zbs.size();++i){
	                    if(zbs[i].x==x+dx[1]&&zbs[i].y==y+dy[1]){
	                        zbs[i].healthy-=(22+at);
	                        if(zbs[i].healthy<=0){
	                            money+=zbs[i].money;
	                            c[zbs[i].x][zbs[i].y]='$';
	                            zbs.erase(zbs.begin()+i);
	                        }
	                    }
	                }
	            }
	            c[x+dx[1]][y+dy[1]]='`';
	            zds.push_back(mp(mp(x+dx[1],y+dy[1]),1));
	            continue;
	        }
	        if(ch==97){
	            if(money<2) continue;
	            money-=2;
	            if(c[x+dx[3]][y+dy[3]]!='.') continue;
	            if(c[x+dx[3]][y+dy[3]]=='z'||c[x+dx[3]][y+dy[3]]=='Z'){
	                for(i=0;i<zbs.size();++i){
	                    if(zbs[i].x==x+dx[3]&&zbs[i].y==y+dy[3]){
	                        zbs[i].healthy-=(22+at);
	                        if(zbs[i].healthy<=0){
	                            money+=zbs[i].money;
	                            c[zbs[i].x][zbs[i].y]='$';
	                            zbs.erase(zbs.begin()+i);
	                        }
	                    }
	                }
	            }
	            c[x+dx[3]][y+dy[3]]='`';
	            zds.push_back(mp(mp(x+dx[3],y+dy[3]),3));
	            continue;
	        }else if(ch==114){
	        	a.money=money;
	        	return a;
			}
	        for(i=0;i<zds.size();++i) mvzd(zds[i]);
	        for(i=0;i<zbs.size();++i) move(i);
	        for(i=0;i<zds.size();++i) mvzd(zds[i]);
	        for(i=0;i<zds.size();++i) mvzd(zds[i]);
	    }
	}
}zbgg;
struct cp{
	cp(){}
	int money=100;
	int t=0;
	int tt=-1;
	int v;
	int d;
	void borrow()
	{
	    if(tt!=-1)
	    {
	        cout<<"你现在不能借钱"<<endl;
	        return;
	    }
	    cout<<"你要借多少钱？"<<endl;
	    cin>>v;
	    if (d==1||d==2)
	    {
	        if (v>1000) cout<<"你不能借这么多钱！"<<endl,cout<<"你要借多少钱？"<<endl,cin>>v;
	        if (v<=1000) money+=v,cout<<"10天以后你要还"<<2*v<<"美元"<<endl;
	        return;
	    }
	    else
	    {
	        if (v>100) cout<<"你不能借这么多钱！"<<endl,cout<<"你要借多少钱？"<<endl,cin>>v;
	        if (v<=100) money+=v,cout<<"10天以后你要还"<<2*v<<"美元"<<endl;
	        return;
	    }
	}
	bool pay()
	{
	    cout<<"你现在要还 "<<2*v<<endl;
	    money-=2*v;
	    tt=-1;
	    v=0;
	    if(money<=0) return false;
	    else return true;
	}
	Player main(Player a)
	{
		money=a.money;
	    cout<<"欢迎来到彩票世界！"<<endl<<endl<<"温馨提示：在游戏内请勿使用小数、负数、英文字母、特殊字符（游戏中另说明除外），"<<endl<<"否则后果自负。"<<endl<<endl;
//	    cout<<"请选择难度(输入序号即可):"<<endl<<"1:入门"<<" "<<"2:简单"<<" "<<"3:普通"<<" "<<"4:中等"<<" "<<"5:困难"<<endl;
	    d=4;
	    bool flag=true;
	    srand(time(0));
	    int n,p;
	    char c[4];
	    if (d==1)
	    {
	        cout<<"每张彩票 购入价为1美元，出售价为5美元，有五个奖项"<<endl<<"小奖：10美元"<<endl<<"中奖：20美元"<<endl<<"大奖：100美元"<<endl<<"巨额奖金：1,000美元"<<endl<<"杰克壶：10,000美元"<<endl;
	        cout<<"你有100美元，当你赚了超过10,000美元，你就发财了。"<<endl<<"但如果你失去了所有的钱，你破产了。"<<endl;
	        cout<<"你可能想借钱（最多1,000美元），如果你想，按0。"<<endl<<"请记住，当你借了十天以后。你必须偿还两倍，"<<endl;
	        cout<<"你想买彩票还是卖彩票？（buy/sell）"<<endl;
	    }
	    if (d==2)
	    {
	        cout<<"每张彩票 购入价为2美元，出售价为3美元，有五个奖项"<<endl<<"小奖：5美元"<<endl<<"中奖：20美元"<<endl<<"大奖：100美元"<<endl<<"巨额奖金：1,000美元"<<endl<<"杰克壶：10,000美元"<<endl;
	        cout<<"你有100美元，当你赚了超过10,000美元，你就发财了。"<<endl<<"但如果你失去了所有的钱，你破产了。"<<endl;
	        cout<<"你可能想借钱（最多1,000美元），如果你想，请按0。"<<endl<<"请记住，当你借了十天以后。你必须偿还两倍，"<<endl;
	        cout<<"你想买彩票还是卖彩票？（buy/sell）"<<endl;
	    }
	    if (d==3)
	    {
	        cout<<"每张彩票 售价2美元，有五个奖项"<<endl<<"小奖：5美元"<<endl<<"中奖：20美元"<<endl<<"大奖：100美元"<<endl<<"巨额奖金：1,000美元"<<endl<<"杰克壶：10,000美元"<<endl;
	        cout<<"你有100美元，当你赚了超过10,000美元，你就发财了。"<<endl<<"但如果你失去了所有的钱，你破产了。"<<endl;
	        cout<<"你可能想借钱（最多100美元），如果你想，请按0。"<<endl<<"请记住，当你借了十天以后。你必须偿还两倍，"<<endl;
	        cout<<"你想买彩票还是卖彩票？（buy/sell）"<<endl;
	    }
	    if (d==4)
	    {
	        cout<<"每张彩票 售价3美元，有五个奖项"<<endl<<"小奖：5美元"<<endl<<"中奖：20美元"<<endl<<"大奖：100美元"<<endl<<"巨额奖金：1,000美元"<<endl<<"杰克壶：10,000美元"<<endl;
	        cout<<"你有100美元，当你赚了超过100,000美元，你就发财了。"<<endl<<"但如果你失去了所有的钱，你破产了。"<<endl;
	        cout<<"你可能想借钱（最多100美元），如果你想，请按0。"<<endl<<"请记住，当你借了七天以后。你必须偿还两倍，"<<endl;
	        cout<<"你想买彩票还是卖彩票？（buy/sell）"<<endl;
	    }
	    if (d==5)
	    {
	        cout<<"每张彩票 购入价为5美元，出售价为2美元，有五个奖项"<<endl<<"小奖：5美元"<<endl<<"中奖：20美元"<<endl<<"大奖：100美元"<<endl<<"巨额奖金：1,000美元"<<endl<<"杰克壶：5,000美元"<<endl;
	        cout<<"你有100美元，当你赚了超过100,000美元，你就发财了。"<<endl<<"但如果你失去了所有的钱，你就破产了。"<<endl;
	        cout<<"你可能想借钱（最多100美元），如果你想，请按0。"<<endl<<"请记住，当你借了五天以后。你必须偿还两倍，"<<endl;
	        cout<<"你想买彩票还是卖彩票？（buy/sell）"<<endl;
	    }
	    cin>>c;
	    if(c[0]=='b'||c[0]=='B')
	    {
	        while(money>0)
	        {
	            if (d==1||d==2||d==3) if(money>=10000)
	                {
	                    cout<<"你发财了! "<<endl;
	                    cout<<"你花了 "<<t<<"天"<<endl;
	                    system("pause");
	                    a.money=money;
	                    return a;
	                }
	            if (d==4||d==5) if(money>=100000)
	                {
	                    cout<<"你发财了! "<<endl;
	                    cout<<"你花了 "<<t<<"天"<<endl;
	                    system("pause");
	                    a.money=money;
	                    return a;
	                }
	            t++;
	            cout<<"你要买几张票？输入-1返回战争世界"<<" "<<"你有$"<<money<<endl;
	            cin>>n;
	            if(n==-1){
	            	a.money=money;
	            	return a;
				}
	            if(n==0)
	            {
	                if (d=4)
	                {
	                    borrow();
	                    tt=t+7;
	                }
	                if (d=5)
	                {
	                    borrow();
	                    tt=t+5;
	                }
	                else
	                {
	                    borrow();
	                    tt=t+10;
	                }
	            }
	            if(t==tt)
	            {
	                flag=pay();
	            }
	            if(t==tt-1) cout<<"[警告]你必须在明天还钱！"<<endl;
	            if(flag==false)
	            {
	                cout<<"你不能偿还你借的钱！"<<endl;
	                cout<<"你破产了。"<<endl;
	                cout<<"你生存了"<<t<<"天。"<<endl;
	                a.money=money;
	                system("pause");
	                return a;
	            }
	            flag=true;
	            if(n<0)
	            {
	                cout<<"因为你违反规则，所以系统强制停止了你的游戏"<<endl;
	                system("pause");
	            }
	            if (d==1) money=money-n;
	            if (d==2||d==3) money=money-n*2;
	            if (d==4) money=money-n*3;
	            if (d==5) money=money-n*5;
	            if(money<0)
	            {
	                cout<<"你破产了。"<<endl;
	                cout<<"你生存了"<<t<<"天"<<endl;
	                system("pause");
	                a.money=money;
	                return a;
	            }
	            for(int i=0; i<n; i++)
	            {
	                p=rand()%12000;
	                if(p==0)
	                {
	                    int q=0;
	                    q=rand()%4;
	                    if(q==1)
	                    {
	                        cout<<"你获得了杰克壶！"<<endl;
	                        if (d==5) money+=5000;
	                        else money+=10000;
	                    }
	                }
	                else if(p>=1&&p<=8)
	                {
	                    int g=0;
	                    g=rand()%2;
	                    if(g==0)
	                    {
	                        cout<<"你获得了巨额奖金！ "<<endl;
	                        money+=1000;
	                    }
	                }
	                else if(p>=9&&p<=99)
	                {
	                    cout<<"你获得了大奖！"<<endl;
	                    money+=100;
	                }
	                else if((p>=100&&p<=399)||(p>1500&&p<=1600))
	                {
	                    cout<<"你获得了中间奖！"<<endl;
	                    money+=20;
	                }
	                else if(p>=400&&p<=1500)
	                {
	                    cout<<"你获得了小奖！"<<endl;
	                    if (d==1) money+=10;
	                    else money+=5;
	                }
	            }
	            if(money<=0)
	            {
	                cout<<"你破产了。"<<endl;
	                cout<<"你生存了"<<t<<"天。"<<endl;
	                system("pause");
	                a.money=money;
	                return a;
	            }
	        }
	    }
	    if(c[0]=='s'||c[0]=='S')
	    {
	        if (d==1)
	        {
	            cout<<"你有$"<<money<<endl;
	            cout<<"你必须付25美元买一个商店。 "<<endl;
	            cout<<"你只能卖同样数量的票作为你的钱。 "<<endl;
	            money-=25;
	        }
	        if (d==2)
	        {
	            cout<<"你有$"<<money<<endl;
	            cout<<"你必须付35美元买一个商店。 "<<endl;
	            cout<<"你只能卖同样数量的票作为你的钱。 "<<endl;
	            money-=35;
	        }
	        if (d==3||d==4)
	        {
	            cout<<"你有$"<<money<<endl;
	            cout<<"你必须付50美元买一个商店。 "<<endl;
	            cout<<"你只能卖同样数量的票作为你的钱。 "<<endl;
	            money-=50;
	        }
	        if (d==5)
	        {
	            cout<<"你有$"<<money<<endl;
	            cout<<"你必须付60美元买一个商店。 "<<endl;
	            cout<<"你只能卖同样数量的票作为你的钱。 "<<endl;
	            money-=60;
	        }
	        cout<<"你有$"<<money<<endl;
	        while(money>0)
	        {
	            if (d==1||d==2||d==3) if(money>=10000)
	                    if (d==4||d==5) if(money>=100000)
	                        {
	                            cout<<"你发财了!"<<endl;
	                            cout<<"你花了"<<t<<"天。"<<endl;
	                            system("pause");
	                            a.money=money;
	                            return a;
	                        }
	            t++;
	            cout<<"你要卖几张票？ 输入-1返回战争大陆"<<" "<<"你有$"<<money<<endl;
	            cin>>n;
	            if(n==-1){
	            	a.money=money;
	            	return a;
				}
	            if(n==0)
	            {
	                borrow();
	                tt=t+10;
	            }
	            if(t==tt) bool flag=pay();
	            if(flag==false)
	            {
	                cout<<"你不能偿还你借的钱。"<<endl;
	                cout<<"你破产了！"<<endl;
	                cout<<"你生存了"<<t<<" 天。"<<endl;
	                system("pause");
	                a.money=money;
	                return a;
	            }
	            if(n<0 || n>money)
	            {
	                cout<<"注意"<<endl;
	                cout<<"你破产了！"<<endl;
	                cout<<"你生存了"<<t<<" 天"<<endl;
	                system("pause");
	                a.money=money;
	                return a;
	            }
	            if (d=1) money=money+n*5;
	            if (d=2) money=money+n*3;
	            else money=money+n*2;
	            if(money<0)
	            {
	                cout<<"你破产了！"<<endl;
	                cout<<"你生存了"<<t<<" 天"<<endl;
	                system("pause");
	                a.money=money;
	                return a;
	            }
	            for(int i=0; i<n; i++)
	            {
	                p=rand()%12000;
	                if(p==0)
	                {
	                    int y;
	                    y=rand()%4;
	                    if(y==1)
	                    {
	                        cout<<"你失去了杰克壶！"<<endl;
	                        if (d==5) money-=5000;
	                        else money-=10000;
	                    }
	                }
	                else if(p>=1&&p<=8)
	                {
	                    cout<<"你失去了巨额奖金！"<<endl;
	                    money-=1000;
	                }
	                else if(p>=15&&p<=50)
	                {
	                    cout<<"你失去了大奖！"<<endl;
	                    money-=100;
	                }
	                else if(p>=61&&p<=360)
	                {
	                    cout<<"你失去了中奖！"<<endl;
	                    money-=20;
	                }
	                else if(p>=401&&p<=1500)
	                {
	                    cout<<"你失去了小奖！"<<endl;
	                    money-=5;
	                }
	            }
	        }
	    }
	    if(money<=0)
	    {
	        cout<<"你破产了。"<<endl;
	        cout<<"你生存了"<<t<<"天。"<<endl;
	        system("pause");
	        a.money=money;
	        return a;
	    }
	}
}cip;
int opencp;
inline void cd(){
	mt19937 mt;
	for(int i=0;i<1982473;++i) mt(); 
	cout<<"请输入你要存的档的名字(英文)\n";
	string s,t;
	cin>>s;
	cout<<"密码：";
	cin>>t;
	ofstream out;
	out.open((s+".qwert").c_str());
	out<<t<<endl;
	out<<player.level<<" "<<player.exp<<" "<<player.ishh<<" "<<player.isqj<<" "<<player.money<<" "<<opencp<<" "<<openmh<<" "<<player.openkx<<' '<<player.fj<<" "<<player.gsp<<" ";
	for(int i=0;i<player.level+player.exp+player.ishh+player.isqj+player.ishh+openmh+opencp+player.openkx+player.fj+player.gsp;++i) mt();
	for(int i=0;i<6;++i){
		out<<player.a[i]<<" ";
		for(int j=0;j<player.a[i];++j) mt();
	}
	for(int i=0;i<6;++i){
		out<<player.add[i]<<' ';
		for(int j=0;j<player.add[i];++j) mt();
	}
	out<<mt()<<endl;
	out.close();
	cout<<"\n\t\t\t\t\tOK\n";
}
inline void rd(){
	mt19937 mt;
	for(int i=0;i<1982473;++i) mt(); 
	cout<<"请输入你要读的档的名字(英文)\n";
	string s,t;
	cin>>s;
	cout<<"密码：";
	cin>>t;
	ifstream out;
	out.open((s+".qwert").c_str());
	string pd;
	out>>pd;
	if(pd!=t){
		cout<<"Wrong Password!!!\n";
		return;
	}
	out>>player.level>>player.exp>>player.ishh>>player.isqj>>player.money>>opencp>>openmh>>player.openkx>>player.fj>>player.gsp;
	for(int i=0;i<player.level+player.exp+player.ishh+player.isqj+player.ishh+openmh+opencp+player.openkx+player.fj+player.gsp;++i) mt();
	for(int i=0;i<6;++i){
		out>>player.a[i];
		for(int j=0;j<player.a[i];++j) mt();
	}
	for(int i=0;i<6;++i){
		out>>player.add[i];
		for(int j=0;j<player.add[i];++j) mt();
	}
	long long ipd;
	out>>ipd;
	if(mt()!=ipd){
		cout<<"Do you change the file???\n";
		return;
	}
	out.close();
	cout<<"\n\t\t\t\t\tOK\n";
}
int main(){ 
	int i,j;
	srand(time(NULL));
    printf("正在连接服务器...\n▊15");
    Sleep(700);
    system("cls");
    printf("加载资源中...\n█▎25");
    Sleep(600);
    system("cls");
    printf("加载资源中...\n██▊55");
    Sleep(400);
    system("cls");
    printf("加载资源中...\n███▌70");
    Sleep(300);
    system("cls");
    printf("加载资源中...\n███▊75");
    Sleep(1500);
    system("cls");
    printf("正在加载剧情...\n████▌90");
    Sleep(400);
    system("cls");
    printf("正在加载剧情...\n█████100");
    Sleep(1000);
    system("cls");
    printf("正在进入游戏...\n█████100");
    Sleep(3000);
    system("pause");
	for(i=0;i<6;++i) for(j=0;j<6;++j) swap(take[i][j].first,take[i][j].second);
	cout<<"欢迎来到战争世界！ 作者：洛谷万岁\n\n请把这个文件夹(WarWorld)移至桌面！！\n";
	player.init();
	player.show();
	system("pause");
	cout<<"是否导入？是输入1，否则输入0\n";
	int tttttt;
	cin>>tttttt;
	if(tttttt) rd();
	cout<<"军营：每此战役前自动增加一些人数\n";
	cout<<"\n\t\t有2个彩蛋！！！有1个彩蛋中还有一个彩蛋！！！\n";
	cout<<"\n\n**提示：可以在设置中关闭逃跑系统！！！**\n\n";
	cout<<"\n\n\t建议先查看部队简介!!!\n\n";
	system("pause");
	cout<<"\n\n\t\t\t**输入的都是从1开始的序号!!!!!**\n\n\n";
	while(1){
		cout<<"------------------------------------------------------\n";
		cout<<"1:fight\n2:shop\n3:show\n4:cls(清屏)\n5:升级军营\n6:设置\n7:部队简介\n8:存档\n9:退出游戏\n";
		if(player.openkx) cout<<"10:空袭专用商店\n"; 
		if(opencp) cout<<"11:彩票世界\n";
		if(openmh) cout<<"12:荒芜世界\n";
		cout<<"\n";
		int t;
		cin>>t;
		while(t<1 or t>9+openmh+opencp+player.openkx){
			cout<<"again!\n";
			cin>>t;
		}
		if(t==1) player.fight();
		else if(t==2) player.shop();
		else if(t==3) player.show();
		else if(t==4) system("cls");
		else if(t==5) player.addjy();
		else if(t==6) player.set();
		else if(t==7) player.jj();
		else if(t==8){
			cout<<"存档:两个附属世界都得重新开始(钱、人、军营、设置···不会丢，而且防更改)，确定？\n确定输入1，否则输入0\n";
			int t;
			cin>>t;
			if(t) cd();
		}else if(t==9) exit(0);
		else if(t==10) player.kxxl();
		else if(t==11) player=cip.main(player);
		else if(t==12) player=zbgg.gd(player);
		if(player.level>=4 and !opencp){
			cout<<"恭喜开启彩票世界！！！\n";
			system("pause");
			opencp=1;
		}
		if(player.level>=5 and !player.openkx){
			cout<<"恭喜开启【战争时可以空袭】！！！\n";
			system("pause");
			player.openkx=1;
		}
		if(player.level==6 and !openmh){
			cout<<"恭喜开启荒芜世界模式！！！\n";
			system("pause");
			openmh=1;
		}
		cout<<"------------------------------------------------------\n";
	}
}
