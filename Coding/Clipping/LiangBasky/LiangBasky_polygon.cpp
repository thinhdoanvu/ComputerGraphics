#include<graphics.h>
#include<stdio.h>
#define INPUT "input.poly"//doan thang
#define MAXDINH 20//da giac toi da 20 dinh

//khai bao prototype
void readfile();

//khai bao bien
FILE *fp;
int sodinh;//so dinh thuc te cua da giac
struct point{
	int x;
	int y;
};

struct point pt[100];

int xmin = 200;
int xmax = 400;
int ymin = 200;
int ymax = 400;

//chuong trinh con
void readfile(){
	fp=fopen(INPUT,"r");
	if(fp==NULL){
		printf("File not found");
		return;
	}
	//do so luong cac dinh cua da giac
	fscanf(fp,"%d",&sodinh);
	printf("So dinh: %d",sodinh);
	//doc toa do cac dinh cua da giac
	for(int i=0; i<sodinh; i++){
	 	fscanf(fp,"%d %d",&pt[i].x,&pt[i].y);
	}
	//gan dinh cuoi = dinh dau
	pt[sodinh].x = pt[0].x;
	pt[sodinh].y = pt[0].y;
	
	//in ra toa do cac dinh
	printf("\nToa do cac dinh: ");
	for(int i=0; i<sodinh; i++){
		 printf("(%d,%d)  ",pt[i].x, pt[i].y);
	}
	fclose(fp);
}

float max(float a, float b){
	return (a>b)?a:b;
}

float min(float a, float b){
	return (a<b)?a:b;
}

void LiangBasky(struct point A, struct point B){
	int dx = B.x - A.x;
	int dy = B.y - A.y;
	int p[4]= {-dx, dx, -dy, dy};
	int q[4]= {A.x - xmin, xmax - A.x, A.y - ymin, ymax - A.y};
	//in ra man hinh gia tri cua mang p
	printf("\np[] = ");
	for(int i=0; i<4; i++){
		printf("%d  ",p[i]);
	}
	//in ra man hinh gia tri cua mang q
	printf("\nq[] = ");
	for(int i=0; i<4; i++){
		printf("%d  ",q[i]);
	}
	//giai bat pt t.pk <= qk
	float t1=0.0;
	float t2=1.0;
	
	for(int i=0; i<4; i++){
		if(p[i]<0){//pk<0
			t1=max(t1,(float)q[i]/p[i]);
		}
		if(p[i]>0){//pk>=0
			t2=min(t2,(float)q[i]/p[i]);
		}
	}
	//in ra t1, t2
	printf("\nt1 = %.3f, t2 = %.3f",t1,t2);
	//the vao phuong trinh xsau (ysau) = xtruoc(y truoc) + t1*dx (dy) hoac xsau = xtruoc + t2*dx
	struct point res[2];//co giao diem
	res[0].x = A.x + t1*dx; res[0].y = A.y + t1*dy;
	res[1].x = A.x + t2*dx; res[1].y = A.y + t2*dy;
	//in ra man hinh toa do cac giao diem
	printf("\nToa do cac giao diem: ");
	for(int i=0; i<2; i++){
		printf("(%d, %d) - ",res[i].x, res[i].y);
	}
	//ve doan thang noi 2 giao diem, sau khi loai tru cac diem ngoai cua so cat
	setlinestyle(1,1,2);
	setcolor(4);
	for(int i=0; i<1; i++){
		if(res[i].x >= xmin && res[i].x <= xmax && res[i].y >= ymin && res[i].y <= ymax){
			line(res[i].x, res[i].y, res[i+1].x, res[i+1].y);
		}
	}
	
}
//chuong trinh chinh
int main(){
	readfile();
	initwindow(600,600);
	//ve cua so cat
	setlinestyle(1,1,2);
	setcolor(2);
	rectangle(xmin, ymin, xmax, ymax);
	//ve da giac
	setlinestyle(1,0,1);
	setcolor(15);
	for(int i=0; i<sodinh; i++){
		line(pt[i].x, pt[i].y, pt[i+1].x, pt[i+1].y);
	}
	//xen tia da giac
	for(int i=0; i<sodinh; i++){
		LiangBasky(pt[i], pt[i+1]);
	}
	getch();
}
