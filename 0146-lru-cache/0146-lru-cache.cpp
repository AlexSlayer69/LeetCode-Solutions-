class Node{
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int k,int v){
        key = k;
        val = v;
        next = NULL;
        prev = NULL;
    }
};


class LRUCache {
public:
    unordered_map<int,Node*> mp;
    int cap;
    int curr;
    
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    void remove(Node* node){
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    void insert(Node* node){
        Node* temp;
        temp = head->next;
        head->next = node;
        node->prev = head;
        temp->prev = node;
        node->next = temp;
    }

    LRUCache(int capacity) {
        cap = capacity;
        curr = 0;
        head->next = tail;
        head->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        remove(mp[key]);
        insert(mp[key]);
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        Node* node = new Node(key,value);
        insert(node);
        mp[key] = node;
        if(curr < cap) curr++;
        else{
            mp.erase(tail->prev->key);
            remove(tail->prev);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */