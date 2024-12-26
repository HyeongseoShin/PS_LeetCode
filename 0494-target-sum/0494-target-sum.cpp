class Solution {
public:
    int func(vector<int>& nums, int t, int idx, int sum)
    {
        if(idx == nums.size())
        {
            return (sum == t) ? 1 : 0;
        }

        int add = func(nums, t, idx+1, sum + nums[idx]);
        int sub = func(nums, t, idx+1, sum - nums[idx]);

        return add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target)
    {
        return func(nums, target, 0, 0);
    }
};