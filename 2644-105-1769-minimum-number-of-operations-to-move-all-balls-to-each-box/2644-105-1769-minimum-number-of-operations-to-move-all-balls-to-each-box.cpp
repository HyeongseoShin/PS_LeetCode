/*
투포인터 이용?
*/
class Solution {
public:
    vector<int> minOperations(string boxes) {
        // 내 답 => O(N^2)
        // int n = (int)boxes.length();

        // vector<int> ans;
        // vector<int> idx;

        // for(int i = 0; i < n; i++)
        // {
        //     if(boxes[i] == '1') idx.push_back(i);
        // }

        // for(int i = 0; i < n; i++)
        // {
        //     int sum = 0;
        //     for(int j: idx)
        //     {
        //         sum += abs(i - j);
        //     }
            
        //     ans.push_back(sum);
        // }
        // return ans;

        // 모범 답안 => O(N)
        int n = boxes.size();
        vector<int> answer(n, 0);

        int ballsToLeft = 0, movesToLeft = 0;
        int ballsToRight = 0, movesToRight = 0;

        // Single pass: calculate moves from both left and right
        for (int i = 0; i < n; i++) {
            // Left pass
            answer[i] += movesToLeft;
            ballsToLeft += boxes[i] - '0';
            movesToLeft += ballsToLeft;

            // Right pass
            int j = n - 1 - i;
            answer[j] += movesToRight;
            ballsToRight += boxes[j] - '0';
            movesToRight += ballsToRight;

        }

        return answer;
    }
};