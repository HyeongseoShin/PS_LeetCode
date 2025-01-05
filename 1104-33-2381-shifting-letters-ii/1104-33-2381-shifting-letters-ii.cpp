/*
Prefix 사용
하나하나씩 반복문 돌면 시간 초과남
*/

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = (int) s.length();
        vector<int> v(n, 0);

        for(int i = 0; i < (int)shifts.size(); i++)
        {
            int st = shifts[i][0];
            int en = shifts[i][1];
            int dir = shifts[i][2] == 1 ? 1 : -1;

            v[st] += dir;

            if(en + 1 < n) v[en + 1] -= dir;
        }

        string result(n, ' ');

        int cnt = 0;
        for(int i = 0; i < (int)v.size(); i++)
        {
            cnt = (cnt + v[i]) % 26;

            if(cnt < 0) cnt += 26;

            result[i] = 'a' + (s[i] - 'a' + cnt) % 26;
        }
        

        return result;
    }
};