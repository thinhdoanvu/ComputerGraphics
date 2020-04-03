//khai bao thu vien
#include<stdio.h>
#include<graphics.h>
#include<string.h>

//khai bao bien
char chuoi[255];
int i,j;
int xc, yc;

int C_A[8][8]=
{
			{0,0,0,1,0,0,0,0},
			{0,0,1,0,1,0,0,0},
			{0,1,0,0,0,1,0,0},
			{1,0,0,0,0,0,1,0},
			{1,1,1,1,1,1,1,0},
			{1,0,0,0,0,0,1,0},
			{1,0,0,0,0,0,1,0}
};

int C_B[8][8]=
{
			{1,1,1,1,1,1,0,0},
   {1,0,0,0,0,0,1,0},
			{1,0,0,0,0,0,1,0},
			{1,1,1,1,1,1,0,0},
			{1,0,0,0,0,0,1,0},
			{1,0,0,0,0,0,1,0},
			{1,1,1,1,1,1,0,0}
};

int C_C[8][8]=
{
			{0,1,1,1,1,1,0,0},
			{1,0,0,0,0,0,1,0},
			{1,0,0,0,0,0,0,0},
			{1,0,0,0,0,0,0,0},
			{1,0,0,0,0,0,0,0},
			{1,0,0,0,0,0,1,0},
			{0,1,1,1,1,1,0,0}
};

int C_D[8][8]=
{
			{1,1,1,1,1,1,0,0},
			{1,0,0,0,0,0,1,0},
			{1,0,0,0,0,0,1,0},
			{1,0,0,0,0,0,1,0},
			{1,0,0,0,0,0,1,0},
			{1,0,0,0,0,0,1,0},
			{1,1,1,1,1,1,0,0}
};

int C_E[8][8]=
{
			{1,1,1,1,1,1,1,0},
			{1,0,0,0,0,0,0,0},
			{1,0,0,0,0,0,0,0},
			{1,1,1,1,1,0,0,0},
			{1,0,0,0,0,0,0,0},
			{1,0,0,0,0,0,0,0},
			{1,1,1,1,1,1,1,0}
};

int C_F[8][8]=
{
			{1,1,1,1,1,1,1,0},
			{1,0,0,0,0,0,0,0},
			{1,0,0,0,0,0,0,0},
			{1,1,1,1,1,0,0,0},
			{1,0,0,0,0,0,0,0},
			{1,0,0,0,0,0,0,0},
			{1,0,0,0,0,0,0,0}
};

int C_G[8][8]=
{
			{0,1,1,1,1,1,0,0},
			{1,0,0,0,0,0,1,0},
			{1,0,0,0,0,0,0,0},
			{1,0,0,1,1,1,1,0},
			{1,0,0,0,0,0,1,0},
			{1,0,0,0,0,0,1,0},
			{0,1,1,1,1,1,0,0}
};

int C_H[8][8]=
{
			{1,0,0,0,0,0,1,0},
			{1,0,0,0,0,0,1,0},
			{1,0,0,0,0,0,1,0},
			{1,1,1,1,1,1,1,0},
			{1,0,0,0,0,0,1,0},
			{1,0,0,0,0,0,1,0},
			{1,0,0,0,0,0,1,0}
};


int C_I[8][8]=
{
			{1,1,1,0,0,0,0,0},
			{0,1,0,0,0,0,0,0},
			{0,1,0,0,0,0,0,0},
			{0,1,0,0,0,0,0,0},
			{0,1,0,0,0,0,0,0},
			{0,1,0,0,0,0,0,0},
			{1,1,1,0,0,0,0,0}
};

int C_J[8][8]=
{
			{0,0,0,0,0,0,1,0},
			{0,0,0,0,0,0,1,0},
			{0,0,0,0,0,0,1,0},
			{0,0,0,0,0,0,1,0},
			{1,0,0,0,0,0,1,0},
			{1,0,0,0,0,0,1,0},
			{0,1,1,1,1,1,0,0}
};

int C_K[8][8]=
{
			{0,0,0,0,0,0,0,0},
			{1,0,0,0,0,1,0,0},
			{1,0,0,0,1,0,0,0},
			{1,0,0,1,0,0,0,0},
			{1,1,1,0,0,0,0,0},
			{1,0,0,1,0,0,0,0},
			{1,0,0,0,1,0,0,0},
			{1,0,0,0,0,1,0,0}
};

