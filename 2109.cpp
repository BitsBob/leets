#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string out;
        int j = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (j < spaces.size() && i == spaces[j]) {
                out += ' ';
                ++j;
            }
            out += s[i];
        }

        return out;
    }
};
