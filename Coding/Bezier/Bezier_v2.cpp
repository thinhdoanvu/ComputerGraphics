#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define max_dinh 4

int x[4], y[4];
int i;

void control(){
	x[0]=10; y[0]=10;
	x[1]=200; y[1]=400;
	//x[2]=250; y[2]=250;
	x[2]=350; y[2]=250;
	x[3]=300; y[3]=100;
	for(int i=0; i<3; i++){
		setcolor(4);
		line(x[i], y[i], x[i+1], y[i+1]);
	}
}

void bezier(){
	double t;
	for(t=0.0; t<1.0; t=t+0.00005){
		double xt=pow(1-t,3)*x[0] + 3*t*pow(1-t,2)*x[1] + 3*pow(t,2)*(1-t)*x[2] + pow(t,3)*x[3];
		double yt=pow(1-t,3)*y[0] + 3*t*pow(1-t,2)*y[1] + 3*pow(t,2)*(1-t)*y[2] + pow(t,3)*y[3];
		putpixel(xt,yt,WHITE);
  	}
 }

int main()
{
	initwindow(600,600);
	//ve cac diem control
	control(); 
	//ve duong cong
	bezier();
	getch();
}
