#define openg
#include<bits/stdc++.h>
#include<conio.h>
#define mp make_pair
#include<fstream>
#include "Player.cpp"
#include "ZombieGame.cpp"
#include "CaiPiaoGame.cpp"
#include "Read.cpp"
#include "Write.cpp"
#include "End.cpp"
#include<windows.h>
using namespace std;
int main(){
	int i,j;
	srand(time(NULL));
	for(i=0;i<6;++i) for(j=0;j<6;++j) swap(take[i][j].first,take[i][j].second);
	Colorset(11);
	__pr("��ӭ����ս�����磡 ���ߣ��������\n\n�������ļ���(WarWorld)�������棡��\n");
	__pr("\t\t\t~~����һ�����X�m������~~\n"); 
	player.init();
	player.show();
	system("pause");
	__pr("�Ƿ��룿������1����������0\n");
	int tttttt;
	cin>>tttttt;
	if(tttttt) rd();
	__pr("��Ӫ��ÿ��ս��ǰ�Զ�����һЩ����\n\n\t\t��2���ʵ���������1���ʵ��л���һ���ʵ�������\n\n\n**��ʾ�������������йر�����ϵͳ������**\n\n\n\n\t�����Ȳ鿴���Ӽ��!!!\n\n");
	system("pause");
	__pr("\n\n\t\t\t**����Ķ��Ǵ�1��ʼ�����!!!!!**\n\n\n");
	Colorback();
	while(1){
		Colorset(10); 
		cout<<"------------------------------------------------------\n1:fight 2:shop 3:show 4:cls(����) 5:������Ӫ 6:���� 7:���Ӽ�� 8:�浵 9:�˳���Ϸ ";
		if(opencp) __pr("10:��Ʊ���� ");
		if(openmh) __pr("11:�������� ");
		if(kswj) __pr("12:��Ϸ�ľ�ͷ����ɼ���ͨ�أ�\n");
		__pr("\n");
		Colorback();
		int t;
		cin>>t;
		while(t<1 or t>9+openmh+opencp+kswj){
			__pr("again!\n");
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
			Colorset(123);
			__pr("�浵:�����������綼�����¿�ʼ(Ǯ���ˡ���Ӫ�����á��������ᶪ�����ҷ�����)��ȷ����\nȷ������1����������0\n");
			Colorback();
			int t;
			cin>>t;
			if(t) cd();
		}else if(t==9) exit(0);
		else if(t==10) player=cip.main(player);
		else if(t==11) player=zbgg.gd(player);
		else if(t==12) Theend.The_end();
		if(player.level==4 and !opencp){
			Colorset(90);
			__pr("��ϲ������Ʊ���磡����\n");
			system("pause");
			opencp=1;
			Colorback();
		}
		if(player.level==6 and !openmh){
			Colorset(90);
			__pr("��ϲ������������ģʽ������\n");
			system("pause");
			openmh=1;
			Colorback();
		}
		if(player.level==6 and player.exp>100000 and !kswj){
			Colorset(135);
			__pr("��ϲ������ͷ������\n");
			__pr("��ɼ���ͨ�أ�����\n");
			kswj=1;
			system("pause");
			Colorback();
		}
		Colorback();
		cout<<"------------------------------------------------------\n";
	}
}
