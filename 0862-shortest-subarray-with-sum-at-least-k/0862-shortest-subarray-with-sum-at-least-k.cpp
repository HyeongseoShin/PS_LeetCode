/*
구간합 + Deque 사용
*/


class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int ans = INT_MAX;
        int n = nums.size();
        long long sum = 0;

        deque<pair<long long, int>> dq; // dq<i,j> : j까지 총합은 i이다.

        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            
            // 0 ~ n-1까지 sum 구하는 도중 k이상인 적이 있다면 최소 길이 Update
            if(sum >= k) ans = min(ans, i + 1);

            // 현재 sum - dq.front()가 k보다 크면 => 시작점 + 1
            while(!dq.empty() && sum - dq.front().first >= k)
            {
                ans = min(ans, i - dq.front().second);
                dq.pop_front();
            }


            // deque은 오름차순으로 유지되어야 함 why?
            // 만약 sum - dq.first는 < k인데 sum - dq.second >= k인 경우가 발생할 수 있음!
            // 따라서 현재 sum보다 dq.back()이 크다면 미리미리 제거해주어야 함
            while(!dq.empty() && dq.back().first > sum)
            {
                dq.pop_back();
            }

            dq.push_back({sum, i});
        }

        if(ans == INT_MAX) ans = -1;

        return ans;
    }
};