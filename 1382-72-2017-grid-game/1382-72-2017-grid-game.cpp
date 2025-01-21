// 구간 합 (Prefix Sum)
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();

        long long firstSum = 0;
        long long secondSum = 0;

        for(int i = 0; i < n; i++)
        {
            firstSum += grid[0][i];
        }

        long long ans = LLONG_MAX;
        for(int i = 0; i < n; i++)
        {
            firstSum -= grid[0][i];
            // 첫 번째 로봇의 목표는 자기 점수를 최대화 하는 게 아니라
            // 두 번째 로봇의 점수의 최댓값을 최소로 만드는 것
            // SecondSum이 더 커지는 순간 줄바꿈이 일어남
            // 따라서 FirSum의 남아있는 구간합이 두 번째 로봇이 얻을 수 있는 점수의 최댓값
            ans = min(ans, max(firstSum, secondSum));
            secondSum += grid[1][i];
        }

        return ans;
    }
};