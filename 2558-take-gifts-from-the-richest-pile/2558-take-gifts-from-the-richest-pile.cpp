/*
우선순위 큐
*/
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        // accumulate: 배열 or vector에서 총합 구하는 기능
        // (시작, 끝, 초기값)
        // 초기값 설정시 자료형에 따라 선언해줄것 -> int : 0, long long : 0LL
        long long ans = accumulate(gifts.begin(), gifts.end(), 0LL);

        priority_queue<int> pq (gifts.begin(), gifts.end());

        while(k--)
        {
            int cur = pq.top();
            int sqrtCur = sqrt(cur);

            ans -= cur;
            ans += sqrtCur;

            pq.pop();
            pq.push(sqrtCur);
        }

        return ans;
    }
};