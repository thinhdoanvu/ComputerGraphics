#include<stdio.h>
#include<graphics.h>
#define max_dinh 20

//khai bao bien
int a[max_dinh][2];
int sodinh;
int i;
int xc,yc;

//chuong trinh con
void nhapdagiac()
{
	  printf("Nhap so dinh cua da giac: ");
	  scanf("%d",&sodinh);
	  
	  for(i=0;i<sodinh;i++)
	  {
	  	  printf("X[%d] = ",i);
	  	  scanf("%d",&a[i][0]);
	  	  printf("Y[%d] = ",i);
	  	  scanf("%d",&a[i][1]);
			}
			
			a[sodinh][0]=a[0][0];
			a[sodinh][1]=a[0][1];
			
			//xac dinh diem ban dau thuoc ben trong da giac
			printf("Toa do diem ben trong da giac:\n");
	  printf("xc = ");
	  scanf("%d",&xc);
	  printf("yc = ");
	  scanf("%d",&yc);
}

void vedagiac()
{
	  setcolor(GREEN);
	  for(i=0;i<sodinh;i++)
	  {
	  	  line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
			}
}

//to mau ben phai
void FillRight(int xa, int ya)
{ 
			
	  if(getpixel(xa,ya) == 0) //mau nen la mau den (BLACK) nen ham getpixel tra ve gia tri la 0
	  {
	  	  putpixel(xa,ya,RED);
	  	  //delay(2);
						//to mau het ve phia ben phai
	  	  FillRight(++xa,ya);
	  	  
	  	  xa--;
	  	  
						//to mau tu diem ke bien den tan cung ben duoi
	  	  FillRight(xa,ya+1);
	  	  
	  	  //to mau tu diem ke bien den tan cung ben tren
	  	  FillRight(xa,ya-1);
			}
		
}

//to mau ben trai
void FillLeft(int xa, int ya)
{ 
			
	  if(getpixel(xa,ya) == 0) //mau nen la mau den (BLACK) nen ham getpixel tra ve gia tri la 0
	  {
	  	  putpixel(xa,ya,RED);
	  	  //delay(2);
						//to mau het ve phia ben trai
	  	  FillLeft(--xa,ya);
	  	  
	  	  xa++;
	  	  
						//to mau tu diem ke bien den tan cung ben duoi
	  	  FillLeft(xa,ya+1);
	  	  
	  	  //to mau tu diem ke bien den tan cung ben tren
	  	  FillLeft(xa,ya-1);
			}
		
}

//to mau da giac
void FloodFill()
{ 
  FillRight(xc,yc);
	 FillLeft(xc-1,yc);
}

//chuong trinh chinh
int main()
{
	  //nhap thong tin da giac
	  nhapdagiac();
	  
	  initwindow(600,600);
	  
	  //ve da giac
	  vedagiac();
	  
	  //to mau
	  FloodFill();
	  
	  getch();
}
