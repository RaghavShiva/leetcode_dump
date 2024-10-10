struct Node {
    int key, value;
    Node* next;
    Node* prev;
    Node(int k, int v) {
        key = k;
        value = v;
        next = nullptr;
        prev = nullptr;
    }
};
 class LRUCache {
public:
    Node *head, *tail;
    int cap;
    map<int, Node*> mp;
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node* node){
        Node* nex = head->next;
        head->next = node;
        node->prev = head;
        node->next = nex;
        nex->prev = node;
    }
    void deleteNode(Node* node){
        Node* nex = node->next;
        Node* pre = node->prev;
        pre->next = nex;
        nex->prev = pre;   
    }
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            deleteNode(node);
            addNode(node);
            mp[key] = head->next;
            return node->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            deleteNode(node);
            mp.erase(key);
        }
        else{
            if(cap == mp.size()){
                Node* node = tail->prev;
                mp.erase(node->key); 
                deleteNode(node);
                delete node;
            }
             
        }
        Node* node = new Node(key, value);
        addNode(node);
        mp[key] = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */