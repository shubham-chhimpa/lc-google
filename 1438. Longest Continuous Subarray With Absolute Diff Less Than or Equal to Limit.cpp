// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int i = 0, j=0;
        multiset<int> m;
        int n = nums.size();
        for (i = 0; i < n; ++i) {
            m.insert(nums[i]);
            if (*m.rbegin() - *m.begin() > limit)
                m.erase(m.find(nums[j++]));
        }
        return i - j;
    }
};
