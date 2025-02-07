class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        
        vector<int> ans;
        
        map<int, int> balls;
        unordered_map<int, int> distinct;

        int n = queries.size();

        int cnt = 0;

        for(int i = 0; i < n; i++)
        {
            int idx = queries[i][0];
            int color = queries[i][1];

            if(balls[idx] != 0)
            {
                distinct[balls[idx]]--;

                if(distinct[balls[idx]] == 0)
                {
                    distinct.erase(balls[idx]);
                }
            }

            balls[idx] = color;
            distinct[color]++;

            ans.push_back(distinct.size());   
        }

        return ans;
    }
};