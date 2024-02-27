//DDA: y=mx+b 
//yi = mxi + b
//yi+1 = mxi+1 +b
//xet m<1, x++: xi+1 = xi+1
//yi+1 = m(xi+1) +b
//yi+1=yi+m
//A(20,30) - B(120,80)

#include <stdio.h>
#include <graphics.h>

int lt(float a){
	return (a+0.5);	
} 

float m;
int x;
float y;

void dda1(int xa, int ya, int xb, int yb){//m<1, xb>xa, yb>ya
	int dy=yb-ya;
	int dx=xb-xa;
	m=(float)dy/dx;
	printf("m= %f",m);
	x=xa;
	y=ya;
	putpixel(x,y,255);
	while(x<xb){
		x++;
		y=y+m;
		putpixel(x,lt(y),255);
		printf("(%d,%d)\n",x,lt(y));
		delay(200);
	}
}
int main()
{	
	initwindow(800,800);
	dda1(20,30,120,80);
	getch();
}
