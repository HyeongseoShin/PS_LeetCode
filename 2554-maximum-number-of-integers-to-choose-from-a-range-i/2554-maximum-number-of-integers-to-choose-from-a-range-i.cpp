class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int ans = 0;
        vector<bool> nums(n + 1, true);

        for(int i = 0; i < (int)banned.size(); i++)
        {
            int cur = banned[i];
            if(cur < 1 || cur > n) continue;
            nums[cur] = false;
        }

        int sum = 0;

        for(int i = 1; i <= n; i++)
        {
            if(nums[i])
            {
                if(sum + i > maxSum)
                {
                    return ans;
                }
                
                sum += i;
                ans++;
            }
        }

        return ans;
    }
};