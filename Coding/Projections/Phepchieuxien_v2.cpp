#include<graphics.h>
#include<stdio.h>
#include<math.h>
#define maxdinh 10

//#define toado "chopnhon.inp"
//#define matranke "chopnhon.mtk"
#define toado "chopcut.inp"
#define matranke "chopcut.mtk"
//khai bao bien
int n; //so dinh cua da giac
int dinh[maxdinh][maxdinh];//ma tran toa do cac dinh cua da giac
int mtk[maxdinh][maxdinh];//ma tran ke cac dinh cua da giac

FILE *fp;

void inmatran(int c[][maxdinh], int m, int n){
	for(int i=0; i<m;i++){
		for(int j=0; j<n; j++){
			printf("%5d",c[i][j]);
		}
		printf("\n");
	}
}

void readfile(){
	fp=fopen(toado,"r");//doc file toa do dinh
	if(fp==NULL){
		printf("File not found");
	}
	else{
		fscanf(fp,"%d",&n);//so dinh
		for(int i=0; i<n; i++){//cac dinh
			for(int j=0; j<3;j++){//x, y, z
				fscanf(fp,"%d",&dinh[i][j]);
			}
		}
	}
	//DOC NOI DUNG TAP TIN MA TRAN KE
	fp=fopen(matranke,"r");//doc file toa do dinh
	if(fp==NULL){
		printf("File not found");
	}
	else{
		fscanf(fp,"%d",&n);//so dinh
		for(int i=0; i<n; i++){//cac dinh
			for(int j=0; j<n;j++){//cac dinh
				fscanf(fp,"%d",&mtk[i][j]);
			}
		}
	}
	fclose(fp);//dong file ma tran ke
	//in toa do cac dinh
	printf("\nToa do cac dinh cua chop nhon: \n");
	inmatran(dinh,n,3);
	//in ma tran ke
	printf("\nma tran ke cac dinh cua chop nhon: \n");
	inmatran(mtk,n,n);
}

void chieuxien(float L, int phi){//phi:goc chieu, L: khoang cach diem chieu - MP
//xi'= x+zLcos(phi)
//yi'=y+zLsin(phi)
	float T[3][3] = {{1,0,0},{0,1,0},{L*cos(phi*3.1416/180),L*sin(phi*3.1416/180),0}};
	printf("\nMa tran bien doi T: \n");
	for(int i=0; i<3; i++){
		for(int j=0; j<3;j++){
			printf("%.2f  ",T[i][j]);
		}
		printf("\n");
	}
	//Tim ma tran ket qua = dinh[n][3]*T[3][3]
	float Pnew[n][3];
	//khoi tao ma tran Pnew = 0 vi cong thuc nhan ma tran co cong don cac phan tu
	for(int i=0; i<n; i++){
		for(int j=0; j<3; j++){
			Pnew[i][j]=0;
		}
	}
	//nhan 2 ma tran T[3][3]*dinh[n][3]
	for(int i=0; i<n; i++){//so hang cua ma tran dinh[n][3]
		for(int j=0; j<3; j++){//so cot cua ma tran dinh[n][3]
			for(int k=0; k<3; k++){//so cot cua ma tran T[3][3]
				Pnew[i][j] += float(dinh[i][k]*T[k][j]);
			}
		}
	}
	//in ket qua cua ma tran Pnew
	printf("\nMa tran Pnew: \n");
	for(int i=0; i<3; i++){
		for(int j=0; j<n;j++){
			printf("%.2f  ",round(Pnew[i][j]));
		}
		printf("\n");
	}
	//ve duong thang noi cac dinh X,Y cua Pnew
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(mtk[i][j]==1){//2 dinh co moi lien he voi nhau
				line(round(Pnew[i][0]), round(Pnew[i][1]), round(Pnew[j][0]), round(Pnew[j][1]));
			}
		}
	}
}



int main(){
	readfile();
	initwindow(600,600);
	for(int phi=0; phi <180; phi++){
		chieuxien(0.5,phi);
		delay(100);
		cleardevice();
	}
	getch();//press any key
}
