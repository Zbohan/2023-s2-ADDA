#include "QuickSort.h"
#include "RecursiveBinarySearch.h"
#include <iostream>
#include <sstream>
#include <vector>

int main() {
    QuickSort qs;
    RecursiveBinarySearch rbs;

    std::string line;
    getline(std::cin, line);
    std::stringstream ss(line);
    std::vector<int> numbers;

    int num;
    while (ss >> num) {
        numbers.push_back(num);
    }

    numbers = qs.sort(numbers);
    bool hasOne = rbs.search(numbers, 1);

    std::cout << (hasOne ? "true" : "false");
    for (int val : numbers) {
        std::cout << " " << val;
    }
    std::cout << std::endl;

    return 0;
}
