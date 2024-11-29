/*
가중치 있는 그래프라서 다익스트라 사용
방문했던 곳을 다시 방문 가능
==> 실제 방문하지 않고 방문했다 치고 시간 ++
*/

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        // 처음부터 진행할 수 없는 경우 예외처리
        if(grid[0][1] > 1 && grid[1][0] > 1) return -1;

        int m = (int)grid.size();
        int n = (int)grid[0].size();

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        vector<vector<bool>> vis(m, vector<bool>(n, false)); // 방문 확인 배열
        vis[0][0] = true;

        // 다익스트라를 위한 우선순위 큐 (minHeap) <셀에 있는 시간, <x, y>>
        priority_queue<pair<int, pair<int, int>>, 
                            vector<pair<int, pair<int, int>>>,
                            greater<pair<int, pair<int, int>>>> pq;
        
        pq.push({0, {0, 0}});

        while(!pq.empty())
        {
            int curTime = pq.top().first;
            int curX = pq.top().second.first;
            int curY = pq.top().second.second;

            pq.pop();

            // 도착지점 도달 시 종료
            if(curX == m - 1 && curY == n - 1) return curTime;

            for(int i = 0; i < 4; i++)
            {
                int nX = curX + dx[i];
                int nY = curY + dy[i];

                if(nX < 0 || nY < 0 || nX >= m || nY >= n) continue;
                if(vis[nX][nY] == true) continue;

                // 인접한 칸과의 차이가 짝수 ==> 칸에 적힌 시간 + 1일때 갈 수 있음
                // 인접한 칸과의 차이가 홀수 ==> 칸에 적힌시간일때 갈 수 있음
                int waitTime = ((grid[nX][nY] - curTime) % 2 == 0) ? 1 : 0;

                // 현재 시간 + 1 vs 인접한 칸에 적혀있는 시간 + 기다려야하는 시간 중 큰 수
                int nextTime = max(curTime + 1, grid[nX][nY] + waitTime);

                pq.push({nextTime, {nX, nY}});
                vis[nX][nY] = true;
            }
        }

        return -1;

    }
};