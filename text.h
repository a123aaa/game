#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>                   //ʱ������
#include<graphics.h>               //��Ϸ����
#include<conio.h>                  //�������
#define width 760                 //��Ϸ���ڿ�
#define height 760                 //��Ϸ���ڸ�
#define long 40                    //ͼƬ�߳�
#define height2 (height-long)      //��Ч���ڸ�
#define NUM width * height2 / long / long          //ͼƬ��Ŀ
#define H (height2 / long + 2)     //��ά����-��
#define W (width / long + 2 )      //��ά����-��
#define h (height2 / long)         //ͼƬ-����
#define w (width / long )          //ͼƬ-����
void INIT(IMAGE* image, IMAGE* image2, IMAGE* pt0, IMAGE* pt1, IMAGE* pt2, IMAGE* pt3, IMAGE* pt4,
	      IMAGE* pt5, IMAGE* pt6, IMAGE* pt7, IMAGE* pt8, IMAGE* lei, IMAGE* sign);   //ͼƬ���ּ���
void INIT2(IMAGE* image, IMAGE* image2);           //������ʼ��
void LEI(int ARR[H][W]);                           //����ը���±�
void LEI_num(int ARR[H][W]);                       //������Χ����
void GAME(int ARR[H][W], IMAGE* pt0, IMAGE* pt1, IMAGE* pt2, IMAGE* pt3, IMAGE* pt4, IMAGE* pt5,
	     IMAGE* pt6, IMAGE* pt7, IMAGE* pt8,  IMAGE* sign,IMAGE* lei,IMAGE* image);    //��Ϸ����






