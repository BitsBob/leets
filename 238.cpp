#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> out(nums.size(), 1);
        int pre = 1;
        for (int i=0; i<nums.size(); ++i) {
            out[i] *= pre;
            pre *= nums[i];
        }

        int post = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            out[i] *= post;
            post *= nums[i];
        }
        
        return out;
    }
};
