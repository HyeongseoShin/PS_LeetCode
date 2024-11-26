/*
DFS인줄 알았으나 쓸 필요도 없음
나로 들어오는 incoming edge가 0이고 유일한 노드일 때 (중복 X)
*/
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int ans = -1;
        vector<int> cnt;
        cnt.resize(n);

        fill(cnt.begin(), cnt.end(), 0);

        // 현재 노드로 들어오는 incoming edge 수 계산
        for(auto edge : edges) cnt[edge[1]]++;

        for(int i = 0; i < n; i++)
        {
            if(cnt[i] == 0)
            {
                // 챔피언이 여러명일 수 없음
                if(ans != -1) return -1;
                ans = i;
            }
        }

        return ans;
    }
};