#include "QuickSort.h"

std::vector<int> QuickSort::sort(const std::vector<int>& list) {
    std::vector<int> sortedList = list;
    quicksort(sortedList, 0, sortedList.size() - 1);
    return sortedList;
}

void QuickSort::quicksort(std::vector<int>& list, int low, int high) {
    if (low < high) {
        int pi = partition(list, low, high);
        quicksort(list, low, pi - 1);
        quicksort(list, pi + 1, high);
    }
}

int QuickSort::partition(std::vector<int>& list, int low, int high) {
    int pivotIndex = (list.size() >= 3) ? 2 : list.size() - 1;
    int pivot = list[pivotIndex];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (list[j] < pivot) {
            i++;
            std::swap(list[i], list[j]);
        }
    }
    std::swap(list[i + 1], list[high]);
    return (i + 1);
}
