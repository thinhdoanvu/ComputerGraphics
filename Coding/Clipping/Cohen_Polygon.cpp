#include<graphics.h>
#include<stdio.h>
#include<limits.h>
#define maxdinh 20//so dinh toi da cua da giac
#define INPUT "input.poly"

//khai bao prototype
void readfile();
int mahoa(int x, int y);
void cohen_sutherland();
void hesogoc();
void vedagiac();

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
	//them dinh cuoi trung voi dinh dau
	pt[sodinh].x = pt[0].x;
	pt[sodinh].y = pt[0].y;
	//tinh he so goc
	hesogoc();
	//dong tap tin da mo
	fclose(fp);
}

void hesogoc(){
	for(int i=0; i<sodinh; i++){
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
	for(int i=0; i<sodinh; i++){
		printf("%.2f\t",m[i]);
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

void cohen_sutherland(int dinh_t, int dinh_s){
	//int dem=0;
	printf("\nGiao diem tim duoc:\n");
	struct point res[2];
	//khong co giao diem
	if(pt[dinh_t].code !=0 && pt[dinh_s].code !=0){
		if((pt[dinh_t].code & pt[dinh_s].code)!=0){
			//khong co giao diem
			printf("\nKhong co giao diem voi cua so cat");
			return;
		}
	}
	//co it nhat 1 giao diem
	int dem=0;//luu giu so giao diem cua doan thang voi csc
	
		///////////////////////////
		//			dinh dau	//
		//////////////////////////
		if(pt[dinh_t].code == 0){//trong
			res[dem].x = pt[dinh_t].x;
			res[dem++].y = pt[dinh_t].y;
		}
		if(pt[dinh_t].code == 1){//trai
			res[dem].x = xmin;
			res[dem++].y = pt[dinh_t].y + (xmin - pt[dinh_t].x)*m[dinh_t];
		}
		if(pt[dinh_t].code == 2){//phai
			res[dem].x = xmax;
			res[dem++].y = pt[dinh_t].y + (xmax - pt[dinh_t].x)*m[dinh_t];
		}
		if(pt[dinh_t].code == 8){//tren
			res[dem].y = ymin;
			res[dem++].x = pt[dinh_t].x + (ymin - pt[dinh_t].y)/m[dinh_t];
		}
		if(pt[dinh_t].code == 4){//duoi
			res[dem].y = ymax;
			res[dem++].x = pt[dinh_t].x + (ymax - pt[dinh_t].y)/m[dinh_t];
		}
		if(pt[dinh_t].code == 9){//tren, trai
			//xet nhu la diem ben tren
			res[dem].y = ymin;
			res[dem].x = pt[dinh_t].x + (ymin - pt[dinh_t].y)/m[dinh_t];
			if(res[dem].x < xmin){
				//xet nhu la diem ben trai
				res[dem].x = xmin;
				res[dem].y = pt[dinh_t].y + (xmin - pt[dinh_t].x)*m[dinh_t];
			}
			dem++;
		}
		if(pt[dinh_t].code == 5){//duoi, trai
			//xet nhu la diem ben duoi
			res[dem].y = ymax;
			res[dem].x = pt[dinh_t].x + (ymax - pt[dinh_t].y)/m[dinh_t];
			if(res[dem].x < xmin){
				//xet nhu la diem ben trai
				res[dem].x = xmin;
				res[dem].y = pt[dinh_t].y + (xmin - pt[dinh_t].x)*m[dinh_t];
			}
			dem++;
		}
		if(pt[dinh_t].code == 6){//duoi, phai
			//xet nhu la diem ben duoi
			res[dem].y = ymax;
			res[dem].x = pt[dinh_t].x + (ymax - pt[dinh_t].y)/m[dinh_t];
			if(res[dem].x > xmax){
				//xet nhu la diem ben phai
				res[dem].x = xmax;
				res[dem].y = pt[dinh_t].y + (xmax - pt[dinh_t].x)*m[dinh_t];
			}
			dem++;
		}
		if(pt[dinh_t].code == 10){//tren, phai
			//xet nhu la diem ben tren
			res[dem].y = ymin;
			res[dem].x = pt[dinh_t].x + (ymin - pt[dinh_t].y)/m[dinh_t];
			if(res[dem].x > xmax){
				//xet nhu la diem ben phai
				res[dem].x = xmax;
				res[dem].y = pt[dinh_t].y + (xmax - pt[dinh_t].x)*m[dinh_t];
			}
			dem++;
		}
		///////////////////////////
		//			dinh cuoi	//
		//////////////////////////
		if(pt[dinh_s].code == 0){//trong
			res[dem].x = pt[dinh_s].x;
			res[dem++].y = pt[dinh_s].y;
		}
		if(pt[dinh_s].code == 2){//phai
			res[dem].x = xmax;
			res[dem++].y = pt[dinh_s].y + (xmax - pt[dinh_s].x)*m[dinh_t];
		}
		if(pt[dinh_s].code == 1){//trai
			res[dem].x = xmin;
			res[dem++].y = pt[dinh_s].y + (xmin - pt[dinh_s].x)*m[dinh_t];
		}
		if(pt[dinh_s].code == 4){//duoi
			res[dem].y = ymax;
			res[dem++].x = pt[dinh_s].x + (ymax - pt[dinh_s].y)/m[dinh_t];
		}
		if(pt[dinh_s].code == 8){//tren
			res[dem].y = ymin;
			res[dem++].x = pt[dinh_s].x + (ymin - pt[dinh_s].y)/m[dinh_t];
		}
		if(pt[dinh_s].code == 9){//tren, trai
			//xet nhu la diem ben tren
			res[dem].y = ymin;
			res[dem].x = pt[dinh_s].x + (ymin - pt[dinh_s].y)/m[dinh_t];
			if(res[dem].x < xmin){
				//xet nhu la diem ben trai
				res[dem].x = xmin;
				res[dem].y = pt[dinh_s].y + (xmin - pt[dinh_s].x)*m[dinh_t];
			}
			dem++;
		}
		if(pt[dinh_s].code == 5){//duoi, trai
			//xet nhu la diem ben duoi
			res[dem].y = ymax;
			res[dem].x = pt[dinh_s].x + (ymax - pt[dinh_s].y)/m[dinh_t];
			if(res[dem].x < xmin){
				//xet nhu la diem ben trai
				res[dem].x = xmin;
				res[dem].y = pt[dinh_s].y + (xmin - pt[dinh_s].x)*m[dinh_t];
			}
			dem++;
		}
		if(pt[dinh_s].code == 6){//duoi, phai
			//xet nhu la diem ben duoi
			res[dem].y = ymax;
			res[dem].x = pt[dinh_s].x + (ymax - pt[dinh_s].y)/m[dinh_t];
			if(res[dem].x > xmax){
				//xet nhu la diem ben phai
				res[dem].x = xmax;
				res[dem].y = pt[dinh_s].y + (xmax - pt[dinh_s].x)*m[dinh_t];
			}
			dem++;
		}
		if(pt[dinh_s].code == 10){//tren, phai
			//xet nhu la diem ben tren
			res[dem].y = ymin;
			res[dem].x = pt[dinh_s].x + (ymin - pt[dinh_s].y)/m[dinh_t];
			if(res[dem].x > xmax){
				//xet nhu la diem ben phai
				res[dem].x = xmax;
				res[dem].y = pt[dinh_s].y + (xmax - pt[dinh_s].x)*m[dinh_t];
			}
			dem++;
		}	
	//loai bo cac diem co toa do nam ngoai gioi han min max
	for(int i=0; i<dem; i++){
		if(res[i].x < xmin || res[i].x >xmax || res[i].y <ymin || res[i].y >ymax){
			return;
		}
	}
	//in ra man hinh giao diem cua doan thang voi csc
	for(int i=0; i<dem-1; i++){
		printf("(%d,%d) <-> (%d,%d)",res[i].x,res[i].y,res[i+1].x,res[i+1].y);
	}
	//ve doan thang noi 2 giao diem
	setlinestyle(1,1,2);
	setcolor(4);
	line(res[0].x, res[0].y,res[1].x,res[1].y);
}

void vedagiac(){
	setlinestyle(1,0,1);//net dut
	setcolor(15);//WHITE
	for(int i=0; i<sodinh; i++){
		line(pt[i].x, pt[i].y, pt[i+1].x, pt[i+1].y);
	}
}

int main(){
	readfile();
	//khoi tao man hinh do hoa
	initwindow(500,500);
	//ve cua so cat
	setcolor(15);//WHITE
	setlinestyle(1,1,2);
	rectangle(xmin,ymin,xmax,ymax);
	//ve da giac ban dau
	vedagiac();
	//tim giao diem cat canh voi cua so cat
	for(int i=0; i<sodinh; i++){
		cohen_sutherland(i,i+1);
	}
	
	getch();
	return 0;
}
