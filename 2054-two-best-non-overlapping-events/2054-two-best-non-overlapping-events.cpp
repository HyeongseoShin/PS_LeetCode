/*
우선순위 큐 이용

*/
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end()); // 이벤트를 시작시간 기준 오름차순 정렬

        // <종료시간, value> 오름차순 우선순위 큐 minHeap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

        int ans = 0;
        int maxVal = 0;

        for(auto& event: events)
        {
            int st = event[0], en = event[1], v = event[2];

            // 현재 이벤트 시작 전에 끝나는 이벤트를 pq.pop()
            // 이 중 value가 가장 높은 이벤트의 value값을 저장
            while(!pq.empty() && pq.top().first < st)
            {
                maxVal = max(maxVal, pq.top().second);
                pq.pop();
                // cout << "maxVal: " << maxVal << "\n";

            }

            // cout << "ans: " << ans << " maxVal: " << maxVal << " v: " << v << "\n";

            // 현재 정답 vs 현재 이벤트 시작 전 가장 높은 value + 현재 value 값 비교
            ans = max(ans, maxVal + v);
            pq.push({en, v});
        }

        return ans;

    }
};