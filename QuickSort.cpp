#include "QuickSort.h"

std::vector<int> QuickSort::sort(const std::vector<int>& list) {
    std::vector<int> sortedList = list; // Create a copy of the list
    quicksort(sortedList, 0, sortedList.size() - 1);
    return sortedList;
}

void QuickSort::quicksort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int QuickSort::partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[low + 2]; // choose the third element as pivot
    int i = low;
    for (int j = low; j <= high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i], arr[low]);
    return i;
}
