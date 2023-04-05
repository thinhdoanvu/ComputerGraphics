#include<graphics.h>
#include<stdio.h>
#define maxdinh 10
//#define toado "chopnhon_v2.inp"
//#define matranke "chopnhon_v2.mtk"
#define toado "chopcut_v2.inp"
#define matranke "chopcut_v2.mtk"
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

void oxy(){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(mtk[i][j]==1){//2 dinh co moi lien he voi nhau
				line(dinh[i][0], dinh[i][1], dinh[j][0], dinh[j][1]);
			}
		}
	}
}

void oxz(){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(mtk[i][j]==1){//2 dinh co moi lien he voi nhau
				line(dinh[i][0], dinh[i][2], dinh[j][0], dinh[j][2]);
			}
		}
	}
}

void oyz(){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(mtk[i][j]==1){//2 dinh co moi lien he voi nhau
				line(dinh[i][1], dinh[i][2], dinh[j][1], dinh[j][2]);
			}
		}
	}
}

int main(){
	readfile();
	initwindow(600,600);
	setcolor(2);
	oxy();
	delay(1000);
	setcolor(4);
	oxz();
	delay(1000);
	setcolor(13);
	oyz();
	getch();//press any key
}
