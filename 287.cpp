class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s = nums[0];
        int f = nums[0];
        
        do {
            s = nums[s];
            f = nums[nums[f]];
        } while (s != f);

        int s2 = nums[0];

        while (s != s2) {
            s = nums[s];
            s2 = nums[s2];
        }

        return s;
    }
};
