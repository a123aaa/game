#include"text.h"
char p[2],pp[2];
void INIT(IMAGE* image,IMAGE* a,IMAGE* b)    //����ͼƬ,����,��ĸ
{
	initgraph(1400, 700);
	loadimage(image, "��õ��.jpg", 1400, 700);
	loadimage(a, "��ݮ����.jpg", 40, 40);
	loadimage(b, "��ݮ.jpg", 40, 40);
	settextstyle(25, 25, "����");
	mciSendString("open ��.mp3", 0, 0, 0);
	mciSendString("play ��.mp3", 0, 0, 0);
	putimage(0, 0, image);
}
void FZ(int* x, int* y, int* t)   //�ṹ�帳ֵ
{
    *x = rand() % 1350 + 5;
	*y = rand() % 500 - 500;
	*t = rand() % 26 + 97;
}
char* ZM(int t)                //��ĸ����
{
	sprintf(p, "%c", t);
	return p;
}
char* FS(int t)                //��������
{
	sprintf(pp, "�÷�:%d", t);
	return pp;
}
void INput(int x, int y, int t, IMAGE image, IMAGE a, IMAGE b)  //���ز�ݮ
{
	putimage(x, y, &a, SRCAND);
	putimage(x, y, &b, SRCPAINT);
	setbkmode(TRANSPARENT);
	outtextxy(x + 8, y + 4, ZM(t));
}
void pause(char key)             //��ͣ����
{
	if (key==' ')
		while (_getch()!= ' ');
}
int judge(char key,char zf, int* x, int* y, int* t)            //�жϹ���
{
	if (key == zf)
	{
		FZ(x, y, t);
		return 1;
	}
	else
		return 0;

}

