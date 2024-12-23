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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int c=0;
        while(!q.empty()){
            
            int n = q.size();
            
            vector<int> v;
            map<int,int>m;
            for(int i = 0; i < n; i++){
                TreeNode* node = q.front();
                q.pop();
                v.push_back(node->val);
                m[node->val]=i;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            vector<int> t;
            t = v;
            sort(t.begin(),t.end());
            for(int i = 0; i < n; i++){
                if(t[i]!=v[i]){
                    c++;
                    v[m[t[i]]] = v[i];
                    m[v[i]]=m[t[i]];
                }
            }
            // cout<<c<<' ';
        }
        return c;
    }
};