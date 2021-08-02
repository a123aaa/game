#include"text.h"
IMAGE image,image2, lei,sign;
IMAGE pt0, pt1, pt2, pt3, pt4, pt5, pt6, pt7, pt8;
int main()
 {
	int ARR[H][W] = {0};
	srand((unsigned int)time(NULL));
	INIT(&image, &image2, &pt0, &pt1, &pt2, &pt3, &pt4,
		 &pt5, &pt6, &pt7, &pt8, &lei, &sign);       //图片音乐加载
 	INIT2(&image, &image2);          //背景初始化
	settextcolor(YELLOW);
	settextstyle(long, long/2, "宋体");
    LEI(ARR);                        //设置炸弹下标	
    LEI_num(ARR);                    //计算周围雷数
	GAME(ARR, &pt0, &pt1, &pt2, &pt3, &pt4, &pt5, &pt6,
		 &pt7, &pt8, &sign, &lei, &image);            //游戏程序                  
	while(1);
	closegraph();
	return 0;
}
