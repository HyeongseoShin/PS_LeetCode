class Solution {
public:
    int ans = 0;
    int n;
    int t;
    vector<int> v;

    void func(int idx, int sum)
    {
        if(idx == n)
        {
            if(sum == t)
            {
                ans++;
            }
            return;
        }

        func(idx+1, sum + v[idx]);
        func(idx+1, sum - v[idx]);
    }

    int findTargetSumWays(vector<int>& nums, int target)
    {
        n = (int)nums.size();
        t = target;

        for(int i = 0; i < n; i++) v.push_back(nums[i]);

        func(0, 0);

        return ans;
    }
};