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
    void solve(TreeNode* left,TreeNode* right, int l){
        if(!left || !right){
            return;
        }
        l++;
        
        if(l%2){
            int t = left->val;
            left->val = right->val;
            right->val = t;
        }
        solve(left->left,right->right,l);
        solve(left->right,right->left,l);
        
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        solve(root->left,root->right,0);
        return root;
    }
};