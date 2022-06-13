#include "CountingSort.h"

void CountingSort::complexity()
{
	wcout << L"Best case O(n) = O(" << length << ")\n";
	wcout << L"Average case O(n) = O(" << length << ")\n";
	wcout << L"Worst case O(n*2) = O(" << length * 2 << ")\n";
}

// sắp xếp tăng
void CountingSort::increase()
{
	int max = Arr[0], min = Arr[0];
	for (int i = 1; i < length; i++)
		if (Arr[i] > max) max = Arr[i]; // tìm max
		else if (Arr[i] < min) min = Arr[i]; // tìm min

	int* countArr = new int[max + 1];
	fill_n(countArr, max + 1, 0);
	for (int i = 0; i < length; i++) countArr[Arr[i]]++; // đếm số lần xuất hiện của mỗi phần tử

	output(countArr, min, max);
	int k = min, i = 0;

	// đẩy lại vô mảng
	while (i < length)
		if (countArr[k] == 0) k++;
		else
		{
			Arr[i] = k;
			countArr[k]--;
			i++;
		}
	delete[] countArr;
}

// sắp xếp giảm
void CountingSort::decrease()
{
	int max = Arr[0], min = Arr[0];
	for (int i = 1; i < length; i++)
		if (Arr[i] > max) max = Arr[i]; // tìm max
		else if (Arr[i] < min) min = Arr[i]; // tìm min

	int* countArr = new int[max + 1];
	fill_n(countArr, max + 1, 0);

	for (int i = 0; i < length; i++) countArr[Arr[i]]++; // đếm số lần xuất hiện của mỗi phần tử
	output(countArr, min, max);
	int k = max, i = 0;

	// đẩy lại vô mảng
	while (i < length)
		if (countArr[k] == 0) k--;
		else
		{
			Arr[i] = k;
			countArr[k]--;
			i++;
		}
	delete[] countArr;
}

// tính số chữ số của một số
int get(int n)
{
	int dem = 0;
	while (n != 0)
	{
		dem++;
		n /= 10;
	}
	return dem;
}

// xuất bảng tần xuất của các phần tử
void CountingSort::output(int* countArr, int min, int max)
{
	clrscr();
	int i = min, dem = 0, y = 0;
	while (i <= max)
	{
		if (dem % 10 == 0 && i != max)
		{
			gotoXY(0, y + (dem / 10) * 4);
			wcout << "Number:";
			gotoXY(0, y + 1 + (dem / 10) * 4);
			wcout << "--------------------------------------------------------------------------------------------------------------";
			gotoXY(0, y + 2 + (dem / 10) * 4);
			wcout << "Total:";
		}
		while (i <= max)
		{
			if (countArr[i] > 0)
			{
				gotoXY(((dem % 10) + 2) * 10 - get(i), y + (dem / 10) * 4); // đưa các phần tử vào đúng vị trí trong bảng
				wcout << i;
				gotoXY(((dem % 10) + 2) * 10 - get(countArr[i]), y + 2 + (dem / 10) * 4); // đưa số lượng các phần tử vào đúng vị trí trong bảng
				int x = countArr[i];
				wcout << x;
				dem++;
			}
			i++;
			if (dem % 10 == 0) break;
		}
	}

	// fix bug mảng có x*10+1 phần tử thì không in bảng ở lần cuối
	if (dem % 10 == 1)
	{
		gotoXY(0, y + (dem / 10) * 4);
		wcout << "Number:";
		gotoXY(0, y + 1 + (dem / 10) * 4);
		wcout << "--------------------------------------------------------------------------------------------------------------";
		gotoXY(0, y + 2 + (dem / 10) * 4);
		wcout << "Total:";
	}
	wcout << endl << endl;
}