/*
vis를 배열 대신 unordered_map<int, int>형태로 사용하면 불필요한 수에 대한 방문을 초기화할 필요가 없음!

그러나 실행속도가 배열보다 unordered_map이 느렸음
*/

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        
        int vis[100005];
        fill(vis, vis + 100005, 0);

        int n = nums.size();
        int l = 0;
        long long sum = 0;

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