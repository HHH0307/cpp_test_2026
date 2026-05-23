#include "sort.h"
#include <cstdlib>

using namespace std;

void fast_sort(vector<int>& nums, int left, int right){
    if(left >= right) {
        return;
    }
    // int mid = left + (right - left) / 2;
    int mid = left + std::rand() % (right - left + 1);
    int pivot = nums[mid];
    int i = left, j = right;
    while(i <= j) {
        while(nums[i] < pivot) {    
            i++;
        }
        while(nums[j] > pivot) {    
            j--;
        }
        if(i <= j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    fast_sort(nums, left, j);
    fast_sort(nums, i, right);
}