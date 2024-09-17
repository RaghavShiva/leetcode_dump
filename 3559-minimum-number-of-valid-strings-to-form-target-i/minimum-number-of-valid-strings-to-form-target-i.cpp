struct Node{
    Node* link[26];
    
    bool contains(char ch){
        return link[ch - 'a'] != NULL;
    }
    void put(char ch, Node* node){
        link[ch - 'a'] = node;
    }
    Node* get(char ch){
        return link[ch - 'a'];
    }
    
};
class Trie{
    public:
    Node* root;
        Trie(){
            root = new Node();
        }
        void insert(string &s){
            Node* node = root;
            for(char ch : s){
                if(!node->contains(ch)){
                    node->put(ch, new Node());
                }
                node = node->get(ch);
            }
        }
        vector<int> search(string &target, int i){
            vector<int> len;
            Node* node = root;
            for(int j = i; j < target.size(); j++){
                if(!node->contains(target[j])){
                    break;
                }
                node = node->get(target[j]);
                len.push_back(j - i + 1);
            }
            return len;
        }      
};
class Solution {
public:

    int minValidStrings(vector<string>& words, string target) {
         int ans = 0;
         Trie trie;
         for(string s : words){
            trie.insert(s);
         }
         int n = target.size();
         vector<int>dp(n + 1, INT_MAX);
         dp[0] = 0;
         for(int i = 0; i < n; i++){
            if(dp[i] == INT_MAX)
                continue;
            vector<int> len = trie.search(target, i);
            for(int l : len){
                dp[i + l] = min(dp[i] + 1,dp[i + l]);
            }
         }
         return dp[n] == INT_MAX ? -1 : dp[n];
    }
};