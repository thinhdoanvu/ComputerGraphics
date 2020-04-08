#include<stdio.h>
#include<math.h>
#include<graphics.h>

int dinh=8;
double L1 = 0.5;
double phi = 45.0;
double phi_rad = (double) (3.14*phi)/180;

//khai bao bien
//int X[10],Y[10],Z[10]; //toi da 10 dinh cua doi tuong 3D
int X[8]={100,100,200,200,100,100,200,200};
int Y[8]={100,100,100,100,200,200,200,200};
int Z[8]={100,200,200,100,100,200,200,100};

//int D[10][10]; //ma tran ke noi cac dinh
int D[8][8]=
				{
								{1,1,0,1,1,0,0,0},//A
								{1,1,1,0,0,1,0,0},//B
								{0,1,1,1,0,0,1,0},//C
								{1,0,1,1,0,0,0,1},//D
								{1,0,0,0,1,1,0,1},//E
								{0,1,0,0,1,1,1,0},//F
								{0,0,1,0,0,1,1,1},//G
								{0,0,0,1,1,0,1,1}//H
						};  
						
//ma tran bien doi Tx,Ty,Tz
float Tx[3]={1,0,L1*cos(phi_rad)};
float Ty[3]={0,1,L1*sin(phi_rad)};
float Tz[3]={0,0,0};
						
//chuong trinh con
void nhapdiem()
{
	  int i,j;
	  printf("Nhap so luong dinh: ");
	  scanf("%d",&dinh);
	  
	  for(i=0;i<dinh;i++)
	  {
	  	  printf("X[%d]= ",i);
	  	  scanf("%d",&X[i]);
	  	  printf("Y[%d]= ",i);
	  	  scanf("%d",&Y[i]);
	  	  printf("Z[%d]= ",i);
	  	  scanf("%d",&Z[i]);
			}
}

void intoadoadiem()
{
	  int i,j;
	  for(i=0;i<dinh;i++)
			{
				 printf("%d\t",X[i]);
			}
			
			printf("\n");
			for(i=0;i<dinh;i++)
			{
				 printf("%d\t",Y[i]);
			}
			
			printf("\n");
			for(i=0;i<dinh;i++)
			{
				 printf("%d\t",Z[i]);
			}
}

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

//chuong trinh chinh
int main()
{

	   //nhap toa do cac diem
	   //nhapdiem();
	   
	   intoadoadiem();
	   
	   //nhap ma tran ke
	   //matranke();
				 
						
				//in ra ma tran ke
				inmatranke();
				
	  //khoi tao man hinh do hoa
	  //initwindow(600,600);
	  
	  //ve3D();
	  
	  getch();
}
