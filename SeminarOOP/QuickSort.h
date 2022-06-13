#pragma once
#include "Sort.h"

class QuickSort : public Sort
{
protected:
	bool kt; // kiểm tra khi nào người dùng yêu cầu dừng thuật toán

public:
	void complexity(); // tính độ phức tạp của thuật toán
	void quickSortIncrease(int, int);
	void increase(); // sắp xếp tăng
	void quickSortDecrease(int, int);
	void decrease(); // sắp xếp giảm
	void output(int, int, int, int); // in mảng các bước sắp xếp
	
};