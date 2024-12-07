/*
이분탐색 Binary Search

nums안에 있는 수를 maxOperations 횟수 안에 나눠서 만들 수 있는 가장 큰 수의 최솟값

*/
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end()); // 최댓값 저장

        // Binary Search 진행
        while(low < high)
        {
            int mid = low + (high - low) / 2;
            int ops = 0; // 현재 가방 나누기 진행 횟수

            // 현재 num의 값을 순회하며 maxOperations 횟수 안에 mid로 만들 수 있는지 확인
            for(int n : nums)
            {
                // maxOperations과의 원활한 비교를 위해 n - 1 사용
                // 예) 4에서 4를 만들기 n / mid => 1회, (n - 1) / mid => 0회
                ops += (n - 1) / mid; 
                if(ops > maxOperations) break;
            }

            ops <= maxOperations ? high = mid: low = mid + 1;
        }

        return high;
    }
};