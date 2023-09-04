#include "QuickSort.h"
#include "RecursiveBinarySearch.h"
#include <iostream>
#include <sstream>

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::stringstream ss(input);

    std::vector<int> nums;
    int num;
    while (ss >> num) {
        nums.push_back(num);
    }

    QuickSort quickSort;
    nums = quickSort.sort(nums);

    RecursiveBinarySearch rbSearch;
    bool containsOne = rbSearch.search(nums, 1);

    std::cout << (containsOne ? "true " : "false ");
    for (int n : nums) {
        std::cout << n << " ";
    }

    return 0;
}
