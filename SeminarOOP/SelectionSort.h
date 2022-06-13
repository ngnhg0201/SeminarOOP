#pragma once
#include "Sort.h"

class SelectionSort : public Sort
{
public:
	void complexity();
	void increase(); // sắp xếp tăng
	void decrease(); // sắp xếp giảm
	void output(int, int, string); // in mảng các bước sắp xếp
	void output(int, int); // in mảng các bước sắp xếp

};