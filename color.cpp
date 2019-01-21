#include<windows.h>
#include<conio.h> 
using namespace std;
inline void Colorset(int color)   /*调整字体颜色*/
{
    /* Has passed the test. */
    /* help : FOREGROUND_BLUE    字体颜色：蓝    1
        FOREGROUND_GREEN    字体颜色：绿    2
        FOREGROUND_RED    字体颜色：红    4
        FOREGROUND_INTENSITY    前景色高亮显示    8
        BACKGROUND_BLUE    背景颜色：蓝    16
        BACKGROUND_GREEN    背景颜色：绿    32
        BACKGROUND_RED    背景颜色：红    64
        BACKGROUND_INTENSITY    背景色高亮显示    128
    */
    HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hOut,color);
}
inline void Colorback()   /*调回字体颜色*/
{
    HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hOut,FOREGROUND_RED |
                            FOREGROUND_GREEN |
                            FOREGROUND_BLUE);
}
