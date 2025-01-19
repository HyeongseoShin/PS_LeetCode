/*
BFS + Prioirty_Queue
*/
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        int ans = 0;

        vector<vector<int>> vis (m, vector<int>(n, 0));

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        // 테두리 pq 삽입
        for(int j = 0; j < n; j++)
        {
            pq.push({heightMap[0][j], 0, j});
            pq.push({heightMap[m - 1][j], m - 1, j});

            vis[0][j] = 1;
            vis[m-1][j] = 1;
        }

        for(int i = 1; i < m - 1; i++)
        {
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][n - 1], i, n - 1});

            vis[i][0] = 1;
            vis[i][n-1] = 1;
        }


        // 현재 가장 낮은 테두리의 셀의 인접 셀과 높이 비교 후 물 채우고 상황 업데이트
        while(!pq.empty())
        {
            auto [curHeight, curX, curY] = pq.top();
            pq.pop();

            for(int i = 0; i < 4; i++)
            {
                int nX = curX + dx[i];
                int nY = curY + dy[i];

                if(nX < 0 || nX > m - 1 || nY < 0 || nY > n - 1 || vis[nX][nY] != 0)
                {
                    continue;
                }

                // 현재 테두리보다 인접한 셀의 높이가 낮으면
                if(heightMap[curX][curY] > heightMap[nX][nY])
                {
                    ans += (heightMap[curX][curY] - heightMap[nX][nY]); // 높이가 같도록 물 채우기
                    heightMap[nX][nY] = heightMap[curX][curY]; // 셀 높이 업데이트
                    
                }

                pq.push({heightMap[nX][nY], nX, nY}); // pq 삽입
                vis[nX][nY] = 1; // 방문 확인
            }
        }

        return ans;
    }
};