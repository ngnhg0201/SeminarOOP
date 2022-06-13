#pragma once
#include "Sort.h"

class BubbleSort : public Sort
{
public:
	void complexity(); // tính độ phức tạp của thuật toán
	void increase(); // sắp xếp tăng
	void decrease(); // sắp xếp giảm
	void output(int, int); // in mảng các bước sắp xếp

};