class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long sum = 0;
        int n = (int)nums.size();
        
        vector<pair<int, int>> v;
        vector<bool> vis (n, false);

        for(int i = 0; i < n; i++)
        {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end());

        for(int i = 0; i < n; i++)
        {
            int val = v[i].first;
            int idx = v[i].second;

            if(vis[idx]) continue;

            vis[idx] = true;
            if(idx > 0) vis[idx - 1] = true;
            if(idx < n - 1) vis[idx + 1] = true;

            sum += val;
        }

        return sum;
    }
};