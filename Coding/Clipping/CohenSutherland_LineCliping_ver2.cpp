#include<stdio.h>
#include<graphics.h>
#define maxgd 100
#include<math.h>

int xwmin = 50;
int xwmax = 100;
int ywmin = 50;
int ywmax = 80;

int xa;
int ya;
int xb;
int yb;
float m;

int X;
int Y;
int X1;
int X2;
int Y1;
int Y2;

int mahoadinh[2];

void nhaptoado()
{
	printf("Nhap to do 2 diem cua duong thang: ");
	printf("xa = "); scanf("%d",&xa);
	printf("ya = "); scanf("%d",&ya);
	printf("xb = "); scanf("%d",&xb);
	printf("yb = "); scanf("%d",&yb);
	
	//ve cua so cat va duong thang AB
	initwindow(400,400);
	setcolor(RED);
	line(xwmin,ywmin,xwmax,ywmin);
	line(xwmax,ywmin,xwmax,ywmax);
	line(xwmax,ywmax,xwmin,ywmax);
	line(xwmin,ywmax,xwmin,ywmin);
	
	setcolor(BLUE);
	line(xa,ya,xb,yb);
}

int ABRL(int tmpx, int tmpy)
{
	int code;
	//ben trong
	if(xwmin<=tmpx && tmpx<=xwmax && ywmin<=tmpy && tmpy<=ywmax)
	{
		code=0;
	}
	//ben trai
	if(tmpx<xwmin && ywmin<tmpy && tmpy<ywmax)
	{
		code=1;
	}
	//ben phai
	if(tmpx>xwmax && ywmin<=tmpy && tmpy<=ywmax)
	{
		code=2;
	}
	//ben tren
	if(tmpy>ywmax && tmpx>xwmin && tmpx<xwmax)
	{
		code=8;
	}
	//ben duoi
	if(tmpy<ywmin && tmpx>xwmin && tmpx<xwmax)
	{
		code=4;
	}
	//goc duoi ben trai
	if(tmpy<ywmin && tmpx<xwmin)
	{
		code=5;
	}
	//goc duoi ben phai
	if(tmpy<ywmin && tmpx>xwmax)
	{
		code=6;
	}
	//goc tren ben trai
	if(tmpy>ywmax && tmpx<xwmin)
	{
		code=9;
	}
	//goc tren ben phai
	if(tmpy>ywmax && tmpx>xwmax)
	{
		code=10;
	}
	return code;	
}

void mahoavasogiaodiem()
{	
	mahoadinh[0]=ABRL(xa,ya);
	mahoadinh[1]=ABRL(xb,yb);
	printf("\nMa hoa diem A: %d",ABRL(xa,ya));
	printf("\nMa hoa diem B: %d",ABRL(xb,yb));
	
	if((mahoadinh[0]& mahoadinh[1])!=0)
	{
		printf("\nDoan thang nam ben ngoai cua so");
	}
	else
	{
		if(mahoadinh[0]==0 && mahoadinh[1]==0)
		{
			printf("\nDoan thang nam ben trong cua so");
		}
		else
		{
			if((mahoadinh[0]!=0 && mahoadinh[1])!=0)
			{
				printf("\nCo 2 giao diem");
			}
			else
			{
				printf("\nCo 1 giao diem");
			}
		}
	}	
}

void cohen_sutherland(int CODE)
{	
	X=0;
	Y=0;
	if(CODE==1) //diem nam ben trai L=1
	{
		X=xwmin;
		Y=round(ya+m*(X-xa));
	}
	if(CODE==2) //diem nam ben phai R=1
	{
		X=xwmax;
		Y=round(ya+m*(X-xa));
	}
	if(CODE==4) //diem nam ben duoi B=1
	{
		Y=ywmin;
		X=round(xa+(Y-ya)/m);
	}
	if(CODE==8) //diem nam ben tren A=1
	{
		Y=ywmax;
		X=round(xa+(Y-ya)/m);
	}
	
	if(CODE==9) //diem nam tren ben trai A=1 va L=1 (CODE 1)
	{
		X=xwmin;
		Y=round(ya+m*(X-xa));
	}
	if(CODE==10) //diem nam tren ben phai A=1 va R=1 (CODE 8)
	{
		Y=ywmax;
		X=round(xa+(Y-ya)/m);
	}
	if(CODE==5) //diem nam duoi ben trai B=1 va L=1 (CODE 1)
	{
		X=xwmin;
		Y=round(ya+m*(X-xa));
	}
	if(CODE==6) //diem nam duoi ben phai B=1 va R=1 (CODE 4)
	{
		Y=ywmin;
		X=round(xa+(Y-ya)/m);
	}
	
	//kiem tra dieu kien 2 dinh deu nam ngoai cua so cat
	if(X<xwmin|| X>xwmax)
	{
		X=0;
	}
	if(Y<ywmin|| Y>ywmax)
	{
		Y=0;
	}
}

