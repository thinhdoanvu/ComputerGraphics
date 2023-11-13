#include<stdio.h>
#include<graphics.h>
#include <stdlib.h>
#define MAX 100
#define INPUT "points.inp"

void readfile();
void intoado(struct mt[MAX], int size);
void vegiaodien();
void veds(struct toado mt[MAX], int size);
void vegiaodien_run();
void keyboard();
void sort();

struct toado{
	int x;
	int y;
	int value;
};

struct toado td[MAX];
int npoints;
FILE* fp;
char buffer[10];
int flag;
int enable_mouse=1;
int is_run=0;

void mouse(){
    int maxx, maxy;
    int x_mouse, y_mouse;
     while (enable_mouse) {
        //su kien mouse click
        if (ismouseclick(WM_LBUTTONDOWN)) {
            //Vi tri cua x_mouse, y_mouse khi click
            getmouseclick(WM_LBUTTONDOWN, x_mouse, y_mouse);
            //in ra toa do cua mouse
            printf("\n(%d,%d)", x_mouse, y_mouse);
            
			//kiem tra nhan nut = Load file
            if(x_mouse >580 && x_mouse <680 && y_mouse>10 && y_mouse<50){
            	printf("\nDOC NOI DUNG CAC DIEM TU TAP TIN INPUT");
            	readfile();
            	//ve cac diem ra man hinh
				veds(td,npoints);
				//cho phep demo
				is_run=1;
			}
			
			//kiem tra nhan nut = Keyboard
            if(x_mouse >580 && x_mouse <680 && y_mouse>70 && y_mouse<110){
            	printf("\nNHAP CAC DIEM BANG BAN PHIM");
            	keyboard();
            	//ve cac diem ra man hinh
				veds(td,npoints);
				//cho phep demo
				is_run=1;
			}
			
			//kiem tra nhan nut = Demo
            if(is_run==1 && x_mouse >580 && x_mouse <680 && y_mouse>130 && y_mouse<170){
            	printf("\nRUNNING...");
            	sort();
			}
        }

        // Check for right mouse button click to exit the loop
        if (ismouseclick(WM_RBUTTONDOWN)) {
            getmouseclick(WM_RBUTTONDOWN, x_mouse, y_mouse);
            printf("\nRight mouse button clicked. Exiting...");
            break;
        }
        delay(100); // Delay to control the loop speed
    }
}

void keyboard(){
	printf("\nGIA TRI CUA 10 DINH NHU SAU: ");
	for(int i=0; i<npoints; i++){
		scanf("%d",&td[i].value);
	}
	printf("\nHOAN TAT VIEC NHAP DU LIEU");
}

void readfile(){
	fp=fopen(INPUT,"r");
	if(fp==NULL){
		printf("File not found");
		return;
	}
	fscanf(fp,"%d",&npoints);
	printf("\nSO LUONG CAC DIEM: %d",npoints);
	for(int i=0; i<npoints; i++){
		fscanf(fp,"%d %d %d",&td[i].x, &td[i].y,&td[i].value);
	}
	fclose(fp);
}

void intoado(struct toado mt[MAX], int size){
	printf("\ntoa do cac dinh: \n");
	for(int i=0; i<size; i++){
		printf("%d  %d %d\n",mt[i].x, mt[i].y, mt[i].value);
	}
}

void vediem(struct toado diem){
	setcolor(WHITE);
	//setlinestyle(int linestyle, unsigned upattern, int thickness);
	setlinestyle(0,1,2);
	//setfillstyle(int pattern, int color)
	//setfillstyle(1,14);
	circle(diem.x, diem.y, 20);
	//floodfill(int x, int y, int border_color)
	//floodfill(mt[i].x, mt[i].y,WHITE);
	//settextstyle(int font , int direction , int charsize);
	settextstyle(1,0,3);
	outtextxy(diem.x-9, diem.y-14,itoa(diem.value, buffer, 10));
}

void veds(struct toado mt[MAX], int size){
	for(int i=0; i<size; i++){
		vediem(mt[i]);
		delay(200);
	}
}

void pointcolor(struct toado diem, int flag){
	setcolor(WHITE);
	vegiaodien_run();
	if(flag==1){
		setcolor(RED);	
	}
	else{
		if(flag==2){
			setcolor(GREEN);	
		}
		else{
			setcolor(WHITE);
		}
	}
	circle(diem.x, diem.y, 20);
	settextstyle(1,0,3);
	outtextxy(diem.x-9, diem.y-14,itoa(diem.value, buffer, 10));
}

