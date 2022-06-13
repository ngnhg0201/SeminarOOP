#include "ShakerSort.h"

void ShakerSort::complexity()
{
	wcout << L"Best case O(n) = O(" << length << ")\n";
	wcout << L"Average case O(n^2) = O(" << length * length << ")\n";
	wcout << L"Worst case O(n*(n-1)/2) = O(" << length * (length - 1) / 2 << ")\n";
}

// sắp xếp tăng
void ShakerSort::increase()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	clrscr();
	int Left = 0;
	int Right = length - 1;
	int k = 0;
	while (Left < Right)
	{
		for (int i = Left; i < Right; i++)
		{
			if (Arr[i] > Arr[i + 1])// nếu giá trị phía trước lớn hơn giá trị phía sau thì hoán vị
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
				output(i, i + 1);
				swap(Arr[i], Arr[i + 1]); // hoán vị
				output(i, i + 1);
				k = i;
			}
		}
		Right = k;
		for (int i = Right; i > Left; i--)
		{
			if (Arr[i] < Arr[i - 1]) // phần tử phía sau nhỏ hơn phần tử phía trước thì hoán vị
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
				output(i, i - 1);
				swap(Arr[i], Arr[i - 1]); // hoán vị
				output(i, i - 1);
				k = i;
			}
		}
		Left = k;
	}
	clrscr();
	output(-1, -1);
}

// sắp xếp giảm
void ShakerSort::decrease()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	clrscr();
	int Left = 0;
	int Right = length - 1;
	int k = 0;
	while (Left < Right)
	{
		for (int i = Left; i < Right; i++)
		{
			if (Arr[i] < Arr[i + 1]) // phần tử phía trước nhỏ hơn phần tử phía sau thì hoán vị
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
				output(i, i + 1);
				swap(Arr[i], Arr[i + 1]); // hoán vị
				output(i, i + 1);
				k = i;
			}
		}
		Right = k;
		for (int i = Right; i > Left; i--)
		{
			if (Arr[i] > Arr[i - 1]) // phần tử phía sau lớn hơn phần tử phía trước thì hoán vị
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
				output(i, i - 1);
				swap(Arr[i], Arr[i - 1]); // hoán vị
				output(i, i - 1);
				k = i;
			}
		}
		Left = k;
	}
	clrscr();
	output(-1, -1);
}

// xuất giá trị tại vị trí i, j màu đỏ
void ShakerSort::output(int i, int j)
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