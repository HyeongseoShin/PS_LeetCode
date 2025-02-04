class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = (int)nums.size();

        int st = 0;
        int en = 1;

        int ans = nums[st];

        while(st < n && en < n)
        {
            int cur = 0;
            cur += nums[st];

            while(en < n && nums[en-1] < nums[en])
            {
                cur += nums[en];
                en++;
            }

            ans = max(ans, cur);

            st = en;
            en++;
        }
        return ans;
    }
};