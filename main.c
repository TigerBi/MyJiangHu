#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "GameLib.h"
#include <conio.h>

#include<windows.h>
#include<mmsystem.h>
#pragma comment(lib, "winmm.lib")

extern int X, Y;

//�û���ȫ�ֱ�������

int main()
{
    char key;   //���յ����û�����
    PlaySound("MP1.wav",NULL,SND_FILENAME|SND_ASYNC |SND_LOOP);
    //���ÿ���̨����
    SetTitle("[��ϰ��Ʒ]Ц������֮���ұ���       ����:����");
    //����������ɫ
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
            //printf("1-5֮�����Ϸ�˵�");
            ProcessMainMenu(key);
            continue;
        }else if(key == 38 || key == 72) { // ��
            Y--;
        }else if(key == 39 || key == 77) {   //��
            X++;
        }else if(key == 40 || key == 80) {   //��
            Y++;
        }else if(key == 37 || key == 75) {   //��
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
