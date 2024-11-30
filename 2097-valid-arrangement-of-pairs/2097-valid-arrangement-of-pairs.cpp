/*
그래프로 변환해서 DFS 진행
Euler Path 라네요
vector는 push_back(), pop_back() 가능
*/

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        
        // vector<int> adj[100002];
        // 위의 방식으로 안되는 이유 node의 범위가 0 ~ 10^9라서 안 쓰이는 노드들이 너무 많음
        
        unordered_map<int, vector<int>> adj; // 그래프를 인접리스트로 표현
        unordered_map<int, int> inOutDegree;

        int n = (int)pairs.size();

        for(int i = 0; i < n; i++)
        {
            int u = pairs[i][0];
            int v = pairs[i][1];

            adj[u].push_back(v);

            inOutDegree[pairs[i][0]]++; // outDegree
            inOutDegree[pairs[i][1]]--; // inDegree
        }

        // 첫 시작 노드 정하기
        int start = pairs[0][0];

        // inOutDegree를 unordered_map으로 둔 이유
        // 노드의 번호가 n보다 클 수 있기 때문에 배열로 지정 시 빈 공간이 생겨 for문 돌 때 매우 비효율적
        for(auto [node, degree]: inOutDegree)
        {
            // in-outDegree 상쇄 후 outDegree가 하나만 있으면 시작 노드로 선정
            if(degree == 1)
            {
                start = node;
                break;
            }
        }

        vector<int> path; // 지나온 경로 저장

        stack<int> stk; // DFS 위한 stack
        stk.push(start);

        // DFS 진행
        while(!stk.empty())
        {
            int cur = stk.top();

            auto& neighbors = adj[cur];

            // 현재 노드에서 outDegree가 없는 경우
            if(neighbors.empty())
            {
                path.push_back(cur); // 현재 노드에서 갈 수 있는 곳이 없어서 마지막임을 표시
                stk.pop();
            }
            
            // 현재 노드에서 outDegree가 있는 경우
            else
            {
                // 인접리스트에서 가장 뒤의 노드 방문
                int nxt = neighbors.back();
                stk.push(nxt);
                neighbors.pop_back(); // 방문 표시를 위해 해당 노드 삭제
            }
        }

        // 도착점 ~ 시작점 순서로 저장되어 있어서 reverse로 순서 변경
        // 시자점 ~ 도착점
        reverse(path.begin(), path.end());

        vector<vector<int>> ans;

        for(int i = 0; i < (int)path.size() - 1; i++)
        {
            ans.push_back({path[i], path[i+1]});
        }

        return ans;
    }
};