#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> out;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int ptr = 0;

        for (int i = 1; i <= n; ++i) {
            while (ptr < n && nums[ptr] < i) {
                ++ptr;
            }

            if (ptr >= n || nums[ptr] != i) {
                out.push_back(i);
            }
        }

        return out;
    }
};
