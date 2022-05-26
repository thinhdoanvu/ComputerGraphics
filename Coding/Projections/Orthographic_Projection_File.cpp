#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#define maxdinh 20
//#define FILENAME "chopnhon.inp"
//#define MTK "chopnhon.mtk"
#define FILENAME "chopcut.inp"
#define MTK "chopcut.mtk"

//khai bao bien
int X[maxdinh];
int Y[maxdinh];
int Z[maxdinh];
int D[maxdinh][maxdinh];
int cot, hang;
FILE *fp;

void nhaptoado(int X[maxdinh], int Y[maxdinh], int Z[maxdinh]){
	fp = fopen(FILENAME,"r");
	if(fp == NULL){
		printf("File not found!");
		exit(1);
	}
	else{
		fscanf(fp,"%d",&hang);
		fscanf(fp,"%d",&cot);
		//doc toa do cho X
		int i;
		for(i=0;i<cot;i++){
			fscanf(fp,"%d",&X[i]);
			printf("%d  ",X[i]);
		}
		printf("\n");
		//doc toa do cho Y
		for(i=0;i<cot;i++){
			fscanf(fp,"%d",&Y[i]);
			printf("%d  ",Y[i]);
		}
		printf("\n");
		//doc toa do cho Z
		for(i=0;i<cot;i++){
			fscanf(fp,"%d",&Z[i]);
			printf("%d  ",Z[i]);
		}
		fclose(fp);
	}
}

void matranke(int D[maxdinh][maxdinh]){
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

int oxy(int X[maxdinh],int Y[maxdinh]){//chieu mat truoc: chieu dung
	int i,j;
	for(i=0;i<cot-1;i++){
		for(j=i+1;j<cot;j++){
			if(D[i][j]==1){
				line(X[i],Y[i],X[j],Y[j]);			
			}
		}
	}
}

int oyz(int Y[maxdinh], int Z[maxdinh]){//chieu mat ben: chieu canh
	int i,j;
	for(i=0;i<cot-1;i++){
		for(j=i+1;j<cot;j++){
			if(D[i][j]==1){
				line(Y[i],Z[i],Y[j],Z[j]);			
			}
		}
	}
}

int oxz(int X[maxdinh], int Z[maxdinh]){//chieu mat day: chieu bang
	int i,j;
	for(i=0;i<cot-1;i++){
		for(j=i+1;j<cot;j++){
			if(D[i][j]==1){
				line(X[i],Z[i],X[j],Z[j]);			
			}
		}
	}
}
int main(){
	nhaptoado(X,Y,Z);
	matranke(D);
	initwindow(600,600);
	//printf("\nKet qua hinh chieu dung:\n");
	//oxy(X,Y);
	//printf("\nKet qua hinh chieu canh:\n");
	//oyz(Y,Z);
	printf("\nKet qua hinh chieu bang:\n");
	oyz(X,Z);
	getch();
}

