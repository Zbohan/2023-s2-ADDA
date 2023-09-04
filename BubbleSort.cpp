#include "BubbleSort.h"

std::vector<int> BubbleSort::sort(const std::vector<int>& list) {
    std::vector<int> sortedList = list;
    for (size_t i = 0; i < sortedList.size(); i++) {
        for (size_t j = 0; j < sortedList.size() - i - 1; j++) {
            if (sortedList[j] > sortedList[j+1]) {
                std::swap(sortedList[j], sortedList[j+1]);
            }
        }
    }
    return sortedList;
}
