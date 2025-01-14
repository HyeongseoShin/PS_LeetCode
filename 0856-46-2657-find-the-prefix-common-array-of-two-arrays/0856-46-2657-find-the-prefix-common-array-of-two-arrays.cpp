class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans;

        vector<bool> check(n+1);

        for(int i = 0; i < n; i++)
        {
            int cnt = 0;

            check[B[i]] = true;

            for(int j = 0; j <= i; j++)
            {
                if(check[A[j]]) cnt++;
            }

            ans.push_back(cnt);
        }

        return ans;
    }
};