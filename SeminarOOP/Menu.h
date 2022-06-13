#pragma once
#include "SelectionSort.h"
#include "InterchangeSort.h"
#include "InsertionSort.h"
#include "BinaryInsertionSort.h"
#include "BubbleSort.h"
#include "ShakerSort.h"
#include "ShellSort.h"
#include "RadixSort.h"
#include "CountingSort.h"
#include "HeapSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "Coordinate.h"
#include <thread>

void check(char&); // in hướng dẫn cho người dùng và kiểm tra người dùng muốn tiếp tục hay thoát

void selection(int); // xử lý các lựa chọn thuật toán của người dùng

void infor(); // thông tin nhóm thực hiện
 
void command(); // điều khiển chương trình

void ShowCur(bool CursorVisibility); //xóa con trỏ

void DisableSelection(); //xóa chọn

void ShowScrollbar(BOOL Show); //xoá thanh cuộn
