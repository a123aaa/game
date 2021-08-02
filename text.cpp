#include"text.h"
char p[10];
char pp[10];
char* QiZhi2(int num)
{
	sprintf(pp, "炸弹/标记旗:%d/%d",NUM/6, num);
	return pp;
}
void QiZhi(int num)
{
	outtextxy(0, 0, QiZhi2(num));
}
void WIN()
{
	outtextxy(0, 0, "游戏胜利");
}
char* Point2(int num)
{
	sprintf(p, "得分:%d", num);
	return p;
}
void Point(int num)
{
	outtextxy(12*long, 0, Point2(num));
}
void INIT(IMAGE* image, IMAGE* image2, IMAGE* pt0, IMAGE* pt1, IMAGE* pt2,IMAGE* pt3, IMAGE* pt4, IMAGE* pt5, IMAGE* pt6,IMAGE* pt7, IMAGE* pt8, IMAGE* lei,IMAGE* sign)   //图片音乐加载
{
	initgraph(width, height);
	loadimage(image, "背景.gif", long, long);
	loadimage(image2, "顶纸.gif", width, long);
	loadimage(lei, "炸弹动态图.gif", long, long);
	loadimage(sign, "标记旗.gif", long, long);
	loadimage(pt0, "0.gif", long, long);
	loadimage(pt1, "1.gif", long, long);
	loadimage(pt2, "2.gif", long, long);
	loadimage(pt3, "3.gif", long, long);
	loadimage(pt4, "4.gif", long, long);
	loadimage(pt5, "5.gif", long, long);
	loadimage(pt6, "6.gif", long, long);
	loadimage(pt7, "7.gif", long, long);
	loadimage(pt8, "8.gif", long, long);
}
void INIT2(IMAGE* image, IMAGE* image2)           //背景初始化
{
	for (int x = 0; x < width; x += long)
		for (int y = long; y < height; y += long)
			putimage(x, y, image);
    putimage(0, 0, image2);
}
void LEI(int ARR[H][W])      //设置炸弹的下标
{
	int flog = 0;
	while(flog<NUM/6)
	{
		int i = rand() % h+1 ;
		int j = rand() % w+1 ;
		if (!ARR[i][j])
		{
			ARR[i][j] = -1;
			flog++;
		}		
	}
}
void LEI_num(int ARR[H][W])             //计算周围雷数
{
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			if (ARR[i][j] != -1)
				for (int a = i - 1,flog1 = 0; flog1 <3; a++,flog1++)
					for (int b = j - 1, flog2 = 0; flog2 < 3; b++,flog2++)
						if (ARR[a][b] == -1)
							ARR[i][j]++;
}
void OVER()
{
	outtextxy(0,0,"游戏结束");
}
void BOMB(int ARR[H][W], IMAGE* lei)          //打印雷
{
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			if (ARR[i][j] == -1)
				putimage((j - 1) * long, i * long, lei);
}
int num_photo(int i,int j, int ARR[H][W], IMAGE* pt0, IMAGE* pt1, IMAGE* pt2, IMAGE* pt3, IMAGE* pt4, IMAGE* pt5, IMAGE* pt6, IMAGE* pt7, IMAGE* pt8, IMAGE* lei,int* socre)       //数字和雷图片
{
	if (ARR[i][j] == 0)
	{
		putimage((j - 1) * long, i * long, pt0);
		(*socre)++;
		ARR[i][j] -= 20;
		return 1;
	}
	if (ARR[i][j] == 1)
	{
		putimage((j - 1) * long, i * long, pt1);
		(*socre)++;
		ARR[i][j] -= 20;
		return 1;
	}
	if (ARR[i][j] == 2)
	{
		putimage((j - 1) * long, i * long, pt2);
		(*socre)++;
		ARR[i][j] -= 20;
		return 1;
	}
	if (ARR[i][j] == 3)
	{
		putimage((j - 1) * long, i * long, pt3);
		(*socre)++;
		ARR[i][j] -= 20;
		return 1;
	}
	if (ARR[i][j] == 4)
	{
		putimage((j - 1) * long, i * long, pt4);
		(*socre)++;
		ARR[i][j] -= 20;
		return 1;
	}
	if (ARR[i][j] == 5)
	{
		putimage((j - 1) * long, i * long, pt5);
		(*socre)++;
		ARR[i][j] -= 20;
		return 1;
	}
	if (ARR[i][j] == 6)
	{
		putimage((j - 1) * long, i * long, pt6);
		(*socre)++;
		ARR[i][j] -= 20;
		return 1;
	}
	if (ARR[i][j] == 7)
	{
		putimage((j - 1) * long, i * long, pt7);
		(*socre)++;
		ARR[i][j] -= 20;
		return 1;
	}
	if (ARR[i][j] == 8)
	{
		putimage((j - 1) * long, i * long, pt8);
		(*socre)++;
		ARR[i][j] -= 20;
		return 1;
	}
	if (ARR[i][j] == -1)
	{
		BOMB(ARR, lei);
		return 0;
	}
}
void num_photo2(int i, int j, IMAGE* sign,int ARR[H][W],IMAGE* image,int* num)       //标记图片
{
	if (ARR[i][j] < 10)
	{
		putimage((j - 1) * long, i * long, sign);
		ARR[i][j] += 20;
		(*num)++;
	}
	else
	{
		putimage((j - 1) * long, i * long, image);
		ARR[i][j] -= 20;
		(*num)--;
	}
}
void GAME(int ARR[H][W], IMAGE* pt0, IMAGE* pt1, IMAGE* pt2, IMAGE* pt3, IMAGE* pt4, IMAGE* pt5, IMAGE* pt6, IMAGE* pt7, IMAGE* pt8, IMAGE* sign, IMAGE* lei,IMAGE* image)
{
	int flog = 1;
	int num = 0;
	int score = 0;
	QiZhi(num);
	while (flog)
	{
		int i, j;
		MOUSEMSG msg = { 0 };
		msg = GetMouseMsg();
		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN:
			i = msg.y / long;
			j = msg.x / long + 1;
			flog = num_photo(i, j, ARR, pt0, pt1, pt2, pt3, pt4, pt5, pt6, pt7, pt8, lei,&score);
			if(NUM/6*5-score==0)
				WIN();
			Point(score);
			break;
		case WM_RBUTTONDOWN:
			i = msg.y / long;
			j = msg.x / long + 1;
			num_photo2(i, j, sign, ARR, image, &num);
			QiZhi(num);
			break;
		}
	}
	OVER();
}




