/*
0-1 BFS
가중치가 0 or 1인 그래프에서 최단 경로를 찾는 알고리즘
Queue대신 Deque를 사용함!

현재 위치까지의 최단거리 + 가중치 < 다음 위치까지의 최단거리
=> 다음 위치까지의 최단거리 업데이트

가중치 => 0 ---> dq.push_front()
가중치 => 1 ---> dq.push_back()

-- 벽이 없는 곳을 최대한 먼저 가는 느낌??
-- 벽이 있으면 나중에 가는 느낌??
*/

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        vector<vector<int>> dst(m, vector<int>(n, 100001));

        // 0 - 1 BFS 진행
        deque<pair<int, int>> dq;
        dq.push_front({0, 0});
        dst[0][0] = 0;

        while(!dq.empty())
        {
            int curX = dq.front().first;
            int curY = dq.front().second;
            dq.pop_front();

            for(int i = 0; i < 4; i++)
            {
                int nX = curX + dx[i];
                int nY = curY + dy[i];

                if(nX < 0 || nY < 0 || nX >= m || nY >= n) continue;
                
                int newDst = dst[curX][curY] + grid[nX][nY]; // 새로운 경로

                // 경로 업데이트
                if(newDst < dst[nX][nY])
                {
                    dst[nX][nY] = newDst;
                    if(grid[nX][nY] == 0) dq.push_front({nX, nY});
                    else dq.push_back({nX, nY});
                }
            }
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << dst[i][j] << " ";
            }
            cout << "\n";
        }

        return dst[m-1][n-1];
    }
};