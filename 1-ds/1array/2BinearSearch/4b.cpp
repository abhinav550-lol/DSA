#include <iostream>
#include <vector>

int findMaxElementIndex(const std::vector<int>& nums) {
    int start = 0;
    int end = nums.size() - 1;

    while  (start < end) {
        int mid =  start + end) / 2;

        if (nums[mid] > nums[mid + 1]) {
            // The maximum element is at index 'mid'
            return mid;
        }

        if (nums[mid] >= nums [start]) {
            // The maximum element is on the right side of 'mid'
         start = mid + 1;
        } else {
            // The maximum element is on the left side of 'mid'
            end = mid;
        }
    }

    //  start' and 'end' will be equal when the loop exits
    // This is the index of the maximum element
    return start;
}

int main() {
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int maxIndex = findMaxElementIndex(nums);

    std::cout << "Index of the maximum element: " << maxIndex << std::endl;

    return 0;
}
