#include<windows.h>
#include<conio.h> 
using namespace std;
inline void Colorset(int color)   /*����������ɫ*/
{
    /* Has passed the test. */
    /* help : FOREGROUND_BLUE    ������ɫ����    1
        FOREGROUND_GREEN    ������ɫ����    2
        FOREGROUND_RED    ������ɫ����    4
        FOREGROUND_INTENSITY    ǰ��ɫ������ʾ    8
        BACKGROUND_BLUE    ������ɫ����    16
        BACKGROUND_GREEN    ������ɫ����    32
        BACKGROUND_RED    ������ɫ����    64
        BACKGROUND_INTENSITY    ����ɫ������ʾ    128
    */
    HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hOut,color);
}
inline void Colorback()   /*����������ɫ*/
{
    HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hOut,FOREGROUND_RED |
                            FOREGROUND_GREEN |
                            FOREGROUND_BLUE);
}
