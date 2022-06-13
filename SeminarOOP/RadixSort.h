#pragma once
#include "Sort.h"

class RadixSort : public Sort
{
public:
	void complexity(); // tính độ phức tạp của thuật toán
	void increase(); // sắp xếp tăng
	void decrease(); // sắp xếp giảm
	void output(int); // in mảng các bước sắp xếp

};

int number(int); // đếm số chữ số của một số