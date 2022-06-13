#include "Menu.h"
#include <cstring>

void DisableSelection()
{
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

	SetConsoleMode(hStdin, ~ENABLE_QUICK_EDIT_MODE);
}

void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConCurInf;

	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = CursorVisibility;

	SetConsoleCursorInfo(handle, &ConCurInf);
}

// in ra hướng dẫn để người dùng biết cách bắt đầu, tiếp tục, tạm dừng
void check(char& ch)
{
	TextColor(15);
	wcout << L"Press ""SPACEBAR"" to start\n";
	wcout << L"To cancel, please press ""ESC""\n";

	// chờ người dùng nhấn phím
	bool flag = true;
	while (flag) 
	{
		if (_kbhit())
		{
			ch = _getch();
			Sleep(500);
			if (ch == 32)
			{
				clrscr();
				PlaySound(TEXT("Building.wav"), NULL, SND_FILENAME | SND_ASYNC);
				wcout << L"Starting...\n";
				flag = !flag;
				Sleep(1500);
				return;
			}
			if (ch == 27)
			{
				clrscr();
				PlaySound(TEXT("cancel.wav"), NULL, SND_FILENAME | SND_ASYNC);
				wcout << L"Canceling...";
				Sleep(1500);
				return;
			}
		}
	}
	cin.ignore();
}

void ShowScrollbar(BOOL Show)
{
	HWND hWnd = GetConsoleWindow();
	ShowScrollBar(hWnd, SB_BOTH, Show);
}

// in khung
void box(int x, int y, int w, int h, char s[]) {
	if (h <= 1 || w <= 1) return;
	for (int ix = x+1; ix < x + w; ix++) {
		gotoXY(ix, y);
		ShowCur(0);
		wcout << L'─';
		gotoXY(ix, y + h);
		ShowCur(0);
		wcout << L'─';
	}
	for (int iy = y + 1; iy < y + h; iy++) {
		gotoXY(x, iy);
		ShowCur(0);
		wcout << L'│';
		gotoXY(x + w, iy);
		ShowCur(0);
		wcout << L'│';
	}
	ShowCur(0);
	gotoXY(x, y); wcout << L'┌';
	ShowCur(0);
	gotoXY(x + w, y); wcout << L'┐';
	ShowCur(0);
	gotoXY(x, y + h); wcout << L'└';
	ShowCur(0);
	gotoXY(x + w, y + h); wcout << L'┘';
	/*
	for (int iy = y + 1; iy < y + h; iy++) {
		gotoXY(x+1, iy);
		if (iy == y + h / 2) {
			int ix = x + 1;
			for (; ix < x + (w - strlen(s)) / 2; ix++) {
				wcout << " ";
			}
			wcout << s;
			ix += strlen(s);
			for (; ix < x + h; ix++) {
				wcout << " ";
			}
		} 
		else
			for (int ix = x + 1; ix < x + h; ix++)
				wcout << " ";
	}
	*/
	ShowCur(0);
	gotoXY(x + (w - strlen(s)) / 2, y + h / 2); wcout << s;
}

