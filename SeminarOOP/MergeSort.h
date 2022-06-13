#pragma once
#include "Sort.h"

class MergeSort : public Sort
{
protected:
	int sort; // kiểm tra người dùng muốn sắp xếp tăng hay giảm
	bool kt; // kiểm tra khi nào người dùng yêu cầu dừng thuật toán

public:
	void complexity(); // tính độ phức tạp của thuật toán
	void sortIncrease(int, int, int); // trộn mảng tăng
	void sortDecrease(int, int, int); // trộn mảng giảm
	void Merge(int, int); // chia mảng làm hai
	void increase(); // sắp xếp tăng
	void decrease(); // sắp xếp giảm
	void output(int, int); // in mảng các bước sắp xếp

};