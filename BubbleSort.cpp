#include "BubbleSort.h"

std::vector<int> BubbleSort::sort(const std::vector<int>& list) {
    std::vector<int> result = list;
    bool swapped;
    do {
        swapped = false;
        for (size_t i = 1; i < result.size(); i++) {
            if (result[i - 1] > result[i]) {
                std::swap(result[i - 1], result[i]);
                swapped = true;
            }
        }
    } while (swapped);
    return result;
}
