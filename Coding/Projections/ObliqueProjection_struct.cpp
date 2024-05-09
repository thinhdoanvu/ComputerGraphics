#include<graphics.h>
#include<stdio.h>
#include<math.h>
#define GEO "chopnhon.geo"
#define ADJ "chopnhon.adj"
#define MAXDINH 20

//khai bao prototype
void readgeo();
void intoado(struct point p, int size);
void readadj();
void inmtk(int m[][MAXDINH], int size);

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
void intoado(struct point p[MAXDINH], int size){
	for(int i=0; i<size; i++){
		printf("%d %d %d\n",p[i].x, p[i].y, p[i].z);
	}
}

void inmtk(int m[][MAXDINH], int size){
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			printf("%d   ",m[i][j]);
		}
		printf("\n");
	}
}

void readgeo(){
	fp=fopen(GEO,"r");
	if(fp==NULL){
		printf("File not found");
		return;
	}
	//doc so dinh cua hinh chop
	fscanf(fp,"%d",&sodinh);
	printf("Sodinh: %d",sodinh);
	//doc toa do cac dinh
	for(int i=0; i<sodinh; i++){
		fscanf(fp,"%d %d %d",&pt[i].x,&pt[i].y,&pt[i].z);
	}
	//in ra toa do cac dinh
	printf("\nToa do cac dinh:\n");
	intoado(pt,sodinh);
	//dong file
	fclose(fp);
}

void readadj(){
	fp=fopen(ADJ,"r");
	if(fp==NULL){
		printf("File not found");
		return;
	}
	//doc so dinh cua hinh chop
	fscanf(fp,"%d",&sodinh);
	printf("Sodinh: %d",sodinh);
	//doc toa do cac dinh
	for(int i=0; i<sodinh; i++){
		for(int j=0; j<sodinh; j++){
			fscanf(fp,"%d",&adj[i][j]);
		}
	}
	printf("\nMa tran ke:\n");
	inmtk(adj,sodinh);
	//dong file
	fclose(fp);
}

void ObliqueProjection(float L, float theta){//theta = degree
	struct point res[MAXDINH];
	float theta_rad = 3.141592*theta/180;
	for(int i=0; i<sodinh; i++){
		res[i].x = pt[i].x + pt[i].z * L * cos(theta_rad);
		res[i].y = pt[i].y + pt[i].z * L * sin(theta_rad);
		res[i].z = 0;
	}
	//in toa do cac dinh sau khi chieu
	printf("\nToa do cac dinh chieu:\n");
	intoado(res,sodinh);
	//ve hinh chop
	setlinestyle(1,1,2);
	setcolor(15);
	for(int i=0; i<sodinh; i++){
		for(int j=0; j<sodinh;j++){
			if(adj[i][j]==1){
				line(res[i].x, res[i].y, res[j].x, res[j].y);
			}
		}
	}
	delay(50);
	cleardevice();
}

//chuong trinh chinh
int main(){
	readgeo();
	readadj();
	//khoi tao man hinh do hoa
	initwindow(600,600);
	//thuc hien phep chieu
	for(int i=0; i<360; i++){
		ObliqueProjection(1,i);
	}
	getch();
}
