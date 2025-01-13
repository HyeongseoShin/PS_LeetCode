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
            if(freq[i] > 2)
            {
                if(freq[i] % 2 == 1) ans -= (freq[i] - 1);
                
                else ans -= (freq[i] - 2);
            }
        }

        return ans;
    }
};