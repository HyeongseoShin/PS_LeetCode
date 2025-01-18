/*
0 - 1 BFS
*/
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        int m = (int)grid[0].size();

        // 최단 거리 배열 초기화
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        deque<pair<int, int>> dq;
        
        dq.push_front({0, 0});
        dist[0][0] = 0;

        while(!dq.empty())
        {
            auto [curX, curY] = dq.front();
            dq.pop_front();

            int curDir = grid[curX][curY] - 1;

            for(int i = 0; i < 4; i++)
            {
                int nX = curX + dx[i];
                int nY = curY + dy[i];

                if(nX < 0 || nX >= n || nY < 0 || nY >= m)
                {
                    continue;
                }

                // cost = 지금까지 오면서 방향을 바꾼 횟수
                int cost = dist[curX][curY] + (curDir == i ? 0 : 1);
                
                // {nX, nY} 까지 오는 데에 원래 경로보다 더 적게 방향을 바꿨으면 Update
                if(cost < dist[nX][nY])
                {
                    dist[nX][nY] = cost;

                    // 바꾸는 방향 횟수를 최소화하기 위해 원래 방향과 같은 grid를 먼저 방문
                    if(curDir == i) dq.push_front({nX, nY}); 

                    // 바꾸는 방향 횟수를 최소화하기 위해 원래 방향과 다른 grid는 나중에 방문
                    else dq.push_back({nX, nY});
                }
            }
        }

        return dist[n-1][m-1];
    }
};