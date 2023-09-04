#include "QuickSort.h"

std::vector<int> QuickSort::sort(const std::vector<int>& list) {
    std::vector<int> sortedList = list;
    quickSort(sortedList, 0, sortedList.size() - 1);
    return sortedList;
}

void QuickSort::quickSort(std::vector<int>& list, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(list, low, high);
        quickSort(list, low, pivotIndex - 1);
        quickSort(list, pivotIndex + 1, high);
    }
}

int QuickSort::partition(std::vector<int>& list, int low, int high) {
    int pivot;
    if (high - low + 1 >= 3)
        pivot = list[low + 2];
    else
        pivot = list[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (list[j] <= pivot) {
            i++;
            std::swap(list[i], list[j]);
        }
    }
    std::swap(list[i + 1], list[high]);
    return (i + 1);
}
