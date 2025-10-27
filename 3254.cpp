#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int power(vector<int> v) {
    if (v.empty()) return -1;

    int min_val = v[0];
    int max_val = v[0];
    unordered_set<int> seen;
    seen.insert(v[0]);

    for (int i = 1; i < v.size(); ++i) {
        if (v[i] < v[i - 1]) return -1;

        if (!seen.insert(v[i]).second) return -1;

        min_val = min(min_val, v[i]);
        max_val = max(max_val, v[i]);
    }

    if (max_val - min_val + 1 == v.size()) return max_val;

    return -1;
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
