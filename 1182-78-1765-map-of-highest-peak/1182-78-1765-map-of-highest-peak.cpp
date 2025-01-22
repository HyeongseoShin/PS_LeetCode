/*
BFS
*/
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        vector<vector<int>> ans(m, vector<int>(n, -1));

        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(isWater[i][j]) 
                {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }

        while(!q.empty())
        {
            auto [curX, curY] = q.front();
            q.pop(); 

            for(int i = 0; i < 4; i++)
            {
                int nX = curX + dx[i];
                int nY = curY + dy[i];

                if(nX < 0 || nX > m - 1 || nY < 0 || nY > n - 1) continue;

                if(ans[nX][nY] != -1) continue;

                ans[nX][nY] = ans[curX][curY] + 1;
                q.push({nX, nY});
            }

        }

        return ans;
    }
};