#ifdef openg
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
		Colorset(11);
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
#endif
