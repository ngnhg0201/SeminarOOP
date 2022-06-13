#pragma once
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <cstdlib>
#include <ctime> 
#include <fstream>
#include <algorithm>
#include <windows.h>
#include <stdio.h>
#include <fcntl.h>
#include <conio.h>
#include"Coordinate.h"

using namespace std;

class Sort
{
protected:
	int length, speed; // length: độ dài mảng, speed: tốc độ biểu diễn
	int* Arr; // con trỏ lưu giá trị

public:
	Sort();
	Sort(int, int);
	virtual ~Sort();
	int getSpeed(); // lấy giá trị biến speed
	void setSpeed(int x); // cài đặt giá trị biến speed
	void Random(); // sinh giá trị ngẫu nhiên cho mảng
	void inputFile(); // lấy dữ liệu từ file
	void outputFile(); // lưu dữ liệu vào file
	virtual void complexity() = 0; // tính độ phức tạp của các thuật toán
	virtual void increase() = 0; // phương thức ảo sắp xếp tăng
	virtual void decrease() = 0; // phương thức ảo sắp xếp giảm 
	friend istream& operator >> (istream&, Sort*); // nhập
	friend wostream& operator << (wostream&, const Sort*); // xuất

};