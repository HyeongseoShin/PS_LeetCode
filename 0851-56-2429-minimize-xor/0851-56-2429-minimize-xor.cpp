/*
비트 마스킹으로 풀어보기
*/
class Solution {
public:
    // 비트 마스킹을 이용해 1의 개수 구하기
    int GetOneCnt(int num)
    {
        int cnt = 0;
        while(num)
        {
            cnt += (num & 1);
            num >>= 1;
        }

        return cnt;
    }
    int minimizeXor(int num1, int num2) {
        // 비트 마스킹 사용
        int cnt = GetOneCnt(num2);
        int ans = 0;

        for(int i = 31; i >= 0 && cnt > 0; i--)
        {
            if(num1 & (1 << i) || cnt > i)
            {
                ans |= (1 << i);
                cnt--;
            }
        }

        return ans;

        // 비트 마스킹 안 쓴 방법
        // int ans = 0;
        // vector<int> v;

        // while(num1 > 0)
        // {
        //     v.push_back(num1 % 2);
        //     num1 /= 2;
        // }

        // int cnt = 0;
        // int n = 0;

        // while(num2 > 0)
        // {
        //     if(num2 % 2 == 1) cnt++;
        //     num2 /= 2;
        //     n++;
        // }

        // while(v.size() < n)
        // {
        //     v.push_back(0);
        // }

        // while(v.size() > n)
        // {
        //     n++;
        // }

        // reverse(v.begin(), v.end());

        // for(int i = 0; i < n; i++)
        // {
        //     if(v[i] == 1 && cnt > 0 || cnt > n - i - 1)
        //     {
        //         ans += pow(2, n - i - 1);
        //         cnt--;
        //     }
        // }

        // return ans;
    }
};