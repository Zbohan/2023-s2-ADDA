#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <vector>
#include <string>

class TrieNode;

class Autocomplete {
private:
    TrieNode* root;

    void getSuggestionsHelper(TrieNode* current, const std::string& currentWord, std::vector<std::string>& suggestions);

public:
    Autocomplete();
    ~Autocomplete();
    
    void insert(const std::string& word);
    std::vector<std::string> getSuggestions(const std::string& partialWord);
};

#endif // AUTOCOMPLETE_H
