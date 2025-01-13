class Solution {
public:
    int minimumLength(string s) {
        int freq[26];
        int n = s.length();
        int ans = n;
        
        for(int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++)
        {
            while(freq[i] >= 3)
            {
                freq[i] -= 2;
                ans -= 2;
            }
        }

        return ans;
    }
};