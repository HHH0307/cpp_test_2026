#include "sort.h"

void heapify(std::vector<int>& nums, int i, int n);

// 堆排序
void heap_sort(std::vector<int>& nums) {
    int n = nums.size();
    // 构建最大堆
    for(int i = n / 2 - 1; i >= 0; i--) {
        heapify(nums, i, n);
    }

    for(int i = n - 1; i > 0; i--) {
        std::swap(nums[0], nums[i]);
        heapify(nums, 0, i);
    }
}   

// 堆化
void heapify(std::vector<int>& nums, int i, int n) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < n && nums[left] > nums[largest]) {
        largest = left;
    }
    if(right < n && nums[right] > nums[largest]) {
        largest = right;
    }
    if(largest != i) {
        std::swap(nums[i], nums[largest]);
        heapify(nums, largest, n);
    }
}   
    