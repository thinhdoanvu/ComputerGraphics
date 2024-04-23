#include<graphics.h>
#include<stdio.h>
#include<limits.h>
#define maxdinh 20//so dinh toi da cua da giac
#define INPUT "input.in"


//khai bao prototype
void readfile();
int mahoa(int x, int y);
void cohen_sutherland();
void hesogoc();

//khai bao bien
int sodinh;//so dinh thuc te cua da giac

struct point{
	int x;
	int y;
	int code;
};

struct point pt[maxdinh];

FILE *fp;

int xmin = 200;
int xmax = 400;
int ymin = 200;
int ymax = 400;

float m[maxdinh];

//chuong trinh con

void readfile(){
	fp=fopen(INPUT,"r");
	if(fp==NULL){
		printf("File not found");
		return;
	}
	//doc noi dung cua tap tin
	fscanf(fp,"%d",&sodinh);
	printf("So dinh cua da giac: %d\n",sodinh);
	for(int i=0; i<sodinh; i++){
		fscanf(fp,"%d %d",&pt[i].x,&pt[i].y);
		//ma hoa dinh
		pt[i].code = mahoa(pt[i].x,pt[i].y);
	}
	
	//in ra cac dinh cua da giac
	printf("X\tY\tCODE\n");
	for(int i=0; i<sodinh; i++){
		printf("%d\t%d\t%d\n",pt[i].x,pt[i].y,pt[i].code);
	}
	//tinh he so goc
	hesogoc();
	//dong tap tin da mo
	fclose(fp);
}

void hesogoc(){
	for(int i=0; i<sodinh-1; i++){
		if(pt[i+1].y == pt[i].y){//dy==0
			m[i]=0;
			return;
		}
		if(pt[i+1].x == pt[i].x){//dx==0
			m[i]=INT_MAX;//+oo
		}
		else{//dx!=0 && dy!=0
			m[i]=(float)(pt[i+1].y - pt[i].y)/(pt[i+1].x - pt[i].x);
		}
	}
	//in ra he so goc cac canh
	printf("He so goc cac canh: \n");
	for(int i=0; i<sodinh-1; i++){
		printf("%.2f",m[i]);
	}
	printf("\n");
}

int mahoa(int x, int y){
	//diem nam giua
	if(x>=xmin && x<=xmax){
		if(y>=ymin && y<=ymax){
			return 0;
		}
		if(y<ymin){
			return 8;
		}
		if(y>ymax){
			return 4;
		}
	}
	//diem nam ben trai
	if(x<xmin){
		if(y>=ymin && y<=ymax){
			return 1;
		}
		if(y<ymin){
			return 9;
		}
		if(y>ymax){
			return 5;
		}
	}
	//diem nam ben phai
	if(x>xmax){
		if(y>=ymin && y<=ymax){
			return 2;
		}
		if(y<ymin){
			return 10;	
		}
		if(y>ymax){
			return 6;
		}
	}
}

void cohen_sutherland(){
	struct point res[2];
	//khong co giao diem
	if(pt[0].code !=0 && pt[1].code !=0){
		if((pt[0].code & pt[1].code)!=0){
			//khong co giao diem
			printf("\nKhong co giao diem voi cua so cat");
			return;
		}
	}
	//co it nhat 1 giao diem
	int dem=0;//luu giu so sao diem cua doan thang voi csc
	for(int i=0; i<2-1; i++){//1 doan thang co 2 dinh
		///////////////////////////
		//			dinh dau	//
		//////////////////////////
		if(pt[i].code == 0){//trong
			res[dem].x = pt[i].x;
			res[dem++].y = pt[i].y;
		}
		if(pt[i].code == 1){//trai
			res[dem].x = xmin;
			res[dem++].y = pt[i].y + (xmin - pt[i].x)*m[i];
		}
		if(pt[i].code == 2){//phai
			res[dem].x = xmax;
			res[dem++].y = pt[i].y + (xmax - pt[i].x)*m[i];
		}
		if(pt[i].code == 8){//tren
			res[dem].y = ymin;
			res[dem++].x = pt[i].x + (ymin - pt[i].y)/m[i];
		}
		if(pt[i].code == 4){//duoi
			res[dem].y = ymax;
			res[dem++].x = pt[i].x + (ymax - pt[i].y)/m[i];
		}
		if(pt[i].code == 9){//tren, trai
			//xet nhu la diem ben tren
			res[dem].y = ymin;
			res[dem].x = pt[i].x + (ymin - pt[i].y)/m[i];
			if(res[dem].x < xmin){
				//xet nhu la diem ben trai
				res[dem].x = xmin;
				res[dem].y = pt[i].y + (xmin - pt[i].x)*m[i];
			}
			dem++;
		}
		//code=5,6,10: tu xu
		
		///////////////////////////
		//			dinh cuoi	//
		//////////////////////////
		if(pt[i+1].code == 0){//trong
			res[dem].x = pt[i+1].x;
			res[dem++].y = pt[i+1].y;
		}
		if(pt[i+1].code == 2){//phai
			res[dem].x = xmax;
			res[dem++].y = pt[i+1].y + (xmax - pt[i+1].x)*m[i];
		}
		if(pt[i+1].code == 1){//trai
			res[dem].x = xmin;
			res[dem++].y = pt[i+1].y + (xmin - pt[i+1].x)*m[i];
		}
		if(pt[i+1].code == 4){//duoi
			res[dem].y = ymax;
			res[dem++].x = pt[i+1].x + (ymax - pt[i+1].y)/m[i];
		}
		if(pt[i+1].code == 8){//tren
			res[dem].y = ymin;
			res[dem++].x = pt[i+1].x + (ymin - pt[i+1].y)/m[i];
		}
		if(pt[i+1].code == 9){//tren, trai
			//xet nhu la diem ben tren
			res[dem].y = ymin;
			res[dem].x = pt[i+1].x + (ymin - pt[i+1].y)/m[i];
			if(res[dem].x < xmin){
				//xet nhu la diem ben trai
				res[dem].x = xmin;
				res[dem].y = pt[i+1].y + (xmin - pt[i+1].x)*m[i];
			}
			dem++;
		}
		//code=5,6,10: tu xu
	}
	//in ra man hinh giao diem cua doan thang voi csc
	printf("Giao diem tim duoc:\n");
	for(int i=0; i<dem-1; i++){
		printf("(%d,%d) <-> (%d,%d)",res[i].x,res[i].y,res[i+1].x,res[i+1].y);
	}
	//loai bo cac diem co toa do nam ngoai gioi han min max
	for(int i=0; i<dem; i++){
		if(res[i].x < xmin || res[i].x >xmax || res[i].y <ymin || res[i].y >ymax){
			return;
		}
	}
	//ve doan thang noi 2 giao diem
	setlinestyle(1,1,2);
	setcolor(4);
	line(res[0].x, res[0].y,res[1].x,res[1].y);
}

int main(){
	readfile();
	//khoi tao man hinh do hoa
	initwindow(500,500);
	//ve cua so cat
	setcolor(15);//WHITE
	setlinestyle(1,1,2);
	rectangle(xmin,ymin,xmax,ymax);
	//ve doan thang
	setlinestyle(1,0,1);//net dut
	setcolor(15);//WHITE
	for(int i=0; i<sodinh-1; i++){
		line(pt[i].x, pt[i].y, pt[i+1].x, pt[i+1].y);
	}
	cohen_sutherland();
	getch();
	return 0;
}