// nhập các dữ liệu cần thiết để bắt đầu sắp xếp
void input(Sort* sort, int n)
{
	int x = 0, s = 0, dem = 0;
	char ch;

	// chọn cách nhập
	PlaySound(TEXT("selecttarget.wav"), NULL, SND_FILENAME | SND_ASYNC);
	char textInsertDirectly[] = "1. Insert directly";
	char textCreateRandomlyArray[] = "2. Create randomly array";
	char textInsertFile[] = "3. Insert file";
	clrscr();
	do
	{
		TextColor(15);
		gotoXY(77, 4);
		ShowCur(0);
		wcout << L"CHOOSE INSERT WAY";
		gotoXY(76, 5);
		ShowCur(0);
		wcout << L"───────────────────";
		if (dem == 0) TextColor(12);
		else TextColor(15);
		box(60, 10, 50, 4, textInsertDirectly);
		if (dem == 1) TextColor(12);
		else TextColor(15);
		box(60, 17, 50, 4, textCreateRandomlyArray);
		if (dem == 2) TextColor(12);
		else TextColor(15);
		box(60, 24, 50, 4, textInsertFile);
		ch = _getch();
		if (ch == 80) // xử lý thao tác nhấn nút down
		{
			dem++;
			if (dem > 2) dem = 0;
		} 
		else if (ch == 72) // xử lý thao tác nhấn nút up
		{
			dem--;
			if (dem < 0) dem = 2;
		}
	} while (ch != 13);

	TextColor(15);
	gotoXY(0, 33);
	for (int i = 0; i < 172; i++) wcout << L"─";

	// xử lý yêu cầu nhập
	if (dem == 0) cin >> sort;
	else if (dem == 1) sort->Random();
	else sort->inputFile();
	wcout << sort << endl;
	sort->complexity();
	TextColor(12);
	wcout << L"\nPress any key to continue...";
	ch = _getch();

	// chọn cách sắp xếp
	PlaySound(TEXT("selecttarget.wav"), NULL, SND_FILENAME | SND_ASYNC);
	char textIncrement[] = "1. Increment";
	char textDecrement[] = "1. Decrement";
	clrscr();
	do
	{
		TextColor(15);
		gotoXY(82, 4);
		ShowCur(0);
		wcout << L"SORT BY";
		gotoXY(81, 5);
		ShowCur(0);
		wcout << L"─────────";
		if (x == 0) TextColor(12);
		else TextColor(15);
		box(60, 10, 50, 4, textIncrement);
		if (x == 1) TextColor(12);
		else TextColor(15);
		box(60, 17, 50, 4, textDecrement);
		ch = _getch();
		if (ch == 80) // xử lý thao tác nhấn nút down
		{
			x++;
			if (x > 1) x = 0;
		}
		else if (ch == 72) // xử lý thao tác nhấn nút up
		{
			x--;
			if (x < 0) x = 1;
		}
	} while (ch != 13);

	
	// chọn tốc độ biểu diễn
	PlaySound(TEXT("selecttarget.wav"), NULL, SND_FILENAME | SND_ASYNC);
	char textSlow[] = "1. Slow";
	char textNormal[] = "2. Normal";
	char textFast[] = "3. Fast";
	clrscr();
	do
	{
		TextColor(15);
		gotoXY(78, 4);
		ShowCur(0);
		wcout << L"CHOOSE THE SPEED";
		gotoXY(77, 5);
		ShowCur(0);
		wcout << L"──────────────────";
		if (s == 0) TextColor(12);
		else TextColor(15);
		box(60, 10, 50, 4, textSlow);
		if (s == 1) TextColor(12);
		else TextColor(15);
		box(60, 17, 50, 4, textNormal);
		if (s == 2) TextColor(12);
		else TextColor(15);
		box(60, 24, 50, 4, textFast);
		ch = _getch();
		if (ch == 80) // xử lý thao tác nhấn nút down
		{
			s++;
			if (s > 2) s = 0;
		}
		else if (ch == 72) // xử lý thao tác nhấn nút up
		{
			s--;
			if (s < 0) s = 2;
		}
	} while (ch != 13);

	// xử lý tốc độ biểu diễn
	if (s == 0) sort->setSpeed(500);
	else if (s == 1) sort->setSpeed(250);
	else sort->setSpeed(100);
	TextColor(15);
	clrscr();
	wcout << sort << endl;
	check(ch);
	if (ch == 27) return;

	// xử lý yêu cầu sắp xếp
	if (x == 0) sort->increase();
	else sort->decrease();
	if (n != 7 & dem != 2) clrscr();
	else if (dem == 2) wcout << sort;
	TextColor(15);
	if (dem == 2) sort->outputFile();
	PlaySound(TEXT("constructioncompleted.wav"), NULL, SND_FILENAME | SND_ASYNC);
	wcout << sort;
	wcout << L"\nSorting completed. Press any key to continue...\n";
	Sleep(100);
	ch = _getch();
}

