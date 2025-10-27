#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string out;
        int i = 0;

        for (; i < word1.size() && i < word2.size(); ++i) {
            out += word1[i];
            out += word2[i];
        }

        if (i < word1.size()) out += word1.substr(i);
        if (i < word2.size()) out += word2.substr(i);

        return out;
    }
};
