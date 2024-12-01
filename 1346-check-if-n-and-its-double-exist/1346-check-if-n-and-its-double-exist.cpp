/*
원래 unordered_map으로 했으나 시간 줄이려
unordered_set으로 변경
*/
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> us;

        for(int i = 0; i < (int)arr.size(); i++)
        {
            int cur = arr[i];
            // 하나의 for문만 사용하기 위해
            // 나누기 2, 곱하기 2 한 값 동시에 확인하기
            if(us.count(cur * 2) || (cur % 2 == 0 && us.count(cur / 2)))
            {
                return true;
            }
            us.insert(cur);
        }

        return false;
    }
};