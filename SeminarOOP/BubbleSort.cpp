#include "BubbleSort.h"

void BubbleSort::complexity()
{
	wcout << L"Best case O(n) = O(" << length << ")\n";
	wcout << L"Average case O(n^2) = O(" << length * length << ")\n";
	wcout << L"Worst case O(n*(n-1)/2) = O(" << length * (length - 1) / 2 << ")\n";
}

// sắp xếp mảng tăng
void BubbleSort::increase()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	clrscr();
	for (int i = 0; i < length - 1; i++) 
	{
		for (int j = 0; j < length - i - 1; j++) 
		{
			output(j, j + 1);
			if (Arr[j] > Arr[j + 1]) // phần tử trước lớn hơn phần tử sau thì hoán vị
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
				swap(Arr[j], Arr[j + 1]);
				output(j, j + 1);
			}
		}
	}
	clrscr();
	output(-1, -1);
}

// sắp xếp giảm
void BubbleSort::decrease()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	clrscr();
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			output(j, j + 1);
			if (Arr[j] < Arr[j + 1]) // phần tử trước nhỏ hơn phần tử sao thì hoán vị
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
				swap(Arr[j], Arr[j + 1]);
				output(j, j + 1);
			}
		}
	}
	clrscr();
	output(-1, -1);
}

//xuất nếu giá trị tại vị trí i, j màu đỏ
void BubbleSort::output(int i, int j)
{
	clrscr();
	TextColor(15);
	wcout << "Arr = ";
	for (int k = 0; k < length; k++)
		if (k == i || k == j)
		{
			TextColor(12); // xử lý đổi màu cho các phần tử i, j
			wcout << Arr[k] << " ";
		}
		else
		{
			TextColor(15); // đổi lại màu sắc cho các phần tử đứng yên
			wcout << Arr[k] << " ";
		}
	Sleep(speed);
}