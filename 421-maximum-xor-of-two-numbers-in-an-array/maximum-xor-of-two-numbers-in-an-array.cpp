struct Node {
    Node* link[2];

    bool contains(char ch) { 
        return link[ch - '0'] != NULL;
    }
    void put(char ch, Node* node) {
        link[ch - '0'] = node;
     }
    Node* get(char ch){
        return link[ch - '0'];
    }
};
class Solution {
public:
    void insert(string s, Node* root){
        Node* node = root;
        for(char ch : s){
            if(!node->contains(ch)){
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
    }
    string conversion(int n) {
        string s = "00000000000000000000000000000000";
        for (int i = 31; i >= 0; i--) {
            if (n & 1) {
                s[i] = '1';
            }
            n = n / 2;
        }
        return s;
    }
    int strToInt(string s){
        int n = 0;
        for(int i = 0; i < 32; i++){
            n += s[i] == '1' ? 1 << (31-i) : 0;
        }
        return n;
    }
    int findMaximumXOR(vector<int>& nums) {
        vector<string> vs;
        Node* root = new Node();
        for (int x : nums) {
            string s = conversion(x);
            vs.push_back(s);
            insert(s,root);
        }
        string ans="00000000000000000000000000000000";
        for(string s : vs){
            Node* node = root;
            string t = "00000000000000000000000000000000";
            for(int i = 0; i < 32; i++){
                if(s[i] == '0' && node->contains('1')){
                    t[i] = '1';
                    node = node->get('1');
                }
                else if(s[i] == '1' && node->contains('0')){
                    t[i] = '1';
                    node = node->get('0');
                }
                else{
                    node = node->get(s[i]);
                }
            }
            if(t>ans){
                ans = t;
            }
        }
        return strToInt(ans);
    }
};