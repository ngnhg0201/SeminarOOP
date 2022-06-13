#include "SelectionSort.h"

void SelectionSort::complexity()
{
	wcout << L"Best case O(n) = O(" << length << ")\n";
	wcout << L"Average case O(n^2) = O(" << length * length << ")\n";
	wcout << L"Worst case O((n-1)(n+3)/2) = O(" << ((length + 3) * (length - 1)) / 2 << ")\n";
}

// sắp xếp tăng
void SelectionSort::increase()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	for (int i = 0; i < length - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < length; j++)
		{
			output(min, j, "green");
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
			}
			if (Arr[min] > Arr[j]) // tìm giá trị nhỏ nhất
			{
				min = j;
				output(j, j);
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
		}
		if (i != min) output(i, min);
		swap(Arr[min], Arr[i]); // hoán vị
		output(i, min);
	}
	clrscr();
	output(-1, -1);
}

// sắp xếp giảm
void SelectionSort::decrease()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	for (int i = 0; i < length - 1; i++)
	{
		int max = i;
		for (int j = i + 1; j < length; j++)
		{
			output(max, j, "green");
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
			if (Arr[max] < Arr[j]) // tìm phần tử có giá trị lớn nhất
			{
				max = j;
				output(j, j);
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
		}
		if (i != max) output(i, max);
		swap(Arr[max], Arr[i]); // hoán vị
		output(i, max);
	}
	clrscr();
	output(-1, -1);
}

// xuất giá trị tại vị trí i màu đỏ, vị trí j tùy theo biến st
void SelectionSort::output(int i, int j, string st)
{
	clrscr();
	TextColor(15);
	wcout << "Arr = ";
	for (int k = 0; k < length; k++)
		if (k == i || k == j)
		{
			TextColor(12);
			if (st == "green" && k == j) TextColor(10);
			wcout << Arr[k] << " ";
		}
		else
		{
			TextColor(15);
			wcout << Arr[k] << " ";
		}
	Sleep(speed);
}

// xuất giá trị tại vị trí i, j màu đỏ
void SelectionSort::output(int i, int j)
{
	clrscr();
	TextColor(15);
	wcout << "Arr = ";
	for (int k = 0; k < length; k++)
		if (k == i || k == j)
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