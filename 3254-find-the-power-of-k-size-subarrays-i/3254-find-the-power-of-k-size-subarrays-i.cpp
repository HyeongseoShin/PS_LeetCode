/*
n의 범위가 적어서 이중 for문으로 구현했다가
투포인터 + 슬라이딩 윈도우로 구현
*/
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        int n = (int)nums.size();

        // k == 1일때는 원본 배열 return
        if(k == 1)
        {
            return nums;
        }

        int l = 0;
        int r = 1;

        while(r < n)
        {
            // consecutive, sorted 아니면
            if(nums[r] - nums[r-1] != 1)
            {
                //l ~ r 사이의 시작 원소는 무조건 -1 대입
                while(l < r && l <= n - k)
                {
                    ans.push_back(-1);
                    l++;
                }
                l = r;
            }

            // l ~ r 개수가 k이면
            if(r - l + 1 == k)
            {   ans.push_back(nums[r]);
                l++;
            }

            r++;
        }

        // for(int i = 0; i < n - k + 1; i++)
        // {
        //     int maxVal = nums[i];
        //     for(int j = 0; j < k - 1; j++)
        //     {
        //         if(nums[i+j] < nums[i+j+1] && nums[i+j+1] - nums[i+j] < 2)
        //         {
        //             maxVal = nums[i+j+1];
        //         }
        //         else
        //         {
        //             maxVal = -1;
        //             break;
        //         }
        //     }
        //     ans.push_back(maxVal);
        // }

        return ans;
    }
};