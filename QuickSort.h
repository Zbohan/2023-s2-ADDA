#include "Sort.h"

class QuickSort : public Sort {
public:
    std::vector<int> sort(const std::vector<int>& list) override;

private:
    void quickSort(std::vector<int>& list, int left, int right);
    int partition(std::vector<int>& list, int left, int right);
};
