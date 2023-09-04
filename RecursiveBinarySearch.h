#ifndef RECURSIVEBINARYSEARCH_H
#define RECURSIVEBINARYSEARCH_H

#include <vector>

class RecursiveBinarySearch {
public:
    bool search(const std::vector<int>& list, int value);

private:
    bool binarySearch(const std::vector<int>& list, int value, int left, int right);
};

#endif // RECURSIVEBINARYSEARCH_H
