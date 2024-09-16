struct Node{
        Node* link[26];
        bool flag = false;

        bool contains(char ch){
            return link[ch-'a'] != NULL;
        }
        void put(char ch,Node* node){
            link[ch-'a'] = node;
        }
        Node* get(char ch){
            return link[ch-'a'];
        }
        void setEnd(){
            flag = true;
        }
        bool isSetEnd(){
            return flag;
        }
    };
class Trie {
public:
    Node* root;
    
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(char ch:word){
            if(!node->contains(ch)){
                node->put(ch,new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(char ch:word){
            if(!node->contains(ch)){
                return false;
            }
            node = node->get(ch);
        }
        return node->isSetEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(char ch:prefix){
            if(!node->contains(ch)){
                return false;
            }
            node = node->get(ch);
        }
        return true;
    }
    
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */