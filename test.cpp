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
string s[]={"����","Ұ����","������","���","��ǹ��","̹��"};
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
		cout<<"�ҷ���\n";
		if(level>=5){
			cout<<"�ɻ�:"<<fj<<"  ������:"<<gsp<<endl;
		}
		for(int i=0;i<level;++i) cout<<s[i]<<"\t\t";
		cout<<endl;
		for(int i=0;i<level;++i) cout<<a[i]<<"\t\t";
		cout<<endl;
		cout<<"------------------------------------------------------\n";
	}
	inline void _show(Monster t){
		cout<<"------------------------------------------------------\n";
		cout<<"�ҷ���\n";
		if(level>=5){
			cout<<"�ɻ�:"<<fj<<"  ������:"<<gsp<<endl;
		}
		for(int i=0;i<level;++i) cout<<s[i]<<"\t\t";
		cout<<endl;
		for(int i=0;i<level;++i) cout<<a[i]<<"\t\t";
		cout<<endl;
		cout<<"------------------------------------------------------\n";
		cout<<"�з���\n";
		if(level>=5){
			cout<<"������:"<<t.gsp<<endl;
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
		cout<<"����ʼ��ս��\n";
		system("pause");
		Monster N;
		bool taop=0;
		N.init(level);
		for(int i=0;i<level;++i) a[i]+=add[i]; 
		if(openkx){
			cout<<"�Ƿ�ʹ�ÿ�Ϯ?�ǣ�����1   ������0\n";
			int t;
			cin>>t;
			while(t<0 or t>1){
				cout<<"again!\n";
				cin>>t;
			} 
			if(t){
				if(N.gsp>fj){
					cout<<"���ڶԷ��ĸ����ڴ�����ķɻ�������Ϯʧ��,�ɻ�����2/3��\n";
					fj=fj/3;
				}else{
					cout<<"��Ϯ�ɹ�,�ɻ�����1/3��\n";
					fj=fj*2/3;
					for(int i=0;i<6;++i) a[i]=a[i]*2/5;
				}
			}
		}
		while(1){
			if(die()){
				cout<<"ɧ�꣬�㶼û�����˻�����ܣ�����\n";
				break;
			}
			if(isqj){
				cout<<"�Ƿ�ȫ�����ܣ���������1����������0������ʱÿһֻ���Ӷ���������1/3\n";
				int ttttt;
				cin>>ttttt;
				if(ttttt){
					for(int i=0;i<level;++i) a[i]=a[i]*2/3;
					taop=1;
					break;
				}			
			}
			_show(N);
			cout<<"��Ҫ�õڼ�ֻ���ӳ���\n";
			int t;
			cin>>t;
			while(t<1 or t>level or !a[t-1]){
				cout<<"�����������һ������\n"; 
				cin>>t;
			}
			--t;
			int df=rand()%level;
			while(!N.a[df]) df=rand()%level;
			++df;
			cout<<"�з�ʹ���˵�"<<df<<"�Ų���\n";
			--df;
/*			#ifdef LOCAL
				cout<<"�ҷ�:"<<s[t]<<" �з�:"<<s[df]<<"  "<<a[t]<<" "<<N.a[df]<<" "<<take[t][df].first<<" "<<take[t][df].second<<" "<<a[t]/take[t][df].first<<" "<<N.a[df]/take[t][df].second<<endl;
			#endif 
*/			if(ishh){
				cout<<"�����Ƿ����ܣ����ܻغ�����1����������0��������80%�ĸ��ʳɹ�������˲���ȫ����û������\n";
				int ttt;
				cin>>ttt;
				if(ttt){
					int t=rand()%10;
					if(t<8){
						cout<<"��ϲ�㣬���ܳɹ�������\n";
						continue;
					}else{
						cout<<"���ź�������ʧ��\n";
						a[t]=0;
						continue;
					}
				} 			
			}
			int mys=a[t]/take[t][df].first;
			int dfs=N.a[df]/take[t][df].second;
			if(mys>dfs){
				cout<<"��ϲ�㣬������!!!\n";
				a[t]-=N.a[df]*take[t][df].first/take[t][df].second;
				exp+=N.a[df]*expr[df];
				money+=am[df]*N.a[df];
				N.a[df]=0;
			}else if(mys==dfs){
				cout<<"���ܾ���\n";
				a[t]=0;
				exp+=N.a[df]*expr[df];
				money+=am[df]*N.a[df];
				N.a[df]=0;
			}else{
				cout<<"���ź���������\n";
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
			cout<<"ɧ�꣬�����ˣ��´�����\n";
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
			cout<<"��ϲ�㣬��Ӯ��\n";
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
			cout<<"�����ӱ��ܹ�����????????????????????????????????????\n";
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
		cout<<"--------------------------------------------------------\n��Ʒ��\n Name:\t\t";
		for(int i=0;i<level;++i) cout<<s[i]<<"\t\t";
		cout<<endl<<" Cost:\t\t";
		for(int i=0;i<level;++i) cout<<mny[i]<<"\t\t";
		cout<<endl;
		cout<<"--------------------------------------------------------\n\n";
		cout<<"What do you want to buy and how many?\n";
		cout<<"���� :     ��� ����\n";
		cout<<"������Ҫ��2��Ұ���ˣ�\n";
        cout<<"����:        1 2\n";
        cout<<"��1����λ��ţ���2����Ϊ��ĸ���\n";
        cout<<"��һ��������-1:�˳�(��ʱ��ȻҪ�����2����������)";
		int t1,t2;
		cin>>t1>>t2;
		while((t1<1 or t1>level) and t1!=-1){
			cout<<"again!!!\n";
			cin>>t1>>t2;
		}
		if(t1==-1) return; 
		--t1;
		if(t2*mny[t1]>money){
			cout<<"��û����ô��Ǯ\n";
			return;
		}
		cout<<"����ɹ�������\n";
		money-=t2*mny[t1];
		a[t1]+=t2;
	}
	inline void kxxl(){
		show();
		cout<<"��Ʒ���ƣ�\n��ը������Ϯר��     �����ڣ�����Ϯ\n ";
		cout<<"�۸�    \n2000                 3500\n";
		cout<<"����Ҫ�����Ʒ����ţ���1��ʼ���͹�������������������-1 0\n";
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
				cout<<"Ǯ����\n";
				return;
			}else{
				cout<<"OK\n";
				money-=2000*t2;
				fj+=t2;
			}
		}
		if(t1==2){
			if(money<3500*t2){
				cout<<"Ǯ����\n";
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
		for(int i=0;i<level;++i) cout<<s[i]<<"��Ӫ\t\t";
		cout<<endl<<" Cost:\t\t";
		for(int i=0;i<level;++i) cout<<costjv[i]<<"\t\t";
		cout<<endl;
		cout<<"�������������ľ�Ӫ����ţ���1��ʼ��-1:�˳�\n";
		int t;
		cin>>t;
		while((t<1 or t>level) and t!=-1){
			cout<<"again!\n";
			cin>>t;
		}
		if(t==-1) return;
		--t;
		if(money<costjv[t]){
			cout<<"��û����ô��Ǯ\n";
			return;
		}
		cout<<"����ɹ�������\n";
		money-=costjv[t];
		add[t]+=5;
	}
	inline void set(){
		cout<<"1:��/��ȫ������ 2:��/�ػغ����� -1:�˳�";
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
		cout<<"level 1 ����:�˺�ս�������ѡ��\n\nlevel 2 Ұ����:�������ս�����˶�֪�������ˣ�\n\nlevel 3 ������:���ˣ�Զ��\n\nlevel 4 ���:�����ڻ���ս���е����ӣ�����\n\nlevel 5 ��ǹ��:Ⱥ�ˣ����˺�(������)\n\nlevel 6 ̹�ˣ���ܣ���ѹһ��\n\n";
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
	    cout<<"p:�̵� b����ը�� f:�㱬ը�� o:���� c������ �������Ҽ��� e:ɾ������ \nZ:��ʬ z:С��ʬ ��ʬ�ɻ��Ǯ����ʬ�࣬С��ʬ�� $:��ʬ����һ���Զ�ɾ��\nWASD�����ӵ� �ӵ�2Ԫһ��\n";
	    cout<<"r:����ս������";
		cout<<"�����ˣ��������\n";
	    cout<<"�вʵ���\n";
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
	    cout<<"�޹ֳ��֣�"; 
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
	    cout<<"1.���ӹ�����\n";
	    cout<<"2.����Ѫ��\n"; 
	    cout<<"3.���ӽ�ʬ\n";
	    cout<<"4.�˳�\n"; 
	    long long kind;
	    cin>>kind;
	    if(kind==1){
	        cout<<"�������ӵĹ�������ÿһ��������9Ԫ\n";
	        long long mny;
	        cin>>mny;
	        if(money<mny*9){
	            cout<<"Ǯ����\n";
	            shop();
	            return;
	        } 
	        money-=mny*9;
	        at+=mny;
	        shop();
	        return;
	    }else if(kind==2){
	        cout<<"�������ӵĹ�������ÿһ��Ѫ��2Ԫ\n";
	        long long mny;
	        cin>>mny;
	        if(money<mny*2){
	            cout<<"Ǯ����\n";
	            shop();
	            return;
	        }
	        money-=mny*2;
	        healthy+=mny;
	        shop();
	        return;
	    }else if(kind==3){
	        cout<<"30Ԫ��������ã���ʬ�ɵ�Ǯ\n";
	        bool by=0;
	        cout<<"��ѡ1������ѡ0\n";
	        cin>>by;
	        if(!by) shop();
	        if(money<30){
	            cout<<"Ǯ����\n";
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
	            cout<<"�ʵ�����!\n";
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
	            cout<<"����Ҫ����ķ��������(�����ǽ�ʬ)\n";
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
	            cout<<"����Ҫ������ը����λ��\n";
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
	        cout<<"�����ڲ��ܽ�Ǯ"<<endl;
	        return;
	    }
	    cout<<"��Ҫ�����Ǯ��"<<endl;
	    cin>>v;
	    if (d==1||d==2)
	    {
	        if (v>1000) cout<<"�㲻�ܽ���ô��Ǯ��"<<endl,cout<<"��Ҫ�����Ǯ��"<<endl,cin>>v;
	        if (v<=1000) money+=v,cout<<"10���Ժ���Ҫ��"<<2*v<<"��Ԫ"<<endl;
	        return;
	    }
	    else
	    {
	        if (v>100) cout<<"�㲻�ܽ���ô��Ǯ��"<<endl,cout<<"��Ҫ�����Ǯ��"<<endl,cin>>v;
	        if (v<=100) money+=v,cout<<"10���Ժ���Ҫ��"<<2*v<<"��Ԫ"<<endl;
	        return;
	    }
	}
	bool pay()
	{
	    cout<<"������Ҫ�� "<<2*v<<endl;
	    money-=2*v;
	    tt=-1;
	    v=0;
	    if(money<=0) return false;
	    else return true;
	}
	Player main(Player a)
	{
		money=a.money;
	    cout<<"��ӭ������Ʊ���磡"<<endl<<endl<<"��ܰ��ʾ������Ϸ������ʹ��С����������Ӣ����ĸ�������ַ�����Ϸ����˵�����⣩��"<<endl<<"�������Ը���"<<endl<<endl;
//	    cout<<"��ѡ���Ѷ�(������ż���):"<<endl<<"1:����"<<" "<<"2:��"<<" "<<"3:��ͨ"<<" "<<"4:�е�"<<" "<<"5:����"<<endl;
	    d=4;
	    bool flag=true;
	    srand(time(0));
	    int n,p;
	    char c[4];
	    if (d==1)
	    {
	        cout<<"ÿ�Ų�Ʊ �����Ϊ1��Ԫ�����ۼ�Ϊ5��Ԫ�����������"<<endl<<"С����10��Ԫ"<<endl<<"�н���20��Ԫ"<<endl<<"�󽱣�100��Ԫ"<<endl<<"�޶��1,000��Ԫ"<<endl<<"�ܿ˺���10,000��Ԫ"<<endl;
	        cout<<"����100��Ԫ������׬�˳���10,000��Ԫ����ͷ����ˡ�"<<endl<<"�������ʧȥ�����е�Ǯ�����Ʋ��ˡ�"<<endl;
	        cout<<"��������Ǯ�����1,000��Ԫ����������룬��0��"<<endl<<"���ס���������ʮ���Ժ�����볥��������"<<endl;
	        cout<<"�������Ʊ��������Ʊ����buy/sell��"<<endl;
	    }
	    if (d==2)
	    {
	        cout<<"ÿ�Ų�Ʊ �����Ϊ2��Ԫ�����ۼ�Ϊ3��Ԫ�����������"<<endl<<"С����5��Ԫ"<<endl<<"�н���20��Ԫ"<<endl<<"�󽱣�100��Ԫ"<<endl<<"�޶��1,000��Ԫ"<<endl<<"�ܿ˺���10,000��Ԫ"<<endl;
	        cout<<"����100��Ԫ������׬�˳���10,000��Ԫ����ͷ����ˡ�"<<endl<<"�������ʧȥ�����е�Ǯ�����Ʋ��ˡ�"<<endl;
	        cout<<"��������Ǯ�����1,000��Ԫ����������룬�밴0��"<<endl<<"���ס���������ʮ���Ժ�����볥��������"<<endl;
	        cout<<"�������Ʊ��������Ʊ����buy/sell��"<<endl;
	    }
	    if (d==3)
	    {
	        cout<<"ÿ�Ų�Ʊ �ۼ�2��Ԫ�����������"<<endl<<"С����5��Ԫ"<<endl<<"�н���20��Ԫ"<<endl<<"�󽱣�100��Ԫ"<<endl<<"�޶��1,000��Ԫ"<<endl<<"�ܿ˺���10,000��Ԫ"<<endl;
	        cout<<"����100��Ԫ������׬�˳���10,000��Ԫ����ͷ����ˡ�"<<endl<<"�������ʧȥ�����е�Ǯ�����Ʋ��ˡ�"<<endl;
	        cout<<"��������Ǯ�����100��Ԫ����������룬�밴0��"<<endl<<"���ס���������ʮ���Ժ�����볥��������"<<endl;
	        cout<<"�������Ʊ��������Ʊ����buy/sell��"<<endl;
	    }
	    if (d==4)
	    {
	        cout<<"ÿ�Ų�Ʊ �ۼ�3��Ԫ�����������"<<endl<<"С����5��Ԫ"<<endl<<"�н���20��Ԫ"<<endl<<"�󽱣�100��Ԫ"<<endl<<"�޶��1,000��Ԫ"<<endl<<"�ܿ˺���10,000��Ԫ"<<endl;
	        cout<<"����100��Ԫ������׬�˳���100,000��Ԫ����ͷ����ˡ�"<<endl<<"�������ʧȥ�����е�Ǯ�����Ʋ��ˡ�"<<endl;
	        cout<<"��������Ǯ�����100��Ԫ����������룬�밴0��"<<endl<<"���ס��������������Ժ�����볥��������"<<endl;
	        cout<<"�������Ʊ��������Ʊ����buy/sell��"<<endl;
	    }
	    if (d==5)
	    {
	        cout<<"ÿ�Ų�Ʊ �����Ϊ5��Ԫ�����ۼ�Ϊ2��Ԫ�����������"<<endl<<"С����5��Ԫ"<<endl<<"�н���20��Ԫ"<<endl<<"�󽱣�100��Ԫ"<<endl<<"�޶��1,000��Ԫ"<<endl<<"�ܿ˺���5,000��Ԫ"<<endl;
	        cout<<"����100��Ԫ������׬�˳���100,000��Ԫ����ͷ����ˡ�"<<endl<<"�������ʧȥ�����е�Ǯ������Ʋ��ˡ�"<<endl;
	        cout<<"��������Ǯ�����100��Ԫ����������룬�밴0��"<<endl<<"���ס��������������Ժ�����볥��������"<<endl;
	        cout<<"�������Ʊ��������Ʊ����buy/sell��"<<endl;
	    }
	    cin>>c;
	    if(c[0]=='b'||c[0]=='B')
	    {
	        while(money>0)
	        {
	            if (d==1||d==2||d==3) if(money>=10000)
	                {
	                    cout<<"�㷢����! "<<endl;
	                    cout<<"�㻨�� "<<t<<"��"<<endl;
	                    system("pause");
	                    a.money=money;
	                    return a;
	                }
	            if (d==4||d==5) if(money>=100000)
	                {
	                    cout<<"�㷢����! "<<endl;
	                    cout<<"�㻨�� "<<t<<"��"<<endl;
	                    system("pause");
	                    a.money=money;
	                    return a;
	                }
	            t++;
	            cout<<"��Ҫ����Ʊ������-1����ս������"<<" "<<"����$"<<money<<endl;
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
	            if(t==tt-1) cout<<"[����]����������컹Ǯ��"<<endl;
	            if(flag==false)
	            {
	                cout<<"�㲻�ܳ�������Ǯ��"<<endl;
	                cout<<"���Ʋ��ˡ�"<<endl;
	                cout<<"��������"<<t<<"�졣"<<endl;
	                a.money=money;
	                system("pause");
	                return a;
	            }
	            flag=true;
	            if(n<0)
	            {
	                cout<<"��Ϊ��Υ����������ϵͳǿ��ֹͣ�������Ϸ"<<endl;
	                system("pause");
	            }
	            if (d==1) money=money-n;
	            if (d==2||d==3) money=money-n*2;
	            if (d==4) money=money-n*3;
	            if (d==5) money=money-n*5;
	            if(money<0)
	            {
	                cout<<"���Ʋ��ˡ�"<<endl;
	                cout<<"��������"<<t<<"��"<<endl;
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
	                        cout<<"�����˽ܿ˺���"<<endl;
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
	                        cout<<"�����˾޶�� "<<endl;
	                        money+=1000;
	                    }
	                }
	                else if(p>=9&&p<=99)
	                {
	                    cout<<"�����˴󽱣�"<<endl;
	                    money+=100;
	                }
	                else if((p>=100&&p<=399)||(p>1500&&p<=1600))
	                {
	                    cout<<"�������м佱��"<<endl;
	                    money+=20;
	                }
	                else if(p>=400&&p<=1500)
	                {
	                    cout<<"������С����"<<endl;
	                    if (d==1) money+=10;
	                    else money+=5;
	                }
	            }
	            if(money<=0)
	            {
	                cout<<"���Ʋ��ˡ�"<<endl;
	                cout<<"��������"<<t<<"�졣"<<endl;
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
	            cout<<"����$"<<money<<endl;
	            cout<<"����븶25��Ԫ��һ���̵ꡣ "<<endl;
	            cout<<"��ֻ����ͬ��������Ʊ��Ϊ���Ǯ�� "<<endl;
	            money-=25;
	        }
	        if (d==2)
	        {
	            cout<<"����$"<<money<<endl;
	            cout<<"����븶35��Ԫ��һ���̵ꡣ "<<endl;
	            cout<<"��ֻ����ͬ��������Ʊ��Ϊ���Ǯ�� "<<endl;
	            money-=35;
	        }
	        if (d==3||d==4)
	        {
	            cout<<"����$"<<money<<endl;
	            cout<<"����븶50��Ԫ��һ���̵ꡣ "<<endl;
	            cout<<"��ֻ����ͬ��������Ʊ��Ϊ���Ǯ�� "<<endl;
	            money-=50;
	        }
	        if (d==5)
	        {
	            cout<<"����$"<<money<<endl;
	            cout<<"����븶60��Ԫ��һ���̵ꡣ "<<endl;
	            cout<<"��ֻ����ͬ��������Ʊ��Ϊ���Ǯ�� "<<endl;
	            money-=60;
	        }
	        cout<<"����$"<<money<<endl;
	        while(money>0)
	        {
	            if (d==1||d==2||d==3) if(money>=10000)
	                    if (d==4||d==5) if(money>=100000)
	                        {
	                            cout<<"�㷢����!"<<endl;
	                            cout<<"�㻨��"<<t<<"�졣"<<endl;
	                            system("pause");
	                            a.money=money;
	                            return a;
	                        }
	            t++;
	            cout<<"��Ҫ������Ʊ�� ����-1����ս����½"<<" "<<"����$"<<money<<endl;
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
	                cout<<"�㲻�ܳ�������Ǯ��"<<endl;
	                cout<<"���Ʋ��ˣ�"<<endl;
	                cout<<"��������"<<t<<" �졣"<<endl;
	                system("pause");
	                a.money=money;
	                return a;
	            }
	            if(n<0 || n>money)
	            {
	                cout<<"ע��"<<endl;
	                cout<<"���Ʋ��ˣ�"<<endl;
	                cout<<"��������"<<t<<" ��"<<endl;
	                system("pause");
	                a.money=money;
	                return a;
	            }
	            if (d=1) money=money+n*5;
	            if (d=2) money=money+n*3;
	            else money=money+n*2;
	            if(money<0)
	            {
	                cout<<"���Ʋ��ˣ�"<<endl;
	                cout<<"��������"<<t<<" ��"<<endl;
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
	                        cout<<"��ʧȥ�˽ܿ˺���"<<endl;
	                        if (d==5) money-=5000;
	                        else money-=10000;
	                    }
	                }
	                else if(p>=1&&p<=8)
	                {
	                    cout<<"��ʧȥ�˾޶��"<<endl;
	                    money-=1000;
	                }
	                else if(p>=15&&p<=50)
	                {
	                    cout<<"��ʧȥ�˴󽱣�"<<endl;
	                    money-=100;
	                }
	                else if(p>=61&&p<=360)
	                {
	                    cout<<"��ʧȥ���н���"<<endl;
	                    money-=20;
	                }
	                else if(p>=401&&p<=1500)
	                {
	                    cout<<"��ʧȥ��С����"<<endl;
	                    money-=5;
	                }
	            }
	        }
	    }
	    if(money<=0)
	    {
	        cout<<"���Ʋ��ˡ�"<<endl;
	        cout<<"��������"<<t<<"�졣"<<endl;
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
	cout<<"��������Ҫ��ĵ�������(Ӣ��)\n";
	string s,t;
	cin>>s;
	cout<<"���룺";
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
	cout<<"��������Ҫ���ĵ�������(Ӣ��)\n";
	string s,t;
	cin>>s;
	cout<<"���룺";
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
    printf("�������ӷ�����...\n��15");
    Sleep(700);
    system("cls");
    printf("������Դ��...\n����25");
    Sleep(600);
    system("cls");
    printf("������Դ��...\n������55");
    Sleep(400);
    system("cls");
    printf("������Դ��...\n��������70");
    Sleep(300);
    system("cls");
    printf("������Դ��...\n��������75");
    Sleep(1500);
    system("cls");
    printf("���ڼ��ؾ���...\n����������90");
    Sleep(400);
    system("cls");
    printf("���ڼ��ؾ���...\n����������100");
    Sleep(1000);
    system("cls");
    printf("���ڽ�����Ϸ...\n����������100");
    Sleep(3000);
    system("pause");
	for(i=0;i<6;++i) for(j=0;j<6;++j) swap(take[i][j].first,take[i][j].second);
	cout<<"��ӭ����ս�����磡 ���ߣ��������\n\n�������ļ���(WarWorld)�������棡��\n";
	player.init();
	player.show();
	system("pause");
	cout<<"�Ƿ��룿������1����������0\n";
	int tttttt;
	cin>>tttttt;
	if(tttttt) rd();
	cout<<"��Ӫ��ÿ��ս��ǰ�Զ�����һЩ����\n";
	cout<<"\n\t\t��2���ʵ���������1���ʵ��л���һ���ʵ�������\n";
	cout<<"\n\n**��ʾ�������������йر�����ϵͳ������**\n\n";
	cout<<"\n\n\t�����Ȳ鿴���Ӽ��!!!\n\n";
	system("pause");
	cout<<"\n\n\t\t\t**����Ķ��Ǵ�1��ʼ�����!!!!!**\n\n\n";
	while(1){
		cout<<"------------------------------------------------------\n";
		cout<<"1:fight\n2:shop\n3:show\n4:cls(����)\n5:������Ӫ\n6:����\n7:���Ӽ��\n8:�浵\n9:�˳���Ϸ\n";
		if(player.openkx) cout<<"10:��Ϯר���̵�\n"; 
		if(opencp) cout<<"11:��Ʊ����\n";
		if(openmh) cout<<"12:��������\n";
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
			cout<<"�浵:�����������綼�����¿�ʼ(Ǯ���ˡ���Ӫ�����á��������ᶪ�����ҷ�����)��ȷ����\nȷ������1����������0\n";
			int t;
			cin>>t;
			if(t) cd();
		}else if(t==9) exit(0);
		else if(t==10) player.kxxl();
		else if(t==11) player=cip.main(player);
		else if(t==12) player=zbgg.gd(player);
		if(player.level>=4 and !opencp){
			cout<<"��ϲ������Ʊ���磡����\n";
			system("pause");
			opencp=1;
		}
		if(player.level>=5 and !player.openkx){
			cout<<"��ϲ������ս��ʱ���Կ�Ϯ��������\n";
			system("pause");
			player.openkx=1;
		}
		if(player.level==6 and !openmh){
			cout<<"��ϲ������������ģʽ������\n";
			system("pause");
			openmh=1;
		}
		cout<<"------------------------------------------------------\n";
	}
}
