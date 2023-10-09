#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H

#include <string>

class BinaryTrieNode;

class PrefixMatcher {
private:
    BinaryTrieNode* root;

public:
    PrefixMatcher();
    ~PrefixMatcher();
    
    void insert(const std::string& address, int routerNum);
    int selectRouter(const std::string& networkAddress);
};

#endif // PREFIXMATCHER_H
