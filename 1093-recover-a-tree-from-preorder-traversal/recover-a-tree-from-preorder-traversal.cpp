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
    TreeNode* recoverFromPreorder(string traversal) {
        vector<pair<int,int>>v;
        int n = traversal.size();
        int c =0;
        for(int i = 0; i < n; i++){
            if(traversal[i]=='-'){
                c++;
            }
            else{
                int t = traversal.find('-',i);
                string s;
                if(t!=string::npos){
                    s = traversal.substr(i,t-i);
                }
                else{
                    t = n;
                    s = traversal.substr(i);
                }
                i = t-1;
                t = stoi(s);
                v.push_back({c,t});
                c=0;
            }
        }
        n = v.size();
        
        TreeNode* root = new TreeNode(v[0].second);
        int d = 0;
        stack<pair<TreeNode*,int>>s;
        s.push({root,0});
        for(int i = 1; i < n; i++){
            TreeNode* node = s.top().first;
            d = s.top().second;
            if(v[i].first>d){
                node->left = new TreeNode(v[i].second);
                s.push({node->left,v[i].first});
            }
            else if(v[i].first==d){
                s.pop();
                node = s.top().first;
                d = s.top().second;
                node->right = new TreeNode(v[i].second);
                s.push({node->right,v[i].first});
            }
            else{
                while(v[i].first<=d && !s.empty()){
                    s.pop();
                    d = s.top().second;
                    node = s.top().first;
                }
                node->right = new TreeNode(v[i].second);
                s.push({node->right,v[i].first});
            }
            cout<<d<<' ';
        }
        return root;
    }
};