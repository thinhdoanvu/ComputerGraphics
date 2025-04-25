![image](https://github.com/user-attachments/assets/e14c9ac6-d050-4441-a382-5582d290d3ac)

## Tọa độ:
```
2
400 320
200 200
//duoi-phai,trong
20 380
250 250
//duoi,trai-trong
380 20
250 250
//tren,phai-trong
20 50
250 250
//tren,trai - trong
20 120
250 10
//tren-trai
250 10
20 120
//trai-tren: khong co giao diem
200 200
350 250
//trong-phai
200 200
50 280
//trong-trai
200 200
200 380
//trong-duoi
150 150
150 50
//trong-tren
150 150	
250 250
//trong-trong
50 350  
350 350 
//ngoai-ngoai
```

## CODE
```
#include<stdio.h>
#include<graphics.h>
#include<limits.h>
#define xmin 100
#define xmax 300
#define ymin 100
#define ymax 300
#define INPUT "cohen.txt"
//#define INPUT "cohen-dagiac.txt"
#define MAX 10 //so dinh toi da
//khai bao prototype
void nhap();
void vedt();
void mahoa();
void vecsc();

//khai bao bien
FILE *fp; //con tro tap tin
int sodinh;//so dinh cua da giac
struct dinh{
	int x;
	int y;
	int code;
};

struct dinh dt[MAX];
float hsg[MAX];

void vecsc(){
	setcolor(15); // white
	setlinestyle(0,1,1); // dash
	rectangle(xmin,ymin,xmax,ymax);
}

void nhap(){
	fp=fopen(INPUT,"r");
	if(fp==NULL){
		printf("File not found");
		return;
	} 
	fscanf(fp,"%d",&sodinh);
	for(int i=0; i<sodinh; i++){
		fscanf(fp,"%d %d",&dt[i].x,&dt[i].y);
	}
	
	
	//ma hoa cac dinh
	mahoa();
	//in ra toa do cac dinh
	printf("Toa do cac dinh: \n");
	for(int i=0; i<sodinh; i++){
		printf("(x: %d, y: %d, code: %d)\n",dt[i].x,dt[i].y,dt[i].code);
	}
	//tim he so goc
	for(int i=0; i<sodinh-1; i++){
		if(dt[i+1].x == dt[i].x){//dx==0
			hsg[i] = INT_MAX;
		}
		else{
			hsg[i]=(float)(dt[i+1].y - dt[i].y)/(float)(dt[i+1].x - dt[i].x);
		}
	}
	fclose(fp);
}

void vedt(){
	setcolor(4);
	setlinestyle(0,1,1);
	for(int i=0; i<sodinh-1;i++){
		line(dt[i].x, dt[i].y, dt[i+1].x, dt[i+1].y);
	}
}

void mahoa(){
	for(int i=0; i<sodinh; i++){
		//ABRL=0000 (0)
		if(dt[i].x >= xmin && dt[i].x <= xmax && dt[i].y >= ymin && dt[i].y <= ymax){
			dt[i].code = 0;
		}
		//ABRL=1000 (8)
		if(dt[i].x >= xmin && dt[i].x <= xmax && dt[i].y < ymin && dt[i].y < ymax){
			dt[i].code = 8;
		}
		//ABRL=0100 (4)
		if(dt[i].x >= xmin && dt[i].x <= xmax && dt[i].y > ymin && dt[i].y > ymax){
			dt[i].code = 4;
		}
		//ABRL=0001 (1)
		if(dt[i].x < xmin && dt[i].x < xmax && dt[i].y >= ymin && dt[i].y <= ymax){
			dt[i].code = 1;
		}
		//ABRL=0010 (2)
		if(dt[i].x > xmin && dt[i].x > xmax && dt[i].y >= ymin && dt[i].y <= ymax){
			dt[i].code = 2;
		}
		//ABRL=1001 (9)
		if(dt[i].x < xmin && dt[i].x < xmax && dt[i].y < ymin && dt[i].y < ymax){
			dt[i].code = 9;
		}
		//ABRL=1010 (10)
		if(dt[i].x > xmin && dt[i].x > xmax && dt[i].y < ymin && dt[i].y < ymax){
			dt[i].code = 10;
		}
		//ABRL=0101 (5)
		if(dt[i].x < xmin && dt[i].x < xmax && dt[i].y > ymin && dt[i].y > ymax){
			dt[i].code = 5;
		}
		//ABRL=0110 (6)
		if(dt[i].x > xmin && dt[i].x > xmax && dt[i].y > ymin && dt[i].y > ymax){
			dt[i].code = 6;
		}
	}
}

void xentia(){
	struct dinh gd[MAX]; //toa doa giao diem
	int dem=0; //so giao diem
	//tim giao diem
	for(int i=0; i<sodinh-1; i++){
		
		
		//2 dinh nam ngoai cua so cat
		if((dt[i].code & dt[i+1].code)!=0){
			printf("Doan thang nam ngoai cua so cat");
		}
		else{//2 dinh bi cat(nam trong, ngoai-trong, ngoai-ngoai)
			//==============xet dinh thu nhat==============//
			if(dt[i].code == 0){//dinh nam ben trong
				gd[dem].x = dt[i].x;
				gd[dem].y = dt[i].y;
			}
			if(dt[i].code == 8){//dinh nam ben tren
				gd[dem].x = dt[i].x + (ymin - dt[i].y)/hsg[i];
				gd[dem].y = ymin;
			}
			if(dt[i].code == 4){//dinh nam ben duoi
				gd[dem].x = dt[i].x + (ymax - dt[i].y)/hsg[i];
				gd[dem].y = ymax;
			}
			if(dt[i].code == 1){//dinh nam ben trai
				gd[dem].x = xmin;
				gd[dem].y = dt[i].y + (xmin - dt[i].x)*hsg[i];
			}
			if(dt[i].code == 2){//dinh nam ben phai
				gd[dem].x = xmax;
				gd[dem].y = dt[i].y + (xmax - dt[i].x)*hsg[i];
			}
			if(dt[i].code == 9){//dinh nam tren - trai: 1001
				//coi nhu bit A = 1, bit L ko quan tam
				gd[dem].x = dt[i].x + (ymin - dt[i].y)/hsg[i];
				gd[dem].y = ymin;
				if(gd[dem].x < xmin){//gd tim duoc khong thoa man
					//coi nhu bit L=1, khong quan tam bit A
					gd[dem].x = xmin;
					gd[dem].y = dt[i].y + (xmin - dt[i].x)*hsg[i];
				}
			}
			if(dt[i].code == 10){//dinh nam tren - phai: 1010
				//coi nhu bit A = 1, bit R ko quan tam
				gd[dem].x = dt[i].x + (ymin - dt[i].y)/hsg[i];
				gd[dem].y = ymin;
				if(gd[dem].x > xmax){//gd tim duoc khong thoa man
					//coi nhu bit R=1, khong quan tam bit A
					gd[dem].x = xmax;
					gd[dem].y = dt[i].y + (xmax - dt[i].x)*hsg[i];
				}
			}
			if(dt[i].code == 5){//dinh nam duoi - trai: 0101
				//coi nhu bit B = 1, bit L ko quan tam
				gd[dem].x = dt[i].x + (ymax - dt[i].y)/hsg[i];
				gd[dem].y = ymax;
				if(gd[dem].x < xmin){//gd tim duoc khong thoa man
					//coi nhu bit L=1, khong quan tam bit B
					gd[dem].x = xmin;
					gd[dem].y = dt[i].y + (xmin - dt[i].x)*hsg[i];
				}
			}
			if(dt[i].code == 6){//dinh nam duoi - phai: 0110
				//coi nhu bit B = 1, bit R ko quan tam
				gd[dem].x = dt[i].x + (ymax - dt[i].y)/hsg[i];
				gd[dem].y = ymax;
				if(gd[dem].x > xmax){//gd tim duoc khong thoa man
					//coi nhu bit R=1, khong quan tam bit B
					gd[dem].x = xmax;
					gd[dem].y = dt[i].y + (xmax - dt[i].x)*hsg[i];
				}
			}
			//==============xet dinh thu hai==============//
			dem++;
			if(dt[i+1].code == 0){//dinh nam ben trong
				gd[dem].x = dt[i+1].x;
				gd[dem].y = dt[i+1].y;
			}
			if(dt[i+1].code == 8){//dinh nam ben tren
				gd[dem].x = dt[i+1].x + (ymin - dt[i+1].y)/hsg[i];
				gd[dem].y = ymin;
			}
			if(dt[i+1].code == 4){//dinh nam ben duoi
				gd[dem].x = dt[i+1].x + (ymax - dt[i+1].y)/hsg[i];
				gd[dem].y = ymax;
			}
			if(dt[i+1].code == 1){//dinh nam ben trai
				gd[dem].x = xmin;
				gd[dem].y = dt[i+1].y + (xmin - dt[i+1].x)*hsg[i];
			}
			if(dt[i+1].code == 2){//dinh nam ben phai
				gd[dem].x = xmax;
				gd[dem].y = dt[i+1].y + (xmax - dt[i+1].x)*hsg[i];
			}
			if(dt[i+1].code == 9){//dinh nam tren - trai: 1001
				//coi nhu bit A = 1, bit L ko quan tam
				gd[dem].x = dt[i+1].x + (ymin - dt[i+1].y)/hsg[i];
				gd[dem].y = ymin;
				if(gd[dem].x < xmin){//gd tim duoc khong thoa man
					//coi nhu bit L=1, khong quan tam bit A
					gd[dem].x = xmin;
					gd[dem].y = dt[i+1].y + (xmin - dt[i+1].x)*hsg[i];
				}
			}
			if(dt[i+1].code == 10){//dinh nam tren - phai: 1010
				//coi nhu bit A = 1, bit R ko quan tam
				gd[dem].x = dt[i+1].x + (ymin - dt[i+1].y)/hsg[i];
				gd[dem].y = ymin;
				if(gd[dem].x > xmax){//gd tim duoc khong thoa man
					//coi nhu bit R=1, khong quan tam bit A
					gd[dem].x = xmax;
					gd[dem].y = dt[i+1].y + (xmax - dt[i+1].x)*hsg[i];
				}
			}
			if(dt[i+1].code == 5){//dinh nam duoi - trai: 0101
				//coi nhu bit B = 1, bit L ko quan tam
				gd[dem].x = dt[i+1].x + (ymax - dt[i+1].y)/hsg[i];
				gd[dem].y = ymax;
				if(gd[dem].x < xmin){//gd tim duoc khong thoa man
					//coi nhu bit L=1, khong quan tam bit B
					gd[dem].x = xmin;
					gd[dem].y = dt[i+1].y + (xmin - dt[i+1].x)*hsg[i];
				}
			}
			if(dt[i+1].code == 6){//dinh nam duoi - phai: 0110
				//coi nhu bit B = 1, bit R ko quan tam
				gd[dem].x = dt[i+1].x + (ymax - dt[i+1].y)/hsg[i];
				gd[dem].y = ymax;
				if(gd[dem].x > xmax){//gd tim duoc khong thoa man
					//coi nhu bit R=1, khong quan tam bit B
					gd[dem].x = xmax;
					gd[dem].y = dt[i+1].y + (xmax - dt[i+1].x)*hsg[i];
				}
			}
			dem++;
		}
	}
	//in ra toa do giao diem
	printf("Toa do giao diem: ");
	for(int i=0; i<dem; i++){
		printf("(%d,%d) ",gd[i].x, gd[i].y);
	}
	//ve doan thang noi cac giao diem
	setcolor(5);
	setlinestyle(1,1,2);
	for(int i=0; i<dem-1; i++){
		if(gd[i].x < xmin || gd[i].y < ymin || gd[i].x > xmax || gd[i].y > ymax){//giao diem nam ngoai cua so cat
			//khong ve doan thang
		}
		else{//ve doan thang noi cac giao diem
			line(gd[i].x, gd[i].y, gd[i+1].x, gd[i+1].y);
		}
	}
}


int main(){
	nhap();
	initwindow(400,400);
	vecsc(); // cua so cat
	vedt();
	xentia();
	getch();
}
```
