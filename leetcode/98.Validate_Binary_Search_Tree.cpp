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
    bool isValidBST(TreeNode* root) {
        return check(root,LONG_MIN,LONG_MAX);
    }
    bool check(TreeNode* root,long min,long max)
    {
        if(!root) return true;
        if(root && root->val<=min) return false;
        if(root && root->val>=max) return false;
        return (check(root->left,min,root->val) && check(root->right,root->val,max) );
    }
};
