#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<graphics.h>
#include<conio.h>                   //按键相关头文件
#include<mmsystem.h>                //音乐库
#pragma comment(lib,"winmm.lib")    //静态音乐库
#define NUM 20
void INIT(IMAGE* image, IMAGE* a, IMAGE* b);   //设置图片,音乐,字母
void FZ(int* x, int* y, int* t);      //结构体赋值
char* ZM(int t);         //字母设置 
char* FS(int t);          //分数设置
void INput(int x,int y,int t, IMAGE image, IMAGE a, IMAGE b);      //草莓加载
void pause(char key);    //暂停功能
int judge(char key,char zf, int* x, int* y, int* t);    //判断功能








