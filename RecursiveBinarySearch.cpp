#include "RecursiveBinarySearch.h"

bool RecursiveBinarySearch::search(const std::vector<int>& list, int value) {
    return binarySearch(list, value, 0, list.size() - 1);
}

bool RecursiveBinarySearch::binarySearch(const std::vector<int>& list, int value, int left, int right) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (list[mid] == value)
            return true;

        if (list[mid] > value)
            return binarySearch(list, value, left, mid - 1);

        return binarySearch(list, value, mid + 1, right);
    }
    return false;
}
