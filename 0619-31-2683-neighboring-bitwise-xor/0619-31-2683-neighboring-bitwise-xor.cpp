class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = (int)derived.size();
        
        int tmp = derived[0];
        for(int i = 1; i < n; i++)
        {
            tmp ^= derived[i];
        }

        if(tmp == 0) return true;

        return false;
    }
};