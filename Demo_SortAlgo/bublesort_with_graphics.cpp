#include<stdio.h>
#include<graphics.h>
#include <stdlib.h>
#define MAX 100
#define INPUT "points.inp"

void readfile();
void intoado(struct mt[MAX], int size);

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

void readfile(){
	fp=fopen(INPUT,"r");
	if(fp==NULL){
		printf("File not found");
		return;
	}
	fscanf(fp,"%d",&npoints);
	printf("So luong cac diem: %d",npoints);
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

void init(){
	for(int i=0; i<npoints; i++){
		
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

void sort(){
	for(int i=0; i<npoints; i++){
		for(int j=0; j<npoints; j++){
			if(i==j){
				flag=1;
			}
			else{
				flag=0;
			}
			pointcolor(td[j],flag);
		}
		for(int k=i+1; k<npoints; k++){
			if(td[i].value > td[k].value){
				int tam=td[i].value;
				td[i].value = td[k].value;
				td[k].value = tam;
			}
		}
		//sau khi ve dong 1 lan cho 10 diem thi ve lan 2
		delay(1000);
		cleardevice();
	}
}


int main(){
	//Doc noi dung file
	readfile();
	//in ra toa do cac diem
	intoado(td,npoints);
	//ve cac diem ra man hinh
	initwindow(600,400);
	veds(td,npoints);
	//sap xep
	sort();
	//ket thuc
	getch();
}
