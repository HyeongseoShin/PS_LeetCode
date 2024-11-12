class Solution {

public:
    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        if(a.first != b.first) return a.first < b.first;
        else return a.second > b.second;
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<pair<int, int>> v;
        vector<int> ans;

        for(int i = 0; i < (int)items.size(); i++)
        {
            v.push_back({items[i][0], items[i][1]});
        }

        sort(v.begin(), v.end(), cmp);

        int maxBeauty = INT_MIN;
        for(int i = 0; i < (int)v.size(); i++)
        {
            maxBeauty = max(maxBeauty, v[i].second);
            v[i].second = maxBeauty;

        }

        for(int i = 0; i < (int)queries.size(); i++)
        {
            int idx = lower_bound(v.begin(), v.end(), make_pair(queries[i], 0)) - v.begin();

            if(idx == 0 && v[idx].first > queries[i])
            {
                ans.push_back(0);
                continue;
            }

            else if(idx >= (int)v.size() || (idx > 0 && v[idx].first > queries[i]))
            {
                idx--;
            }

            ans.push_back(v[idx].second);
            
        }

        return ans;
    }
};