/*
반복문 한 번만에 공백 위치 찾으면 공백 추가 후 원래 문자 추가
*/

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int idx = 0;

        string ans;
        for(int i = 0; i < s.length(); i++)
        {
            if(idx < spaces.size() && i == spaces[idx])
            {
                ans += " ";
                idx++;
            }
            ans += s[i];
        }
        return ans;
    }
};