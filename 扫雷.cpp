#include"text.h"
IMAGE image,image2, lei,sign;
IMAGE pt0, pt1, pt2, pt3, pt4, pt5, pt6, pt7, pt8;
int main()
 {
	int ARR[H][W] = {0};
	srand((unsigned int)time(NULL));
	INIT(&image, &image2, &pt0, &pt1, &pt2, &pt3, &pt4,
		 &pt5, &pt6, &pt7, &pt8, &lei, &sign);       //ͼƬ���ּ���
 	INIT2(&image, &image2);          //������ʼ��
	settextcolor(YELLOW);
	settextstyle(long, long/2, "����");
    LEI(ARR);                        //����ը���±�	
    LEI_num(ARR);                    //������Χ����
	GAME(ARR, &pt0, &pt1, &pt2, &pt3, &pt4, &pt5, &pt6,
		 &pt7, &pt8, &sign, &lei, &image);            //��Ϸ����                  
	while(1);
	closegraph();
	return 0;
}
