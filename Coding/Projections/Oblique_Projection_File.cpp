#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define maxdinh 20
#define FILENAME "chopnhon.inp"
#define MTK "chopnhon.mtk"
#define MTBD "chopnhon.mtbd"

//khai bao bien
int X[maxdinh];
int Y[maxdinh];
int Z[maxdinh];
int P[maxdinh][maxdinh];//ma tran hinh hop chu nhat
int D[maxdinh][maxdinh];//ma tran ke
int R[maxdinh][maxdinh];//ma tran ket qua
float T[maxdinh][3];//ma tran bien doi
int cot, hang; //hang, cot cua 3D
int rbd=3;//cot cua ma tran bien doi

FILE *fp;

int phi = 15;
double L1 = 1;
double phi_rad = (double) (3.14*phi/180);

//chuong trinh con
void matranke(){
	fp=fopen(MTK,"r");
	if(fp==NULL){
		printf("File not found!");
		exit(1);
	}
	else{
		int i,j;
		for(i=0;i<cot;i++){
			for(j=0;j<cot;j++){
				fscanf(fp,"%d",&D[i][j]);
			}
		}
		printf("\nMa tran ke cac dinh:\n");
		for(i=0;i<cot;i++){
			for(j=0;j<cot;j++){
				printf("%d  ",D[i][j]);
			}
			printf("\n");
		}
		fclose(fp);
	}
}

void nhaptoado()
{
int i,j;
	fp = fopen(FILENAME,"r");
	if(fp == NULL){
		printf("File not found!");
		exit(1);
	}
	else{
		fscanf(fp,"%d",&hang);
		fscanf(fp,"%d",&cot);
		
		//doc toa do cho P
		for(i=0;i<hang;i++){
			for(j=0;j<cot;j++){
				fscanf(fp,"%d",&P[i][j]);
			}
		}
		fclose(fp);
	}
	//in ra cac phan tu cua ma tran P
	printf("\nToa do cac dinh cua hinh chop:\n");
	for(i=0;i<hang;i++){
		for(j=0;j<cot;j++){
			printf("%d  ",P[i][j]);
		}
		printf("\n");
	}			
}

void matranbiendoi()
{
	T[0][0] = 1; 
	T[0][1] = 0; 
	T[0][2] = L1*cos(phi_rad); 
	T[0][3] = 0;
	T[1][0] = 0; 
	T[1][1] = 1; 
	T[1][2] = L1*sin(phi_rad); 
	T[1][3] = 0;
	T[2][0] = 0; 
	T[2][1] = 0;
	T[2][2] = 0; 
	T[2][3] = 0;
	
	int i,j;
	printf("\nMa tran bien doi:\n");
	for(i=0;i<hang;i++){
		for(j=0;j<3;j++){
			printf("%.2f ",T[i][j]);
		}
		printf("\n");
	}
}

void cabinet()
{
	int i,j,k;
	  
	//khoi tao ma tran ket qua 
	for(i=0; i<hang; i++) //so hang
	{
	  	for(k=0; k<cot; k++) //so cot
	  	{
			R[i][k] = 0;
		}
	}

	//nhan 2 ma tran
	for(i=0; i<hang; i++) //so hang P
	{
		for(j=0; j<cot; j++)//so cot P
		{
			for(k=0; k<rbd; k++)//so cot T
			{
				R[i][j] += (float)T[i][k]* P[k][j];
			}
		}
	}
	
	//ma tran sau khi bien doi
	printf("\nToa do cac dinh cua hinh hop sau khi chieu:\n");
	for(i=0;i<hang;i++)
	{
	  	for(j=0;j<cot;j++)
	  	{
	  	  	printf("%d  ",R[i][j]);
		}
		printf("\n");
	}
}


//in hinh chieu ra man hinh
void inhinhchieu()
{
	int i,j;
	for(i=0; i<cot;i++)
	{
		X[i]=R[0][i];
		Y[i]=R[1][i];
	}
	//in ra mang X va Y
	printf("\nToa do XY sau khi bien doi\n");
	for(i=0;i<cot;i++)
	{
		printf("(%d,%d)  ",X[i],Y[i]);
	}
}

void oxy()
{
	int i,j;
	  
	setcolor(RED);
	for(i=0;i<cot-1;i++)
	{
	  	for(j=i+1;j<cot;j++)
	  	{
	  	 	if(D[i][j]==1)
	  	 	{
	  	 	  	line(X[i],Y[i],X[j],Y[j]);
	  	 	  	delay(100);
			}
		}
	}
}

//chuong trinh chinh
int main()
{
	//nhap toa do cac dinh cua hinh hop
	nhaptoado();
	//nhap ma tran bien doi
	matranbiendoi();
	//in ra ma tran ke
	matranke();
	//tinh toan ma tran ket qua
	cabinet();
	//in ket qua cua phep chieu
	inhinhchieu();
	//khoi tao man hinh do hoa
	initwindow(600,600);
	oxy();
	getch();
}
