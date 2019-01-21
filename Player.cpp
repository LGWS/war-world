#include<bits/stdc++.h>
#include<windows.h>
#include "Color.cpp"
#include "Monster.cpp"
using namespace std;
struct Player{
	int level,exp,money;
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
	}
	inline void show(){
		cout<<"------------------------------------------------------\n";
		cout<<"Money: "<<money<<"\nlevel: "<<level<<"\nexp: "<<exp<<endl; 
		cout<<"我方：\n";
		for(int i=0;i<level;++i) cout<<s[i],cout<<"\t\t";
		cout<<endl;
		for(int i=0;i<level;++i) cout<<a[i]<<"\t\t";
		cout<<endl;
		cout<<"------------------------------------------------------\n";
	}
	inline void _show(Monster t){
		cout<<"------------------------------------------------------\n";
		cout<<"我方：\n";
		for(int i=0;i<level;++i) cout<<s[i],cout<<"\t\t";
		cout<<endl;
		for(int i=0;i<level;++i) cout<<a[i]<<"\t\t";
		cout<<endl;
		cout<<"------------------------------------------------------\n";
		cout<<"敌方：\n";
		for(int i=0;i<level;++i) cout<<s[i],cout<<"\t\t";
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
		Colorset(10);
		cout<<"------------------------------------------------------\n";
		cout<<"您开始了战斗\n";
		system("pause");
		Monster N;
		bool taop=0;
		N.init(level);
		for(int i=0;i<level;++i) a[i]+=add[i]; 
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
			Colorback();
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
			Colorback();
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
			Colorback();
		}
	}
	inline void shop(){
		Colorset(14);
		show();
		cout<<endl; 
		cout<<"--------------------------------------------------------\n商品：\n Name:\t\t";
		for(int i=0;i<level;++i) cout<<s[i],cout<<"\t\t";
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
		Colorback();
	}
	inline void addjy(){
		Colorset(11);
		cout<<"--------------------------------------------------------\n Name:\t\t";
		for(int i=0;i<level;++i) cout<<s[i],cout<<"军营\t\t";
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
		Colorback();
	}
	inline void set(){
		Colorset(10);
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
		Colorback();
	}
	inline void __pr(string s){
		for(int i=0;i<s.size();++i) cout<<s[i],Sleep(7);
	}
	inline void jj(){
		Colorset(14);
		cout<<"--------------------------------------------------------\n";
		__pr("level 1 骷髅:人海战术的最佳选择\n\nlevel 2 野蛮人:玩过皇室战争的人都知道（单伤）\n\nlevel 3 弓箭手:单伤，远程\n\nlevel 4 骑兵:类似于皇室战争中的王子，单伤\n\nlevel 5 机枪手:群伤，克人海(骷髅们)\n\nlevel 6 坦克：肉盾，碾压一切\n\n");
		cout<<"--------------------------------------------------------\n";
		Colorback();
	}
}player;
