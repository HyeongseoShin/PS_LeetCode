/*
Prefix 이용
*/

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = (int)nums.size();
        int q = (int)queries.size();

        vector<int> prefix(n, 0); // 현재 수와 이전 수가 같은 성질인지 아닌지 판별하기 위해 필요함

        for(int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i-1];

            // 이전 수와 현재 수의 성질이 같다 (짝수 - 짝수 or 홀수 - 홀수)
            // 이를 톨해 알 수 있는 것
            // prefix[end] == prefix[st] ==> st ~ end 구간 안에 (짝수 - 짝수) or (홀수 - 홀수)가 없는 것을 알 수 있음
            if(nums[i-1] % 2 == nums[i] % 2)
            {
                prefix[i]++;
            }
        }

        vector<bool> result;

        for(int i = 0; i < q; i++)
        {
            int st = queries[i][0];
            int en = queries[i][1];

            if(prefix[st] == prefix[en]) result.push_back(true);
            else result.push_back(false);
        }

        return result;
    }
};