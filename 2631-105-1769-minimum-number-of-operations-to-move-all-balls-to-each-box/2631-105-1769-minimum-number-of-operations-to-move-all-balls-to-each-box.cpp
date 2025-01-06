class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans;
        vector<int> idx;
        int n = (int)boxes.length();

        for(int i = 0; i < n; i++)
        {
            if(boxes[i] == '1') idx.push_back(i);
        }

        for(int i = 0; i < n; i++)
        {
            int cnt = 0;
            for(int j = 0; j < (int)idx.size(); j++)
            {
                cnt += abs(i - idx[j]);
            }

            ans.push_back(cnt);
        }
        return ans;
    }
};