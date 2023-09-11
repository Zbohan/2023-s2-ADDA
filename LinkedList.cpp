#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::LinkedList(int* array, int len) : head(nullptr) {
    for (int i = 0; i < len; ++i) {
        insertPosition(i + 1, array[i]);
    }
}

LinkedList::~LinkedList() {
    while (head) {
        Node* temp = head;
        head = head->link;
        delete temp;
    }
}

void LinkedList::insertPosition(int pos, int newNum) {
    Node* newNode = new Node(newNum);
    if (!head || pos <= 1) {
        newNode->link = head;
        head = newNode;
    } else {
        Node* prev = head;
        for (int i = 2; i < pos && prev->link; ++i) {
            prev = prev->link;
        }
        newNode->link = prev->link;
        prev->link = newNode;
    }
}

bool LinkedList::deletePosition(int pos) {
    if (!head) return false;

    if (pos == 1) {
        Node* temp = head;
        head = head->link;
        delete temp;
        return true;
    }

    Node* prev = head;
    for (int i = 2; i < pos && prev->link; ++i) {
        prev = prev->link;
    }

    if (!prev->link) return false;

    Node* temp = prev->link;
    prev->link = temp->link;
    delete temp;
    return true;
}

int LinkedList::get(int pos) {
    Node* current = head;
    for (int i = 1; i < pos && current; ++i) {
        current = current->link;
    }

    if (!current) return std::numeric_limits<int>::max();

    return current->data;
}

int LinkedList::search(int target) {
    Node* current = head;
    int pos = 1;
    while (current) {
        if (current->data == target) return pos;
        current = current->link;
        pos++;
    }
    return -1;
}

void LinkedList::printList() {
    std::cout << "[";
    for (Node* current = head; current; current = current->link) {
        std::cout << current->data;
        if (current->link) std::cout << " ";
    }
    std::cout << "]" << std::endl;
}
