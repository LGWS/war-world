#include<iostream>
#include<windows.h>
 
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0) //��Ҫ�ģ����Ǳ������� 
 
using namespace std;
 
void color(int a){//�ı��������ɫ����system("color x")��ö�
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
/*
<span style="white-space:pre">	</span>�� 
	1	����ɫ
	2	����ɫ
	3	����ɫ 
	4	���ɫ
	5	���ɫ
	6	��ɫ
	7	���ɫ
	8	��ɫ
	9	ǳ��ɫ
	10	ǳ��ɫ 
	11	ǳ��ɫ 
	12	ǳ��ɫ 
	13	ǳ��ɫ 
	14	ǳ��ɫ 
	15	ǳ��ɫ 
	
	����
	1~15		��ɫ 
	16~31		����ɫ 
	32~47		����ɫ
	48~63		����ɫ
	64~79		���ɫ
	80~95		���ɫ
	96~111		���ɫ
	112~127 	���ɫ
	128~143 	��ɫ
	144~159 	ǳ��ɫ
	160~175 	ǳ��ɫ
	176~191 	ǳ��ɫ
	192~207 	ǳ��ɫ
	208~223 	ǳ��ɫ
	224~239 	ǳ��ɫ
	240~255 	ǳ��ɫ
*/
}
 
void check(char c){//���ĳ�������Ƿ��£����¾͸ı������ɫ
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
		
		Sleep(20);//ѭ��ʱ��������ֹ̫ռ�ڴ� 
		system("cls");//���� 
	}
 
	return 0;
}
