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
    if(high - low + 1 >= 3) { // Ensure the sublist is at least of size 3
        std::swap(arr[low + 2], arr[high]); // Move the third item to the end
    }
    int pivot = arr[high]; // choose the third element (now moved to the end) as pivot
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}
