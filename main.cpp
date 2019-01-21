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
	__pr("欢迎来到战争世界！ 作者：洛谷万岁\n\n请把这个文件夹(WarWorld)移至桌面！！\n");
	__pr("\t\t\t~~我是一个大蒟蒻！！！~~\n"); 
	player.init();
	player.show();
	system("pause");
	__pr("是否导入？是输入1，否则输入0\n");
	int tttttt;
	cin>>tttttt;
	if(tttttt) rd();
	__pr("军营：每此战役前自动增加一些人数\n\n\t\t有2个彩蛋！！！有1个彩蛋中还有一个彩蛋！！！\n\n\n**提示：可以在设置中关闭逃跑系统！！！**\n\n\n\n\t建议先查看部队简介!!!\n\n");
	system("pause");
	__pr("\n\n\t\t\t**输入的都是从1开始的序号!!!!!**\n\n\n");
	Colorback();
	while(1){
		Colorset(10); 
		cout<<"------------------------------------------------------\n1:fight 2:shop 3:show 4:cls(清屏) 5:升级军营 6:设置 7:部队简介 8:存档 9:退出游戏 ";
		if(opencp) __pr("10:彩票世界 ");
		if(openmh) __pr("11:荒芜世界 ");
		if(kswj) __pr("12:游戏的尽头（完成即可通关）\n");
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
			__pr("存档:两个附属世界都得重新开始(钱、人、军营、设置···不会丢，而且防更改)，确定？\n确定输入1，否则输入0\n");
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
			__pr("恭喜开启彩票世界！！！\n");
			system("pause");
			opencp=1;
			Colorback();
		}
		if(player.level==6 and !openmh){
			Colorset(90);
			__pr("恭喜开启荒芜世界模式！！！\n");
			system("pause");
			openmh=1;
			Colorback();
		}
		if(player.level==6 and player.exp>100000 and !kswj){
			Colorset(135);
			__pr("恭喜开启尽头！！！\n");
			__pr("完成即可通关！！！\n");
			kswj=1;
			system("pause");
			Colorback();
		}
		Colorback();
		cout<<"------------------------------------------------------\n";
	}
}
