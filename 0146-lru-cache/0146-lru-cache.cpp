class LRUCache {
public:
    class node{
        public:
        int key;
        int val;
        node* next;
        node* prev;

        node(int _key, int _val){
            key = _key;
            val = _val;
        }

    };

    void deleteNode(node* delnode){
        node* delprev = delnode->prev;
        node* delnext = delnode->next;

        delprev->next = delnext;
        delnext->prev= delprev;
    }
    void insertAfterHead(node* insert){
        node* temp = head->next;
        insert->next = temp;
        insert->prev = head;
        head->next = insert;
        temp->prev = insert;
    }

    map<int,node*>mpp;
    int cap;
    node* head= new node(-1,-1);
    node* tail = new node(-1,-1);

    LRUCache(int capacity) {
        cap = capacity;
        while (!mpp.empty()) { 
            auto it = mpp.begin(); 
            mpp.erase(it); 
        }
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mpp.find(key) != mpp.end()){
            node* getnode = mpp[key];
            mpp.erase(key);
            deleteNode(getnode);
            insertAfterHead(getnode);
            mpp[key] = head->next;
            return getnode->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            node* extnode = mpp[key];
            mpp.erase(key);
            deleteNode(extnode);
        }
        if(mpp.size() == cap){
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        insertAfterHead(new node(key,value));
        mpp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */