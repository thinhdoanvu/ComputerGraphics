#include<graphics.h>
#include<stdio.h>

int xw_min=100;
int yw_min=100;
int xw_max=200;
int yw_max=200;
int x0,y0,x1,y1;
float m;

int CODE(int X, int Y){//ABRL
	if(X>=xw_min && X<=xw_max && Y>=yw_min && Y<=yw_max) return 0;//0000
	if(X>=xw_min && X<=xw_max && Y<yw_min) return 4;//0100
	if(X>=xw_min && X<=xw_max && Y>yw_max) return 8;//1000
	if(X>xw_max && Y>=yw_min && Y<=yw_max) return 2;//0010
	if(X<xw_min && Y>=yw_min && Y<=yw_max) return 1;//0001
	if(X<xw_min && Y>=yw_max) return 9;//1001
	if(X<xw_min && Y<=yw_min) return 5;//0101
	if(X>xw_max && Y>=yw_max) return 10;//1010
	if(X>xw_max && Y<=yw_min) return 6;//0110
}

void timgiaodiem(int x, int y){
	switch(CODE(x,y)){
		//dy==0
		case 1: {
			x0=xw_min;
			y0=y+m*(x0-x);
			break;
		}
		//dx==0
		case 8: {
			y0=xw_max;
			x0=x+(y0-y)/m;
			break;
		}
		//dy==0
		case 2: {
			x0=xw_max;
			y0=y+m*(x0-x);
			break;
		}
		//dx==0
		case 4: {
			y0=yw_min;
			x0=x+(y0-y)/m;
			break;
		}
		case 9: {//|m|<1
			if((m>0 && m<1) || (m<0 && m>-1) ){
				x0=xw_min;
				y0=y+m*(x0-x);	
			}
			else{//m>1
				y0=yw_max;
				x0=x+(y0-y)/m;	
			}
			break;
		}
		case 10: {//|m|<1
			if((m>0 && m<1) || (m<0 && m>-1) ){	
				x0=xw_max;
				y0=y+m*(x0-x);	
			}
			else{//m>1
				y0=yw_max;
				x0=x+(y0-y)/m;	
			}
			(y0 > yw_max)?yw_max:y0;
			(x0 > xw_max)?xw_max:x0;
			break;
		}
		case 5: {//|m|<1
			if((m>0 && m<1) || (m<0 && m>-1) ){
				x0=xw_min;
				y0=y+m*(x0-x);	
			}
			else{//m>1
				y0=yw_min;
				x0=x+(y0-y)/m;	
			}
			break;
		}
		case 6: {//|m|<1
			if((m>0 && m<1) || (m<0 && m>-1) ){
				x0=xw_max;
				y0=y+m*(x0-x);	
			}
			else{//m>1
				y0=yw_min;
				x0=x+(y0-y)/m;	
			}
			break;
		}
	}
}

void veduongthang(int x0, int y0, int x1, int y1){
	//duong thang sau khi xen tia
	printf("\nx=%d,y=%d,x1=%d,y1=%d",x0,y0,x1,y1);
	setcolor(15);
	setlinestyle(1,0,2);
	line(x0,y0,x1,y1);
}

void cohen(int xa, int ya, int xb, int yb){
	if(xa != xb && ya != yb){
		m=(float)(yb-ya)/(xb-xa);
	}
	else{
		if(xa==xb){
			m=9999;
		}
		if(ya==yb){
			m=0;
		}
	}
	printf("\nm=%f",m);
	//ve cua so cat va duong thang di qua 2 diem
	setcolor(2);
	rectangle(xw_min, yw_max, xw_max, yw_min);
	setcolor(13);
	line(xa, ya, xb, yb);
	printf("\nDiem A sau khi ma hoa: %d",CODE(xa, ya));
	printf("\nDiem B sau khi ma hoa: %d",CODE(xb, yb));
	
	//Tim so giao diem
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
	if(CODE(xa,ya)==0 && CODE(xb,yb)==0){
		printf("\nDoan thang nam trong cua so cat");
		x0=xa;y0=ya;x1=xb;y1=yb;
		veduongthang(x0,y0,x1,y1);	
		return;
	}
	if(CODE(xa,ya)==0 && CODE(xb,yb)!=0){//A nam trong, B nam ngoai
		printf("\nCo 1 giao diem voi cua so cat");
		x1=xa;
		y1=ya;
		timgiaodiem(xb,yb);
		veduongthang(x0,y0,x1,y1);
		return;
	}
	if(CODE(xa,ya)!=0 && CODE(xb,yb)==0){//A nam ngoai, B nam trong
		printf("\nCo 1 giao diem voi cua so cat");
		x1=xb;
		y1=yb;
		timgiaodiem(xa,ya);
		veduongthang(x0,y0,x1,y1);
		return;
	}
	if(CODE(xa,ya)!=0 && CODE(xb,yb)!=0 && (CODE(xa,ya) & CODE(xb,yb))==0){//A nam trong, B nam ngoai
		printf("\nCo 2 giao diem voi cua so cat");
		timgiaodiem(xa,ya);
		x1=x0;
		y1=y0;
		timgiaodiem(xb,yb);
		veduongthang(x0,y0,x1,y1);
		return;
	}
	//nen dua dieu kien nay xuong duoi
	if(CODE(xa,ya)!=0 && CODE(xb,yb)!=0 && (CODE(xa,ya) & CODE(xb,yb)!=0)){//A ngoai B trong
		printf("\nDoan thang nam ben ngoai cua so cat");
		return;
	}
}

