class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int ans = 0;
        vector<int> v;

        while(num1 > 0)
        {
            v.push_back(num1 % 2);
            num1 /= 2;
        }

        int cnt = 0;
        int n = 0;

        while(num2 > 0)
        {
            if(num2 % 2 == 1) cnt++;
            num2 /= 2;
            n++;
        }

        while(v.size() < n)
        {
            v.push_back(0);
        }

        while(v.size() > n)
        {
            n++;
        }

        reverse(v.begin(), v.end());

        for(int i = 0; i < n; i++)
        {
            if(v[i] == 1 && cnt > 0 || cnt > n - i - 1)
            {
                ans += pow(2, n - i - 1);
                cnt--;
            }
        }

        return ans;
    }
};