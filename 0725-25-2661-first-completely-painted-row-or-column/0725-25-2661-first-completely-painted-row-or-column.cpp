class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int ans = 0;

        unordered_map<int, pair<int, int>> pos;

        vector<int> visX(m, 0);
        vector<int> visY(n, 0);

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int cur = mat[i][j];

                pos[cur] = {i, j};
            }
        }

        for(int i = 0; i < m * n; i++)
        {
            auto [curX, curY] = pos[arr[i]];

            visX[curX]++;
            visY[curY]++;

            if(visX[curX] == n || visY[curY] == m) return i;
        }

        return arr.size() - 1;
    }
};