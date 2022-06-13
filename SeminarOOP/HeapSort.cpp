#include "HeapSort.h"

void HeapSort::complexity()
{
	wcout << L"Best case O(n-1) = O(" << length - 1 << ")\n";
	wcout << L"Average case O(log2(n)) = O(log2(" << length << "))\n";
	wcout << L"Worst case O(n*log2(n)) = O(" << length << "*log2(" << length << "))\n";
}

void HeapSort::heapIncrease(int n, int i)
{
	if (kt == false) return;
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 

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
			kt = false;
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
			kt = false;
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

    if (l < n && Arr[l] > Arr[largest]) largest = l;
    if (r < n && Arr[r] > Arr[largest]) largest = r;
    if (largest != i)
    {
        swap(Arr[i], Arr[largest]);
		output();
        heapIncrease(n, largest);
    }
}

// sắp xếp tăng
void HeapSort::increase()
{
	kt = true;
	for (int i = length / 2 - 1; i >= 0; i--)
	{
		heapIncrease(length, i);
		if (kt == false) return;
	}
    for (int i = length - 1; i > 0; i--)
    {
        swap(Arr[0], Arr[i]);
		output();
        heapIncrease(i, 0);
		if (kt == false) return;
    }
}

void HeapSort::heapDecrease(int n, int i)
{
	if (kt == false) return;
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

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
			kt = false;
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
			kt = false;
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

    if (l < n && Arr[l] < Arr[largest]) largest = l;
    if (r < n && Arr[r] < Arr[largest]) largest = r;
    if (largest != i)
    {
        swap(Arr[i], Arr[largest]);
		output();
        heapDecrease(n, largest);
    }
}

// sắp xếp giảm
void HeapSort::decrease()
{
	kt = true;
	for (int i = length / 2 - 1; i >= 0; i--)
	{
		heapDecrease(length, i);
		if (kt == false) return;
	}
    for (int i = length - 1; i > 0; i--)
    {
        swap(Arr[0], Arr[i]);
		output();
        heapDecrease(i, 0);
		if (kt == false) return;
    }
}

// in mảng
void HeapSort::output()
{
	clrscr();
	TextColor(12);
	wcout << "Arr = ";
	for (int k = 0; k < length; k++) wcout << Arr[k] << " ";
	wcout << endl;
	Sleep(speed);
}