#include"text.h"
IMAGE image, a, b;
struct MESS
{
   int x; int y; int t;
}APP[NUM];
int x, y, t;                //(x,y)坐标和符号值
int CMP(const void* a, const void* b)     //排序
{
	return ((struct MESS*)a)->y - ((struct MESS*)b)->y;
}
void GAME()                //游戏程序
{
	int score = 0,speed=1;
	while (score<=500)
	{
		for (int i = 0; i < NUM; i++)         //给结构体赋值
			FZ(&APP[i].x, &APP[i].y, &APP[i].t);
		qsort(APP, NUM, sizeof(APP[0]), CMP); //按y值递增排序
		while (APP[0].y<=700)
		{
			BeginBatchDraw();
			putimage(0, 0, &image);           //背景打印	
			for (int i = 0; i < NUM; i++)     //打印草莓
			{
				INput(APP[i].x, APP[i].y, APP[i].t, image, a, b);  //打印草莓
				APP[i].y += speed;
			}
			if (_kbhit())    //字符输入
			{
				char key = _getch();
				pause(key);      //暂停功能
				for (int i = NUM-1; i >=0 ; i--)
					if (judge(key, APP[i].t, &APP[i].x, &APP[i].y, &APP[i].t))      //判断功能
					{
						score++;
						qsort(APP, NUM, sizeof(APP[0]), CMP); //按y值递增排序
						break;
					}
			}
			if ((score + 1) % 50 == 0)
			{
				speed ++;
				score++;
			}
			setbkmode(TRANSPARENT);
			outtextxy(0, 0, FS(score));       //分数打印
			EndBatchDraw();
		}
	}
}
int main()
 {
	srand((unsigned int)time(NULL));   //时间种子
	INIT(&image, &a, &b);              //窗口设置
	GAME();                            //游戏程序
	while(1);
	mciSendString("close 窗.mp3", 0, 0, 0);
	closegraph();
	return 0;
}