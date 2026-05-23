#include "sort.h"

using namespace std;

void merge(vector<int>& nums, int left, int mid, int right);

// 归并排序
void merge_sort(vector<int>& nums, int left, int right){
    if(left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    merge_sort(nums, left, mid);
    merge_sort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}

// 合并两个有序数组
void merge(vector<int>& nums, int left, int mid, int right){
    vector<int> temp;
    int i = left, j = mid + 1;
    while(i <= mid && j <= right) {
        if(nums[i] <= nums[j]) {
            temp.push_back(nums[i]);
            i++;
        } else {
            temp.push_back(nums[j]);
            j++;
        }
    }
    while(i <= mid) {
        temp.push_back(nums[i]);
        i++;
    }
    while(j <= right) {
        temp.push_back(nums[j]);
        j++;
    }
    for(int i = left; i <= right; i++) {
        nums[i] = temp[i - left];
    }
}
