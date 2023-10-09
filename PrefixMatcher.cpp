#include "PrefixMatcher.h"

class BinaryTrieNode {
public:
    BinaryTrieNode* children[2];
    int routerNumber;

    BinaryTrieNode() : routerNumber(-1) {
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

PrefixMatcher::PrefixMatcher() {
    root = new BinaryTrieNode();
}

PrefixMatcher::~PrefixMatcher() {
    // TODO: Free the memory used by BinaryTrieNode objects.
    // Implementing this might require a recursive function.
}

void PrefixMatcher::insert(const std::string& address, int routerNum) {
    BinaryTrieNode* curr = root;
    for (char c : address) {
        int index = c - '0';  
        if (!curr->children[index]) {
            curr->children[index] = new BinaryTrieNode();
        }
        curr = curr->children[index];
    }
    curr->routerNumber = routerNum;
}

int PrefixMatcher::selectRouter(const std::string& networkAddress) {
    BinaryTrieNode* curr = root;
    int lastRouterNumber = -1; 
    for (char c : networkAddress) {
        int index = c - '0';
        if (!curr->children[index]) {
            break;
        }
        curr = curr->children[index];
        if (curr->routerNumber != -1) {
            lastRouterNumber = curr->routerNumber;
        }
    }
    return lastRouterNumber;
}
