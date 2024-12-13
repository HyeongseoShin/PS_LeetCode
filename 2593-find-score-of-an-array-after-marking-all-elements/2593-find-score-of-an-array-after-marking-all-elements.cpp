class Solution {
public:
    struct cmp
    {
        bool operator()(pair<int, int> A, pair<int, int> B)
        {
            if(A.first != B.first)
            {
                return A.first > B.first;
            }
            else
            {
                return A.second > B.second;
            }
        }
    };
    
    long long findScore(vector<int>& nums) {
        long long sum = 0;
        int n = (int)nums.size();
        vector<bool> vis (n, false);

        priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> pq;

        for(int i = 0; i < n; i++)
        {
            pq.push({nums[i], i});
        }

        while(!pq.empty())
        {
            int val = pq.top().first;
            int idx = pq.top().second;

            pq.pop();

            if(vis[idx])
            {
                continue;
            }

            vis[idx] = true;

            if(idx < n - 1) vis[idx + 1] = true;
            if(idx > 0) vis[idx - 1] = true;

            sum += val;
        }

        return sum;
    }
};