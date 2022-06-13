#include "Sort.h"

// contructor mặc định
Sort::Sort()
{
	length = 0;
	speed = 0;
	Arr = new int[length];
}

// contructor có tham số
Sort::Sort(int n, int x)
{
	length = n;
	Arr = new int[length];
	speed = 0;
	for (int i = 0; i < length; i++) Arr[i] = x;
}

// detructor
Sort::~Sort()
{
	delete[] Arr;
}

// lấy giá trị của biến speed
int Sort::getSpeed()
{
	return speed;
}

// cài giá trị cho biến speed
void Sort::setSpeed(int x)
{
	speed = x;
}

// sinh ngẫu nhiên mảng
void Sort::Random()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	int min, max;
	do
	{
		wcout << L"Insert number of element(s): ";
		cin >> length;
		if (length < 0)
		{
			PlaySound(TEXT("try.wav"), NULL, SND_FILENAME | SND_ASYNC);
			wcout << L"Invalid, please retype!\n";
		}
	} while (length < 0);
	wcout << L"Distance of randomly created number(s):\n";
	wcout << "From: "; cin >> min;
	wcout<<"To: ";cin >> max;
	Sleep(500);
	Arr = new int[length];
	srand(time(NULL));
	for (int i = 0; i < length; i++) Arr[i] = rand() % (max - min + 1) + min;// Sinh ngẫu nhiên từ 0 đến 998
}

// lấy giá trị từ file dữ liệu
void Sort::inputFile()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	string link;
	bool kt;
	do
	{
		TextColor(15);
		wcout << L"Insert file directory: ";
		cin >> link;
		ifstream fileInput(link, ios::in);
		if (fileInput.fail())
		{
			wcout << L"File is not exist!" << endl;
		}
		kt = fileInput.fail();
	} while (kt);
	PlaySound(TEXT("newmissionopj.wav"), NULL, SND_FILENAME | SND_ASYNC);
	ifstream fileInput(link, ios::in);
	fileInput >> length;
	Arr = new int[length];
	for (int i = 0; i < length; i++) fileInput >> Arr[i];
	fileInput.close();
}

// lưu dữ liệu vào file
void Sort::outputFile()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	char link[255];
	wcout << L"\nInsert directory: ";
	cin.ignore();
	cin.getline(link, 255);
	ofstream fileOutput(link, ios::out);
	fileOutput << length << "\n";
	for (int i = 0; i < length; i++) fileOutput << Arr[i] << " ";
	fileOutput.close();
	TextColor(12);
	PlaySound(TEXT("newtechaquired(inputfile).wav"), NULL, SND_FILENAME | SND_ASYNC);
	wcout << L"Data saved " << link << L" successfully! Please check!\n";
	Sleep(1500);
	TextColor(15);
}

// operator >> (nhập)
istream& operator >> (istream& is, Sort* sort)
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	do
	{
		wcout << L"Insert number of element(s): ";
		is >> sort->length;
		if (sort->length  <1)
		{
			PlaySound(TEXT("try.wav"), NULL, SND_FILENAME | SND_ASYNC);
			wcout << L"Invalid, please retype!\n";
		}
	} while (sort->length <1);
	PlaySound(TEXT("selecttarget.wav"), NULL, SND_FILENAME | SND_ASYNC);
	sort->Arr = new int[sort->length];
	wcout << L"Insert each of element:\n";
	for (int i = 0; i < sort->length; i++)
	{
		wcout << "Arr[" << i << "]=";
		is >> sort->Arr[i];
	}
	Sleep(400);
	return is;
}

//operator << (xuất)
wostream& operator << (wostream& os, const Sort* sort)
{
	os << "Array = ";
	for (int i = 0; i < sort->length; i++) os << sort->Arr[i] << " ";
	os << endl;
	return os;
}