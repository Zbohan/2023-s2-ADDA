#include "Autocomplete.h"

class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

Autocomplete::Autocomplete() {
    root = new TrieNode();
}

Autocomplete::~Autocomplete() {
    // TODO: Free the memory used by TrieNode objects.
    // Implementing this might require a recursive function.
}

void Autocomplete::insert(const std::string& word) {
    TrieNode* curr = root;
    for (char c : word) {
        int index = c - 'a';
        if (!curr->children[index]) {
            curr->children[index] = new TrieNode();
        }
        curr = curr->children[index];
    }
    curr->isEndOfWord = true;
}

std::vector<std::string> Autocomplete::getSuggestions(const std::string& partialWord) {
    std::vector<std::string> suggestions;
    TrieNode* curr = root;
    for (char c : partialWord) {
        int index = c - 'a';
        if (!curr->children[index]) {
            return suggestions;
        }
        curr = curr->children[index];
    }
    getSuggestionsHelper(curr, partialWord, suggestions);
    return suggestions;
}

void Autocomplete::getSuggestionsHelper(TrieNode* current, const std::string& currentWord, std::vector<std::string>& suggestions) {
    if (!current) {
        return;
    }
    if (current->isEndOfWord) {
        suggestions.push_back(currentWord);
    }
    for (int i = 0; i < 26; i++) {
        if (current->children[i]) {
            getSuggestionsHelper(current->children[i], currentWord + (char)('a' + i), suggestions);
        }
    }
}
