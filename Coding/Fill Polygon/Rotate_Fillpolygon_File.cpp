#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define FILENAME "scanline.inp"
#define maxdinh 20

int sodinh;
int chieu;
int A[maxdinh][2];
int X[maxdinh];
int Y[maxdinh];
float m[maxdinh];
int xgd[maxdinh];

FILE *fp;

void nhaptoado(){
	int i;
	int j;
	fp=fopen(FILENAME,"r");
	if(fp==NULL){
		printf("File not found");
		exit(1);
	}
	else{
		fscanf(fp,"%d",&sodinh);
		fscanf(fp,"%d",&chieu);
		//doc cac toa do luu vao MT A
		for(i=0;i<sodinh;i++){
			for(j=0;j<2;j++){
				fscanf(fp,"%d",&A[i][j]);
			}
		}
		fclose(fp);
	}
	//luu cot 0 vao X, 1 vao Y
	for(i=0;i<sodinh;i++){
		X[i]=A[i][0];
		Y[i]=A[i][1];
	}
}

void intoado(){
	int i,j;
	//in ra noi dung tap tin scanline.inp
	for(i=0;i<sodinh;){
		printf("%d  %d",X[i],Y[i]);	
		printf("\n");
		i++;
	}	
}

void hesogoc(){
	int i;
	//tim he so goc
	//printf("He so goc cac canh la: \n");
	for(i=0;i<sodinh;i++){
		if(X[i+1]==X[i]){
			m[i]=999999;
		}
		else{
			if(Y[i+1]==Y[i]){
				m[i]=1.0;
			}
			else{
				m[i]=(float)(Y[i+1]-Y[i])/(X[i+1]-X[i]);
			}
		}
		//printf("%.1f  ",m[i]);
	}	
}

void vedagiac(){
	X[sodinh]=X[0];//gan X[cuoi]=X[dau]
	Y[sodinh]=Y[0];//gan Y[cuoi]=Y[dau]
	hesogoc();
	int i;
	for(i=0;i<sodinh;i++){
		line(X[i],Y[i],X[i+1],Y[i+1]);
	}
}
void scanline(int color){
	//tim ymin va ymax
	int ymin=Y[0];
	int ymax=Y[0];
	int i;
	for(i=0;i<sodinh;i++){
		xgd[i]=0;
	}
	for(i=1;i<sodinh;i++){
		if(ymin>Y[i]){
			ymin=Y[i];
		}
	}
	for(i=1;i<sodinh;i++){
		if(ymax<Y[i]){
			ymax=Y[i];
		}
	}
	int y;
	for(y=ymin;y<=ymax;){
		int dem=0;//reset lai so giao diem
		for(i=0;i<sodinh;){//xet lan luot cac canh cua da giac
			if((y<Y[i] && y<Y[i+1]) || (y>Y[i] && y>Y[i+1])){
				//khong co giao diem
			}
			else{//co 1 hoac maxdinh giao diem
				xgd[dem]=round(X[i]+(float)(y - Y[i])/m[i]);
				dem++;//tang du phong so giao diem
			}
			i++;//xet toi canh ke tiep
		}
		//in ra toa do cac giao diem
		//for(i=0;i<dem;i++){
		//	printf("\n(x = %d, y = %d)",xgd[i],y);
		//}
		//ve duong thang noi cac giao diem
		setcolor(color);//RED
		for(i=0;i<dem-1;i=i+2){//(1,2),(2,3),(3,4),(4,1)
			line(xgd[i],y,xgd[i+1],y);
		}
		//xet dong quet tiep theo
		y++;
	}
}

int phepquay(int xr, int yr, int goc){
	int dx;
	int dy;
	int i;
	for(i=0;i<sodinh;i++){
		dx=(X[i]-xr);
		dy=(Y[i]-yr);
		X[i]=(xr + (float)dx*cos(goc*3.1416/180) - (float)dy*sin(3.1416*goc/180));
		Y[i]=(yr + (float)dx*sin(goc*3.1416/180) + (float)dy*cos(3.1416*goc/180));
	}
	vedagiac();
}

int main(){
	nhaptoado();
	printf("\ntoa do goc: \n");
	intoado();
	initwindow(500,500);
	/*
	vedagiac();
	printf("\ntoa do sau ve: \n");
	intoado();
	scanline(5);
	printf("\ntoa do sau to: \n");
	intoado();
	*/
	int j;
	for(j=1;j<10;j++){
		phepquay(200,300,36);
		scanline(j);
	}
	getch();
}
