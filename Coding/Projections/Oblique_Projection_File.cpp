#include<graphics.h>//line
#include<stdio.h>//printf, scanf
#include<stdlib.h>//FILE
#include<math.h>//sin cos

//#define INPUT "chopnhon.inp"
//#define MTK "chopnhon.mtk"
#define INPUT "chopcut.inp"
#define MTK "chopcut.mtk"
#define maxdinh 20

int P[maxdinh][maxdinh];//Cac dinh cua vat the
int D[maxdinh][maxdinh];//ma tran ke
int R[3][maxdinh];//ma tran ket qua
int sodinh, sochieu;//so chieu =3 (XYZ)
int X[maxdinh];
int Y[maxdinh];
int Z[maxdinh];
float T[3][3];//ma tran bien doi
int phi;
float L=0.5;
FILE *fp;

void nhaptoado(){
	int i,j;
	
	fp=fopen(INPUT,"r");
	if(fp==NULL){
		printf("File not found");
	}
	else{
		//doc so chieu
		fscanf(fp,"%d",&sochieu);
		//doc so dinh
		fscanf(fp,"%d",&sodinh);
		//doc toa do cac dinh cua vat the
		for(i=0;i<sochieu;i++){
			for(j=0;j<sodinh;j++){
				fscanf(fp,"%d",&P[i][j]);
			}
		}
		fclose(fp);
	}

	//in ra man hinh
	printf("so chieu khong gian = %d",sochieu);
	printf("\nso dinh cua vat the = %d",sodinh);
	printf("\nToa do cac dinh cua vat the la:\n");
	for(i=0;i<sochieu;i++){
		for(j=0;j<sodinh;j++){
			printf("%d  ",P[i][j]);
		}
		printf("\n");
	}
}

void matranke(){
	int i,j;
	fp=fopen(MTK,"r");
	if(fp==NULL){
		printf("File not found");
	}
	else{
		for(i=0;i<sodinh;i++){
			for(j=0;j<sodinh;j++){
				fscanf(fp,"%d",&D[i][j]);
			}
		}
		fclose(fp);
	}
	//in ra ma tran ke
	printf("\nma tran ke:\n");
	for(i=0;i<sodinh;i++){
		for(j=0;j<sodinh;j++){
			printf("%d  ",D[i][j]);
		}
		printf("\n");
	}
}

void mbiendoiZ(){//theo Z
	int i,j;
	T[0][0]=1;
	T[0][1]=0;
	T[0][2]=(float)L*cos(phi*3.1416/180);
	
	T[1][0]=0;
	T[1][1]=1;
	T[1][2]=(float)L*sin(phi*3.1416/180);
	
	T[2][0]=0;
	T[2][1]=0;
	T[2][2]=0;
	
	printf("\nma tran bien doi:\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%.1f  ",T[i][j]);
		}
		printf("\n");
	}
}

void mbiendoiY(){//theo Y
	int i,j;
	T[0][0]=1;
	T[0][1]=(float)L*cos(phi*3.1416/180);
	T[0][2]=0;
	
	T[1][0]=0;
	T[1][1]=(float)L*sin(phi*3.1416/180);
	T[1][2]= 1;
	
	T[2][0]=0;
	T[2][1]=0;
	T[2][2]=0;
	
	printf("\nma tran bien doi:\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%.1f  ",T[i][j]);
		}
		printf("\n");
	}
}

void mbiendoiX(){//theo X
	int i,j;
	T[0][0]=(float)L*cos(phi*3.1416/180);
	T[0][1]=1;
	T[0][2]=0;
	
	T[1][0]=(float)L*sin(phi*3.1416/180);
	T[1][1]=0;
	T[1][2]= 1;
	
	T[2][0]=0;
	T[2][1]=0;
	T[2][2]=0;
	
	printf("\nma tran bien doi:\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%.1f  ",T[i][j]);
		}
		printf("\n");
	}
}

void oblique(){
	int i,j,k;
	//khoi tao ma tran ket qua
	for(i=0;i<sochieu;i++){
		for(j=0;j<sodinh;j++){
			R[i][j]=0;
		}
	}
	//nhan 2 ma tran
	for(i=0;i<sochieu;i++){//hang P
		for(j=0;j<sodinh;j++){//cot P
			for(k=0;k<3;k++){//cot T
				R[i][j]+=T[i][k]*P[k][j];
			}
		}
	}
	printf("\nMa tran ket qua:\n");
	for(i=0;i<sochieu;i++){
		for(j=0;j<sodinh;j++){
			printf("%d  ",R[i][j]);
		}
		printf("\n");
	}
	//gan X,Y
	for(i=0;i<sodinh;i++){
		X[i]=R[0][i];
		Y[i]=R[1][i];
		Z[i]=R[2][i];
	}
}

void oxy(){//chieu len truc z = chieu dung (z=0)
	int i,j;
	for(i=0;i<sodinh-1;i++){
		for(j=i+1;j<sodinh;j++){
			if(D[i][j]==1){
				line(X[i],Y[i],X[j],Y[j]);
			}
		}
	}
}

int main(){
	nhaptoado();
	matranke();
	initwindow(800,800);
	while(1){
		for(phi=0;phi<360;phi++){
			mbiendoiZ();
			oblique();	
			oxy();		
			delay(100);
			cleardevice();
		}
		for(phi=0;phi<360;phi++){
			mbiendoiY();
			oblique();	
			oxy();		
			delay(100);
			cleardevice();
		}
		for(phi=0;phi<360;phi++){
			mbiendoiX();
			oblique();	
			oxy();		
			delay(100);
			cleardevice();
		}
	}
	getch();
}
