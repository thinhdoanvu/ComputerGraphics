#include<stdio.h>
#include<math.h>
#include<graphics.h>
#define dinh 5

//Phep chieu cabinet. cho hinh hop chu nhat co dinh = 8

//khai bao bien
int phi;
double L1 = 0.5;
double phi_rad;

int a[3][dinh]; //ma tran hinh hop chu nhat
int P[3][dinh]; //ma tran ket qua
float T[3][3]; //ma tran bien doi

int X[dinh];
int Y[dinh];

int m=3; //so hang cua ma tran toa do dinh
int p=5; //so cot cua ma tran toa do dinh
int n=3; //so hang = so cot cua ma tran bien doi T

//int D[10][10]; //ma tran ke noi cac dinh
int D[5][5]=
				{
								{1,1,0,1,1},
								{1,1,1,0,1},
								{0,1,1,1,1},
								{1,0,1,1,1},
								{1,1,1,1,1},
						};   
						
//chuong trinh con
void matranke()
{
	  int i,j;
	  
	  for(i=0;i<dinh;i++)
	  {
	  	 D[i][i]=1;
			}
			
			for(i=0;i<dinh-1;i++)
			{
				 for(j=i+1;j<dinh;j++)
				 {
				 	  printf("D[%d,%d]= ",i,j);
				 	  scanf("%d",&D[i][j]);
					}
			}
			
			for(i=0;i<dinh;i++)
			{
				  for(j=0;j<dinh;j++)
				  {
				  	  if(i>j)
				  	  {
				  	  	  D[i][j]=D[j][i];
									}
						}
			}
}

void inmatranke()
{
	  int i,j;
	  
	  	//in ra ma tran ke
			printf("\nDanh sach ma tran ke:\n");
			for(i=0;i<dinh;i++)
			{
				  for(j=0;j<dinh;j++)
				  {
				  	  printf("%d\t",D[i][j]);
						}
						printf("\n");
			}
}

void nhaptoado()
{
			//X												Y														Z
	  a[0][0] = 100; a[1][0] = 100; a[2][0] = 100;//A
			a[0][1] = 100; a[1][1] = 100; a[2][1] = 300;//B
			a[0][2] = 300; a[1][2] = 100; a[2][2] = 300;//C
			a[0][3] = 300; a[1][3] = 100; a[2][3] = 100;//D	
			a[0][4] = 200; a[1][4] = 500; a[2][4] = 200;//S
			
			printf("\nNhap he so goc phi = \n");
			scanf("%d",&phi);
			while(phi<0 || phi >180)
			{
				 printf("\nNhap lai he so goc phi tu 0 - 180 do \n");
				 scanf("%d",&phi);
			}
			phi_rad = (double) (3.14*phi)/180;
}

void matranbiendoi()
{
	  T[0][0] = 1; T[0][1] = 0; T[0][2] = L1*cos(phi_rad); T[0][3] = 0;
			T[1][0] = 0; T[1][1] = 1; T[1][2] = L1*sin(phi_rad); T[1][3] = 0;
			T[2][0] = 0; T[2][1] = 0;	T[2][2] = 0; T[2][3] = 0;
}

void cabinet()
{
	  int i,j,k;
	  
	  //khoi tao ma tran ket qua 
	  for(i=0; i<m; i++) //so hang
	  {
	  	 for(k=0; k<p; k++) //so cot
	  	 {
	  	 	  P[i][k] = 0;
					}
			}

  //nhan 2 ma tran
			for(i=0; i<m; i++) //so hang a
			{
				 for(j=0; j<p; j++)//so cot a
				 {
				 	  for(k=0; k<n; k++)//so cot T
				 	  {
				 	  	  P[i][j] += (float)T[i][k]* a[k][j];
								}
					}
			}
}

void inketqua()
{
	  int i,j;
	  
	  //in toa do cac dinh
	  printf("Toa do cac dinh cua hinh hop:\n");
	  for(i=0;i<m;i++)
	  {
	  	  for(j=0;j<p;j++)
	  	  {
	  	  	  printf("%d\t",a[i][j]);
						}
						printf("\n");
			}
			
			printf("\nGia tri cua ma tran cabinet\n");
			for(i=0;i<m;i++)
			{
				  for(j=0;j<n;j++)
				  {
				  	  printf("%.2f\t",T[i][j]);
						}
						printf("\n");
			}
			
			printf("\nToa do cac dinh cua hinh hop sau khi chieu:\n");
	  for(i=0;i<m;i++)
	  {
	  	  for(j=0;j<p;j++)
	  	  {
	  	  	  printf("%d\t",P[i][j]);
						}
						printf("\n");
			}
}

//in hinh chieu ra man hinh
void inhinhchieu()
{
   int i,j;
   
   for(i=0; i<dinh;i++)
   {
   	 X[i]=P[0][i];
   	 Y[i]=P[1][i];
			}
			
			//in ra mang X va Y
			for(i=0;i<dinh;i++)
			{
				  printf("(%d,%d)\t",X[i],Y[i]);
			}
}

void oxy()
{
	  int i,j;
	  
	  //cai nay do minh dat ban dau, neu sau nay tu nhap tu ban phim thi thay bang so cu the
	  setcolor(RED);
	  for(i=0;i<dinh-1;i++)
	  {
	  	 for(j=i+1;j<dinh;j++)
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

			//nhap ma tran ke
			//nhapmatranke()
			
			//in ra ma tran ke
			inmatranke();
			
   //tinh toan ma tran ket qua
   cabinet();
			
			//in ket qua cac phep toan
			inketqua();
			
			//in ket qua cua phep chieu
			inhinhchieu();
			
			//khoi tao man hinh do hoa
			initwindow(600,600);
			oxy();

			getch();

}
