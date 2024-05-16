#include<stdio.h>
#include<math.h>
#include<graphics.h>
#define MAXDINH 20
//#define GEO "perspective_chopnhon.geo"
//#define ADJ "perspective_chopnhon.adj"
//#define GEO "chopnhon.geo"
//#define ADJ "chopnhon.adj"
#define GEO "chopcut_v2.inp"
#define ADJ "chopcut_v2.mtk"

//khai bao prototype
void readgeo();
void intoado(struct point p[MAXDINH], int size);
void readadj();
void inmatran(int m[][MAXDINH], int size);

//khai bao bien
FILE *fp;
int sodinh;
struct point{
	int x;
	int y;
	int z;
};

struct point pt[MAXDINH];
int adj[MAXDINH][MAXDINH];

//chuong trinh con
void readgeo(){
	fp=fopen(GEO,"r");
	if(fp==NULL){
		printf("File not found");
		return;
	}	
	//doc dong dau tien = so dinh
	fscanf(fp,"%d",&sodinh);
	printf("So dinh: %d",sodinh);
	//doc toa do cac dinh
	for(int i=0; i<sodinh; i++){
		fscanf(fp,"%d %d %d",&pt[i].x,&pt[i].y,&pt[i].z);
	}
	printf("\nToa do cac dinh: \n");
	intoado(pt,sodinh);
	
	fclose(fp);
}

void intoado(struct point p[MAXDINH], int size){
	for(int i=0; i<size; i++){
		printf("%d %d %d\n",p[i].x, p[i].y, p[i].z);
	}
}

void readadj(){
	fp=fopen(ADJ,"r");
	if(fp==NULL){
		printf("File not found");
		return;
	}	
	//doc dong dau tien = so dinh
	fscanf(fp,"%d",&sodinh);
	for(int i=0; i<sodinh; i++){
		for(int j=0; j<sodinh; j++){
			fscanf(fp,"%d",&adj[i][j]);
		}
	}
	//in ra ma tran ke cac dinh
	printf("Ma tran ke:\n");
	inmatran(adj,sodinh);
	fclose(fp);
}

void inmatran(int m[][MAXDINH], int size){
	for(int i=0; i<sodinh; i++){
		for(int j=0; j<sodinh; j++){
			printf("%d  ",adj[i][j]);
		}
		printf("\n");
	}
}

void perspective_1tam(int xp, int yp, int zp)
{
	
	struct point res[MAXDINH];
	//tinh toan gia tri cac dinh tren man chieu
	for(int i=0; i<sodinh; i++){
		res[i].x = xp + (float)(pt[i].x + xp)*zp/(pt[i].z+zp);
		res[i].y = yp + (float)(pt[i].y + yp)*zp/(pt[i].z+zp);
		res[i].z = 0.0;
	}
	//in toa do hinh chieu
	//printf("Toa do hinh chieu:\n");
	//intoado(res,sodinh);
	//ve hinh chieu
	for(int i=0; i<sodinh; i++){
		for(int j=0; j<sodinh; j++){
			if(adj[i][j]==1){
				line(res[i].x, res[i].y, res[j].x, res[j].y);
			}
		}
	}
	delay(100);
	cleardevice();
}

//chuong trinh chinh
int main()
{
	readgeo();
	readadj();
	initwindow(600,600);
	for(int i=50; i<500; i++){
		for(int j=50; j<500; j++){
			for(int k=50; k<500; k++){
				perspective_1tam(i,j,k);
			}
		}
	}
	
	getch();
}
