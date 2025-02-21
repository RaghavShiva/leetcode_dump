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
class FindElements {
public:
    unordered_set<int> s;
    FindElements(TreeNode* root) {
        root->val = 0;
        queue<TreeNode*> q;
        q.push(root);
       
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
             s.insert(node->val);
            if(node->left){
                q.push(node->left);
                node->left->val = node->val*2+1;
            }
            if(node->right){
                q.push(node->right);
                node->right->val = node->val*2+2;
            }
        }
    }
    
    bool find(int target) {
        return s.find(target)!=s.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */