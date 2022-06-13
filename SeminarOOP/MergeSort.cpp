#include "MergeSort.h"

void MergeSort::complexity()
{
	wcout << L"Best case O(n*log(n)) = O(" << length << "*log(" << length << "))\n";
	wcout << L"Average case O(n*log(n)) = O(" << length << "*log(" << length << "))\n";
	wcout << L"Worst case O(n*log(n)) = O(" << length << "*log(" << length << "))\n";
}

// trộn mảng tăng
void MergeSort::sortIncrease(int l, int m, int r)
{
	if (kt == false) return;
	output(l, r);
	int i, j, k = l;
	int n1 = m - l + 1;
	int n2 = r - m;
	int* L = new int[n1];
	int* R = new int[n2];
	for (i = 0; i < n1; i++) L[i] = Arr[l + i]; // lấy giá trị ra mảng L
	for (j = 0; j < n2; j++) R[j] = Arr[m + 1 + j]; // lấy giá trị ra mảng R
	i = 0; j = 0;
	while (i < n1 && j < n2) Arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++]; // trộn mảng tăng
	while (i < n1) Arr[k++] = L[i++]; // nếu L còn dư phần tử thì đưa vào
	while (j < n2) Arr[k++] = R[j++]; // nếu R còn dư phần tử thì đưa vào
	output(l, r);
	delete[] L, R;
}

// trộn mảng giảm
void MergeSort::sortDecrease(int l, int m, int r)
{
	output(l, r);
	int i, j, k = l;
	int n1 = m - l + 1;
	int n2 = r - m;
	int* L = new int[n1];
	int* R = new int[n2];
	for (i = 0; i < n1; i++) L[i] = Arr[l + i]; // lấy giá trị ra mảng L
	for (j = 0; j < n2; j++) R[j] = Arr[m + 1 + j]; // lấy giá trị ra mảng R
	i = 0; j = 0;
	while (i < n1 && j < n2) Arr[k++] = (L[i] >= R[j]) ? L[i++] : R[j++]; // trộn mảng giảm
	while (i < n1) Arr[k++] = L[i++]; // nếu L còn dư phần tử thì đưa vào
	while (j < n2) Arr[k++] = R[j++]; // nếu R còn dư phần tử thì đưa vào
	output(l, r);
	delete[] L, R;
}

// tách mảng
void MergeSort::Merge(int l, int r)
{
	if (kt == false) return;
	_setmode(_fileno(stdout), _O_U16TEXT);
	clrscr();
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
	if (kt == false) return;
	if (l < r)
	{
		int m = l + (r - l) / 2; // tìm vị trí giữa
		Merge(l, m); // tách mảng từ l->m
		Merge(m + 1, r);// tách mảng từ m+1->r
		if (sort == 0) sortIncrease(l, m, r); // sắp xếp tăng
		else sortDecrease(l, m, r); // sắp xếp giảm
	}
}

// thiết lập giá trị sắp xếp tăng cho hàm merge
void MergeSort::increase()
{
	sort = 0;
	kt = true;
	Merge(0, length - 1);
}

// thiết lập giá trị sắp xếp giảm cho hàm merge
void MergeSort::decrease()
{
	sort = 1;
	kt = true;
	Merge(0, length - 1);
}

// xuất ra giá trị từ vị trí i->j màu đỏ
void MergeSort::output(int i, int j)
{
	clrscr();
	TextColor(15);
	wcout << "Arr = ";
	for (int k = 0; k < length; k++)
		if (k >= i && k <= j)
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