void sort2(){
	enable_mouse=0;//khong cho su dung chuot
	for(int i=0; i<npoints; i++){
		
		for(int k=i+1; k<npoints; k++){
			// in ra man hinh 2 so dang so sanh
			for(int j=0; j<npoints; j++){
				pointcolor(td[j],0);
			}
			pointcolor(td[i],1);
			pointcolor(td[k],1);
			int isSort = 0;
			
			if(td[i].value > td[k].value){
				isSort  = 1;
				for(int j=0; j<npoints; j++){
					pointcolor(td[j],0);
				}
				pointcolor(td[i],2);
				pointcolor(td[k],2);
				delay(1000);
				cleardevice();
				
				int tam=td[i].value;
				td[i].value = td[k].value;
				td[k].value = tam;	
				for(int j=0; j<npoints; j++){
					pointcolor(td[j],0);
				}
				pointcolor(td[i],2);
				pointcolor(td[k],2);
				delay(1000);
				cleardevice();
			}
		
			if (isSort == 0){
				delay(1000);
				cleardevice();
			}
		}
	}
}

void sort(){
	for(int i=0; i<npoints-1; i++){
		for(int k=i+1; k<npoints; k++){
			//ve ra man hinh: day so (color=WHITE)
			for(int j=0; j<npoints; j++){
				pointcolor(td[j],0);
			}
			//ve ra man hinh 2 so dang duoc so sanh: color=RED
			pointcolor(td[i],1);
			pointcolor(td[k],1);
			//doi cho 2 so tai vi tri i va k
			if(td[i].value > td[k].value){
				//ve lai 2 diem voi 2 mau color = GREEN
				for(int j=0; j<npoints; j++){
					pointcolor(td[i],2);
					pointcolor(td[k],2);
				}
				//doi cho 2 so
				int tam=td[i].value;
				td[i].value=td[k].value;
				td[k].value=tam;
				delay(200);
			}
			//xoa man hinh va ve lai 2 so moi i - k
			delay(300);
			cleardevice();
		}
	}
	//ve lai danh sach sau khi sap xep
	vegiaodien();
	veds(td,npoints);
}


void vegiaodien(){
	setcolor(WHITE);
	//ve khung lon
	setlinestyle(3,1,3);
	rectangle(10,10,550,370);
	//ve nut load file
	setlinestyle(1,0,2);
	rectangle(580,10,680,50);
	settextstyle(2,0,7);
	outtextxy(590,20,"Load file");
	//ve nut keyboard: y=y+60 (top,bot)
	setlinestyle(1,0,2);
	rectangle(580,70,680,110);
	settextstyle(2,0,7);
	outtextxy(590,80,"Keyboard");
	//ve nut run: y=y+60 (top,bot)
	setcolor(LIGHTGRAY);
	setlinestyle(1,0,2);
	rectangle(580,130,680,170);
	settextstyle(2,0,7);
	outtextxy(590,140,"Demo...");
	//aboutme: y=y+60 (top,bot)
	setcolor(GREEN);
	settextstyle(2,0,5);
	outtextxy(560,250,"Name: HacWindao");
	outtextxy(560,270,"M: thinhdv@ntu.edu.vn");
	outtextxy(560,290,"F: HacQuinDao");
	outtextxy(560,310,"Baldum Khanh Hoa");
}

void vegiaodien_run(){
	setcolor(WHITE);
	//ve khung lon
	setlinestyle(3,1,3);
	rectangle(10,10,550,370);
	//ve nut load file
	setcolor(LIGHTGRAY);
	setlinestyle(1,0,2);
	rectangle(580,10,680,50);
	settextstyle(2,0,7);
	outtextxy(590,20,"Load file");
	//ve nut keyboard: y=y+60 (top,bot)
	setlinestyle(1,0,2);
	rectangle(580,70,680,110);
	settextstyle(2,0,7);
	outtextxy(590,80,"Keyboard");
	//ve nut run: y=y+60 (top,bot)
	setcolor(RED);
	setlinestyle(1,0,2);
	rectangle(580,130,680,170);
	settextstyle(2,0,7);
	outtextxy(590,140,"Demo...");
	//aboutme: y=y+60 (top,bot)
	setcolor(GREEN);
	settextstyle(2,0,5);
	outtextxy(560,250,"Name: HacWindao");
	outtextxy(560,270,"M: thinhdv@ntu.edu.vn");
	outtextxy(560,290,"F: HacQuinDao");
	outtextxy(560,310,"Baldum Khanh Hoa");
}

int main(){
	//khoi tao man hinh do hoa
	initwindow(700,400);

	//ve giao dien
	vegiaodien();
	
	//goi ham chuot
	mouse();
	
	//ket thuc
	getch();
}
