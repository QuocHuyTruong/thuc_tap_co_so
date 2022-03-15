#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include"library.h"

void box(int x, int y, int w, int h,int color, int data)
{
	SetColor(color);
	gotoXY(x+w/3,y+h/2);
	printf("%d",data);
	for(int ix=x;ix<=x+w;ix++)
	{
		gotoXY(ix,y);
		printf("%c",char(196));
		gotoXY(ix,y+h);
		printf("%c",char(196));
	}
	for(int iy=y;iy<=y+h;iy++)
	{
		gotoXY(x,iy);
		printf("%c",char(179));
		gotoXY(x+w,iy);
		printf("%c",char(179));
	}
	gotoXY(x,y);
	printf("%c",char(218));
	gotoXY(x+w,y);
	printf("%c",char(191));
	gotoXY(x,y+h);
	printf("%c",char(192));
	gotoXY(x+w,y+h);
	printf("%c",char(217));
	SetColor(15);
}

void boxmenu(int x, int y, int w, int h,int color)
{
	SetColor(color);
	for(int ix=x;ix<=x+w;ix++)
	{
		gotoXY(ix,y);
		printf("%c",char(196));
		gotoXY(ix,y+h);
		printf("%c",char(196));
	}
	for(int iy=y;iy<=y+h;iy++)
	{
		gotoXY(x,iy);
		printf("%c",char(179));
		gotoXY(x+w,iy);
		printf("%c",char(179));
	}
	gotoXY(x,y);
	printf("%c",char(218));
	gotoXY(x+w,y);
	printf("%c",char(191));
	gotoXY(x,y+h);
	printf("%c",char(192));
	gotoXY(x+w,y+h);
	printf("%c",char(217));
	SetColor(15);
}

void inmang(int mang[],int n, int vta,int vtb, int maua, int maub)
{
	int vtx=10;
	int vty=15;
	int w=6;
	int h=2;
	int space=7;
	for(int i=0;i<n;i++)
	{
		if(i==vta)
		{
			box(vtx,vty,w,h,maua,mang[i]);
			gotoXY(vtx+2,vty+3);
			printf("i=%d",i);
			gotoXY(vtx+1,vty+6);
			vtx+=space;
		}
		else if(i==vtb)
		{
			box(vtx,vty,w,h,maub,mang[i]);
			gotoXY(vtx+2,vty+3);
			printf("i=%d",i);
			gotoXY(vtx+1,vty+6);
			vtx+=space;
		}
		else
		{	
			box(vtx,vty,w,h,15,mang[i]);
			gotoXY(vtx+2,vty+3);
			printf("i=%d",i);
			gotoXY(vtx+1,vty+6);
			vtx+=space;
		}
	}
}

void swap(int vta, int vtb, int mang[],int n) 
{
	int vtx=10;
	int vty=15;
	int space=7;
	// in mang ban dau
	inmang(mang,n,vta,vtb,4,5);
	Sleep(300);
	system("cls");
	//doi cho
	for(int i=1;i<6;i++)
	{
		inmang(mang,n,vta,vtb,0,0);
		box(vtx+vta*space+i,vty-i,4,2,4,mang[vta]);
		box(vtx+vtb*space-i,vty-i,4,2,5,mang[vtb]);
		Sleep(50);
		system("cls");
	}
	int temp = mang[vta];
    mang[vta] = mang[vtb];
    mang[vtb] = temp;
    vtx=10;
	vty=13;
    // in lai mang sau khi doi cho
	inmang(mang,n,vta,vtb,4,5);
	Sleep(300);
}

void bubbleSort(int a[], int n)
{
    int i, j;
    bool swapped;
    for (i = (n-1); i >= 0; i--)
	{
		swapped = false;
        for (j = 1; j <= i; j++)
		{
            if (a[j-1] > a[j])
            {
            	system("cls");
            	swap(j-1,j,a,n);
            	swapped = true;
			}
			else
			{
				inmang(a,n,j-1,j,4,5);
				Sleep(300);
			}
        }
        if(!swapped)
        {
        	break;
		}
    }
}

void thanh_sang(int x,int y,int w,int h,int b_color, int yp)
{
	gotoXY(50 + 1, 5 + 1);
	printf("Tim tich lon nhat");
	gotoXY(50 + 1, 7 + 1);
	printf("Tim tich be nhat");
	gotoXY(50 + 1, 9 + 1);
	printf("Tim tich lon be");
	gotoXY(50 + 1, 11 + 1);
	printf("Thoat");
	bcolor(b_color);
	for (int iy = y + 1;iy <= y + h - 1;iy++)
	{
		for (int ix = x + 1;ix <= x + w - 1;ix++)
		{
			gotoXY(ix, iy);
			printf(" ");
		}
	}
	SetColor(7);
	gotoXY(x + 1, y + 1);
	if(yp==5)
	{
		printf("Tim tich lon nhat");
	}
	if(yp==7)
	{
		printf("Tim tich be nhat");
	}
	if(yp==9)
	{
		printf("Tim tich lon be");
	}
	if(yp==11)
	{
		printf("Thoat");
	}
	bcolor(15);
}

