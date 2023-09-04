#include "RecursiveBinarySearch.h"

bool RecursiveBinarySearch::search(const std::vector<int>& sortedList, int val) {
    return binarySearch(sortedList, val, 0, sortedList.size() - 1);
}

bool RecursiveBinarySearch::binarySearch(const std::vector<int>& sortedList, int val, int low, int high) {
    if (low > high)
        return false;

    int mid = (low + high) / 2;

    if (sortedList[mid] == val)
        return true;
    else if (sortedList[mid] > val)
        return binarySearch(sortedList, val, low, mid - 1);
    else
        return binarySearch(sortedList, val, mid + 1, high);
}