int C_L[8][8]=
{
			{1,0,0,0,0,0,0,0},
			{1,0,0,0,0,0,0,0},
			{1,0,0,0,0,0,0,0},
			{1,0,0,0,0,0,0,0},
			{1,0,0,0,0,0,0,0},
			{1,0,0,0,0,0,0,0},
			{1,1,1,1,1,1,1,0}
};

int C_M[8][8]=
{
			{1,0,0,0,0,0,1,0},
			{1,1,0,0,0,1,1,0},
			{1,0,1,0,1,0,1,0},
			{1,0,0,1,0,0,1,0},
			{1,0,0,0,0,0,1,0},
			{1,0,0,0,0,0,1,0},
			{1,0,0,0,0,0,1,0}
};

int C_N[8][8]=
{
			{1,0,0,0,0,0,1,0},
			{1,1,0,0,0,0,1,0},
			{1,0,1,0,0,0,1,0},
			{1,0,0,1,0,0,1,0},
			{1,0,0,0,1,0,1,0},
			{1,0,0,0,0,1,1,0},
			{1,0,0,0,0,0,1,0}
};

int C_O[8][8]=
{
			{1,1,1,1,1,1,1,0},
			{1,0,0,0,0,0,1,0},
			{1,0,0,0,0,0,1,0},
			{1,0,0,0,0,0,1,0},
			{1,0,0,0,0,0,1,0},
			{1,0,0,0,0,0,1,0},
			{1,1,1,1,1,1,1,0}
};

int C_P[8][8]=
{
			{1,1,1,1,1,1,0,0},
			{1,0,0,0,0,0,1,0},
			{1,0,0,0,0,0,1,0},
			{1,1,1,1,1,1,0,0},
			{1,0,0,0,0,0,0,0},
			{1,0,0,0,0,0,0,0},
			{1,0,0,0,0,0,0,0}
};

int C_Q[8][8]=
{
			{0,1,1,1,1,1,0,0},
			{1,0,0,0,0,0,1,0},
			{1,0,0,0,0,0,1,0},
			{1,0,0,0,0,0,1,0},
			{1,0,0,0,1,0,1,0},
			{1,0,0,0,0,1,0,0},
			{0,1,1,1,1,0,1,0}
};

int C_R[8][8]=
{
			{1,1,1,1,1,1,0,0},
			{1,0,0,0,0,0,1,0},
			{1,0,0,0,0,0,1,0},
			{1,1,1,1,1,1,0,0},
			{1,0,0,0,1,0,0,0},
			{1,0,0,0,0,1,0,0},
			{1,0,0,0,0,0,1,0}
};

int C_S[8][8]=
{
			{0,1,1,1,1,1,0,0},
			{1,0,0,0,0,0,1,0},
			{1,0,0,0,0,0,0,0},
			{0,1,1,1,1,1,0,0},
			{0,0,0,0,0,0,1,0},
			{1,0,0,0,0,0,1,0},
			{0,1,1,1,1,1,0,0}
};

int C_T[8][8]=
{
			{1,1,1,1,1,1,1,0},
			{0,0,0,1,0,0,0,0},
			{0,0,0,1,0,0,0,0},
			{0,0,0,1,0,0,0,0},
			{0,0,0,1,0,0,0,0},
			{0,0,0,1,0,0,0,0},
			{0,0,0,1,0,0,0,0}
};

int C_U[8][8]=
{
			{1,0,0,0,0,0,1,0},
			{1,0,0,0,0,0,1,0},
			{1,0,0,0,0,0,1,0},
			{1,0,0,0,0,0,1,0},
			{1,0,0,0,0,0,1,0},
			{1,0,0,0,0,0,1,0},
			{0,1,1,1,1,1,0,0},
};

int C_V[8][8]=
{
			{1,0,0,0,0,0,1,0},
			{1,0,0,0,0,0,1,0},
			{1,0,0,0,0,0,1,0},
			{1,0,0,0,0,0,1,0},
			{0,1,0,0,0,1,0,0},
			{0,0,1,0,1,0,0,0},
			{0,0,0,1,0,0,0,0}
};

int C_W[8][8]=
{
			{1,0,0,0,0,0,1,0},
			{1,0,0,1,0,0,1,0},
			{1,0,0,1,0,0,1,0},
			{1,0,0,1,0,0,1,0},
			{1,0,0,1,0,0,1,0},
			{1,0,0,1,0,0,1,0},
			{0,1,1,0,1,1,0,0}
};

