#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

/*******************************************
*�ļ�����Game.h
*����������������Ϸ��һЩ���Ľṹ�ͺ���
*���ڣ�2017.5.29
*******************************************/

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/**************��Ϸ�Ľṹ����**************/

//��ͼ
typedef struct _map {
    int id;
    char name[50];
    int minLevel;
    COORD coord;    //����ṹ
    char desc[500];
}Map;

//��Ϸ��������ö��
typedef enum _proptype {
    Weapon, Armor, Con, Card, Frag
}PropType;

//װ��
typedef struct _prop {
    int id;
    char name[50];
    int level;
    int stock;
    double price;
    PropType type;
    union {             //���ϻ��� ��ѡһ
        int minAttack;
        int minDefence;
        int minPower;
    };
    union {
        int maxAttack;
        int maxDefence;
        int maxPower
    };
    char desc[200];
}Prop;
typedef struct _martial {
    int id;
    char name[50];
    char type[50];  //���ɣ�а��
    COORD hqCoord;
    int isOpen;
    char desc[1000];
}Martial;
typedef struct _player {
    int id;
    char name[50];
    char pass[50];
    int life;
    int level;
    int exp;
    int hp;
    int mp;
    int mpMax;
    int gold;
    Martial martial;
    Prop weapon;
    Prop armor;
    COORD coord;
    //��ҵı���
    //��ҵ�����
}Player;

typedef struct _monster {
    int id;
    char name[50];
    int level;
    int hp;
    int att;    //������
    int deff;   //������
    int minMoney;   //ɱ��������������ٽ��
    int maxMoney;   //������
    int exp;        //����ֵ
    int state;      //���ﵱ��״̬ 0:�������� ��0��ʾ������
    COORD coord;    //���������
}Monster;

/**************��Ϸ�Ĳ��Ժ���**************/
void Init();
void Show();

/**************��Ϸ�ĺ���**************/
void Start();       //��ʼ����
void ShowWelcome(); //��ӭ��Ϣ
void ShowMap();     //��Ϸ��ͼ
void ShowInfo();    //��Ϸ�ڲ���Ϣ
void showMainMenu();    //��Ϸ�Ľ���˵�
void ShowMapInfo();     //��Ϸ��ͼ����Ϣ(��Ϣ������)
void ProcessMainMenu(char key); //������Ϸ�����˵�

/**************���˵�����**************/
void ShowPlayerInfo();  //��Ϣ������ʾ��ҵĸ�������
void ShowMonsters();    //����Ϣ������ʾ��ǰ��ͼ�Ĺ���

void Fight(int monsterId);  //�������ж�ս

void Move(int x, int y);     //�ص��ܶ棬������������ƶ�


#endif // GAME_H_INCLUDED

