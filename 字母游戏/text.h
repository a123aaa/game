#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<graphics.h>
#include<conio.h>                   //�������ͷ�ļ�
#include<mmsystem.h>                //���ֿ�
#pragma comment(lib,"winmm.lib")    //��̬���ֿ�
#define NUM 20
void INIT(IMAGE* image, IMAGE* a, IMAGE* b);   //����ͼƬ,����,��ĸ
void FZ(int* x, int* y, int* t);      //�ṹ�帳ֵ
char* ZM(int t);         //��ĸ���� 
char* FS(int t);          //��������
void INput(int x,int y,int t, IMAGE image, IMAGE a, IMAGE b);      //��ݮ����
void pause(char key);    //��ͣ����
int judge(char key,char zf, int* x, int* y, int* t);    //�жϹ���








