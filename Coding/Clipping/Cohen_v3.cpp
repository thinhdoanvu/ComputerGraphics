#include<graphics.h>
#include<stdio.h>
//khai bao cua so gioi han
int xwmin = 100;
int xwmax = 300;
int ywmin = 100;
int ywmax = 300;
int x0,y0,x1,y1;//toa doa cua doan thang sau khi xen tia
int xgd, ygd;
float m;

void khoitao(){
	//ve cua so gioi han
	setcolor(15);	//white
	rectangle(xwmin, ywmax, xwmax, ywmin);
}
int mahoa(int x, int y){
	if(x>=xwmin && x<=xwmax && y>=ywmin && y<=ywmax){
		return 0;//nam hoan toan ben trong
	}
	if(x>=xwmin && x<=xwmax && y>ywmax){
		return 8;//nam hoan toan ben tren
	}
	if(x>=xwmin && x<=xwmax && y<ywmin){
		return 4;//nam hoan toan ben duoi
	}
	if(x<xwmin && y>=ywmin && y<=ywmax){
		return 1;//nam hoan toan ben trai
	}
	if(x>xwmax && y>=ywmin && y<=ywmax){
		return 2;//nam hoan toan ben phai
	}
	if(x<xwmin && y>ywmax){
		return 9;//goc tren ben trai
	}
	if(x>xwmax && y>ywmax){
		return 10;//goc tren ben phai
	}
	if(x<xwmin && y<ywmin){
		return 5;//goc duoi ben trai
	}
	if(x>xwmax && y<ywmin){
		return 6;//goc duoi ben phai
	}
}

void timgiaodiem(int x, int y){
	//ket qua luu vao xgd, ygd
	switch(mahoa(x,y)){
		case 2:{//diem nam ben phai cua so cat
			xgd = xwmax;
			ygd = y + (xgd - x)*m;
			break;
		}
		case 8:{
			ygd = ywmax;
			xgd = x + (ygd - y)/m;
			break;
		}	
		case 1:{//diem nam ben phai cua so cat
			xgd = xwmin;
			ygd = y + (xgd - x)*m;
			break;
		}
		case 4:{
			ygd = ywmin;
			xgd = x + (ygd - y)/m;
			break;
		}
		case 6:{//B==R==1
			//B==1
			ygd = ywmin;
			xgd = x + (ygd - y)/m;
			if(xgd<xwmin || xgd >xwmax){//R==1
				xgd = xwmax;
				ygd = y + (xgd - x)*m;	
			}
			break;
		}
		case 10:{//A==R==1
			//A==1
			ygd = ywmax;
			xgd = x + (ygd - y)/m;
			if(xgd<xwmin || xgd >xwmax){//R==1
				xgd = xwmax;
				ygd = y + (xgd - x)*m;	
			}
			break;
		}
		case 5:{//B==L==1
			//B==1
			ygd = ywmin;
			xgd = x + (ygd - y)/m;
			if(xgd<xwmin || xgd >xwmax){//L==1
				xgd = xwmin;
				ygd = y + (xgd - x)*m;	
			}
			break;
		}
		case 9:{//A==L==1
			//A==1
			ygd = ywmax;
			xgd = x + (ygd - y)/m;
			if(xgd<xwmin || xgd >xwmax){//L==1
				xgd = xwmin;
				ygd = y + (xgd - x)*m;	
			}
			break;
		}
	}
}

void CohenSutherland(int xa, int ya, int xb, int yb){
	//tim he so goc
	if(xa == xb){
		m=99999;
	}
	if(ya == yb){
		m=0;
	}
	if(xa!=xb && ya!=yb){
		m=(float)(yb-ya)/(xb-xa);
	}
	printf("\nhe so goc = %f\n",m);
	setcolor(2);
	line(xa,ya,xb,yb);
	printf("ma hoa P1 = %d va P2 = %d",mahoa(xa,ya),mahoa(xb,yb));
	//xet xem doan thang co gioi han boi cua so cat hay ko?
	if(mahoa(xa,ya) == 0 && mahoa(xb,yb)==0){//doan thang hoan toan ben trong cua so cat
		x0=xa; y0=ya;
		x1=xb; y1=yb;
	}
	//A ben trong B ben ngoai
	if(mahoa(xa,ya)==0 && mahoa(xb,yb)!=0){
		x0=xa; y0=ya;
		//tim x1,y1
		timgiaodiem(xb,yb);
		x1=xgd; y1=ygd;
	}
	//A ben ngoai B ben trong
	if(mahoa(xa,ya)!=0 && mahoa(xb,yb)==0){
		x0=xb; y0=yb;
		//tim x1,y1
		timgiaodiem(xa,ya);
		x1=xgd; y1=ygd;
	}
	//A B cung ben ngoai va cat cua so cat
	if(mahoa(xa,ya)!=0 && mahoa(xb,yb)!=0 && (mahoa(xa,ya) & mahoa(xb,yb))==0){
		timgiaodiem(xa,ya);
		x0=xgd;y0=ygd;
		timgiaodiem(xb,yb);
		x1=xgd;y1=ygd;
	}
	//in ra toa doa doan thang sau xen tia
	printf("\nX0 = %d, Y0 = %d, X1 = %d, Y1 = %d",x0,y0,x1,y1);
	//ve lai doan thang sau xen tia
	if(x0<xwmin || x0>xwmax || y0<ywmin || y0>ywmax || x1<xwmin || x1>xwmax || y1<ywmin || y1>ywmax){
		//bo qua khong ve
	}
	else{
		setlinestyle(1,0,2);
		setcolor(13);
		line(x0,y0,x1,y1);
	}
	
}

int main(){
	initwindow(600,600);
	khoitao();
	//A -> B
	//CohenSutherland(150,200,250,200);
	//CohenSutherland(40,120,80,225);
	//CohenSutherland(150,200,350,200);
	//CohenSutherland(150,200,150,350);
	//CohenSutherland(150,200,50,200);
	//CohenSutherland(150,200,150,80);
	//B -> A
	//CohenSutherland(250,200,150,200);
	//CohenSutherland(80,225,40,120);
	//CohenSutherland(350,200,150,200);
	//CohenSutherland(150,350,150,200);
	//CohenSutherland(50,200,150,200);
	//CohenSutherland(150,80,150,200);
	//A B cung nam ben ngoai
	//CohenSutherland(50,180,350,180);
	//CohenSutherland(200,50,200,350);
	//CohenSutherland(120,245,360,20);
	//CohenSutherland(280,175,380,20);
	//CohenSutherland(125,175,380,20);
	//CohenSutherland(125,175,330,350);
	//CohenSutherland(125,175,30,50);
	//CohenSutherland(125,175,30,350);
	//CohenSutherland(30,50,350,310);
	CohenSutherland(230,350,600,180);
	getch();//press any key
}
