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
    TreeNode* bst(vector<int>&preorder,int ps, int pe){
        if(ps > pe){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[ps]);
        int temp = pe;
        for(int i = ps + 1; i <= pe; i++){
            if(preorder[i] > preorder[ps]){
                temp = i - 1;
                break;
            }
        }
        root->left = bst(preorder, ps + 1, temp);
        root->right = bst(preorder, temp + 1, pe);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bst(preorder, 0, preorder.size() - 1);
    }
};