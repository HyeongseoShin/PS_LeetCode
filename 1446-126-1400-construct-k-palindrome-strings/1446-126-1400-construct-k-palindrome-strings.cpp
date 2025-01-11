/*
k는 모든 문자를 써서 만들 수 있는 팰린드롬 문자의 개수

예) k == 2 가능한 경우: ㅁ + ㅁ
k == 3 가능한 경우: ㅁ + ㅁ + ㅁ
k == 4 가능한 경우: ㅁ + ㅁ + ㅁ + ㅁ
*/

class Solution {
public:
    bool canConstruct(string s, int k) {
        int cnt[26];
        int n = s.length();

        if(n < k) return false;

        for(int i = 0; i < n; i++)
        {
            cnt[s[i] - 'a']++;
        }

        int oddCnt = 0;
        int evenCnt = 0;

        for(int i = 0; i < 26; i++)
        {
            if(cnt[i] % 2 == 0 && cnt[i] != 0) evenCnt++;
            else if(cnt[i] % 2 == 1) oddCnt++;
        }

        if(oddCnt > k) return false;

        return true;
    }
};