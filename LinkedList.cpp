#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::LinkedList(int* array, int len) : head(nullptr) {
    for(int i = 0; i < len; i++) {
        insertPosition(i+1, array[i]);
    }
}

LinkedList::~LinkedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->getNext();
        delete temp;
    }
}

void LinkedList::insertPosition(int pos, int newNum) {
    Node* newNode = new Node(newNum);
    if (pos <= 1 || head == nullptr) {
        newNode->setNext(head);
        head = newNode;
    } else {
        Node* prev = head;
        for (int i = 1; i < pos-1 && prev->getNext() != nullptr; i++) {
            prev = prev->getNext();
        }
        newNode->setNext(prev->getNext());
        prev->setNext(newNode);
    }
}

bool LinkedList::deletePosition(int pos) {
    if (head == nullptr || pos < 1) return false;

    if (pos == 1) {
        Node* temp = head;
        head = head->getNext();
        delete temp;
        return true;
    }

    Node* prev = head;
    for (int i = 1; i < pos-1 && prev->getNext() != nullptr; i++) {
        prev = prev->getNext();
    }

    if (prev->getNext() == nullptr) return false;

    Node* temp = prev->getNext();
    prev->setNext(temp->getNext());
    delete temp;

    return true;
}

int LinkedList::get(int pos) {
    Node* current = head;
    for (int i = 1; i < pos && current != nullptr; i++) {
        current = current->getNext();
    }
    
    if (current == nullptr) return std::numeric_limits<int>::max();

    return current->getData();
}

int LinkedList::search(int target) {
    Node* current = head;
    int pos = 1;
    while (current != nullptr) {
        if (current->getData() == target) return pos;
        current = current->getNext();
        pos++;
    }
    return -1;
}

void LinkedList::printList() {
    std::cout << "[";
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->getData();
        current = current->getNext();
        if(current != nullptr) std::cout << " ";
    }
    std::cout << "]" << std::endl;
}
