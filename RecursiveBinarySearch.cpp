#include "RecursiveBinarySearch.h"

bool RecursiveBinarySearch::search(const std::vector<int>& list, int item) {
    return binarySearch(list, 0, list.size() - 1, item);
}

bool RecursiveBinarySearch::binarySearch(const std::vector<int>& list, int l, int r, int item) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (list[mid] == item)
            return true;
        if (list[mid] > item)
            return binarySearch(list, l, mid - 1, item);
        return binarySearch(list, mid + 1, r, item);
    }
    return false;
}
