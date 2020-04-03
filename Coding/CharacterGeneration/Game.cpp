//khai bao thu vien
#include<graphics.h>
#include<stdio.h>
#include<math.h>

//khai bao bien
int x,y;
int i,j,kk;

//chuong trinh con

void bephong()
{
	  setcolor(WHITE);
			line(0,400,640,400);
			rectangle(300,330,340,400);
			rectangle(310,320,330,330);
			
			setcolor(4);
			line(319,280,319,398);
			line(320,280,320,398);
			rectangle(320,280,330,300);
			outtextxy(340,280,"PRESS ANY KEY ...");
			getch();
			
			for(j=400;j<640;j++)
			{
				  cleardevice();
						setcolor(WHITE);
						line(0,j,640,j);
						rectangle(300,j-70,340,j);
						rectangle(310,j-80,330,j-70);
						
						setcolor(RED);
						line(319,280,319,400);
						line(320,280,320,400);
						rectangle(320,280,330,300);
						
						setcolor(YELLOW);
						circle(325,300,2);
						
						delay(5);
   }	
}

void bay()
{
	  for(i=400;i>340;i--)
			{
						cleardevice();
						
						setcolor(RED);
						line(319,i,319,i-120);
						line(320,i,320,i-120);
						rectangle(320,i-120,330,i-100);
						
						setcolor(YELLOW);
						circle(325,i-100,2);
						delay(25);
			}
}

void dammay()
{
			cleardevice();
			kk=0;
			for(j=100;j<350;j++)
			{
						if(j%20==0)
						{
									setcolor(kk);
									kk=kk+3;
									delay(50);
						}
						ellipse(320,30,0,360,j+100,j+0);
			}
		
			for(j=100;j<350;j++)
			{
						if(j%20==0)
						{
									setcolor(BLACK);
									delay(2);
						}
						ellipse(320,30,0,360,j+100,j+0);
			}
}

void bum()
{
	  cleardevice();
			for(i=0;i<70;i++)
			{
			setcolor(i);
			settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
			outtextxy(110,150,"Tach ... Tach ... Tach");
			delay(90);
			}
}

//chuong trinh chinh
int main()
{
	
			initwindow(800,800);

			//ve be phong
			bephong();
			
			//bay len nao
   bay();

   //no hinh dam may
   dammay();
   
   //ket thuc roi
   bum();
getch();
}
