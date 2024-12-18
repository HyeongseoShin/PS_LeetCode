class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans;

        int n = (int)prices.size();

        for(int i = 0; i < n; i++)
        {
            bool isPossible = false;
            for(int j = i + 1; j < n; j++)
            {
                if(prices[j] <= prices[i])
                {
                    ans.push_back(prices[i] - prices[j]);
                    isPossible = true;
                    break;
                }
            }

            if(!isPossible)
            {
                ans.push_back(prices[i]);
            }
        }

        return ans;
    }
};