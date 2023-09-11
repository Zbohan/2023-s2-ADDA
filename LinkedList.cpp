#include "LinkedList.h"
#include <iostream>

// Default constructor: initializes the head of the list to nullptr.
LinkedList::LinkedList() : head(nullptr) {}

// Overloaded constructor: initializes the list using an array of integers.
LinkedList::LinkedList(int* array, int len) : head(nullptr) {
    for(int i = 0; i < len; i++) {
        insertPosition(i+1, array[i]);
    }
}

// Destructor: deallocates memory used by the linked list.
LinkedList::~LinkedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->getNext();
        delete temp;
    }
}

// Inserts a node with value 'newNum' at a specific position in the list.
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

// Deletes a node at a specific position in the list. 
// Returns 'true' if successful, 'false' otherwise.
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

// Retrieves the value at a specific position in the list.
// If the position is out of bounds, it returns the maximum integer value.
int LinkedList::get(int pos) {
    Node* current = head;
    for (int i = 1; i < pos && current != nullptr; i++) {
        current = current->getNext();
    }
    
    if (current == nullptr) return std::numeric_limits<int>::max();

    return current->getData();
}

// Searches for a target value in the list.
// Returns the position of the target if found, -1 otherwise.
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

// Prints the entire list to the console.
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