// xử lý các lựa chọn của người dùng
void selection(int x)
{
	Sort* sort;
	TextColor(15);
	switch (x)
	{
	case 0: 
		sort = new SelectionSort;
		input(sort,x);
		delete sort;
		break; 
	case 1: 
		sort = new InterchangeSort;
		input(sort,x);
		delete sort;
		break; 
	case 2: 
		sort = new InsertionSort;
		input(sort,x);
		delete sort;
		break; 
	case 3: 
		sort = new BinaryInsertionSort;
		input(sort,x);
		delete sort;
		break; 
	case 4:
		sort = new BubbleSort;
		input(sort,x);
		delete sort;
		break;
	case 5:
		sort = new ShakerSort;
		input(sort,x);
		delete sort;
		break;
	case 8:
		sort = new ShellSort;
		input(sort,x);
		delete sort;
		break;
	case 9:
		sort = new CountingSort;
		input(sort,x);
		delete sort;
		break;
	case 10:
		sort = new RadixSort;
		input(sort,x);
		delete sort;
		break;
	case 11:
		sort = new HeapSort;
		input(sort,x);
		delete sort;
		break;
	case 12:
		sort = new QuickSort;
		input(sort,x);
		delete sort;
		break;
	case 13:
		sort = new MergeSort;
		input(sort,x);
		delete sort;
		break;
	case 7:
	case 15:
		// xử lý khi người dùng thoát
		Sleep(400);
		infor();
		TextColor(12);
		gotoXY(81, 20);
		wcout << L"Exiting...\n";
		Sleep(1000);
		clrscr();
		gotoXY(84, 20);
		PlaySound(TEXT("quit.wav"), NULL, SND_FILENAME | SND_ASYNC);
		wcout << L"Cya";
		gotoXY(0, 35);
		Sleep(3000);
		break;
	}

}

// in ra thông tin của các bạn trong nhóm
void infor()
{
	PlaySound(TEXT("outro.wav"), NULL, SND_FILENAME | SND_ASYNC);
	ShowCur(0);
			clrscr();
			TextColor(7);
			gotoXY(80, 13);
			wcout << L"== Mentor ==\n";
			TextColor(15);
			gotoXY(77, 14);
			wcout << L"------------------\n";
			TextColor(3);
			gotoXY(79, 16);
			Sleep(1000);
			wcout << L"Bùi Văn Thành\n";
			TextColor(14);
			gotoXY(78, 19);
			Sleep(1000);
			wcout << L"== Created by ==\n";
			TextColor(15);
			gotoXY(70, 20);
			wcout << L"--------------------------------\n";
			TextColor(2);
			gotoXY(75, 22);
			Sleep(1000);
			wcout << L"Lê Đình Trí - 21521561\n";
			Sleep(1000);
			gotoXY(72, 24);
			wcout << L"Nguyễn Ngọc Nhung - 21521248\n";
			gotoXY(74, 26);
			Sleep(1000);
			wcout << L"Bùi Thành Đạt - 21520689\n";
			Sleep(2500);
	clrscr();
}

// in ra menu để người dùng lựa chọn
void firstMenu(int& dem) {
	char textSelectionSort[] = "1. Selection Sort";
	char textInterchangeSort[] = "2. Interchange Sort";
	char textInsertionSort[] = "3. Insertion Sort";
	char textBinaryInsersionSort[] = "4. Binary Insersion Sort";
	char textBubbleSort[] = "5. Bubble Sort";
	char textShakerSort[] = "6. Shaker Sort";
	char textMore[] = "More...";
	char textQuit[] = "Quit";
	TextColor(15);
	gotoXY(77, 4);
	ShowCur(0);
	wcout << L"CHOOSE ONE OPTION";
	gotoXY(76, 5);
	ShowCur(0);
	wcout << L"───────────────────";
	if (dem == 0) TextColor(12);
	else TextColor(15); 
	box(25, 10, 50, 4, textSelectionSort);
	if (dem == 1) TextColor(12);
	else TextColor(15);
	box(25, 17, 50, 4, textInterchangeSort);
	if (dem == 2) TextColor(12);
	else TextColor(15);
	box(25, 24, 50, 4, textInsertionSort);
	if (dem == 3) TextColor(12);
	else TextColor(15);
	box(25, 31, 50, 4, textBinaryInsersionSort);
	if (dem == 4) TextColor(12);
	else TextColor(15);
	box(96, 10, 50, 4, textBubbleSort);
	if (dem == 5) TextColor(12);
	else TextColor(15);
	box(96, 17, 50, 4, textShakerSort);
	if (dem == 6) TextColor(12);
	else TextColor(15);
	box(96, 24, 50, 4, textMore);
	if (dem == 7) TextColor(12);
	else TextColor(15);
	box(96, 31, 50, 4, textQuit);
}

