#include "sort.h"
#include <iostream>
#include <functional>
#include <string>
#include <vector>

using namespace std;

static void print_vector(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << ' ';
    }
    cout << endl;
}

static void run_sort_test(const string& name,
                          const function<void(vector<int>&)>& sorter,
                          const vector<int>& original) {
    vector<int> nums = original;
    sorter(nums);

    cout << name << ": ";
    print_vector(nums);

    if (is_sorted(nums.begin(), nums.end())) {
        cout << "  OK" << endl;
    } else {
        cout << "  FAIL" << endl;
    }
}

static void run_sort_tests() {
    const vector<int> sample = {5, 2, 9, 1, 5, 6, 3, 0, -4};

    cout << "Original: ";
    print_vector(sample);
    cout << endl;

    run_sort_test("bubble_sort", [](vector<int>& nums) {
        bubble_sort(nums);
    }, sample);

    run_sort_test("fast_sort", [](vector<int>& nums) {
        if (!nums.empty()) {
            fast_sort(nums, 0, static_cast<int>(nums.size()) - 1);
        }
    }, sample);

    run_sort_test("merge_sort", [](vector<int>& nums) {
        if (!nums.empty()) {
            merge_sort(nums, 0, static_cast<int>(nums.size()) - 1);
        }
    }, sample);

    run_sort_test("heap_sort", [](vector<int>& nums) {
        heap_sort(nums);
    }, sample);
}

int main() {
    run_sort_tests();
    return 0;
}
