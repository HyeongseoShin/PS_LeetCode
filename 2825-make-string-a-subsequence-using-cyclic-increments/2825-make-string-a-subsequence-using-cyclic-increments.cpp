/*
투포인터
Subsequence -> 나오는 순서는 유지가 되어야함
예) abc , ac => OK
    abc, ca => X
*/
class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        bool ans = false;

        int n = str1.length();
        int m = str2.length();

        int idx1 = 0;
        int idx2 = 0;

        int cnt = 0;
        while(idx1 < n && idx2 < m)
        {
            if(str1[idx1] == str2[idx2] || (str1[idx1] - 'a' + 1) % 26 + 'a' == str2[idx2])
            {
                idx2++;
                cnt++;
            }

            idx1++;
        }

        if(cnt == m) return true;
        else return false;

    }
};