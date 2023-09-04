#include <iostream>
#include <sstream>
#include <vector>
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);

    std::vector<int> nums;
    int num;
    while (iss >> num) {
        nums.push_back(num);
    }

    QuickSort qs;
    nums = qs.sort(nums);

    RecursiveBinarySearch rbs;
    bool hasOne = rbs.search(nums, 1);

    std::cout << (hasOne ? "true" : "false");
    for (int val : nums) {
        std::cout << " " << val;
    }
    std::cout << std::endl;

    return 0;
}
