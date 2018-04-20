#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "GameLib.h"
#include <conio.h>

#include<windows.h>
#include<mmsystem.h>
#pragma comment(lib, "winmm.lib")

extern int X, Y;

//用户的全局变量坐标

int main()
{
    char key;   //接收到的用户按键
    PlaySound("MP1.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
    //设置控制台名称
    SetTitle("[练习作品]笑傲江湖之精忠报国       作者:永恒");
    //更改字体颜色
    SetColor(10, 0);
    Init();
    Start();
    ShowWelcome();
    ShowMap();
    ShowInfo();
    showMainMenu();

    while(1) {
        fflush(stdin);
        key = getch();
        fflush(stdin);
        if(key == '1' || key == '2' || key =='3' || key == '4' || key == '5') {
            //printf("1-5之间的游戏菜单");
            ProcessMainMenu(key);
            continue;
        }else if(key == 38 || key == 72) { // 上
            Y--;
        }else if(key == 39 || key == 77) {   //右
            X++;
        }else if(key == 40 || key == 80) {   //下
            Y++;
        }else if(key == 37 || key == 75) {   //左
            X--;
        }

        if(X > 7) X = 0;
        if(X < 0) X = 7;
        if(Y > 7) Y = 0;
        if(Y < 0) Y = 7;
        ShowMap();
    }

    return 0;
}
