/*
우선순위 큐 이용
*/
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double ans = 0;

        // <extraStudents가 투입되었을 때의 평균 - 현재 평균, 현재 pass, 현재 total>
        priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>> pq;

        int n = (int)classes.size();
        
        // extraStudents가 투입되었을 때 평균 상승량이 가장 큰 학급에 extraStudents 투입
        for(int i = 0; i < n; i++)
        {
            double newPr = (double)(classes[i][0] + 1) / (classes[i][1] + 1);
            double curPr = (double)classes[i][0] / classes[i][1];

            ans += curPr;
            pq.push({newPr - curPr, classes[i][0], classes[i][1]});
        }

        while(extraStudents--)
        {
            auto [pr, p, t] = pq.top();
            pq.pop();

            double newPr = (double)(p+2) / (t+2);
            double curPr = (double)(p+1) / (t+1);
            
            ans -= (double)p / t;
            ans += curPr;
            
            pq.push({newPr - curPr, p+1, t+1});
        }

        return (double)ans / n;
    }
};