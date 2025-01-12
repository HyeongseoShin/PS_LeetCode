/*
그냥 '('와 unlocked ')'을 구분하여 stack에 저장하기

stack에는 index 저장
*/
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();

        stack<int> openBrackets, unlocked;

        if(n % 2 == 1) return false;

        for(int i = 0; i < n; i++)
        {
            if(locked[i] == '0') unlocked.push(i);

            else
            {
                if(s[i] == '(') openBrackets.push(i);

                // locked == 1인 '('부터 먼저 처리하기
                else if(!openBrackets.empty()) openBrackets.pop();

                else if(!unlocked.empty()) unlocked.pop();
                
                else return false;
                
            }
        
        }

        while(!openBrackets.empty() && !unlocked.empty() && openBrackets.top() < unlocked.top())
        {
            openBrackets.pop();
            unlocked.pop();
        }

        if(!openBrackets.empty()) return false;
                
        return true;
    }
};