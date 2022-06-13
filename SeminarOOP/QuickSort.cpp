#include "QuickSort.h"

void QuickSort::complexity()
{
    wcout << L"Best case O(n*log(n)) = O(" << length << "*log(" << length << "))\n";
    wcout << L"Average case O(n*log(n)) = O(" << length << "*log(" << length << "))\n";
    wcout << L"Worst case O(n^2) = O(" << length * length << ")\n";
}

void QuickSort::quickSortIncrease(int left, int right)
{
    if (kt == false) return;
    int l = left, r = right, x;
    x = Arr[(l + r) / 2];
    output(left, right, -1, -1);
    while (l < r)
    {
        while (Arr[l] < x) l++;
        while (Arr[r] > x) r--;

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
                    Sleep(1000);
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

        if (l <= r)
        {
            if (l!=r) output(left, right, l, r);
            swap(Arr[l++], Arr[r--]);
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
            if (l!=r) output(left, right, l, r);
        }
    }
    if (left < r) quickSortIncrease(left, r);
    if (right > l) quickSortIncrease(l, right);
}

// gọi quick sort tăng
void QuickSort::increase()
{
    kt = true;
    quickSortIncrease(0, length - 1);
}

//Hàm thực hiện giải thuật quick sort 
void QuickSort::quickSortDecrease(int left, int right)
{
    if (kt == false) return;
    int l = left, r = right, x;
    x = Arr[(l + r) / 2];
    output(left, right, -1, -1);
    while (l < r)
    {
        while (Arr[l] > x) l++;
        while (Arr[r] < x) r--;

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

        if (l <= r)
        {
            if (l != r) output(left, right, l, r);
            swap(Arr[l++], Arr[r--]);
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
            if (l != r) output(left, right, l, r);
        }
    }
    if (left < r) quickSortIncrease(left, r);
    if (right > l) quickSortIncrease(l, right);
}

// gọi quick sort giảm
void QuickSort::decrease()
{
    kt = true;
    quickSortDecrease(0, length - 1);
}

void QuickSort::output(int l, int r, int x, int y)
{
    clrscr();
    int m;
    TextColor(15);
    wcout << "Arr = ";
    for (int k = 0; k < length; k++)
        if (k >= l && k <= r)
        {
            if (k == x || k == y) TextColor(8);
            else if (k == (l + r) / 2) TextColor(9);
            else TextColor(12);
            wcout << Arr[k] << " ";
        }
        else
        {
            TextColor(15);
            wcout << Arr[k] << " ";
        }
    wcout << endl;
    Sleep(speed);
}