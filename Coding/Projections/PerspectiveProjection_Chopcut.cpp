#include<stdio.h>
#include<math.h>
#include<graphics.h>
#define dinh 8

//Phep chieu cabinet. cho hinh hop chu nhat co dinh = 8

//khai bao bien
int xp, yp, zp; //tam chieu

int a[4][dinh]; //ma tran hinh hop chu nhat
int P[4][dinh]; //ma tran ket qua

int X[dinh];
int Y[dinh];

int m=8;//so dinh
int p=8;


//int D[10][10]; //ma tran ke noi cac dinh
int D[8][8]=
				{
							//A,B,C,D,E,F,G,H
								{1,1,0,1,1,0,0,0},//A
								{1,1,1,0,0,1,0,0},//B
								{0,1,1,1,0,0,1,0},//C
								{1,0,1,1,0,0,0,1},//D
								{1,0,0,0,1,1,0,1},//E
								{0,1,0,0,1,1,1,0},//F
								{0,0,1,0,0,1,1,1},//G
								{0,0,0,1,1,0,1,1},//H
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
			a[0][1] = 100; a[1][1] = 100; a[2][1] = 400;//B
			a[0][2] = 400; a[1][2] = 100; a[2][2] = 400;//C
			a[0][3] = 400; a[1][3] = 100; a[2][3] = 100;//D	
			a[0][4] = 200; a[1][4] = 400; a[2][4] = 200;//E
			a[0][5] = 200; a[1][5] = 400; a[2][5] = 300;//F
			a[0][6] = 300; a[1][6] = 400; a[2][6] = 300;//G
			a[0][7] = 300; a[1][7] = 400; a[2][7] = 200;//H
			
			
			printf("\nNhap toa do tam chieu (xp,yp,zp)=\n");
			printf("xp = ");
			scanf("%d",&xp);
			printf("yp = ");
			scanf("%d",&yp);
			printf("zp = ");
			scanf("%d",&zp);
			
			
			//xp = 300; yp = 320; zp = 100;
}

void perspective_1tam()
{
	  int i,j;
	  int x;
	  int y;
	  int z;
	  
	  for(i=0;i<dinh;i++)
	  {
	  	  for(j=0;j<dinh;j++)
	  	  {
	  	  	  P[i][j]=0;
						}
		 }
		 
		 //tinh toan gia tri cac dinh tren man chieu
		 for(i=0;i<dinh;i++)
		 {
		 	  x=a[0][i];
		 	  y=a[1][i];
		 	  z=a[2][i];
		 	  
		 	  P[0][i]= xp+(float)(x+xp)/(z+zp)*zp; //Toa do x'
		 	  P[1][i]= yp+(float)(y+yp)/(z+zp)*zp;//Toa do y'
		 	  
		 	  //P[0][i]= (float)(x*zp)/(z+zp); //Toa do x'
		 	  //P[1][i]= (float)(y*zp)/(z+zp);//Toa do y'
		 	  
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
	  setcolor(GREEN);
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
	  
   //nhap ma tran ke
			//nhapmatranke()
			
			//in ra ma tran ke
			inmatranke();
			
   //tinh toan ma tran ket qua
   perspective_1tam();
			
			//in ket qua cac phep toan
			inketqua();
			
			//in ket qua cua phep chieu
			inhinhchieu();
			
			//khoi tao man hinh do hoa
			initwindow(600,600);
			oxy();


getch();

}
