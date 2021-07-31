#include"text.h"
char p[2],pp[2];
void INIT(IMAGE* image,IMAGE* a,IMAGE* b)    //设置图片,音乐,字母
{
	initgraph(1400, 700);
	loadimage(image, "蓝玫瑰.jpg", 1400, 700);
	loadimage(a, "草莓掩码.jpg", 40, 40);
	loadimage(b, "草莓.jpg", 40, 40);
	settextstyle(25, 25, "楷体");
	mciSendString("open 窗.mp3", 0, 0, 0);
	mciSendString("play 窗.mp3", 0, 0, 0);
	putimage(0, 0, image);
}
void FZ(int* x, int* y, int* t)   //结构体赋值
{
    *x = rand() % 1350 + 5;
	*y = rand() % 500 - 500;
	*t = rand() % 26 + 97;
}
char* ZM(int t)                //字母设置
{
	sprintf(p, "%c", t);
	return p;
}
char* FS(int t)                //分数设置
{
	sprintf(pp, "得分:%d", t);
	return pp;
}
void INput(int x, int y, int t, IMAGE image, IMAGE a, IMAGE b)  //加载草莓
{
	putimage(x, y, &a, SRCAND);
	putimage(x, y, &b, SRCPAINT);
	setbkmode(TRANSPARENT);
	outtextxy(x + 8, y + 4, ZM(t));
}
void pause(char key)             //暂停功能
{
	if (key==' ')
		while (_getch()!= ' ');
}
int judge(char key,char zf, int* x, int* y, int* t)            //判断功能
{
	if (key == zf)
	{
		FZ(x, y, t);
		return 1;
	}
	else
		return 0;

}

