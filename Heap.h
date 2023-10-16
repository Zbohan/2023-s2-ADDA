#ifndef HEAP_H
#define HEAP_H

#include <vector>

template <typename Type>
class Heap {
private:
    std::vector<Type> heap;
    int heapSize;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    void heapify(int index);

public:
    Heap() : heapSize(0) {}
    
    Type getMin();
    void insert(Type value);
    void remove();
};

#endif // HEAP_H
