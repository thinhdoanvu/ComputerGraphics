#include<graphics.h>
#include<stdio.h>

//khai bao bien
int xwmin = 100;
int xwmax = 300;
int ywmin = 100;
int ywmax = 300;
int x0, y0, x1, y1;//toa doa doan thang sau khi xen tia
int tmp_x, tmp_y;//toa do cua diem tam thoi
float m;//he so goc

void khoitaocuaso(){
	setcolor(15);//white
	setlinestyle(1,0,2);
	rectangle(xwmin,ywmax,xwmax,ywmin);
}

int mahoa(int x, int y){//ma hoa doan thang
	if(x>=xwmin && x<=xwmax && y>=ywmin && y<=ywmax){//diem(x,y) ben trong cua so
		return 0;
	}
	if(x>=xwmin && x<=xwmax && y>ywmax){//diem(x,y) ben tren cua so
		return 8;
	}
	if(x>=xwmin && x<=xwmax && y<ywmin){//diem(x,y) ben duoi cua so
		return 4;
	}
	if(x<xwmin && y>=ywmin && y<=ywmax){//diem(x,y) ben trai cua so
		return 1;
	}
	if(x>xwmax && y>=ywmin && y<=ywmax){//diem(x,y) ben phai cua so
		return 2;
	}
	if(x<xwmin && y>ywmax){//diem(x,y) goc tren ben trai cua so
		return 9;
	}
	if(x>xwmax && y>ywmax){//diem(x,y) goc tren ben phai cua so
		return 10;
	}
	if(x<xwmin && y<ywmin){//diem(x,y) goc duoi ben trai cua so
		return 5;
	}
	if(x>xwmax && y<ywmin){//diem(x,y) goc duoi ben phai cua so
		return 6;
	}
}

void timgiaodiem(int x, int y){
	switch(mahoa(x,y)){
		case 0:{//diem(x,y): ben trong cua so
			tmp_x = x;
			tmp_y = y;
			break;
		}
		case 2:{//diem(x,y): ben phai cua so
			tmp_x = xwmax;
			tmp_y = y + m*(tmp_x - x);
			break;
		}
		case 8:{//diem(x,y): ben tren cua so
			tmp_y = ywmax;
			tmp_x = x + (tmp_y - y)/m;
			break;
		}
		case 1:{//diem(x,y): ben trai cua so
			tmp_x = xwmin;
			tmp_y = y + m*(tmp_x - x);
			break;
		}
		case 4:{//diem(x,y): ben duoi cua so
			tmp_y = ywmin;
			tmp_x = x + (tmp_y - y)/m;
			break;
		}
		case 5:{//diem(x,y): goc tren ben trai cua so
			tmp_y = ywmin;
			tmp_x = x + (tmp_y - y)/m;
			if(tmp_x <xwmin){
				tmp_x = xwmin;
				tmp_y = y + m*(tmp_x - x);	
			}
			break;
		}
		case 9:{//diem(x,y): goc duoi ben trai cua so
			tmp_y = ywmax;
			tmp_x = x + (tmp_y - y)/m;
			if(tmp_x <xwmin){
				tmp_x = xwmin;
				tmp_y = y + m*(tmp_x - x);	
			}
			break;
		}
		case 6:{//diem(x,y): goc duoi ben phai cua so
			tmp_x = xwmax;
			tmp_y = y + m*(tmp_x - x);
			if(tmp_y <ywmin){
				tmp_y = ywmin;
				tmp_x = x + (tmp_y - y)/m;	
			}
			break;
		}
		case 10:{//diem(x,y): goc tren ben phai cua so
			tmp_y = ywmax;
			tmp_x = x + (tmp_y - y)/m;
			if(tmp_x >xwmax){
				tmp_x = xwmax;
				tmp_y = y + m*(tmp_x - x);	
			}
			break;
		}
	}
}

void CohenSutherland(int xa, int ya, int xb, int yb){
	//tim he so goc
	if(ya==yb){
		m=0;
	}
	if(xa!=xb, ya!=yb){
		m = (float)(yb-ya)/(xb-xa);
	}
	if(xa==xb){
		m = 99999;
	}
	//ve doan thang can xen tia
	setcolor(2);
	line(xa,ya,xb,yb);
	//in ra man hinh ket qua ma hoa duong thang
	printf("\nMa hoa A = %d va B = %d",mahoa(xa,ya),mahoa(xb,yb));
	//tim giao diem
	timgiaodiem(xa,ya);//xet diem A truoc
	x0=tmp_x;
	y0=tmp_y;
	timgiaodiem(xb,yb);//xet diem B sau
	x1=tmp_x;
	y1=tmp_y;
	//in ra man hinh toa do doan thang sau xen tia
	printf("\nX0 = %d, Y0 = %d, X1 = %d, Y1 = %d",x0,y0,x1,y1);
	if(x0<xwmin || x0>xwmax || y0<ywmin || y0>ywmax || x1<xwmin || x1>xwmax || y1<ywmin || y1>ywmax){
		//khong lam gi ca
	}
	else{
		//ve duong thang noi 2 toa do sau xen tia
		setcolor(13);
		line(x0,y0,x1,y1);
	}
}

int main(){
	initwindow(500,500);
	khoitaocuaso();
	//A trong + B ngoai
	//CohenSutherland(150,280,260,150);//AB nam trong
	//CohenSutherland(150,280,360,150);//A trong, B phai
	//CohenSutherland(150,140,150,450);//A trong, B tren
	//CohenSutherland(200,140,60,140);//A trong, B trai
	//CohenSutherland(200,140,200,70);//A trong, B duoi

	//A ngoai + B trong
	//CohenSutherland(360,150,150,280);//B trong, A phai
	//CohenSutherland(150,450,150,140);//B trong, A tren
	//CohenSutherland(60,140,200,140);//B trong, A trai
	//CohenSutherland(200,70,200,140);//B trong, A duoi
	
	//A trai + B phai
	//CohenSutherland(70,200,350,200);//A trai, B phai
	
	//A tren + B duoi
	//CohenSutherland(200,40,200,360);//A tren, B duoi
	
	//A trai + B tren
	//CohenSutherland(70,200,240,400);//A trai, B tren
	
	//A trai + B duoi
	//CohenSutherland(70,200,240,35);//A trai, B duoi
	
	//A phai + B tren
	//CohenSutherland(370,200,140,320);//A phai, B tren
	
	//A phai + B duoi
	//CohenSutherland(370,200,160,400);//A phai, B duoi
	
	//A goc tren, trai + B ben trong
	//CohenSutherland(50,30,150,140);//B trong, A tren, trai
	//CohenSutherland(10,80,150,140);//B trong, A tren, trai
	
	//A goc duoi, trai + B ben trong
	//CohenSutherland(80,430,150,140);//B trong, A duoi, trai
	//CohenSutherland(10,430,150,140);//B trong, A duoi, trai
	
	//A goc tren, phai + B ben trong
	//CohenSutherland(450,30,200,170);//B trong, A tren, phai
	//CohenSutherland(330,10,200,170);//B trong, A tren, phai
	
	//A goc duoi, phai + B ben trong
	//CohenSutherland(450,430,200,170);//B trong, A duoi, phai
	//CohenSutherland(330,410,200,170);//B trong, A duoi, phai
	
	//A trai, B tren: ngoai cua so cat
	CohenSutherland(30,200,140,450);//A trai, B tren
	
	getch();//press any key
}
