//khai bao thu vien
#include <stdio.h>
#include <graphics.h>
#define max_dinh 20

//khai bao bien
int sodinh;
int a[max_dinh][2];
int i;
int xc, yc;

//chuong trinh con
void nhapthongso()
{
	  printf("So dinh cua da giac: ");
	  scanf("%d",&sodinh);
	  
	  printf("Nhap toa do cac dinh cua da giac\n");
	  for(i=0;i<sodinh;i++)
	  {
	  	  printf("X[%d] = ",i);
	  	  scanf("%d",&a[i][0]);
	  	  printf("Y[%d] = ",i);
	  	  scanf("%d",&a[i][1]);
			}
			
			a[sodinh][0]=a[0][0];
			a[sodinh][1]=a[0][1];
			
			printf("Nhap toa do diem ben trong da giac\n");
			printf("xc = ");
			scanf("%d",&xc);
			printf("yc = ");
			scanf("%d",&yc);
}

//ve da giac
void vedagiac()
{
	  setcolor(GREEN);
	  for(i=0;i<sodinh;i++)
	  {
	  	  line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
			}
}

//to mau
void BoundaryRight(int xa, int ya)
{ 
			
	  if( (getpixel(xa,ya) != GREEN) && (getpixel(xa,ya) != RED) ) //mau nen la mau den (BLACK) nen ham getpixel tra ve gia tri la 0
	  {
	  	  putpixel(xa,ya,RED);
	  	  delay(1);
	  	  
						//to mau het ve phia ben phai
	  	  BoundaryRight(++xa,ya);
	  	  
	  	  //giam x - 1
	  	  xa--;
	  	  
						//to mau tu diem ke bien den tan cung ben duoi
	  	  BoundaryRight(xa,ya+1);
	  	  
	  	  //to mau tu diem ke bien den tan cung ben tren
	  	  BoundaryRight(xa,ya-1);
			}
		
}

//to nua ben trai
void BoundaryLeft(int xa, int ya)
{ 
			
	  if( (getpixel(xa,ya) != GREEN) && (getpixel(xa,ya) != RED) ) //mau nen la mau den (BLACK) nen ham getpixel tra ve gia tri la 0
	  {
	  	  putpixel(xa,ya,RED);
	  	  delay(1);
	  	  
						//to mau het ve phia ben phai
	  	  BoundaryLeft(--xa,ya);
	  	  
	  	  //tang x - 1
	  	  xa++;
	  	  
						//to mau tu diem ke bien den tan cung ben duoi
	  	  BoundaryLeft(xa,ya+1);
	  	  
	  	  //to mau tu diem ke bien den tan cung ben tren
	  	  BoundaryLeft(xa,ya-1);
			}
		
}

void BoundaryFill()
{
	  BoundaryRight(xc,yc);
	  BoundaryLeft(xc-1,yc);
}

//chuong trinh chinh
int main()
{
	  //nhap thong so cho da giac
	  nhapthongso();
	  
	  initwindow(600,600);
	  //ve da giac
	  vedagiac();
	  
	  //To mau 
	  BoundaryFill();
	  
	  getch();
	  
}