int C_X[8][8]=
{
			{1,0,0,0,0,0,1,0},
			{0,1,0,0,0,1,0,0},
			{0,0,1,0,1,0,0,0},
			{0,0,0,1,0,0,0,0},
			{0,0,1,0,1,0,0,0},
			{0,1,0,0,0,1,0,0},
			{1,0,0,0,0,0,1,0}
};

int C_Y[8][8]=
{
			{1,0,0,0,0,0,1,0},
			{0,1,0,0,0,1,0,0},
			{0,0,1,0,1,0,0,0},
			{0,0,0,1,0,0,0,0},
			{0,0,0,1,0,0,0,0},
			{0,0,0,1,0,0,0,0},
			{0,0,0,1,0,0,0,0}
};

int C_Z[8][8]=
{
			{1,1,1,1,1,1,1,0},
			{0,0,0,0,0,1,0,0},
			{0,0,0,0,1,0,0,0},
			{0,0,0,1,0,0,0,0},
			{0,0,1,0,0,0,0,0},
			{0,1,0,0,0,0,0,0},
			{1,1,1,1,1,1,1,0}
};

int C_Space[8][8]=
{
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0}
};


//hien thi cac ky tu
void character_A(int xa, int ya)
{
	  //hien thi ky tu A
			for(i=0;i<7;i++)
			{
						for(j=0;j<7;j++)
						{
									if(C_A[i][j]==1)
									{
												putpixel(xa+j,ya+i,WHITE);
									}
						}
				}
}

void character_B(int xa, int ya)
{
	  //hien thi ky tu B
			for(i=0;i<7;i++)
			{
						for(j=0;j<7;j++)
						{
									if(C_B[i][j]==1)
									{
												putpixel(xa+j,ya+i,WHITE);
									}
						}
				}
}

void character_C(int xa, int ya)
{
	  //hien thi ky tu C
			for(i=0;i<7;i++)
			{
						for(j=0;j<7;j++)
						{
									if(C_C[i][j]==1)
									{
												putpixel(xa+j,ya+i,WHITE);
									}
						}
				}
}

void character_D(int xa, int ya)
{
	  //hien thi ky tu D
			for(i=0;i<7;i++)
			{
						for(j=0;j<7;j++)
						{
									if(C_D[i][j]==1)
									{
												putpixel(xa+j,ya+i,WHITE);
									}
						}
				}
}

void character_E(int xa, int ya)
{
	  //hien thi ky tu E
			for(i=0;i<7;i++)
			{
						for(j=0;j<7;j++)
						{
									if(C_E[i][j]==1)
									{
												putpixel(xa+j,ya+i,WHITE);
									}
						}
				}
}

void character_F(int xa, int ya)
{
	  //hien thi ky tu F
			for(i=0;i<7;i++)
			{
						for(j=0;j<7;j++)
						{
									if(C_F[i][j]==1)
									{
												putpixel(xa+j,ya+i,WHITE);
									}
						}
				}
}

void character_G(int xa, int ya)
{
	  //hien thi ky tu G
			for(i=0;i<7;i++)
			{
						for(j=0;j<7;j++)
						{
									if(C_G[i][j]==1)
									{
												putpixel(xa+j,ya+i,WHITE);
									}
						}
				}
}

void character_H(int xa, int ya)
{
	  //hien thi ky tu H
			for(i=0;i<7;i++)
			{
						for(j=0;j<7;j++)
						{
									if(C_H[i][j]==1)
									{
												putpixel(xa+j,ya+i,WHITE);
									}
						}
				}
}

void character_I(int xa, int ya)
{
	  //hien thi ky tu I
			for(i=0;i<7;i++)
			{
						for(j=0;j<7;j++)
						{
									if(C_I[i][j]==1)
									{
												putpixel(xa+j,ya+i,WHITE);
									}
						}
				}
}

void character_J(int xa, int ya)
{
	  //hien thi ky tu J
			for(i=0;i<7;i++)
			{
						for(j=0;j<7;j++)
						{
									if(C_J[i][j]==1)
									{
												putpixel(xa+j,ya+i,WHITE);
									}
						}
				}
}

void character_K(int xa, int ya)
{
	  //hien thi ky tu K
			for(i=0;i<7;i++)
			{
						for(j=0;j<7;j++)
						{
									if(C_K[i][j]==1)
									{
												putpixel(xa+j,ya+i,WHITE);
									}
						}
				}
}

