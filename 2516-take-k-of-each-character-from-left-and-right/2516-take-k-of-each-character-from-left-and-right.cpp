/*
슬라이딩 윈도우
*/

class Solution {
public:
    int takeCharacters(string s, int k) {
        if(k == 0) return 0;

        int cnt[3] = {0, 0, 0}; // 총 a, b, c의 개수
        int n = (int)s.length();

        for(int i = 0; i < s.length(); i++)
        {
            int idx = s[i] - 'a';
            cnt[idx]++;
        }

        // a, b, c의 개수 중 k보다 작은 값이 있으면 -1 리턴
        for(int i = 0; i < 3; i++)
        {
            if(cnt[i] < k) return -1;
        }

        int ans = INT_MAX;
        int l = 0, r = 0;

        int curCnt[3] = {0, 0, 0}; // 현재 a, b, c의 개수

        while(r < n)
        {
            int rIdx = s[r] - 'a';
            curCnt[rIdx]++;
            r++;

            while(curCnt[0] > cnt[0] - k || curCnt[1] > cnt[1] - k || curCnt[2] > cnt[2] - k)
            {
                int lIdx = s[l] - 'a';
                curCnt[lIdx]--;
                l++;
            }

            // 전체 길이 - (l ~ r) = (시작점 ~ l까지 + r ~ 끝점까지)
            ans = min(ans, n - (r - l));
        }

        return ans;
    }
};