void timgiaodiem()
{
	//ca 2 diem deu nam ben trong cua so cat
	if(mahoadinh[0]==0 && mahoadinh[1]==0)
	{
		X1=xa;Y1=ya;X2=xb;Y2=yb;
	}
	
	//Khi dy=0, duong thang song song voi truc x
	if(ya==yb)
	{
		//diem a nam ben trong va diem b nam ben ngoai
		if(mahoadinh[0]==0 && mahoadinh[1]!=0)
		{
			//diem b nam ben trai cua so cat
			if(xa>xb)
			{
				X1=xa;Y1=ya;X2=xwmin;Y2=ya;//Y2=yb	
			}
			//diem b nam ben phai cua so cat
			if(xa<xb)
			{
				X1=xa;Y1=ya;X2=xwmax;Y2=ya;//Y2=yb
			}
		}
		//diem b nam ben trong va diem a nam ben ngoai
		if(mahoadinh[0]!=0 && mahoadinh[1]==0)
		{
			//diem a nam ben trai cua so cat
			if(xa<xb)
			{
				X1=xb;Y1=yb;X2=xwmin;Y2=ya;//Y2=yb	
			}
			//diem a nam ben phai cua so cat
			else
			{
				X1=xb;Y1=yb;X2=xwmax;Y2=ya;//Y2=yb
			}
		}
		//ca 2 diem deu ben ngoai
		else
		{
			X1=xwmin;Y1=ya;X2=xwmax;Y2=ya;//Y2=yb
		}
	}
	
	//Khi dx==0, doan thang song song voi truc y
	if(xa==xb)
	{
		//diem a nam ben trong va diem b nam ben ngoai
		if(mahoadinh[0]==0 && mahoadinh[1]!=0)
		{
			//diem b nam ben tren cua so cat
			if(ya>yb)
			{
				X1=xa;Y1=ya;X2=xa;Y2=ywmin;//X2=xb	
			}
			//diem b nam ben duoi cua so cat
			else
			{
				X1=xa;Y1=ya;X2=xa;Y2=ywmax;//X2=yb
			}
		}
		//diem b nam ben trong va diem a nam ben ngoai
		if(mahoadinh[0]!=0 && mahoadinh[1]==0)
		{
			//diem a nam ben tren cua so cat
			if(ya<yb)
			{
				X1=xb;Y1=yb;Y2=ywmin;X2=xa;//X2=xb	
			}
			//diem a nam ben duoi cua so cat
			else
			{
				X1=xb;Y1=yb;Y2=ywmax;X2=xa;//X2=xb
			}
		}
		//ca 2 diem deu ben ngoai
		else
		{
			X1=xa;Y1=ywmin;X2=xb;Y2=ywmax;//X2=xa
		}
	}
	
	//khi ca dx va dy deu <> 0, co 2 diem cat
	if(mahoadinh[0]!=0 && mahoadinh[1]!=0 && (mahoadinh[0] & mahoadinh[1])==0)
	{
		m=(float)(yb-ya)/(xb-xa);
		cohen_sutherland(mahoadinh[0]);
		X1=X;
		Y1=Y;
		cohen_sutherland(mahoadinh[1]);
		X2=X;
		Y2=Y;
		printf("\nX1= %d, Y1= %d, X2= %d, Y2= %d ",X1,Y1,X2,Y2);
	}
	
	//ve duong thang noi 2 diem
	setcolor(GREEN);
	setlinestyle(1,0,1);
	line(X1,Y1,X2,Y2);
}

int main()
{
	nhaptoado();
	mahoavasogiaodiem();
	timgiaodiem();
	getch();	
}
