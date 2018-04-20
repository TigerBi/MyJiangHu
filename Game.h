#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

/*******************************************
*文件名：Game.h
*描述：用来定义游戏的一些核心结构和函数
*日期：2017.5.29
*******************************************/

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/**************游戏的结构类型**************/

//地图
typedef struct _map {
    int id;
    char name[50];
    int minLevel;
    COORD coord;    //坐标结构
    char desc[500];
}Map;

//游戏道具类型枚举
typedef enum _proptype {
    Weapon, Armor, Con, Card, Frag
}PropType;

//装备
typedef struct _prop {
    int id;
    char name[50];
    int level;
    int stock;
    double price;
    PropType type;
    union {             //联合机构 多选一
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
    char type[50];  //正派，邪派
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
    //玩家的背包
    //玩家的门派
}Player;

typedef struct _monster {
    int id;
    char name[50];
    int level;
    int hp;
    int att;    //攻击力
    int deff;   //防御力
    int minMoney;   //杀死怪物后掉落的最少金币
    int maxMoney;   //做多金币
    int exp;        //经验值
    int state;      //怪物当的状态 0:怪物已死 非0表示怪物存活
    COORD coord;    //怪物的坐标
}Monster;

/**************游戏的测试函数**************/
void Init();
void Show();

/**************游戏的函数**************/
void Start();       //开始界面
void ShowWelcome(); //欢迎信息
void ShowMap();     //游戏地图
void ShowInfo();    //游戏内部信息
void showMainMenu();    //游戏的进入菜单
void ShowMapInfo();     //游戏地图的信息(信息界面中)
void ProcessMainMenu(char key); //处理游戏的主菜单

/**************主菜单函数**************/
void ShowPlayerInfo();  //信息界面显示玩家的个人资料
void ShowMonsters();    //在信息界面显示当前地图的怪物

void Fight(int monsterId);  //与怪物进行对战

void Move(int x, int y);     //回到总舵，给你坐标帮你移动


#endif // GAME_H_INCLUDED