void secondMenu(int& dem){
	char textShellSort[] = "7. Shell Sort";
	char textCountingSort[] = "8. Counting Sort";
	char textRadixSort[] = "9. Radix Sort";
	char textHeapSort[] = "10. Heap Sort";
	char textQuickSort[] = "11. Quick Sort";
	char textMergeSort[] = "12. Merge Sort";
	char textBack[] = "Back...";
	char textQuit[] = "Quit";
	TextColor(15);
	gotoXY(77, 4);
	ShowCur(0);
	wcout << L"CHOOSE ONE OPTION";
	gotoXY(76, 5); 
	ShowCur(0);
	wcout << L"───────────────────";
	if (dem == 8) TextColor(12);
	else TextColor(15);
	box(25, 10, 50, 4, textShellSort);
	if (dem == 9) TextColor(12);
	else TextColor(15);
	box(25, 17, 50, 4, textCountingSort);
	if (dem == 10) TextColor(12);
	else TextColor(15);
	box(25, 24, 50, 4, textRadixSort);
	if (dem == 11) TextColor(12);
	else TextColor(15);
	box(25, 31, 50, 4, textHeapSort);
	if (dem == 12) TextColor(12);
	else TextColor(15);
	box(96, 10, 50, 4, textQuickSort);
	if (dem == 13) TextColor(12);
	else TextColor(15);
	box(96, 17, 50, 4, textMergeSort);
	if (dem == 14) TextColor(12);
	else TextColor(15);
	box(96, 24, 50, 4, textBack);
	if (dem == 15) TextColor(12);
	else TextColor(15);
	box(96, 31, 50, 4, textQuit);
}

