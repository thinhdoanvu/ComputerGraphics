//khai bao thu vien
#include<stdio.h>
#include<graphics.h>
#define max_dinh 20

//khai bao bien
int dinh[max_dinh][2];
int xgd[max_dinh];
int dx,dy,ymin,ymax;
float hesogoc[max_dinh];
int i,j,k,tam,sodinh;

//chuong trinh con
void nhapthongso()
{
	  printf("Nhap so dinh cua da giac: ");
	  scanf("%d",&sodinh);
	
	  //nhap lan luot toa do cho cac dinh cua da giac
	  for(i=0;i<sodinh;i++)
	  {
	     printf("X[%d]= ",i);	
	     scanf("%d",&dinh[i][0]);
	     printf("Y[%d]= ",i);	
	     scanf("%d",&dinh[i][1]);
	  }
	  
	  //gan toa do dinh cuoi cung tro lai dinh dau tien de tao thanh da giac khep kin
	  dinh[sodinh][0]=dinh[0][0];
	  dinh[sodinh][1]=dinh[0][1];
	  
	  //tinh toan he so goc: m=dy/dx nhung de thuan tien cho phep toan sau nay: m=dx/dy
	  for(i=0;i<sodinh;i++)
	  {
	  	   dx=dinh[i+1][0]-dinh[i][0];
	  	   dy=dinh[i+1][1]-dinh[i][1];
	  	   if(dx==0)
	  			 {
	  			 	  hesogoc[i]=0.0;
			    }
			    if(dy==0)
	  			 {
	  			 	  hesogoc[i]=1.0;
			    }
			    if(dx!=0 && dy!=0)
			    {
			    	  hesogoc[i]=(float)dx/dy;
							}
			}
			
			//tim gia tri lon nhat va nho nhat cua tung do
			ymin=dinh[0][1];
			ymax=dinh[0][1];
			
			for(i=1;i<sodinh;i++)
			{
			   if(ymin>dinh[i][1])
			   {
			   	  ymin=dinh[i][1];
						}
						if(ymax<dinh[i][1])
			   {
			   	  ymax=dinh[i][1];
						}
			}
			
			//in ra man hinh cac tham so hesogoc, ymin, ymax
			for(i=0;i<sodinh;i++)
			{
				  printf("%3f\t",hesogoc[i]);
			}
			printf("\ntung do be nhat: %d",ymin);
			printf("\ntung do lon nhat: %d",ymax);
}

//ve da giac
void vedagiac()
{
	  setcolor(GREEN);
		 for(i=0;i<sodinh;i++)
		 {
		 	  line(dinh[i][0],dinh[i][1],dinh[i+1][0],dinh[i+1][1]);
		 }	
}

//Thuat toan to mau do thi
void scanline()
{
	  int y;
	  
	  for(y=ymin;y<=ymax;y++)
	  {
	  	  k=0;
	  	  //kiem tra dong quet co cat qua canh nao do hay khong?
	  	  for(i=0;i<sodinh;i++)
	  	  {
	  	  	  if( ((dinh[i][1] <=y) && (dinh[i+1][1]>y))|| ((dinh[i][1] > y ) && (dinh[i+1][1]<=y)) )
	  	       {
	  	  	       xgd[k]=(int) (dinh[i][0] + hesogoc[i]*(y - dinh[i][1]));
	  	  	       k++;
						     }
						}
	  	  
						// sap xep toa do cac giao diem theo thu tu tang dan
						for(i=0;i<k-1;i++)
						{
							  for(j=i+1;j<k;j++)
							  {
							  	  if(xgd[i] > xgd[j])
							  	  {
							  	  	  tam=xgd[i];
							  	  	  xgd[i]=xgd[j];
							  	  	  xgd[j]=tam;
												}
									}
						}
						
						//in ra man hinh toa do cac giao diem
						printf("\ny = %d: ",y);
						for(i=0;i<k;i++)
						{
							  printf("%d\t",xgd[i]);
						}
						
						//ve duong thang noi toa do cac giao diem voi tung do la y
						setcolor(BLUE);
						for(i=0;i<k;i=i+2)
						{
						  line(xgd[i],y,xgd[i+1],y);
						}
						
			}
}

//chuong trinh chinh

int main()
{
	  nhapthongso();
	 
	  //ve da giac
	  initwindow(800,800); //khoi tao man hinh do hoa co kich thuoc 400 x 400 px
	  vedagiac();
	  
	  //to mau theo dong quet 
	  scanline();
	  
	  //doi bam phim Enter
	  getch();
}

//nhap 10 dinh:
//(75,250)	(210,250)	(250,128)	(291,250)	(425,250)
//(318,331)	(360,460)	(249,380)	(140,460)	(182,331)
