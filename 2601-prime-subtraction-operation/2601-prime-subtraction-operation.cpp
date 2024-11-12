class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        bool isPrime[2000];
        fill(isPrime, isPrime + 2000, true);

        vector<int> primes;

        // 소수 찾기
        for(int i = 2; i * i <= 1000; i++)
        {
            for(int j = i * i; j <= 1000; j += i)
            {
                if(!isPrime[j]) continue;
                isPrime[j] = false;
            }
        }

        for(int i = 2; i <= 1000; i++)
        {
            if(isPrime[i]) primes.push_back(i);
        }

        // 뒤에서부터 검사
        for(int i = (int)nums.size() - 2; i >= 0; i--)
        {
            if(nums[i] >= nums[i+1])
            {
                // 현재 원소 - p < 다음원소인 p를 구하기
                int p = GetPrime(primes, nums[i], nums[i+1]);

                // 조건에 맞는 p가 없으면 실패
                if(p == nums[i]) return false;
                else
                {
                    nums[i] -= p;
                }
            }
        }

        for(int i = 0; i < (int)nums.size(); i++)
        {
            cout << nums[i] << " ";
        }
        cout << "\n";

        return true;
    }

private:
    int GetPrime(const vector<int>& primes, int cur, int target)
    {
        for(int prime: primes)
        {
            // cur - prime은 항상 0보다 커야함
            if(cur - prime > 0 && cur - prime < target)
            {
                return prime;
            }
        }

        return cur;
    }
};