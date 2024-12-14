/*
슬라이딩 윈도우 + Deque
*/
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = 0;
        int n = (int)nums.size();

        int l = 0;
        deque<int> minDq; // front()에 슬라이딩 윈도우 범위 내에 최솟값 저장
        deque<int> maxDq; // front()에 슬라이딩 윈도우 범위 내에 최댓값 저장

        for(int r = 0; r < n; r++)
        {
            // 현재 front()보다 nums[r]이 작으면 이전 최솟값 pop
            while(!minDq.empty() && nums[minDq.back()] >= nums[r]) minDq.pop_back();

            // 현재 front()보다 nums[r]이 크면 이전 최댓값 pop
            while(!maxDq.empty() && nums[maxDq.back()] <= nums[r]) maxDq.pop_back();

            minDq.push_back(r);
            maxDq.push_back(r);

            // 슬라이딩 윈도우 범위 내에 최댓값 - 최솟값이 2보다 클 때까지
            // l 업데이트
            // l보다 인덱스가 작은 최소 / 최대값 삭제
            while(nums[maxDq.front()] - nums[minDq.front()] > 2)
            {
                l++;
                if(minDq.front() < l) minDq.pop_front();
                if(maxDq.front() < l) maxDq.pop_front();
            }

            ans += r - l + 1;

            // cout << "ans: " << ans << " l : " << l << " r: " << r << "\n";

        }
        
        return ans;
    }
};