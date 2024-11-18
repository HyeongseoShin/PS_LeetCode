class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans;
        int n = code.size();

        for(int i = 0; i < n; i++)
        {
            if(k == 0) 
            {
                ans.push_back(0);
                continue;
            }

            int sum = 0;

            if(k > 0)
            {
                for(int j = 1; j <= k; j++) sum += code[(i + j) % n];
            }

            else
            {
                for(int j = k; j <= -1; j++) sum += code[(i + n + j) % n];
            }

            ans.push_back(sum);
        }

        return ans;
    }
};