#include"text.h"
IMAGE image, a, b;
struct MESS
{
   int x; int y; int t;
}APP[NUM];
int x, y, t;                //(x,y)����ͷ���ֵ
int CMP(const void* a, const void* b)     //����
{
	return ((struct MESS*)a)->y - ((struct MESS*)b)->y;
}
void GAME()                //��Ϸ����
{
	int score = 0,speed=1;
	while (score<=500)
	{
		for (int i = 0; i < NUM; i++)         //���ṹ�帳ֵ
			FZ(&APP[i].x, &APP[i].y, &APP[i].t);
		qsort(APP, NUM, sizeof(APP[0]), CMP); //��yֵ��������
		while (APP[0].y<=700)
		{
			BeginBatchDraw();
			putimage(0, 0, &image);           //������ӡ	
			for (int i = 0; i < NUM; i++)     //��ӡ��ݮ
			{
				INput(APP[i].x, APP[i].y, APP[i].t, image, a, b);  //��ӡ��ݮ
				APP[i].y += speed;
			}
			if (_kbhit())    //�ַ�����
			{
				char key = _getch();
				pause(key);      //��ͣ����
				for (int i = NUM-1; i >=0 ; i--)
					if (judge(key, APP[i].t, &APP[i].x, &APP[i].y, &APP[i].t))      //�жϹ���
					{
						score++;
						qsort(APP, NUM, sizeof(APP[0]), CMP); //��yֵ��������
						break;
					}
			}
			if ((score + 1) % 50 == 0)
			{
				speed ++;
				score++;
			}
			setbkmode(TRANSPARENT);
			outtextxy(0, 0, FS(score));       //������ӡ
			EndBatchDraw();
		}
	}
}
int main()
 {
	srand((unsigned int)time(NULL));   //ʱ������
	INIT(&image, &a, &b);              //��������
	GAME();                            //��Ϸ����
	while(1);
	mciSendString("close ��.mp3", 0, 0, 0);
	closegraph();
	return 0;
}