class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;

        sort(nums.begin(), nums.end());

        // 틀렸습니다 원인 나와 Pair될 수는 나 + 1부터 검사
        for(int i = 0; i < (int)nums.size() - 1; i++)
        {
            int minVal = lower - nums[i]; // 더해서 최솟값이 될 수 있는 수
            int maxVal = upper - nums[i]; // 더해서 최댓값이 될 수 있는 수

            // 틀렸습니다 원인 나와 Pair될 수는 나 + 1부터 검사
            // 최솟값이 될 수 있는 수 ~ 최댓값이 될 수 있는 수 범위에 있는 수는 무조건 Fair함!
            auto maxIdx = upper_bound(nums.begin() + i + 1, nums.end(), maxVal);
            auto minIdx = lower_bound(nums.begin() + i + 1, nums.end(), minVal);

            ans += (maxIdx - minIdx);            
        }
        return ans;
    }
};