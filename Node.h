#ifndef NODE_H
#define NODE_H

class Node {
private:
    int data;
    Node* link;

    // Giving LinkedList class access to Node's private members
    friend class LinkedList;

public:
    // Constructor to initialize data and set link to nullptr
    Node(int value) : data(value), link(nullptr) {}
};

#endif // NODE_H
