#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define max_dinh 4

int x[4], y[4];
int i;

//nhap cac dinh
void nhapdinh()
{
	 for(i=0;i<4;i++)
	 {
	 	  printf("x[%d]= ",i);
	 	  scanf("%d",&x[i]);
	 	  printf("y[%d]= ",i);
	 	  scanf("%d",&y[i]);
		}
}

//ve cac dinh
void vedinh()
{
	  for(i=0;i<3;i++)
	  {
	  	  line(x[i],y[i],x[i+1],y[i+1]);
			}
}

void bezier()
{
	  double t;
	  
	  for(t=0.0; t<1.0; t=t+0.00005)
	  {
	  	  double xt=pow(1-t,3)*x[0] + 3*t*pow(1-t,2)*x[1] + 3*pow(t,2)*(1-t)*x[2] + pow(t,3)*x[3];
			   double yt=pow(1-t,3)*y[0] + 3*t*pow(1-t,2)*y[1] + 3*pow(t,2)*(1-t)*y[2] + pow(t,3)*y[3];
			  putpixel(xt,yt,WHITE);
  }
  
  //ve 4 dinh da set
  for(i=0;i<4;i++)
  {
  	  putpixel(x[i],y[i],RED);
		}
		
		getch();
 }

int main()
{
	  //nhap toa do
	  nhapdinh();
	  
	  initwindow(600,600);
	  
	  //ve cac dinh
	  setcolor(GREEN);
	  vedinh();
	  
	  //ve duong cong
	  bezier();
	  
	  getch();
}

