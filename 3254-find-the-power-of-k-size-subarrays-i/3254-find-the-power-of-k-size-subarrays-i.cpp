/*
n의 범위가 적어서 이중 for문으로 구현
*/
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        int n = (int)nums.size();

        for(int i = 0; i < n - k + 1; i++)
        {
            int maxVal = nums[i];
            for(int j = 0; j < k - 1; j++)
            {
                if(nums[i+j] < nums[i+j+1] && nums[i+j+1] - nums[i+j] < 2)
                {
                    maxVal = nums[i+j+1];
                }
                else
                {
                    maxVal = -1;
                    break;
                }
            }
            ans.push_back(maxVal);
        }

        

        return ans;
    }
};