#pragma once 

#include <algorithm>
#include <vector>

// 快速排序
void fast_sort(std::vector<int>& nums, int left, int right);

// 归并排序
void merge_sort(std::vector<int>& nums, int left, int right);

// 堆排序
void heap_sort(std::vector<int>& nums);

// 冒泡排序
void bubble_sort(std::vector<int>& nums);
