'''
#include<graphics.h>  
#include<stdio.h>  
#define INPUT "dagiac.txt"  
#define MAX 20  
#include<limits.h>  
#include<algorithm>  
#include<math.h>  

using namespace std;  

int sodinh;  
struct point{  
	int x,y;  
};  

struct point p[MAX];  
FILE *fp;  

void readfile(){  
	fp =fopen(INPUT,"r");  
	if(fp==NULL){  
		printf("file not found");  
		return;  
	}  
	//doc so dinh  
	fscanf(fp,"%d",&sodinh);  
	printf("So dinh cua da giac: %d",sodinh);  
	//doc toa do cac dinh  
	for(int i=0; i<sodinh; i++){  
		fscanf(fp,"%d %d",&p[i].x,&p[i].y);  
	}  
	//them 1 dinh  
	p[sodinh]=p[0];  
	sodinh++;  
	//in ra man hinh toa do cac dinh  
	printf("\nToa do cac dinh:\n");  
	for(int i=0;i<sodinh;i++){  
		printf("%d, %d\n",p[i].x,p[i].y);  
	}  
}  

void draw(){  
	for(int i=0; i<sodinh-1; i++){  
		line(p[i].x,p[i].y,p[i+1].x,p[i+1].y);  
	}  
}  

void tinhtien(int dx, int dy){  
	for(int i=0; i<sodinh; i++){  
		p[i].x += dx;  
		p[i].y += dy;  
	}  
}  

void quay(int xr, int yr, float phi){  
	float rad = (float)phi*3.1416/180;  
	for(int i=0; i<sodinh; i++){  
		float dx = (float)(p[i].x - xr);//chuyen sang so thuc  
		float dy = (float)(p[i].y - yr);//chuyen sang so thuc  
		p[i].x = xr + dx*cos(rad) - dy*sin(rad);  
		p[i].y = yr + dx*sin(rad) + dy*cos(rad);  
	}  
//	for(int i=0; i<sodinh; i++){  
//		printf("%d,%d\n",p[i].x,p[i].y);  
//	}  
}  

int main(){  
	readfile();  
	initwindow(600,600);  
	setcolor(2);//chon mau  
	setlinestyle(0,1,1);//tang kich thuoc duong ve  
	draw();  
	setcolor(4);//chon mau  
	setlinestyle(1,1,1);//tang kich thuoc duong ve  
	for(int i=0; i<18; i++){  
		quay(200,200,i);  
		draw();  
		delay(200);  
	}  
	getch();  
	return 0;  
}  
'''

![image](https://github.com/user-attachments/assets/dfebc2df-2284-422e-8433-1d203a747cc3)

![image](https://github.com/user-attachments/assets/c771e71b-05ee-4c04-b17e-830906b9912f)


