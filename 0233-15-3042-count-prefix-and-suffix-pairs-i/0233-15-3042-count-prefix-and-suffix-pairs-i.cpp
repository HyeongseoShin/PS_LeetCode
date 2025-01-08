class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = (int)words.size();
        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(words[i].length() > words[j].length()) continue;

                if(words[j].find(words[i]) == 0 && words[j].rfind(words[i]) == words[j].length() - words[i].length())
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};