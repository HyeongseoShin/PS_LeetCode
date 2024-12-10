/*
투포인터로 special한 subString 구한 후
for문으로 전체 검사 (브루트 포스)
*/

class Solution {
public:
    int maximumLength(string s) {
        int ans = -1;

        int st = 0;
        int en = 0;

        vector<string> subString;

        // Special한 SubString 구하기
        while(st <= en && en < s.length())
        {
            string str;
            while(s[st] == s[en])
            {
                str += s[en];
                subString.push_back(str);
                en++;
            }

            st = en; 
        }

        sort(subString.begin(), subString.end(), greater<>());
        subString.erase(unique(subString.begin(), subString.end()), subString.end());

        for(int i = 0; i < subString.size(); i++)
        {
            cout << subString[i] << "\n";
        }

        for(int i = 0; i < subString.size(); i++)
        {
            int cnt = 0;
            for(int j = 0; j < s.length(); j++)
            {
                if(s[j] != subString[i][0]) continue;

                bool isPossible = true;

                if(j + subString[i].length() > s.length()) continue;

                for(int k = j; k < j + subString[i].length(); k++)
                {
                    if(s[k] != subString[i][k - j])
                    {
                        isPossible = false;
                    }
                }

                if(isPossible) cnt++;
            }

            if(cnt >= 3)
            {
                ans = max(ans, (int)subString[i].length());
            }
        }
        return ans;
    }
};