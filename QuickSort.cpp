#include "QuickSort.h"

std::vector<int> QuickSort::sort(const std::vector<int>& list) {
    std::vector<int> result = list;
    quickSort(result, 0, result.size() - 1);
    return result;
}

void QuickSort::quickSort(std::vector<int>& list, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(list, left, right);
        quickSort(list, left, pivotIndex - 1);
        quickSort(list, pivotIndex + 1, right);
    }
}

int QuickSort::partition(std::vector<int>& list, int left, int right) {
    int pivot = list[left + 2];
    int i = left;
    int j = right;

    while (true) {
        while (list[i] < pivot && i < right) {
            i++;
        }

        while (list[j] > pivot && j > left) {
            j--;
        }

        if (i < j) {
            std::swap(list[i], list[j]);
        } else {
            return j;
        }
    }
}
