#include <stdio.h>
#include <conio.h>
#include<ctime> /* thu vi?n h? tr? v? th?i gian th?c */
#include "windows.h" // thu vi?n n�y b� d?o l?m nh� - ch?a nhi?u d? choi nek - c? t�m hi?u d?n d?n s

int inputKey()
{
	if (_kbhit()) //true
	{
		int key = _getch();

		if (key == 224)
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return 0;
	}
	return 0;
}

int main()
{
	printf("%d",inputKey());
}
