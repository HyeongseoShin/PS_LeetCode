/*
DFS
*/
class Solution {
public:
    bool vis[200];
    vector<int> nums[200];
    int ans = -1;

    void DFS(int x)
    {
        ans++;
        for(auto nxt : nums[x])
        {
            if(vis[nxt]) continue;
            vis[nxt] = true;
            DFS(nxt);
        }
        
    }
    int findChampion(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < (int)edges.size(); i++)
        {
            nums[edges[i][0]].push_back(edges[i][1]);
        }

        for(int i = 0; i < n; i++)
        {
            ans = -1;
            fill(vis, vis + n, false);
            vis[i] = true;
            DFS(i);

            if(ans == n - 1) return i;
        }

        return -1;
    }
};