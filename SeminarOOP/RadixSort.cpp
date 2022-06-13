#include "RadixSort.h"

void RadixSort::complexity()
{
	int max = -1;
	for (int i = 0; i < length; i++)
		if (Arr[i] > max) max = Arr[i];
	wcout << L"Best case O(n) = O(" << length << ")\n";
	wcout << L"Average case O(n) = O(" << length << ")\n";
	wcout << L"Worst case O(2mn) = O(" << 2 * length * number(max) << ")\n";
}

void RadixSort::increase()
{
	int i, max = Arr[0], exp = 1;
	int* b = new int[length];
	for (i = 0; i < length; i++)
		if (Arr[i] > max) max = Arr[i];
	while (max / exp > 0)
	{
		int bucket[10] = { 0 };
		for (i = 0; i < length; i++) bucket[Arr[i] / exp % 10]++;
		for (i = 1; i < 10; i++) bucket[i] += bucket[i - 1];
		for (i = length - 1; i >= 0; i--) b[--bucket[Arr[i] / exp % 10]] = Arr[i];
		for (i = 0; i < length; i++) Arr[i] = b[i];
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

		output(exp);
		Sleep(speed);
		exp *= 10;
	}
	delete[] b;
}

void RadixSort::decrease()
{
	int i, m = Arr[0], exp = 1;
	int* b = new int[length];
	for (i = 0; i < length; i++)
		if (Arr[i] > m) m = Arr[i];
	while (m / exp > 0)
	{
		int bucket[10] = { 0 };
		for (i = 0; i < length; i++) bucket[Arr[i] / exp % 10]++;
		for (i = 1; i < 10; i++) bucket[i] += bucket[i - 1];
		for (i = length - 1; i >= 0; i--) b[--bucket[Arr[i] / exp % 10]] = Arr[i];
		for (i = 0; i < length; i++) Arr[i] = b[i];
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

		output(exp);
		Sleep(speed);
		exp *= 10;
	}
	delete[] b;
}

// in ra vị trí đang so sánh
void series(int exp)
{
	TextColor(12);
	switch (exp)
	{
	case 1: 
		wcout << L"1-digit numbers row:\n\n";
		break;
	case 10:
		wcout << L"2-digit numbers row:\n\n";
		break;
	case 100:
		wcout << L"3-digit number row:\n\n";
		break;
	case 1000:
		wcout << L"4-digit numbers row:\n\n";
		break;
	case 10000:
		wcout << L"5-digit numbers row:\n\n";
		break;
	case 100000:
		wcout << L"6-digit numbers row:\n\n";
		break;
	}
}

// đếm số chữ số của một số
int number(int n)
{
	int dem = 0;
	while (n != 0)
	{
		dem++;
		n /= 10;
	}
	return dem;
}

// xuất bảng
void RadixSort::output(int exp)
{
	clrscr();
	int index[10] = { 0 };
	series(exp);
	TextColor(15);

	// tìm vị trí đầu tiên của phần tử có hàng bằng i
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < length; j++)
			if (Arr[j] / exp % 10 == i)
			{
				index[i] = j;
				break;
			}
	}
	// in bảng
	for (int i = 0; i < 10; i++)
	{
		gotoXY(10 * (i + 1), 2);
		wcout << i;
	}
	wcout << "\n-------------------------------------------------------------------------------------------------------\n";
	int dem = 0, x = 0;
	// điền các giá trị vào
	while (dem < length)
	{
		for (int i = 0; i < 10; i++)
			if (Arr[index[i]] / exp % 10 == i)
			{
				gotoXY(10 * (i + 1) - number(Arr[index[i]]) + 1, x + 4);
				wcout << Arr[index[i]++];
				dem++;
			}
		x++;
	}
	TextColor(12);
	// xuất mảng
	wcout << "\n\nArr = ";
	for (int i = 0; i < length; i++) wcout << Arr[i] << " ";
	wcout << endl;
}