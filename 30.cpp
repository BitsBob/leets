#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> out;
        if (s.empty() || words.empty()) return out;
`
        int wordLen = words[0].size();
        int numWords = words.size();
        int totalLen = wordLen * numWords;

        unordered_map<string, int> wordCount;
        for (auto &w : words) wordCount[w]++;

        for (int i = 0; i <= s.size() - totalLen; i++) {
            unordered_map<string, int> seen;
            int j = 0;
            for (; j < totalLen; j += wordLen) {
                if (i + j + wordLen > s.size()) break;
                string word = s.substr(i + j, wordLen);
                if (wordCount.find(word) == wordCount.end()) break;
                seen[word]++;
                if (seen[word] > wordCount[word]) break;
            }
            if (j == totalLen) out.push_back(i);
        }

        return out;
    }
};