int main(){
	initwindow(400,400);
	//cohen(120,110,120,180);//nam trong
	//cohen(80,100,80,200);//ben trai
	//cohen(220,100,220,200);//ben phai
	//cohen(100,80,200,80);//ben tren
	//cohen(100,280,200,280);//ben duoi
	//cohen(80,150,150,150);//ngoai trai -> trong phai: dy=0
	//cohen(250,150,150,150);//ngoai phai -> trong trai: dy=0
	//cohen(150,250,150,150);//ngoai tren -> trong duoi: dx=0
	//cohen(150,250,150,150);//ngoai duoi -> trong tren: dx=0
	
	//A ngoai B trong
	//cohen(50,250,150,150);//ngoai tren -> trong duoi: dx!=0 dy!=0
	//cohen(30,250,150,150);//ngoai tren -> trong duoi: dx!=0 dy!=0
	//cohen(90,250,150,150);//ngoai tren -> trong duoi: dx!=0 dy!=0
	//cohen(250,250,150,150);//ngoai duoi -> trong tren: dx!=0 dy!=0
	//cohen(230,250,150,150);//ngoai duoi -> trong tren: dx!=0 dy!=0
	//cohen(290,250,150,150);//ngoai duoi -> trong tren: dx!=0 dy!=0
	//cohen(50,50,150,150);//ngoai trai -> trong tren: dx!=0 dy!=0
	//cohen(30,50,150,150);//ngoai trai -> trong tren: dx!=0 dy!=0
	//cohen(90,50,150,150);//ngoai trai -> trong tren: dx!=0 dy!=0
	//cohen(250,50,150,150);//ngoai phai -> trong tren: dx!=0 dy!=0
	//cohen(230,50,150,150);//ngoai phai -> trong tren: dx!=0 dy!=0
	//cohen(290,50,150,150);//ngoai phai -> trong tren: dx!=0 dy!=0
	
	//A trong B ngoai
	//cohen(150,150,50,250);//ngoai tren -> trong duoi: dx!=0 dy!=0
	//cohen(150,150,30,250);//ngoai tren -> trong duoi: dx!=0 dy!=0
	//cohen(150,150,90,250);//ngoai tren -> trong duoi: dx!=0 dy!=0
	//cohen(150,150,250,250);//ngoai duoi -> trong tren: dx!=0 dy!=0
	//cohen(150,150,230,250);//ngoai duoi -> trong tren: dx!=0 dy!=0
	//cohen(150,150,290,250);//ngoai duoi -> trong tren: dx!=0 dy!=0
	//cohen(150,150,50,50);//ngoai trai -> trong tren: dx!=0 dy!=0
	//cohen(150,150,30,50);//ngoai trai -> trong tren: dx!=0 dy!=0
	//cohen(150,150,90,50);//ngoai trai -> trong tren: dx!=0 dy!=0
	//cohen(150,150,250,50);//ngoai phai -> trong tren: dx!=0 dy!=0
	//cohen(150,150,230,50);//ngoai phai -> trong tren: dx!=0 dy!=0
	//cohen(150,150,290,50);//ngoai phai -> trong tren: dx!=0 dy!=0
	
	//A trai B phai
	//cohen(80,150,220,150);//ben trai - ben phai
	//cohen(180,50,180,250);//ben tren - ben duoi
	//cohen(80,150,150,250);//ben trai - ben tren
	//cohen(80,150,180,50);//ben trai - ben duoi
	//cohen(150,250,220,150);//ben phai - ben tren
	//cohen(220,150,150,50);//ben phai - ben duoi
	
	//A B nam ngoai
	//cohen(50,90,220,250);//duoi trai -> tren phai: dx!=0 dy!=0 m<1: tai sao sai
	cohen(50,90,250,220);//duoi trai -> tren phai: dx!=0 dy!=0 m<1
	getch();
}

