#include <vector>
#include <queue>

int kth_largest(std::vector<int> values, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;  // Min-heap

    for(int num : values) {
        min_heap.push(num);
        if(min_heap.size() > k) {
            min_heap.pop();
        }
    }

    return min_heap.top();
}
