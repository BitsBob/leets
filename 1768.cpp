#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string& longer  = (word1.size() > word2.size()) ? word1 : word2;
        string& shorter = (word1.size() < word2.size()) ? word1 : word2;

        string out;
        int i=0;
        for (i=0; i<shorter.size(); ++i) {
            out += shorter[i];
            out += longer[i];
        }

        return out + longer.substr(i);
    }
};
