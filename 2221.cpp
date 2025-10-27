#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        while (n > 1) {
            vector<int> newnums(n - 1);
            for (int i=0; i<n-1; ++i) {
                newnums[i] = (nums[i] + nums[i + 1]) % 10;
            }
            nums = std::move(newnums);
            n = nums.size();
        }
        return nums[0];
    }
};