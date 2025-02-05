class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2) return true;

        int n = s1.length();
        int cnt = 0;

        vector<int> diff;

        // 문자열 비교하며 문자가 다른 좌표를 구함
        for(int i = 0; i < n; i++)
        {
            if(s1[i] != s2[i]) diff.push_back(i);
        }

        if(diff.size() != 2) return false; // 좌표가 다른 곳이 두 곳이 아니면 불가능

        // 좌표가 다른 한 곳과 다른 곳의 문자와 비교 후 같으면 true
        return (s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]]);
    }
};