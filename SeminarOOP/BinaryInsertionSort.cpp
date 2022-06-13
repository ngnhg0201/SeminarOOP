#include "BinaryInsertionSort.h"

void BinaryInsertionSort::complexity()
{
	wcout << L"Best case O(n) = O(" << length << ")\n";
	wcout << L"Average case O(n^2) = O(" << length * length<< ")\n";
	wcout << L"Worst case O(n*(n-1+log2(n))/2) = O(" << length << " * (" << length - 1 << "+log2(" << length << "))/2" << ")\n";
}

// sắp xếp mảng tăng
void BinaryInsertionSort::increase()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	int l, r, m;
	int x;

	// thuật toán sắp xếp
	for (int i = 1; i < length; i++)
	{
		x = Arr[i]; l = 0; r = i - 1;
		output(i);
		while (l <= r) 
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
			
			m = (l + r) / 2; 
			if (x < Arr[m]) r = m - 1; // tìm vị trí chèn hợp lệ bằng phương pháp duyệt nhị phân
			else l = m + 1;
		}
		for (int j = i - 1; j >= l; j--) Arr[j + 1] = Arr[j]; // dời mảng
		Arr[l] = x;
		output(l);
	}
	clrscr();
	output(-1);
}

// sắp xếp mảng giảm
void BinaryInsertionSort::decrease()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	int l, r, m;
	int x;

	// thuật toán sắp xếp
	for (int i = 1; i < length; i++)
	{
		x = Arr[i]; l = 0; r = i - 1;
		output(i);
		while (l <= r)
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

			m = (l + r) / 2;
			if (x > Arr[m]) r = m - 1; // tìm vị trí chèn hợp lệ bằng phương pháp duyệt nhị phân
			else l = m + 1;
		}
		for (int j = i - 1; j >= l; j--) Arr[j + 1] = Arr[j]; // dời mảng
		Arr[l] = x;
		output(l);
	}
	clrscr();
	output(-1);
}

// xuất mảng giá trị vị trí tại i sẽ màu đỏ các vị trí khác màu trắng
void BinaryInsertionSort::output(int i)
{
	clrscr();
	TextColor(15);
	wcout << "Arr = ";
	for (int k = 0; k < length; k++)
		if (k == i)
		{
			TextColor(12); // xử lý màu sắc tại i
			wcout << Arr[k] << " ";
		}
		else
		{
			TextColor(15); // đổi lại màu trắng cho các phần tử không đổi
			wcout << Arr[k] << " ";
		}
	Sleep(speed);
}