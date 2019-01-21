#include<iostream>
#include<windows.h>
 
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0) //必要的，我是背下来的 
 
using namespace std;
 
void color(int a){//改变输出的颜色，比system("color x")快得多
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
/*
<span style="white-space:pre">	</span>字 
	1	深蓝色
	2	深绿色
	3	深青色 
	4	深红色
	5	深粉色
	6	黄色
	7	深白色
	8	灰色
	9	浅蓝色
	10	浅绿色 
	11	浅青色 
	12	浅红色 
	13	浅粉色 
	14	浅黄色 
	15	浅白色 
	
	背景
	1~15		黑色 
	16~31		深蓝色 
	32~47		深绿色
	48~63		深青色
	64~79		深红色
	80~95		深粉色
	96~111		深黄色
	112~127 	深白色
	128~143 	灰色
	144~159 	浅蓝色
	160~175 	浅绿色
	176~191 	浅青色
	192~207 	浅红色
	208~223 	浅粉色
	224~239 	浅黄色
	240~255 	浅白色
*/
}
 
void check(char c){//检测某个按键是否按下，按下就改变输出颜色
	if(!KEY_DOWN(c))color(7);
	else color(112);
	printf("  %c  ",c);
	color(7);
}
 
int main(){
	while(1){
		check('Q');check('W');check('E');check('R');check('T');check('Y');check('U');check('I');check('O');check('P');
		printf("\n\n ");
		check('A');check('S');check('D');check('F');check('G');check('H');check('J');check('K');check('L');
		printf("\n\n  ");
		check('Z');check('X');check('C');check('V');check('B');check('N');check('M');
		
		Sleep(20);//循环时间间隔，防止太占内存 
		system("cls");//清屏 
	}
 
	return 0;
}
