#include <vector>

class RecursiveBinarySearch {
public:
    bool search(const std::vector<int>& sortedList, int target);

private:
    bool binarySearch(const std::vector<int>& list, int target, int start, int end);
};
