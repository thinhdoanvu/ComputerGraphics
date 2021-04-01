#include<stdio.h>
#include<graphics.h>
#include<math.h>

int xmin;
int xmax;
int ymin;
int ymax;

int xa;
int ya;
int xb;
int yb;

int dx;
int dy;

int p[4];
int q[4];

int X1;
int Y1;
int X2;
int Y2;

void nhapthongso()
{
	xmin=100;
	xmax=400;
	ymin=100;
	ymax=400;
	
	printf("xA = ");scanf("%d",&xa);
	printf("yA = ");scanf("%d",&ya);
	printf("xB = ");scanf("%d",&xb);
	printf("yB = ");scanf("%d",&yb);
	
	//duong cheo cat 2 diem
	
	//xa=60;
	//ya=40;
	//xb=110;
	//yb=60;
	
	//xa=70;
	//ya=90;
	//xb=110;
	//yb=60;
	
	//xa=70;
	//ya=90;
	//xb=30;
	//yb=60;
	
	//xa=60;
	//ya=40;
	//xb=30;
	//yb=60;
	
	//song song truc hoanh
	
	//xa=30;
	//ya=60;
	//xb=70;
	//yb=60;
	
	//xa=70;
	//ya=120;
	//xb=70;
	//yb=60;
	
	//tinh gia tri pk va qk
	dx=xb-xa;
	dy=yb-ya;
	
	p[0]=-dx;
	p[1]=dx;
	p[2]=-dy;
	p[3]=dy;
	
	q[0]=xa-xmin;
	q[1]=xmax-xa;
	q[2]=ya-ymin;
	q[3]=ymax-ya;
	/*
	printf("P[i] va Q[i] la:");
	int i;
	for(i=0;i<4;i++)
	{
		printf("\n%d \t",p[i]);
		printf("\n%d \t",q[i]);
	}
	*/
	initwindow(500,500);
	
	line(xmin,ymin,xmax,ymin);
	line(xmax,ymin,xmax,ymax);
	line(xmax,ymax,xmin,ymax);
	line(xmin,ymax,xmin,ymin);
	
	setcolor(BLUE);
	line(xa,ya,xb,yb);
}

int check()
{
	if(xa<xmin &&  xb<xmin)
	{
		return 0;
	}
	else
	{
		if(xa>xmax && ya>ymax)
		{
			return 0;
		}
		else
		{
			if(ya<ymin && yb<ymin)
			{
				return 0;
			}
			else
			{
				if(ya>ymax && yb>ymax)
				{
					return 0;
				}
				else
				{
					return 1;
				}
			}	
		}
	}
	
	
}

float MIN(float a, float b)
{
	float min;
	float max;
	
	if(a<b)
	{
		min=a;
	}
	else
	{
		min=b;
	}
	return min;
}

float MAX(float a, float b)
{
	float max;
	
	if(a<b)
	{
		max=b;
	}
	else
	{
		max=a;
	}
	return max;
}

