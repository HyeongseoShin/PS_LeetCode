class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = (int)nums.size();
        int ans = 0;

        unordered_map<int, int> um;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i != j)
                {
                    um[(nums[i] * nums[j])]++;
                }
            }
        }

        for(auto [x, frq] : um)
        {
            if(frq >= 4)
            {
                frq /= 2;
                ans += ((frq) * (frq - 1) * 4);
            }
        }

        return ans;
    }
};