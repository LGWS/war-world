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
		cout<<"�ҷ���\n";
		for(int i=0;i<level;++i) cout<<s[i],cout<<"\t\t";
		cout<<endl;
		for(int i=0;i<level;++i) cout<<a[i]<<"\t\t";
		cout<<endl;
		cout<<"------------------------------------------------------\n";
	}
	inline void _show(Monster t){
		cout<<"------------------------------------------------------\n";
		cout<<"�ҷ���\n";
		for(int i=0;i<level;++i) cout<<s[i],cout<<"\t\t";
		cout<<endl;
		for(int i=0;i<level;++i) cout<<a[i]<<"\t\t";
		cout<<endl;
		cout<<"------------------------------------------------------\n";
		cout<<"�з���\n";
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
		cout<<"����ʼ��ս��\n";
		system("pause");
		Monster N;
		bool taop=0;
		N.init(level);
		for(int i=0;i<level;++i) a[i]+=add[i]; 
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
			Colorback();
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
			Colorback();
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
			Colorback();
		}
	}
	inline void shop(){
		Colorset(14);
		show();
		cout<<endl; 
		cout<<"--------------------------------------------------------\n��Ʒ��\n Name:\t\t";
		for(int i=0;i<level;++i) cout<<s[i],cout<<"\t\t";
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
		Colorback();
	}
	inline void addjy(){
		Colorset(11);
		cout<<"--------------------------------------------------------\n Name:\t\t";
		for(int i=0;i<level;++i) cout<<s[i],cout<<"��Ӫ\t\t";
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
		Colorback();
	}
	inline void set(){
		Colorset(10);
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
		Colorback();
	}
	inline void __pr(string s){
		for(int i=0;i<s.size();++i) cout<<s[i],Sleep(7);
	}
	inline void jj(){
		Colorset(14);
		cout<<"--------------------------------------------------------\n";
		__pr("level 1 ����:�˺�ս�������ѡ��\n\nlevel 2 Ұ����:�������ս�����˶�֪�������ˣ�\n\nlevel 3 ������:���ˣ�Զ��\n\nlevel 4 ���:�����ڻ���ս���е����ӣ�����\n\nlevel 5 ��ǹ��:Ⱥ�ˣ����˺�(������)\n\nlevel 6 ̹�ˣ���ܣ���ѹһ��\n\n");
		cout<<"--------------------------------------------------------\n";
		Colorback();
	}
}player;
