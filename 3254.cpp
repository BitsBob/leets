#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int power(vector<int> v) {
    if (v.empty()) return -1;

    int min_val = *min_element(v.begin(), v.end());
    int max_val = *max_element(v.begin(), v.end());

    std::set<int> s(v.begin(), v.end());

    if (max_val - min_val == v.size() - 1 && s.size() == v.size() && std::is_sorted(v.begin(), v.end())) {
        return max_val;
    } else {
        return -1;
    }
} 

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> out;
        for (int i=0; i<=nums.size() - k; ++i) {
          vector<int> subarray(nums.begin() + i, nums.begin() + i + k);
          out.push_back(power(subarray));
        }
        return out;
    }
};
