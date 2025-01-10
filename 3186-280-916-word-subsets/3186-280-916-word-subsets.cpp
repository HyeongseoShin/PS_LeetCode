class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;

        unordered_map<char, int> um;

        for(auto str : words2)
        {
            unordered_map<char, int> cur;

            for(auto c : str)
            {
                cur[c]++;
                um[c] = max(um[c], cur[c]);
            }
        }

        for(auto str : words1)
        {
            unordered_map<char, int> cur;

            for(auto c : str)
            {
                cur[c]++;
            }

            bool isOk = true;

            for(auto [ch, frq] : um)
            {
                if(cur[ch] < frq)
                {
                    isOk = false;
                    break;
                }
            }

            if(isOk) ans.push_back(str);
        }

        return ans;
    }
};