int menu()
{
	//----- setting ----
	int vitri;
	int w = 20;
	int h = 2;
	int t_color = 11;
	int b_color = 1;
	int b_color_sang = 75;
	int sl = 4;
	for (int i = 0;i < sl;i++)
	{
		boxmenu(50, 5 + (i * 2), w, h,11);
		if (i != 0)
		{
			gotoXY(50, 5 + (i * 2));
			printf("%c",char(195));
			gotoXY(50 + w, 5 + (i * 2));
			printf("%c",char(180));
		}
	}
	gotoXY(40,3);
	SetColor(10);
	printf("CHUONG TRINH MINH HOA TIM TICH BE NHAT VA LON NHAT");
	gotoXY(50 + 1, 5 + 1);
	printf("Tim tich lon nhat");
	gotoXY(50 + 1, 7 + 1);
	printf("Tim tich be nhat");
	gotoXY(50 + 1, 9 + 1);
	printf("Tim tich lon be");
	gotoXY(50 + 1, 11 + 1);
	printf("Thoat");
	//-----------
	int xp = 50;int yp = 5;//t?a d? thanh sáng
	int xcu = xp;int ycu = yp;
	bool kt = true;
	while (true)
	{
		if (kt == true)
		{
			gotoXY(xcu, ycu);
			thanh_sang(xcu, ycu, w, h, b_color,0);//rs thanh sang cu
			xcu = xp;ycu = yp;
			thanh_sang(xp, yp, w, h, b_color_sang,yp);
			kt = false;
		}
		//----- dieu khien ---- //----- di chuyen ----
		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				kt = true;
				c = _getch();
				if (c == 72)
				{
					if(yp != 5)yp -= 2;
					else
					{
						yp = 5 + h*(sl - 1);
					}
				}
				else if (c == 80 )
				{
					if(yp != 5 + h*(sl - 1))yp += 2;
					else
					{
						yp = 5;
					}
				}
			}
			else if(c==13)
			{
				vitri=yp;
				bcolor(4);
				return vitri;
			}
		}
		//---- speed ----
	}
}

void thanh_sang_nho(int x,int y,int w,int h,int b_color, int yp)
{
	gotoXY(70 + 1, 5 + 1);
	printf("Doc file");
	gotoXY(70 + 1, 7 + 1);
	printf("Nhap tay");
	gotoXY(70 + 1, 9 + 1);
	printf("Quay lai");
	bcolor(b_color);
	for (int iy = y + 1;iy <= y + h - 1;iy++)
	{
		for (int ix = x + 1;ix <= x + w - 1;ix++)
		{
			gotoXY(ix, iy);
			printf(" ");
		}
	}
	SetColor(7);
	gotoXY(x + 1, y + 1);
	if(yp==5)
	{
		printf("Doc file");
	}
	if(yp==7)
	{
		printf("Nhap tay");
	}
	if(yp==9)
	{
		printf("Quay lai");
	}
	bcolor(7);
}

int menu_nho()
{
	//----- setting ----
	int vitri;
	int w = 20;
	int h = 2;
	int t_color = 11;
	int b_color = 1;
	int b_color_sang = 75;
	int sl = 3;
	for (int i = 0;i < sl;i++)
	{
		boxmenu(70, 5 + (i * 2), w, h,11);
		if (i != 0)
		{
			gotoXY(70, 5 + (i * 2));
			printf("%c",char(195));
			gotoXY(70 + w, 5 + (i * 2));
			printf("%c",char(180));
		}
	}
	gotoXY(70 + 1, 5 + 1);
	printf("Doc file");
	gotoXY(70 + 1, 7 + 1);
	printf("Nhap tay");
	gotoXY(70 + 1, 9 + 1);
	printf("Quay lai");
	//-----------
	int xp = 70;int yp = 5;//t?a d? thanh sáng
	int xcu = xp;int ycu = yp;
	bool kt = true;
	while (true)
	{
		if (kt == true)
		{
			gotoXY(xcu, ycu);
			thanh_sang_nho(xcu, ycu, w, h, b_color,0);//rs thanh sang cu
			xcu = xp;ycu = yp;
			thanh_sang_nho(xp, yp, w, h, b_color_sang,yp);
			kt = false;
		}
		//----- dieu khien ---- //----- di chuyen ----
		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				kt = true;
				c = _getch();
				if (c == 72)
				{
					if(yp != 5)yp -= 2;
					else
					{
						yp = 5 + h*(sl - 1);
					}
				}
				else if (c == 80 )
				{
					if(yp != 5 + h*(sl - 1))yp += 2;
					else
					{
						yp = 5;
					}
				}
			}
			else if(c==13)
			{
				vitri=yp;
				bcolor(7);
				system("cls");
				return vitri;
			}
		}
	}
}

