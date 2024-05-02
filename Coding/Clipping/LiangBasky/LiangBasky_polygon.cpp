#include<graphics.h>
#include<stdio.h>
#define INPUT "input.line"
#define MAXDINH	20
//khai bao prototype
void readfile();
void Liangbasky();

//khai bao bien
FILE *fp;
int sodinh;

struct point{
	int x;
	int y;
};

struct point pt[MAXDINH];

int p[4];
int q[4];

int xmin = 200;
int xmax = 400;
int ymin = 200;
int ymax = 400;
int dx;
int dy;

//chuong trinh con
void readfile(){
	fp=fopen(INPUT,"r");
	if(fp==NULL){
		printf("File not found");
		return;
	}
	//doc dong dau tien cua tap tin
	fscanf(fp,"%d",&sodinh);
	printf("So dinh cua da giac: %d",sodinh);
	//doc toa do cac dinh cua da giac
	for(int i=0; i<sodinh; i++){
		fscanf(fp,"%d %d",&pt[i].x, &pt[i].y);
	}
	//gan dinh cuoi bang dinh dau
	pt[sodinh].x = pt[0].x;
	pt[sodinh].y = pt[0].y;
	sodinh++;
	//in ra toa do cac dinh cua da giac
	for(int i=0; i<sodinh; i++){
		printf("\n%d\t%d",pt[i].x, pt[i].y);
	}
	
	fclose(fp);
}

float  max(float a, float b){
	return (a>b)?a:b;
}

float  min(float a, float b){
	return (a<b)?a:b;
}

void Liangbasky(struct point p1, struct point p2){
	//tinh gia tri cho p
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	p[0] = -dx;
	p[1] = dx;
	p[2] = -dy;
	p[3] = dy;
	//in ra man hinh mang p
	printf("\nP[]: ");
	for(int i=0; i<4; i++){
		printf("\t%d",p[i]);
	}
	//tinh gia tri cho q
	q[0]=p1.x - xmin;
	q[1]=xmax - p1.x;
	q[2]=p1.y - ymin;
	q[3]=ymax - p1.y;
	//in ra man hinh mang q
	printf("\nQ[]: ");
	for(int i=0; i<4; i++){
		printf("\t%d",q[i]);
	}
	//Tim giao diem
	struct point res[2];
	
	float t1=0.0, t2=1.0;
	//tim giao diem 1:
	for(int i=0; i<4; i++){
		if(p[i]<0){
			t1=max(t1,(float)q[i]/p[i]);
		}
	}
	printf("\nt1 = %.3f",t1);
	res[0].x = p1.x + t1*dx;
	res[0].y = p1.y + t1*dy;
	
	//tim giao diem 2:
	for(int i=0; i<4; i++){
		if(p[i]>=0){
			t2=min(t2,(float)q[i]/p[i]);
		}
	}
	printf("\nt2 = %.3f",t2);
	res[1].x = p1.x + t2*dx;
	res[1].y = p1.y + t2*dy;
	//in ra man hinh giao diem tim duoc
	printf("\nToa do cac giao diem: ");
	for(int i=0; i<2-1; i++){
		printf("(%d, %d) - (%d,%d)",res[0].x, res[0].y, res[1].x, res[1].y);
	}
	
	//ve doan thang noi 2 giao diem
	setlinestyle(1,1,2);
	setcolor(4);
	//them dieu kien loai tru giao diem nam ben ngoai cua so cat
	for(int i=0; i<2-1; i++){
		if(res[i].x >=xmin && res[i].x <=xmax && res[i].y >=ymin && res[i].y <= ymax){
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
	setcolor(15);
	rectangle(xmin, ymin, xmax, ymax);
	//ve doan thang
	setcolor(2);
	setlinestyle(1,0,1);
	for(int i=0; i<sodinh-1; i++){
		line(pt[i].x, pt[i].y, pt[i+1].x, pt[i+1].y);
	}
	//xen tia da giac
	for(int i=0; i<sodinh-1; i++){
		Liangbasky(pt[i], pt[i+1]);
	}
	
	getch();
	return 0;
}
