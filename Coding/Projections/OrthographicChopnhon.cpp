//khai bao thu vien
#include<graphics.h>

//khai bao bien
//int X[10],Y[10],Z[10]; //toi da 10 dinh cua doi tuong 3D
int X[5]={100,100,300,300,200};
int Y[5]={100,100,100,100,500};
int Z[5]={100,300,300,100,200};

//int D[10][10]; //ma tran ke noi cac dinh
int D[5][5]=
				{
								{1,1,0,1,1},
								{1,1,1,0,1},
								{0,1,1,1,1},
								{1,0,1,1,1},
								{1,1,1,1,1},
						};  
						
int sodinh =5;
	   
//chuong trinh con
void nhapdiem()
{
	  int i,j;
	  printf("Nhap so luong dinh: ");
	  scanf("%d",&sodinh);
	  
	  for(i=0;i<sodinh;i++)
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
	  for(i=0;i<sodinh;i++)
			{
				 printf("%d\t",X[i]);
			}
			
			printf("\n");
			for(i=0;i<sodinh;i++)
			{
				 printf("%d\t",Y[i]);
			}
			
			printf("\n");
			for(i=0;i<sodinh;i++)
			{
				 printf("%d\t",Z[i]);
			}
}

void matranke()
{
	  int i,j;
	  
	  for(i=0;i<sodinh;i++)
	  {
	  	 D[i][i]=1;
			}
			
			for(i=0;i<sodinh-1;i++)
			{
				 for(j=i+1;j<sodinh;j++)
				 {
				 	  printf("D[%d,%d]= ",i,j);
				 	  scanf("%d",&D[i][j]);
					}
			}
			
			for(i=0;i<sodinh;i++)
			{
				  for(j=0;j<sodinh;j++)
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
			for(i=0;i<sodinh;i++)
			{
				  for(j=0;j<sodinh;j++)
				  {
				  	  printf("%d\t",D[i][j]);
						}
						printf("\n");
			}
}

void oxy()
{
	  int i,j;
	  
	  //cai nay do minh dat ban dau, neu sau nay tu nhap tu ban phim thi thay bang so cu the
	  
	  for(i=0;i<sodinh-1;i++)
	  {
	  	 for(j=i+1;j<sodinh;j++)
	  	 {
	  	 	  if(D[i][j]==1)
	  	 	  {
	  	 	  	  line(X[i],Y[i],X[j],Y[j]);
								}
					}
			}
}

void oxz()
{
	  int i,j;
	  
	  //cai nay do minh dat ban dau, neu sau nay tu nhap tu ban phim thi thay bang so cu the
	  
	  for(i=0;i<sodinh-1;i++)
	  {
	  	 for(j=i+1;j<sodinh;j++)
	  	 {
	  	 	  if(D[i][j]==1)
	  	 	  {
	  	 	  	  line(X[i],Z[i],X[j],Z[j]);
								}
					}
			}
}

void oyz()
{
	  int i,j;
	  
	  //cai nay do minh dat ban dau, neu sau nay tu nhap tu ban phim thi thay bang so cu the
	  
	  for(i=0;i<sodinh-1;i++)
	  {
	  	 for(j=i+1;j<sodinh;j++)
	  	 {
	  	 	  if(D[i][j]==1)
	  	 	  {
	  	 	  	  line(Z[i],Y[i],Z[j],Y[j]);
								}
					}
			}
}


void ve3D()
{
			outtextxy(0,0,"Hinh chieu tren mat phang XY");
			setcolor(RED);
	  oxy();
	  getch();
	  
	  cleardevice();
	  outtextxy(0,0,"Hinh chieu tren mat phang XZ");
	  setcolor(GREEN);
	  oxz();
	  getch();
	  
	  cleardevice();
	  outtextxy(0,0,"Hinh chieu tren mat phang YZ");
	  setcolor(YELLOW);
	  oyz();
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
	  initwindow(600,600);
	  
	  ve3D();
	  
	  getch();
}
