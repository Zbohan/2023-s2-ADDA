#ifndef RECURSIVEBINARYSEARCH_H
#define RECURSIVEBINARYSEARCH_H

#include <vector>

class RecursiveBinarySearch {
public:
    bool search(const std::vector<int>& sortedList, int val);
private:
    bool binarySearch(const std::vector<int>& sortedList, int val, int low, int high);
};

#endif // RECURSIVEBINARYSEARCH_H
