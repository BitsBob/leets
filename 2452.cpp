#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> twoEditWords(std::vector<std::string>& queries, 
                                          std::vector<std::string>& dictionary) {
        std::vector<std::string> out;

        for (const std::string& s1 : queries) {
            for (const std::string& s2 : dictionary) {
                int diff = 0;
                for (int i = 0; i < s1.size(); i++) {
                    if (s1[i] != s2[i]) {
                        diff++;
                        if (diff > 2) break;
                    }
                }
                if (diff <= 2) {
                    out.push_back(s1);
                    break; 
                }
            }
        }
        return out;
    }
};
