#include "BubbleSort.h"

std::vector<int> BubbleSort::sort(const std::vector<int>& list) {
    std::vector<int> sortedList = list;
    int n = sortedList.size();
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (sortedList[j] > sortedList[j+1])
                std::swap(sortedList[j], sortedList[j+1]);
    return sortedList;
}
