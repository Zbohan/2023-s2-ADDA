#include "QuickSort.h"
#include "RecursiveBinarySearch.h"
#include <iostream>
#include <sstream>

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::stringstream ss(input);

    int num;
    std::vector<int> numbers;
    while (ss >> num) {
        numbers.push_back(num);
    }

    QuickSort qs;
    numbers = qs.sort(numbers);

    RecursiveBinarySearch rbs;
    bool containsOne = rbs.search(numbers, 1);

    std::cout << (containsOne ? "true " : "false ");
    for (const int& n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