void Liang_Barsky()
{
	int i;
	float t1;
	float t2;
	
	t1=0.0;
	t2=1.0;
	
	//printf("\nCheck = %d",check());
	
	if(check()!=0)
	{
		for(i=0;i<4;i++)
		{
			if(p[i]<0)//doi voi pk<0
			{
				t1=MAX(t1,(float)q[i]/p[i]);
				//printf("\np[%d]=%d q[%d]= %d  %.2f",i,p[i],i,q[i],(float)q[i]/p[i]);
			}
			else //doi voi pk>0
			{
				t2=MIN(t2,(float)q[i]/p[i]);
				//printf("\np[%d]=%d q[%d]= %d  %.2f",i,p[i],i,q[i],(float)q[i]/p[i]);
			}
		}
		
		printf("\nt1 = %f, t2 = %f",t1,t2);
		//tim X va Y
		if(dx!=0 && dy!=0)//co 2 giao diem
		{
			X1=round(xa+t1*dx);
			Y1=round(ya+t1*dy);
			X2=round(xa+t2*dx);
			Y2=round(ya+t2*dy);
			
			printf("\n(X1 = %d, Y1 = %d, X2 = %d, Y2 = %d)",X1,Y1,X2,Y2);
			
			//kiem tra giao diem co thoa man nam trong cua so?
			if(X1<xmin || X1 >xmax || Y1 < ymin || Y1 > ymax || X2<xmin || X2 >xmax || Y2 < ymin || Y2 > ymax)
			{
				X1=0;
				Y1=0;
				X2=0;
				Y2=0;
			}
		}
		//Co 1 giao diem
		else
		{
			//duong thang song song truc x
			if(dy==0)
			{
				//diem a nam trong cua so
				if(xa>=xmin && xa<=xmax)
				{
					//diem b nam trong
					if(xb>=xmin && xb<=xmax)
					{
						X1=xa;Y1=ya;X2=xb;Y2=yb;
					}
					//diem b nam ben trai diem a
					if(xb<xmin)
					{
						X1=xa;Y1=ya;X2=xmin;Y2=ya;//Y2=yb
					}
					//diem b nam ben phai
					if(xb>xmax)
					{
						X1=xa;Y1=ya;X2=xmax;Y2=ya;//Y2=yb
					}
				}
				//diem b nam ben trong cua so
				if(xb>=xmin && xb<=xmax)
				{
					//diem a nam trong
					if(xa>=xmin && xa<=xmax)
					{
						X1=xb;Y1=yb;X2=xa;Y2=ya;
					}
					//diem a nam ben trai diem a
					if(xa<xmin)
					{
						X1=xb;Y1=yb;X2=xmin;Y2=yb;//Y2=ya
					}
					//diem a nam ben phai
					if(xa>xmax)
					{
						X1=xb;Y1=yb;X2=xmax;Y2=yb;//Y2=ya
					}
				}
				//ca 2 diem deu nam ben ngoai
				if((xa<xmin && xb>xmax) || (xa>xmax && xb<xmin))
				{
					X1=xmin;Y1=ya;X2=xmax;Y2=ya;
				}
				printf("\n(X1 = %d, Y1 = %d, X2 = %d, Y2 = %d)",X1,Y1,X2,Y2);
			}
			else
			//dx==0 //nam song song voi truc tung
			{
				//diem a nam trong cua so
				if(ya>=ymin && ya<=ymax)
				{
					//diem b nam trong
					if(yb>=ymin && yb<=ymax)
					{
						X1=xa;Y1=ya;X2=xb;Y2=yb;
					}
					//diem b nam ben duoi diem a
					if(yb<ymin)
					{
						X1=xa;Y1=ya;Y2=ymin;X2=xa;//X2=xb
					}
					//diem b nam ben tren diem a
					if(yb>ymax)
					{
						X1=xa;Y1=ya;Y2=ymax;X2=xa;//X2=xb
					}
				}
				//diem b nam ben trong cua so
				if(yb>=ymin && yb<=ymax)
				{
					//diem a nam trong
					if(ya>=ymin && ya<=ymax)
					{
						X1=xa;Y1=ya;X2=xb;Y2=yb;
					}
					//diem a nam ben duoi diem b
					if(ya<ymin)
					{
						X1=xb;Y1=yb;Y2=ymin;X2=xa;//X2=xb
					}
					//diem a nam ben tren diem b
					if(ya>ymax)
					{
						X1=xb;Y1=yb;Y2=ymax;X2=xa;//X2=xb
					}
				}
				//ca 2 diem deu nam ben ngoai
				if((ya<ymin && yb>ymax) || (ya>ymax && yb<ymin))
				{
					X1=xa;Y1=ymin;X2=xb;Y2=ymax;
				}
			}
		}
		
		//ve 2 giao diem
		setcolor(GREEN);
		setlinestyle(1,0,1);
		line(X1,Y1,X2,Y2);
		
	}
	else
	{
		printf("\nKhong co giao diem");
	}
}


int main()
{
	nhapthongso();
	Liang_Barsky();
	getch();
}
