#pragma once
#include "Sort.h"

class HeapSort : public Sort
{
protected:
	bool kt; // kiểm tra khi nào người dùng yêu cầu dừng thuật toán

public:
	void complexity(); // tính độ phức tạp của thuật toán
	void heapIncrease(int, int);
	void increase(); // sắp xếp tăng
	void heapDecrease(int, int);
	void decrease(); // sắp xếp giảm
	void output(); // in mảng các bước sắp xếp

};