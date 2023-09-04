#ifndef RECURSIVEBINARYSEARCH_H
#define RECURSIVEBINARYSEARCH_H

#include <vector>

class RecursiveBinarySearch {
public:
    bool search(const std::vector<int>& list, int item);

private:
    bool binarySearch(const std::vector<int>& list, int l, int r, int item);
};

#endif // RECURSIVEBINARYSEARCH_H
