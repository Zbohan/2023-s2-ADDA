#include "Node.h"

Node::Node(int val) : data(val), link(nullptr) {}

int Node::getData() {
    return data;
}

Node* Node::getNext() {
    return link;
}

void Node::setNext(Node* next) {
    link = next;
}
