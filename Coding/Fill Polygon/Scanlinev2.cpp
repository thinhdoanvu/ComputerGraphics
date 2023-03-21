#include<winbgim.h>
#include<stdio.h>
#include<math.h>
#define maxdinh 20
#define INPUT "scanline.inp"

//khai bao bien
int td[maxdinh][maxdinh];//toa do cac dinh cua da giac
int n;//so dinh cua da giac
FILE *fp;//con tro tap tin fp
float m[maxdinh];//he so goc cac canh cua da giac
int ymin, ymax;

void nhapdinh(){
	fp=fopen(INPUT,"r");//mo tap tin de doc
	if(fp==NULL){
		printf("File not found");
	}
	fscanf(fp,"%d",&n);
	printf("So dinh cua da giac: %d",n);
	//doc cac dinh cua da giac
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++){
			fscanf(fp,"%d",&td[i][j]);	
		}
	}
	//them 1 dinh thu 4 == dinh thu 0
	td[n][0]=td[0][0];//x[n] = x[0]
	td[n][1]=td[0][1];//y[n] = y[0]
	//in ra cac dinh cua da giac
	printf("\nToa do cac dinh cua da giac: \n");
	for(int i=0; i<n; i++){
		for(int j=0;j<2;j++){
			printf("%10d",td[i][j]);
		}
		printf("\n");
	}
	fclose(fp);
}

void hesogoc(){
	for(int i=0; i<n; i++){
		//co 2 truong hop dac biet: dy=0 va dx=0
		//xsau=xtruoc + (y-ytruoc)/m
		if(td[i+1][1] == td[i][1]){//dy=0
			m[i]=1;//dang le m=0 nhung do cong thuc tim xgd co chia m nen phep chia bao loi (m chi can #0)
		}
		else{
			if(td[i+1][0] == td[i][0]){//dx=0
				m[i]=9999;//man hinh co do phan giai 400x400 nen m =9999 la vuot qua size man hinh = vo cung
			}
			else{
				//m=dy/dx;
				m[i]=(float)(td[i+1][1] - td[i][1])/(td[i+1][0] - td[i][0]);//yi+1 - yi / xi+1 - xi	
			}	
		}
	}
	printf("\nHe so goc cac canh cua da giac: ");
	for(int i=0;i<n;i++){
		printf("%.1f  ",m[i]);
	}
	
}

void minmax(){
	ymin=td[0][1];//ymin = tung do dinh 0
	ymax=td[0][1];//ymax = tung do dinh 0
	for(int i=0; i<n; i++){
		if(ymin > td[i][1]){
			ymin=td[i][1];
		}
		if(ymax < td[i][1]){
			ymax=td[i][1];
		}
	}
	printf("\nymin= %d",ymin);
	printf("\nymax= %d",ymax);
}

void vedagiac(){
	for(int i=0;i<n;i++){//hang: so dinh
		setcolor(4);//thiep lap mau ve
		setlinestyle(1,0,3);
		line(td[i][0],td[i][1],td[i+1][0],td[i+1][1]);
	}
}

void scanline(){
	int xgd[maxdinh];
	for(int y=ymin;y<ymax;y++){
		//xet xem co giao diem hay khong co giao diem tung canh cua da giac
		int dem=0;//luu giu so giao diem cua moi y so voi cac canh cua da giac
		//moi lan tang dong quet thi dem se lai ve 0 hay so giao diem = 0
		for(int i=0; i<n; i++){//xet tung canh cua da giac
			if((y < td[i][1] && y < td[i+1][1])||(y > td[i][1] && y > td[i+1][1])){//dong quet nam duoi hoac tren ca 2 tung do dinh
				printf("\nKhong co giao diem y = %d voi canh (%d,%d) - (%d,%d)",y,td[i][0],td[i][1],td[i+1][0],td[i+1][1]);
			}
			else{
				printf("\nTon tai giao diem giua y = %d voi canh cua da giac",y);
				//xac dinh hoanh do giao diem
				xgd[dem++]=round(td[i][0] + (y - td[i][1])/m[i]);
//				dem++;
			}
		}
		//in ra cac xgd cua y voi cac canh cua da giac
		printf("\nCac hoanh do giao diem cua y = %d voi cac canh cua da giac:",y);
		for(int i=0; i<dem; i++){
			printf("(%d,%d)   ",xgd[i],y);
		}
		//sap xep cac dinh theo hoanh do cua xgd
		for(int i=0;i<dem-1;i++){
			for(int j=i+1;j<dem;j++){
				if(xgd[i]>xgd[j]){
					int tam=xgd[i];
					xgd[i]=xgd[j];
					xgd[j]=tam;
				}
			}
		}
		//noi cac dinh cua hoanh do giao diem lai voi nhau
		for(int i=0; i<dem-1;i=i+2){
			setcolor(2);
			line(xgd[i],y,xgd[i+1],y);//vi cung y
		}
	}	
}


int main(){
	nhapdinh();
	hesogoc();
	minmax();
	initwindow(500,500);
	vedagiac();
	scanline();
	getch();//press any key
}

