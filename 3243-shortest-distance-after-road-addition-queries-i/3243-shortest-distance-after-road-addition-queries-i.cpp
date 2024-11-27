/*
최단거리 구하는 알고리즘
뒤로가는 경우는 없음!
그냥 BFS;;

다익스트라
플로이드 (정점 1000개까지 가능) => 시간초과남
*/
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> adj[502]; // 인접리스트

        int dst[502]; // 최단거리

        // 테스트 케이스를 보니 현재 도시보다 앞 도시로 가는 경우는 없음
        for(int i = 0; i < n - 1; i++)
        {
            adj[i].push_back(i+1);
        }

        int sz = (int)queries.size();

        for(int i = 0; i < sz; i++)
        {
            int u = queries[i][0];
            int v = queries[i][1];

            adj[u].push_back(v);

            // BFS 진행
            fill(dst, dst + n, -1);
            dst[0] = 0;

            queue<int> q;

            q.push(0);

            while(!q.empty())
            {
                int cur = q.front();
                q.pop();

                for(auto nxt: adj[cur])
                {
                    if(dst[nxt] != -1) continue;
                    dst[nxt] = dst[cur] + 1;
                    q.push(nxt);
                }
            }

            ans.push_back(dst[n-1]);
        }

        return ans;
    }
};