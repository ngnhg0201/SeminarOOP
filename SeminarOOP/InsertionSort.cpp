#include "InsertionSort.h"

void InsertionSort::complexity()
{
	wcout << L"Best case O(3*(n-1)) = O(" << 3 * (length - 1) << ")\n";
	wcout << L"Average case O(n^2) = O(" << length * length << ")\n";
	wcout << L"Worst case O(3/2*n-1) = O(" << 1.5 * length - 1 << ")\n";
}

// sắp xếp mảng tăng
void InsertionSort::increase()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	int i, key, j;
	for (i = 1; i < length; i++)
	{
		key = Arr[i];
		j = i - 1;
		output(i);
		while (j >= 0 && Arr[j] > key)
		{
			bool flag = false;
			char ch;
			// xử lý khi người dùng có yêu cầu dừng, tiếp tục, hủy
			if (_kbhit())
			{
				TextColor(15);
				ch = _getch();
				if (ch == 32)
				{
					if (flag == false)
					{
						wcout << L"\nOn hold!...\n";
						PlaySound(TEXT("Onhold.wav"), NULL, SND_FILENAME | SND_ASYNC);
						wcout << L"Press ""SPACEBAR"" to continue\n";
					}
					flag = !flag;
				}
				else if (ch == 27)
				{
					PlaySound(TEXT("cancel.wav"), NULL, SND_FILENAME | SND_ASYNC);
					wcout << L"\nCanceling...";
					Sleep(2000);
					return;
				}
			}
			if (flag)
			{
				char ch1 = _getch();
				if (ch1 == 27)
				{
					PlaySound(TEXT("cancel.wav"), NULL, SND_FILENAME | SND_ASYNC);
					wcout << L"\nCanceling...";
					Sleep(2000);
					return;
				}
				else
				{
					clrscr();
					wcout << L"\nInitiating...";
					PlaySound(TEXT("Building.wav"), NULL, SND_FILENAME | SND_ASYNC);
					Sleep(1000);
				}
				flag = !flag;
			}
			Arr[j + 1] = Arr[j]; // tìm vị trí hợp lệ để chèn và dời các phần tử cùng lúc
			j = j - 1;
		}
		Arr[j + 1] = key;
		output(j + 1);
	}
	clrscr();
	output(-1);
}

// sắp xếp mảng giảm
void InsertionSort::decrease()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	int i, key, j;
	for (i = 1; i < length; i++)
	{
		key = Arr[i];
		j = i - 1;
		output(i);
		while (j >= 0 && Arr[j] < key)
		{
			bool flag = false;
			char ch;
			// xử lý khi người dùng có yêu cầu dừng, tiếp tục, hủy
			if (_kbhit())
			{
				TextColor(15);
				ch = _getch();
				if (ch == 32)
				{
					if (flag == false)
					{
						wcout << L"\nOn hold!...\n";
						PlaySound(TEXT("Onhold.wav"), NULL, SND_FILENAME | SND_ASYNC);
						wcout << L"Press ""SPACEBAR"" to continue\n";
					}
					flag = !flag;
				}
				else if (ch == 27)
				{
					PlaySound(TEXT("cancel.wav"), NULL, SND_FILENAME | SND_ASYNC);
					wcout << L"\nCanceling...";
					Sleep(2000);
					return;
				}
			}
			if (flag)
			{
				char ch1 = _getch();
				if (ch1 == 27)
				{
					PlaySound(TEXT("cancel.wav"), NULL, SND_FILENAME | SND_ASYNC);
					wcout << L"\nCanceling...";
					Sleep(2000);
					return;
				}
				else
				{
					clrscr();
					wcout << L"\nInitiating...";
					PlaySound(TEXT("Building.wav"), NULL, SND_FILENAME | SND_ASYNC);
					Sleep(1000);
				}
				flag = !flag;
			}
			Arr[j + 1] = Arr[j];// tìm vị trí hợp lệ để chèn và dời các phần tử cùng lúc
			j = j - 1;
		}
		Arr[j + 1] = key;
		output(j+1);
	}
	clrscr();
	output(-1);
}

// xuất ra giá trị tại vị trí i màu đỏ
void InsertionSort::output(int i)
{
	clrscr();
	TextColor(15);
	wcout << "Arr = ";
	for (int k = 0; k < length; k++)
		if (k == i)
		{
			TextColor(12);
			wcout << Arr[k] << " ";
		}
		else
		{
			TextColor(15);
			wcout << Arr[k] << " ";
		}
	Sleep(speed);
}