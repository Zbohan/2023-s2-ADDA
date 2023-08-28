// Finder.cpp
#include "Finder.h"
using namespace std;

// Helper function: Rabin-Karp substring search
vector<int> rabinKarpSearch(const string &text, const string &pattern) {
    const int p = 31;  // Prime number
    const int m = 1e9 + 9;  // Modulus
    int n = text.size(), s = pattern.size();
    vector<int> result;

    // Compute powers of p modulo m
    vector<long long> p_pow(max(n, s));
    p_pow[0] = 1;
    for (int i = 1; i < p_pow.size(); i++)
        p_pow[i] = (p_pow[i-1] * p) % m;

    // Compute hashes for text and pattern
    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++)
        h[i+1] = (h[i] + (text[i] - 'a' + 1) * p_pow[i]) % m;
    long long h_s = 0;
    for (int i = 0; i < s; i++)
        h_s = (h_s + (pattern[i] - 'a' + 1) * p_pow[i]) % m;

    // Search
    for (int i = 0; i + s - 1 < n; i++) {
        long long cur_h = (h[i+s] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
            result.push_back(i);
    }

    return result;
}

vector<int> Finder::findSubstrings(string s1, string s2) {
    vector<int> result;

    for(size_t i = 1; i <= s2.size(); i++) {
        vector<int> indices = rabinKarpSearch(s1, s2.substr(0, i));
        if (!indices.empty()) {
            result.push_back(indices[0]);  // Only push the first occurrence
        } else {
            result.push_back(-1);
        }
    }

    return result;
}
