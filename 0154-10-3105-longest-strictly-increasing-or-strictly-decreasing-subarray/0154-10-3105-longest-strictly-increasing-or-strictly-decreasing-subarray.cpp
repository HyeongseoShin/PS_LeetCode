class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        int st = 0;
        int en = 1;

        while(st < n && en < n)
        {
            while(en < n && nums[en - 1] < nums[en])
            {
                ans = max(ans, (en - st + 1));
                en++;
            }
            st = en;
            en++;
        }

        st = 0;
        en = 1;

        while(st < n && en < n)
        {
            while(en < n && nums[en - 1] > nums[en])
            {
                ans = max(ans, (en - st + 1));
                en++;
            }
            st = en;
            en++;
        }

        return ans;
    }
};