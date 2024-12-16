class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k--)
        {
            int minIdx = min_element(nums.begin(), nums.end()) - nums.begin();
            nums[minIdx] *= multiplier;
        }
        return nums;
    }
};