void command()
{	
	char ch;
	int dem = 0;
	_setmode(_fileno(stdout), _O_U16TEXT);
	PlaySound(TEXT("begining.wav"), NULL, SND_FILENAME | SND_ASYNC);
	gotoXY(74, 16);
	TextColor(12);
	ShowCur(0);
	wcout << "== GROUP 12 IT002.M21 ==";
	gotoXY(72, 17);
	TextColor(15);
	ShowCur(0);
	wcout << "----------------------------";
	Sleep(3600);
	gotoXY(63, 19);
	TextColor(10);
	ShowCur(0);
	wcout << "== NORTH TANK DIVISION Cooperation Present! ==";
	gotoXY(61, 20);
	TextColor(15);
	ShowCur(0);
	wcout << "--------------------------------------------------";
	Sleep(3600);
	gotoXY(73, 22);
	TextColor(9);
	ShowCur(0);
	wcout << "== SORTING PROGRAM 0.1a ==";
	gotoXY(71, 23);
	TextColor(15);
	wcout << "------------------------------";
	Sleep(3000);
	clrscr();
	TextColor(15);
	ShowCur(1);
	PlaySound(TEXT("boot.wav"), NULL, SND_FILENAME | SND_ASYNC);
	wcout << "0> This is demo of Sorting Program. If you want the full version please DONATE...............";
	Sleep(300);
	wcout << "\n0> LAUNCHING PROGRAM.........................................................................";
	Sleep(300);
	wcout << "\n0> Copyright © 2022 NTD Cooperation, Inc.All rights reserved.................................";
	Sleep(300);
	wcout << "\n0> NTD PROPRIETARY / CONFIDENTIAL............................................................";
	Sleep(300);
	wcout << "\n0> Use is subject to license terms...........................................................";
	Sleep(300);
	wcout << "\n0> POST engaging.............................................................................";
	Sleep(300);
	wcout << "\n0> Executing TACTICAL ELECTRONIC VOICE AGENT ARTIFICIAL INTELLIGENCE.........................";
	Sleep(300);
	wcout << "\n0> Start VOLKNET.....";
	Sleep(3000);
	PlaySound(TEXT("Start.wav"), NULL, SND_FILENAME | SND_ASYNC);
	wcout << "\n0> "; wcout << "E"; Sleep(50); wcout << "s"; Sleep(50); wcout << "t"; Sleep(50); wcout << "a"; Sleep(50); wcout << "b"; Sleep(50); wcout << "l"; Sleep(50); wcout << "i"; Sleep(50); wcout << "s"; Sleep(50); wcout << "h"; Sleep(50); wcout << "i"; Sleep(50); wcout << "n"; Sleep(50); wcout << "g"; Sleep(50); wcout << " B"; Sleep(50); wcout << "a"; Sleep(50); wcout << "t"; Sleep(50); wcout << "t"; Sleep(50); wcout << "l"; Sleep(50); wcout << "e"; Sleep(50); wcout << "f"; Sleep(50); wcout << "i"; Sleep(50); wcout << "e"; Sleep(50); wcout << "l"; Sleep(50); wcout << "d"; Sleep(50); wcout << " C"; Sleep(50); wcout << "o"; Sleep(50); wcout << "n"; Sleep(50); wcout << "t"; Sleep(50); wcout << "r"; Sleep(50); wcout << "o"; Sleep(50); wcout << "l"; Sleep(50); wcout << " S"; Sleep(50); wcout << "t"; Sleep(50); wcout << "a"; Sleep(50); wcout << "n"; Sleep(50); wcout << "d"; Sleep(50); wcout << "b"; Sleep(50); wcout << "y"; Sleep(50); wcout << "."; Sleep(50); wcout << "."; Sleep(50); wcout << ".";
	Sleep(3000);
	PlaySound(TEXT("Welcome.wav"), NULL, SND_FILENAME | SND_ASYNC); 
	clrscr();
	gotoXY(82, 20);
	TextColor(11);
	ShowCur(0);
	wcout << "W"; Sleep(80); wcout << "E"; Sleep(80); wcout << "L"; Sleep(80); wcout << "C"; Sleep(80); wcout << "O"; Sleep(80); wcout << "M"; Sleep(80); wcout << "E"; Sleep(500);
	Sleep(2000);
	PlaySound(TEXT("newtechaquired(inputfile).wav"), NULL, SND_FILENAME | SND_ASYNC);
	do
	{
		clrscr();
		dem = 0;
		while (true) {
			firstMenu(dem);
			ch = _getch();
			if (ch == 13)
			{
				selection(dem);
				if (dem == 7 || dem == 6) break;
				clrscr();
				dem = 0;
			}
			if (ch == 80) // xử lý thao tác nhấn nút down
			{
				dem++;
				if (dem > 7 || dem == 4 ) dem -= 4;
			}
			else if (ch == 72) // xử lý thao tác nhấn nút up
			{
				dem--;
				if (dem < 0 || dem == 3) dem += 4;
			}
			else if (ch == 75 || ch == 77) // xử lý thao tác nhấn nút trái phải
			{
				dem+=4;
				if (dem > 7) dem -= 8;
			}
		}
		if (dem == 7) break;
		clrscr();
		dem = 8;
		while (true) {
			secondMenu(dem);
			ch = _getch();
			if (ch == 13)
			{
				selection(dem);
				if (dem == 15 || dem == 14) break;
				clrscr();
				dem = 8;
			}
			if (ch == 80) // xử lý thao tác nhấn nút down
			{
				dem++;
				if (dem > 15 || dem == 12) dem -= 4;
			}
			else if (ch == 72) // xử lý thao tác nhấn nút up
			{
				dem--;
				if (dem < 8 || dem == 11) dem += 4;
			}
			else if (ch == 75 || ch == 77) // xử lý thao tác nhấn nút trái phải
			{
				dem += 4;
				if (dem > 15) dem -= 8;
			}
		}
		if (dem == 15) break;
	} while (true);
}