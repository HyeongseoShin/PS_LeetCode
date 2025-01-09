class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        int n = (int)words.size();

        for(int i = 0; i < n; i++)
        {
            if(words[i].find(pref) == 0) ans++;
        }

        return ans;
    }
};