void character_L(int xa, int ya)
{
	  //hien thi ky tu L
			for(i=0;i<7;i++)
			{
						for(j=0;j<7;j++)
						{
									if(C_L[i][j]==1)
									{
												putpixel(xa+j,ya+i,WHITE);
									}
						}
				}
}


void character_M(int xa, int ya)
{
	  //hien thi ky tu M
			for(i=0;i<7;i++)
			{
						for(j=0;j<7;j++)
						{
									if(C_M[i][j]==1)
									{
												putpixel(xa+j,ya+i,WHITE);
									}
						}
				}
}

void character_N(int xa, int ya)
{
	  //hien thi ky tu N
			for(i=0;i<7;i++)
			{
						for(j=0;j<7;j++)
						{
									if(C_N[i][j]==1)
									{
												putpixel(xa+j,ya+i,WHITE);
									}
						}
				}
}

void character_O(int xa, int ya)
{
	  //hien thi ky tu O
			for(i=0;i<7;i++)
			{
						for(j=0;j<7;j++)
						{
									if(C_O[i][j]==1)
									{
												putpixel(xa+j,ya+i,WHITE);
									}
						}
				}
}

void character_P(int xa, int ya)
{
	  //hien thi ky tu P
			for(i=0;i<7;i++)
			{
						for(j=0;j<7;j++)
						{
									if(C_P[i][j]==1)
									{
												putpixel(xa+j,ya+i,WHITE);
									}
						}
				}
}

void character_Q(int xa, int ya)
{
	  //hien thi ky tu Q
			for(i=0;i<7;i++)
			{
						for(j=0;j<7;j++)
						{
									if(C_Q[i][j]==1)
									{
												putpixel(xa+j,ya+i,WHITE);
									}
						}
				}
}

void character_R(int xa, int ya)
{
	  //hien thi ky tu R
			for(i=0;i<7;i++)
			{
						for(j=0;j<7;j++)
						{
									if(C_R[i][j]==1)
									{
												putpixel(xa+j,ya+i,WHITE);
									}
						}
				}
}

void character_S(int xa, int ya)
{
	  //hien thi ky tu S
			for(i=0;i<7;i++)
			{
						for(j=0;j<7;j++)
						{
									if(C_S[i][j]==1)
									{
												putpixel(xa+j,ya+i,WHITE);
									}
						}
				}
}

void character_T(int xa, int ya)
{
	  //hien thi ky tu T
			for(i=0;i<7;i++)
			{
						for(j=0;j<7;j++)
						{
									if(C_T[i][j]==1)
									{
												putpixel(xa+j,ya+i,WHITE);
									}
						}
				}
}

void character_U(int xa, int ya)
{
	  //hien thi ky tu U
			for(i=0;i<7;i++)
			{
						for(j=0;j<7;j++)
						{
									if(C_U[i][j]==1)
									{
												putpixel(xa+j,ya+i,WHITE);
									}
						}
				}
}

void character_V(int xa, int ya)
{
	  //hien thi ky tu V
			for(i=0;i<7;i++)
			{
						for(j=0;j<7;j++)
						{
									if(C_V[i][j]==1)
									{
												putpixel(xa+j,ya+i,WHITE);
									}
						}
				}
}

void character_W(int xa, int ya)
{
	  //hien thi ky tu W
			for(i=0;i<7;i++)
			{
						for(j=0;j<7;j++)
						{
									if(C_W[i][j]==1)
									{
												putpixel(xa+j,ya+i,WHITE);
									}
						}
				}
}

void character_X(int xa, int ya)
{
	  //hien thi ky tu X
			for(i=0;i<7;i++)
			{
						for(j=0;j<7;j++)
						{
									if(C_X[i][j]==1)
									{
												putpixel(xa+j,ya+i,WHITE);
									}
						}
				}
}

void character_Y(int xa, int ya)
{
	  //hien thi ky tu Y
			for(i=0;i<7;i++)
			{
						for(j=0;j<7;j++)
						{
									if(C_Y[i][j]==1)
									{
												putpixel(xa+j,ya+i,WHITE);
									}
						}
				}
}

void character_Z(int xa, int ya)
{
	  //hien thi ky tu Z
			for(i=0;i<7;i++)
			{
						for(j=0;j<7;j++)
						{
									if(C_Z[i][j]==1)
									{
												putpixel(xa+j,ya+i,WHITE);
									}
						}
				}
}

