#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>                   //时间种子
#include<graphics.h>               //游戏窗口
#include<conio.h>                  //按键相关
#define width 760                 //游戏窗口宽
#define height 760                 //游戏窗口高
#define long 40                    //图片边长
#define height2 (height-long)      //有效窗口高
#define NUM width * height2 / long / long          //图片数目
#define H (height2 / long + 2)     //二维数组-行
#define W (width / long + 2 )      //二维数组-列
#define h (height2 / long)         //图片-行数
#define w (width / long )          //图片-列数
void INIT(IMAGE* image, IMAGE* image2, IMAGE* pt0, IMAGE* pt1, IMAGE* pt2, IMAGE* pt3, IMAGE* pt4,
	      IMAGE* pt5, IMAGE* pt6, IMAGE* pt7, IMAGE* pt8, IMAGE* lei, IMAGE* sign);   //图片音乐加载
void INIT2(IMAGE* image, IMAGE* image2);           //背景初始化
void LEI(int ARR[H][W]);                           //设置炸弹下标
void LEI_num(int ARR[H][W]);                       //计算周围雷数
void GAME(int ARR[H][W], IMAGE* pt0, IMAGE* pt1, IMAGE* pt2, IMAGE* pt3, IMAGE* pt4, IMAGE* pt5,
	     IMAGE* pt6, IMAGE* pt7, IMAGE* pt8,  IMAGE* sign,IMAGE* lei,IMAGE* image);    //游戏程序






