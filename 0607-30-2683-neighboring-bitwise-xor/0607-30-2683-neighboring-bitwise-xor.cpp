class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = (int) derived.size();
        vector<int> origin(n, 0);

        for(int i = 0; i < n - 1; i++)
        {
            if(derived[i] == 0)
            {
                origin[i+1] = origin[i];
            }

            else
            {
                if(origin[i] == 0) origin[i+1] = 1;
                else origin[i+1] = 0;
            }
        }

        if((derived[n-1] == 0 && origin[0] != origin[n-1]) || derived[n-1] == 1 && origin[0] == origin[n-1])
        {
            return false;
        }

        return true;
    }
};