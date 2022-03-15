#include<stdio.h>
#include<unistd.h>
#include<windows.h>

void SET_COLOR(int color)
{
	WORD wColor;
     

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
}

void inmang(int mang[], int n)
{
	for(int i=0; i<n;i++)
	{
		printf("%d\t",mang[i]);
	}
}

int max1(int mang[], int n)
{
	int max=0;
	for(int i=0;i<n;i++)
	{
		inmang(mang,n);
		if(max<mang[i])
		{
			max=mang[i];
			printf("\nmax=%d",max);
			Sleep(500);
			system("cls");
		}
	}
	return max;
}

int max2(int mang[], int max1, int n)
{
	int max=0;
	for(int i=0;i<n;i++)
	{
		if(max<mang[i] && mang[i] != max1)
		{
			max=mang[i];
		}
	}
	return max;
}


int main()
{
	int n;
	printf("Nhap n=");
	scanf("%d",&n);
	int mang[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&mang[i]);
	}
//	printf("%d",max1(mang, n));
//	printf("%d",max2(mang, max1(mang, n), n));
//	int tich=max1(mang, n)*max2(mang, max1(mang, n), n);
//	printf("tich lon nhat trong day la %d",tich);
//	for(int i=0;i<100;i++)
//	{
//		printf("%d",i);
//		Sleep(500);
//		system("cls");
//	}


	printf("%d",max1(mang, n));


}
