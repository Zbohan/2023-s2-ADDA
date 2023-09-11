#include "Node.h"

// Constructor implementation: initializes the data member with the provided value (val) 
// and sets the link (pointer to the next node) to nullptr (indicating it's the end of the list initially).
Node::Node(int val) : data(val), link(nullptr) {}

// Method implementation to retrieve the data stored in this node.
// Returns the data of this node.
int Node::getData() {
    return data;
}

// Method implementation to retrieve the next node in the linked list.
// Returns a pointer to the next node. If it returns nullptr, it indicates the end of the list.
Node* Node::getNext() {
    return link;
}

// Method implementation to set the next node in the linked list.
// Takes a pointer to a Node as an argument and sets it as the next node (link).
void Node::setNext(Node* next) {
    link = next;
}
