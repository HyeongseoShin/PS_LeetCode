class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        int n = (int)nums.size();

        vector<int> v;
        v.resize(n);

        for(int i = 0; i < n; i++) v[i] = nums[i];

        sort(v.begin(), v.end());

        // 틀렸습니다 원인 나와 Pair될 수는 나 + 1부터 검사
        for(int i = 0; i < n - 1; i++)
        {
            int minVal = lower - v[i];
            int maxVal = upper - v[i];

            // 틀렸습니다 원인 나와 Pair될 수는 나 + 1부터 검사
            int maxIdx = upper_bound(v.begin() + i + 1, v.end(), maxVal) - v.begin();
            int minIdx = lower_bound(v.begin() + i + 1, v.end(), minVal) - v.begin();

            ans += (maxIdx - minIdx);            
        }
        return ans;
    }
};