/*
우선순위 큐 이용
*/
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string ans;
        int n = (int)s.length();

        vector<int> freq(26, 0);
        priority_queue<pair<char, int>> pq;

        for(int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++)
        {
            if(freq[i] > 0)
            {
                pq.push({i + 'a', freq[i]});
            }
        }

        while(!pq.empty())
        {
            auto [curChar, curFreq] = pq.top();
            pq.pop();

            int cnt = min(curFreq, repeatLimit);

            // 현재 문자 repeatLimit or 남은 개수 중 작은 수만큼 정답뒤에 연결
            ans.append(cnt, curChar); // (횟수, 문자)
            curFreq -= cnt;

            // 현재 문자가 남아서 다음으로 큰 문자 하나 붙인 후 또 다시 붙여져야 한다면
            if(curFreq > 0)
            {
                if(pq.empty()) break;

                auto [nxtChar, nxtFreq] = pq.top();
                pq.pop();

                // 일단 그다음 큰 문자 덧붙이기
                ans += nxtChar;
                nxtFreq--;

                // 만약 그 다음 문자가 남은 게 없으면 pq에 넣지 않음
                if(nxtFreq > 0)
                {
                    pq.push({nxtChar, nxtFreq});
                }

                // 현재 문자의 남은 개수 업데이트
                pq.push({curChar, curFreq});
            }
        }


        return ans;
    }
};