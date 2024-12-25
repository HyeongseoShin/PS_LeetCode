/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> ans;

    void GetMaxVal(TreeNode* node, int row)
    {
        if(node == NULL) return;
        
        if(ans.size() < row + 1) ans.push_back(node->val);
        
        else ans[row] = max(ans[row], node->val);

        GetMaxVal(node->left, row + 1);
        GetMaxVal(node->right, row + 1);
    }
    
    vector<int> largestValues(TreeNode* root) {
        GetMaxVal(root, 0);
        return ans;
    }
};