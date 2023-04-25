#include<winbgim.h> 
#include<stdio.h>

//khai bao bien
int xwmin = 100;
int xwmax = 300;
int ywmin = 100;
int ywmax = 300;
int x0, y0, x1, y1;

void khoitao(){
	setcolor(15);
	setlinestyle(1,1,2);
	rectangle(xwmin,ywmax,xwmax,ywmin);
}

void inmang(int a[]){
	for(int i=0; i<4; i++){
		printf("%5d",a[i]);
	}
}

float min(float a, float b){
	return (a<b)?a:b;
}

float max(float a, float b){
	return (a>b)?a:b;
}

void LiangBasky(int xa, int ya, int xb, int yb){
	setcolor(2);
	line(xa,ya,xb,yb);
	//tinh pk
	int pk[4]={-(xb-xa),(xb-xa),-(yb-ya),(yb-ya)};
	//tinh qk
	int qk[4]={(xa-xwmin),(xwmax-xa),(ya-ywmin),(ywmax-ya)};
	//in mang pk,qk
	printf("\npk[]:");inmang(pk);
	printf("\nqk[]:");inmang(qk);
	//Xet cac truong hop pk<0: tim t1
	float t1=0;
	for(int i=0;i<4;i++){
		if(pk[i]<0){
			//printf("\nt1=%f,q[%d]/p[%d]=%f",t1,i,i,(float)qk[i]/pk[i]);
			t1 = max(t1,(float)qk[i]/pk[i]);
		}
	}
	printf("\nt1 = %f",t1);
	x0=xa+t1*(xb-xa);
	y0=ya+t1*(yb-ya);
	
	//Xet cac truong hop pk>0: tim t2
	float t2=1;
	for(int i=0;i<4;i++){
		if(pk[i]>0){
			t2 = min(t2,(float)qk[i]/pk[i]);
			//printf("\nt2=%f,q[%d]/p[%d]=%f",t2,i,i,(float)qk[i]/pk[i]);
		}
	}
	printf("\nt2 = %f",t2);
	x1=xa+t2*(xb-xa);
	y1=ya+t2*(yb-ya);
	
	//xet gia tri cua x,y sau khi xen tia co nam trong cua so cat?
	if(x0<xwmin || x0>xwmax || y0<ywmin || y0>ywmax || x1<xwmin || x1>xwmax || y1<ywmin || y1>ywmax){
		//khong lam gi ca
		printf("\nDoan thang nam ngoai cua so cat");
	}
	else{
		//ve duong thang noi x0,y0,x1,y1
		setcolor(4);
		printf("\n(x0 = %d, y0 = %d),(x1 = %d, y1 = %d)",x0,y0,x1,y1);
		line(x0,y0,x1,y1);
	}
}

int main(){
	initwindow(400,400);
	khoitao();
	//A trong + B ngoai
	//Cohen(150,280,260,150);//AB nam trong
	
	//Cohen(150,280,360,150);//A trong, B phai
	//Cohen(150,140,150,450);//A trong, B tren
	//Cohen(200,140,60,140);//A trong, B trai
	//Cohen(200,140,200,70);//A trong, B duoi

	//A ngoai + B trong
	//Cohen(360,150,150,280);//B trong, A phai
	//Cohen(150,450,150,140);//B trong, A tren
	//Cohen(60,140,200,140);//B trong, A trai
	//Cohen(200,70,200,140);//B trong, A duoi
	
	//A trai + B phai
	//Cohen(70,200,350,200);//A trai, B phai
	
	//A tren + B duoi
	//Cohen(200,40,200,360);//A tren, B duoi
	
	//A trai + B tren
	//Cohen(70,200,240,400);//A trai, B tren
	
	//A trai + B duoi
	//Cohen(70,200,240,35);//A trai, B duoi
	
	//A phai + B tren
	//Cohen(370,200,140,320);//A phai, B tren
	
	//A phai + B duoi
	//Cohen(370,200,140,35);//A phai, B duoi
	
	//A goc tren, trai + B ben trong
	//Cohen(50,30,150,140);//B trong, A tren, trai
	//Cohen(10,80,150,140);//B trong, A tren, trai
	
	//A goc duoi, trai + B ben trong
	//Cohen(80,430,150,140);//B trong, A duoi, trai
	//Cohen(10,430,150,140);//B trong, A duoi, trai
	
	//A goc tren, phai + B ben trong
	//Cohen(450,30,200,170);//B trong, A tren, phai
	//Cohen(330,10,200,170);//B trong, A tren, phai
	
	//A goc duoi, phai + B ben trong
	//Cohen(450,430,200,170);//B trong, A duoi, phai
	//Cohen(330,410,200,170);//B trong, A duoi, phai
	
	//A trai, B tren: ngoai cua so cat
	Cohen(30,200,140,450);//A trai, B tren

	getch();//press any key
}
