/*
배열이 LIS가 되도록 제거해야하는 가장 짧은 길이의 SubArray구하기

SubArray - 연결되어있는 것

투 포인터 이용
시작점 ~ 현재 수보다 작은 수 나올 때까지
끝점 ~ 현재 수보다 큰 수 나올 때까지
*/
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = (int)arr.size();
        int l = 0;
        int r = n - 1;

        while(l < n - 1 && arr[l] <= arr[l + 1]) l++;

        // 이미 정렬 완료된 경우
        if(l == n - 1) return 0;

        while(r > 0 && arr[r] >= arr[r - 1]) r--;
        
        // r : 앞쪽 전체
        // n - l - 1: l ~ 끝까지
        // 둘 중 더 적게 지우는 것을 선택
        int ans = min(n - l - 1, r);

        int i = 0;
        int j = r;

        while(i <= l && j < n)
        {
            if(arr[i] <= arr[j])
            {
                // ans를 (i-1) ~ j까지 수의 개수로 계속 업데이트
                ans = min(ans, j - i - 1);
                i++;
            }
            else j++;
        }

        return ans;
    } 
};