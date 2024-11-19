class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        int vis[100005];
        int n = nums.size();
        int l = 0;
        long long sum = 0;

        fill(vis, vis + 100005, 0);

        for(int i = 0; i < n; i++)
        {
            
            while(vis[nums[i]] != 0)
            {
                sum -= nums[l];
                vis[nums[l++]]--;   
            }
            
            vis[nums[i]]++;
            sum += nums[i];

            if(i - l + 1 == k)
            {
                ans = max(ans, sum);
                vis[nums[l]]--;
                sum -= nums[l++];
            }
        }

        return ans;
    }
};