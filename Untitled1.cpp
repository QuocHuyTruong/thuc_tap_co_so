#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void SetColor(int ForgC)
 {
     WORD wColor;

      HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
      CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
                 //Mask out all but the background attribute, and add in the forgournd     color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
 }

void gotoXY (int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void box(int x, int y, int w, int h,int color, int data)
{
	SetColor(color);
	gotoXY(x+w/2,y+h/2);
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

int main()
{
	int mang[50];
	int n;
	int vtmax1=0;
	int vtmax2=0;
	int vtx=10;
	int vty=10;
	printf("Nhap n=");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&mang[i]);
	}
	system("cls");
	int MAX1=mang[0];
	int MAX2=mang[0];
	// in mang ban dau
	for(int i=0;i<n;i++)
	{
		box(vtx,vty,4,2,15,mang[i]);
		gotoXY(vtx+1,vty+3);
		printf("i=%d",i);
		gotoXY(vtx+1,vty+6);
		vtx+=5;
	}
	Sleep(1000);
	// duyet tim max1
	vtx=10;
	vty=10;
	for(int i=0;i<n;i++)
	{
		if(i!=0)
		{
			box(vtx-5,vty,6,3,15,mang[i-1]);
		}
		box(vtx,vty,6,3,4,mang[i]);
		gotoXY(vtx+1,vty+3);
		printf("i=%d",i);
		gotoXY(vtx+1,vty+6);
		if(MAX1<mang[i])
		{
			MAX1=mang[i];
			vtmax1=i;
		}
		vtx+=5;
		gotoXY(10,15);
		printf("So max thu nhat=%d",MAX1);
		Sleep(500);
	}
	//duyet tim max2
	vtx=10;
	vty=10;
	for(int i=0;i<n;i++)
	{
		if(i!=0)
		{
			box(vtx-5,vty,6,3,15,mang[i-1]);
		}
		box(vtx,vty,6,3,5,mang[i]);
		gotoXY(vtx+1,vty+3);
		printf("i=%d",i);
		gotoXY(vtx+1,vty+6);
		if(MAX2<mang[i] && i!=vtmax1)
		{
			MAX2=mang[i];
			vtmax2=i;
		}
		vtx+=5;
		gotoXY(10,17);
		printf("So max thu hai=%d",MAX2);
		Sleep(500);
	}
	//danh dau 2 so max
	vtx=10;
	vty=10;
	for(int i=0;i<n;i++)
	{
		box(vtx,vty,6,3,15,mang[i]);
		gotoXY(vtx+1,vty+3);
		printf("i=%d",i);
		if(i==vtmax1)
		{
			box(vtx,vty,6,3,4,mang[i]);
			gotoXY(vtx+1,vty+3);
			printf("i=%d",i);
		}
		if(i==vtmax2)
		{
			box(vtx,vty,6,3,5,mang[i]);
			gotoXY(vtx+1,vty+3);
			printf("i=%d",i);
		}
		vtx+=5;
	}
	gotoXY(10,20);
}