void tichlonnhat(int mang[], int n)
{
	if(mang[0]*mang[1]<mang[n-1]*mang[n-2])
	{
//		inmang(mang,n,n-1,n-2,4,5);
		printf("\nHai so la %d va %d\n",mang[n-1],mang[n-2]);
		printf("Tich lon nhat la %d",mang[n-1]*mang[n-2]);
	}
	else
	{
//		inmang(mang,n,0,1,4,5);
		printf("\nHai so la %d va %d\n",mang[0],mang[1]);
		printf("Tich lon nhat la %d",mang[0]*mang[1]);
	}
}

void tichbenhat(int mang[], int n)
{
	if(mang[0]*mang[1]<mang[0]*mang[n-1])
	{
//		inmang(mang,n,0,1,4,5);
		printf("\nHai so la %d va %d\n",mang[0],mang[1]);
		printf("Tich be nhat la %d",mang[0]*mang[1]);
	}
	else
	{
//		inmang(mang,n,0,n-1,4,5);
		printf("\nHai so la %d va %d\n",mang[0],mang[n-1]);
		printf("Tich be nhat la %d",mang[0]*mang[n-1]);
	}
}

void nhap(int mang[], int &n)
{
	do
	{
		printf("Nhap n=");
		scanf("%d",&n);
	}
	while(n<2 || n>=50);
	for(int i=0;i<n;i++)
	{
		printf("Nhap phan tu thu %d=",i);
		scanf("%d",&mang[i]);
	}
}

int main()
{
	
	SetScreenBufferSize(1000,90);
	ShowCur(0);
	int vitri;
	Back: vitri=menu();
	ShowCur(0);
	int n=0;
	int mang[50];
	switch(vitri)
	{
		case 5:
			{
				vitri = menu_nho();
				if(vitri==5)
				{
					//doc file
					FILE * f;
					f=fopen("input.txt","r");
					printf("\n");
					while(!feof(f))
					{
						fscanf(f,"%d",&mang[n]);
						n++;
					}
					fclose(f);
					//ket thuc doc file
					if(n<2 || n>=50)
					{
						gotoXY(0,16);
						printf("File phai co it nhat 2 gia tri va nhieu nhat 50 gia tri");
						goto Back;
					}
					else
					{
						bubbleSort(mang,n);
						inmang(mang,n,0,0,7,7);
						tichlonnhat(mang,n);
						goto Back;
					}
				}
				if(vitri==7)
				{
					system("cls");
					SetColor(10);
					nhap(mang,n);
					system("cls");
					bubbleSort(mang,n);
					inmang(mang,n,0,0,7,7);
					tichlonnhat(mang,n);
					goto Back;
				}
				if(vitri==9)
				{
					system("cls");
					goto Back;
				}
			}
		case 7:
			{
				vitri = menu_nho();
				if(vitri==5)
				{
					//doc file
					FILE * f;
					f=fopen("input.txt","r");
					printf("\n");
					while(!feof(f))
					{
						fscanf(f,"%d",&mang[n]);
						n++;
					}
					fclose(f);
					//ket thuc doc file
					if(n<2 || n>=50)
					{
						gotoXY(0,16);
						printf("File phai co it nhat 2 gia tri va nhieu nhat 50 gia tri");
						goto Back;
					}
					else
					{
						bubbleSort(mang,n);
						inmang(mang,n,0,0,7,7);
						tichbenhat(mang,n);
						goto Back;
					}
				}
				if(vitri==7)
				{
					system("cls");
					SetColor(10);
					nhap(mang,n);
					system("cls");
					bubbleSort(mang,n);
					inmang(mang,n,0,0,7,7);
					tichbenhat(mang,n);
					goto Back;
				}
				if(vitri==9)
				{
					system("cls");
					goto Back;
				}
			}
		case 9:
			{
				vitri = menu_nho();
				if(vitri==5)
				{
					//doc file
					FILE * f;
					f=fopen("input.txt","r");
					printf("\n");
					while(!feof(f))
					{
						fscanf(f,"%d",&mang[n]);
						n++;
					}
					fclose(f);
					//ket thuc doc file
					if(n<2 || n>=50)
					{
						gotoXY(0,16);
						printf("File phai co it nhat 2 gia tri va nhieu nhat 50 gia tri");
						goto Back;
					}
					else
					{
						bubbleSort(mang,n);
						inmang(mang,n,0,0,7,7);
						tichlonnhat(mang,n);
						tichbenhat(mang,n);
						goto Back;
					}
				}
				if(vitri==7)
				{
					system("cls");
					SetColor(10);
					nhap(mang,n);
					system("cls");
					bubbleSort(mang,n);
					inmang(mang,n,0,0,7,7);
					tichlonnhat(mang,n);
					tichbenhat(mang,n);
					goto Back;
				}
				if(vitri==9)
				{
					system("cls");
					goto Back;
				}
			}
		case 11:
			{
				exit(0);
			}
		
	}

}

