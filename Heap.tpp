#include "Heap.h"
#include <algorithm>  // for std::swap

template <typename Type>
Type Heap<Type>::getMin() {
    if(heapSize == 0) {
        throw std::runtime_error("Heap is empty");
    }
    return heap[0];
}

template <typename Type>
void Heap<Type>::insert(Type value) {
    heap.push_back(value);
    int index = heapSize++;
    while(index > 0 && heap[parent(index)] > heap[index]) {
        std::swap(heap[parent(index)], heap[index]);
        index = parent(index);
    }
}

template <typename Type>
void Heap<Type>::remove() {
    if(heapSize == 0) {
        throw std::runtime_error("Heap is empty");
    }
    heap[0] = heap[--heapSize];
    heap.pop_back();
    heapify(0);
}

template <typename Type>
void Heap<Type>::heapify(int index) {
    int l = left(index);
    int r = right(index);
    int smallest = index;

    if(l < heapSize && heap[l] < heap[smallest]) {
        smallest = l;
    }
    if(r < heapSize && heap[r] < heap[smallest]) {
        smallest = r;
    }
    if(smallest != index) {
        std::swap(heap[smallest], heap[index]);
        heapify(smallest);
    }
}
