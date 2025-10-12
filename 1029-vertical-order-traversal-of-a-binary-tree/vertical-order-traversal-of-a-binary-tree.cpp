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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int,int,int>> store;
        queue<tuple<TreeNode*,int,int>>q;
        q.push({root,0,0});
        int mny=0,mxy=0;
        while(!q.empty()){
            auto[node,x,y] = q.front();
            q.pop();
            mny = min(mny,y);
            mxy = max(mxy,y);
            store.push_back({y,x,node->val});
            if(node->left){
                q.push({node->left,x+1,y-1});
            }
            if(node->right){
                q.push({node->right,x+1,y+1});
            }
        }
        sort(store.begin(),store.end());
        vector<vector<int>>ans(mxy-mny+1);
        for(auto[y,x,val]:store){
            ans[y-mny].push_back(val);
        }
        return ans;
    }
};