void character_Space(int xa, int ya)
{
	  //hien thi ky tu Z
			for(i=0;i<7;i++)
			{
						for(j=0;j<7;j++)
						{
									if(C_Space[i][j]==1)
									{
												putpixel(xa+j,ya+i,WHITE);
									}
						}
				}
}

//chuong trinh chinh
int main()
{
	  xc=10;
	  yc=10;
	
	  printf("Noi dung can hien thi: \n");
	  fflush(stdin);
	  gets(chuoi);
	  
	  //doi cac ky tu thanh hoa
	  for(int k=0; k<strlen(chuoi);k++)
	  {
	  	  if(chuoi[k] >= 'a' && chuoi[k] <= 'z')
	  	  {
	  	  	  chuoi[k]=chuoi[k]-32;
						}
			}
	  	  
	  initwindow(400,400);
	  
	  
	  for (int k=0; k< strlen(chuoi); k++)
	  {
	  	  switch(chuoi[k])
	  			{
	  					case 'A': 
	  					{
	  						  	character_A(xc,yc);
								  		xc=xc+8;
								  		break;
								}
								
								case 'B': 
	  					{
	  						  	character_B(xc,yc);
								  		xc=xc+8;
								  		break;
								}  
								
								case 'C': 
	  					{
	  						  	character_C(xc,yc);
								  		xc=xc+8;
								  		break;
								}  
								
								case 'D': 
	  					{
	  						  	character_D(xc,yc);
								  		xc=xc+8;
								  		break;
								} 
								
								case 'E': 
	  					{
	  						  	character_E(xc,yc);
								  		xc=xc+8;
								  		break;
								}
								
								case 'F': 
	  					{
	  						  	character_F(xc,yc);
								  		xc=xc+8;
								  		break;
								}
								
								case 'G': 
	  					{
	  						  	character_G(xc,yc);
								  		xc=xc+8;
								  		break;
								}
								
								case 'H': 
	  					{
	  						  	character_H(xc,yc);
								  		xc=xc+8;
								  		break;
								}
								
								case 'I': 
	  					{
	  						  	character_I(xc,yc);
								  		xc=xc+8;
								  		break;
								}
								
								case 'J': 
	  					{
	  						  	character_J(xc,yc);
								  		xc=xc+8;
								  		break;
								}
								
								case 'K': 
	  					{
	  						  	character_K(xc,yc);
								  		xc=xc+8;
								  		break;
								}
								
								case 'L': 
	  					{
	  						  	character_L(xc,yc);
								  		xc=xc+8;
								  		break;
								}
								
								case 'M': 
	  					{
	  						  	character_M(xc,yc);
								  		xc=xc+8;
								  		break;
								}
								
								case 'N': 
	  					{
	  						  	character_N(xc,yc);
								  		xc=xc+8;
								  		break;
								}
								
								case 'O': 
	  					{
	  						  	character_O(xc,yc);
								  		xc=xc+8;
								  		break;
								}
								
								case 'P': 
	  					{
	  						  	character_P(xc,yc);
								  		xc=xc+8;
								  		break;
								}
								
								case 'Q': 
	  					{
	  						  	character_Q(xc,yc);
								  		xc=xc+8;
								  		break;
								}
								
								case 'R': 
	  					{
	  						  	character_R(xc,yc);
								  		xc=xc+8;
								  		break;
								}
								
								case 'S': 
	  					{
	  						  	character_S(xc,yc);
								  		xc=xc+8;
								  		break;
								}
								
								case 'T': 
	  					{
	  						  	character_T(xc,yc);
								  		xc=xc+8;
								  		break;
								}
								
								case 'U': 
	  					{
	  						  	character_U(xc,yc);
								  		xc=xc+8;
								  		break;
								}
								
								case 'V': 
	  					{
	  						  	character_V(xc,yc);
								  		xc=xc+8;
								  		break;
								}
								
								case 'W': 
	  					{
	  						  	character_W(xc,yc);
								  		xc=xc+8;
								  		break;
								}
								
								case 'X': 
	  					{
	  						  	character_X(xc,yc);
								  		xc=xc+8;
								  		break;
								}
								
								case 'Y': 
	  					{
	  						  	character_Y(xc,yc);
								  		xc=xc+8;
								  		break;
								}
								
								case 'Z': 
	  					{
	  						  	character_Z(xc,yc);
								  		xc=xc+8;
								  		break;
								}
								
								
								default:
	  					{
	  						  	character_Space(xc,yc);
								  		xc=xc+8;
								  		break;
								}
						}
						
			}
				
		 getch();
}
