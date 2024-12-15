class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double ans = 0;
        priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>> pq;

        int n = (int)classes.size();

        for(int i = 0; i < n; i++)
        {
            double newPr = (double)(classes[i][0] + 1) / (classes[i][1] + 1);
            double curPr = (double)classes[i][0] / classes[i][1];
            pq.push({newPr - curPr, classes[i][0], classes[i][1]});
        }

        while(extraStudents--)
        {
            auto [pr, p, t] = pq.top();
            pq.pop();

            // cout << "pr: " << pr << " p: " << p << " t: " << t << "\n";

            double newPr = (double)(p+2) / (t+2);
            double curPr = (double)(p+1) / (t+1);

            pq.push({newPr - curPr, p+1, t+1});
        }

        while(!pq.empty())
        {
            auto [pr, p, t] = pq.top();
            pq.pop();

            // cout << "p: " << p << " t: " << t << "\n";
            // cout << "res: " << (double)p / t << "\n";

            ans += (double)p / (double)t;

            // cout << "ans: " << ans << "\n";

            
        }

        

        return (double)ans / n;
    }
};