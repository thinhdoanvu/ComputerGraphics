//khai bao thu vien
#include<stdio.h>
#include<graphics.h>

//khai bao bien


//chuong trinh con
void khoitao()
{
  int gd=DETECT;
  int gm;
  initgraph(&gd,&gm,NULL);
}

void ketthuc()
{
  int in;
  in=0;
  while(in==0)
  {
    in=getchar();
  }
  closegraph();
}

void yourfunction()
{

  //input 

  khoitao();

  //processing
}


//chuong trinh chinh
int main()
{
  yourfunction();
  ketthuc();
  delay(1000);
  return 0;
}



//gcc template.c -o outputname -lgraph

