class Solution {
public:
    bool CheckValid(int x, int y, int m, int n, vector<int>& visX, vector<int>& visY)
    {
        visX[x]++;
        visY[y]++;

        cout << "x: " << x << " visX[x]: " << visX[x] << " y: " << y << " visY[y]: " << visY[y] << "\n";

        if(visX[x] == n || visY[y] == m) return true;
        else return false;
    }
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int ans = 0;

        map<int, pair<int, int>> pos;

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

            if(CheckValid(curX, curY, m, n, visX, visY)) return i;
        }

        return ans;
    }
};