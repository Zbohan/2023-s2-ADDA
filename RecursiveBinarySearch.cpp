#include "RecursiveBinarySearch.h"

bool RecursiveBinarySearch::search(const std::vector<int>& sortedList, int target) {
    return binarySearch(sortedList, target, 0, sortedList.size() - 1);
}

bool RecursiveBinarySearch::binarySearch(const std::vector<int>& list, int target, int start, int end) {
    if (start <= end) {
        int mid = start + (end - start) / 2;

        if (list[mid] == target) {
            return true;
        } else if (list[mid] > target) {
            return binarySearch(list, target, start, mid - 1);
        } else {
            return binarySearch(list, target, mid + 1, end);
        }
    }
    return false;
}
