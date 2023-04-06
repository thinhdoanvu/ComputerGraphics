#include<graphics.h>//ve hinh
#include<stdio.h>//printf ...
#include<math.h>//sin cos round
#define maxdinh 20//toi da la 20 dinh
#define toado "chopcut_v2.inp"
#define matranke "chopcut_v2.mtk"

//khai bao bien
int n;//so dinh cua hinh chop
int dinh[maxdinh][maxdinh];//toa do cac dinh
int mtk[maxdinh][maxdinh];//danh sach ma tran ke
FILE *fp;//con tro tap tin

//ham in ra ma tran
void inmatran(int a[][maxdinh], int hang, int cot){
	for(int i=0;i<hang;i++){
		for(int j=0; j<cot; j++){
			printf("%5d",a[i][j]);
		}
		printf("\n");//het so cot thi xuong hang
	}
	printf("\n");
}
//doc toa do cac dinh cua hinh chop
void readfile(){
	//doc file toa do
	fp=fopen(toado,"r");
	if(fp==NULL) printf("File not found");
	//doc so dinh: dong 1 cua tap tin
	fscanf(fp,"%d",&n);//1 lan fscanf thi doc duoc 1 gia tri
	for(int i=0; i<n; i++){//so hang: 5
		for(int j=0; j<3; j++){//so cot: 3
			fscanf(fp,"%d",&dinh[i][j]);//5*3=15 ham fscanf
		}
	}
	//in ra toa do cac dinh cua da giac
	inmatran(dinh,n,3);
	fclose(fp);//dong tap tin toa do dinh
	
	//doc file ma tran ke
	fp=fopen(matranke,"r");
	if(fp==NULL) printf("File not found");
	//doc so dinh: dong 1 cua tap tin
	fscanf(fp,"%d",&n);//1 lan fscanf thi doc duoc 1 gia tri
	for(int i=0; i<n; i++){//so hang: 5
		for(int j=0; j<n; j++){//so cot: 5
			fscanf(fp,"%d",&mtk[i][j]);//5*5=25 ham fscanf
		}
	}
	//in ra toa do cac dinh cua da giac
	inmatran(mtk,n,n);
	fclose(fp);//dong tap tin toa do dinh
}

void chieuxien(float L, int theta){
	printf("\n");
	float T[3][3] = {{1,0,0},{0,1,0,},{L*cos(theta*3.1416/180),L*sin(theta*3.1416/180),0}};
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			printf("%.2f  ",T[i][j]);
		}		
		printf("\n");
	}
	//khoi tao ma tran ket qua
	int Pnew[maxdinh][maxdinh];
	for(int i=0; i<n; i++){
		for(int j=0; j<3; j++){
			Pnew[i][j]=0;
		}
	}
	//nhan 2 ma tran dinh[n][3] * T[3][3]
	for(int i=0; i<n; i++){//so hang cua ma tran dinh[][]
		for(int j=0; j<3; j++){//so cot cua ma tran dinh[][] == so hang ma tran T
			for(int k=0; k<3; k++){//so cot cua ma tran T
				Pnew[i][j] += round(dinh[i][k]*T[k][j]);//toa do cac dinh cua hinh chop la so nguyen
			}
		}
	}
	//in ra toa do sau khi chieu
	inmatran(Pnew,n,3);
	//ve toa do cac dinh cua hinh chop sau khi chieu
	for(int i=0;i<n-1;i++){
		for(int j=i+1; j<n; j++){
			if(mtk[i][j]==1){
				line(Pnew[i][0], Pnew[i][1], Pnew[j][0], Pnew[j][1]);
			}
		}
	}
}

int main(){
	readfile();
	initwindow(600,600);
	char buf[32];
	settextstyle(DEFAULT_FONT,HORIZ_DIR, 20);
	for(int i=0; i<180; i++){
		sprintf(buf,"%d",i);
		outtextxy(0,0,buf);
		chieuxien(0.5,i);
		delay(100);
		cleardevice();
	}
	getch();//press any key
}
