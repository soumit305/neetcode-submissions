struct Node{
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int key, int val) : key(key), val(val), next(NULL), prev(NULL) {};
};

class LRUCache {

    Node* head;
    Node* tail;
    unordered_map<int,Node*> mpp;
    int cap;

    void deleteLRUNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        node->next = NULL;
        node->prev = NULL;
    }

    void appendToFront(Node* node){
        Node* headNext = head->next;
        node->prev = head;
        head->next = node;
        headNext->prev = node;
        node->next = headNext;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (mpp.find(key)!=mpp.end()){
            Node* node = mpp[key];
            // Delete the LRU   
            deleteLRUNode(node);
            // Update the LRU with the get key Node at the front
            appendToFront(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mpp.find(key)!=mpp.end()){
            Node* node = mpp[key];
            node->val = value;
            // Delete the LRU   
            deleteLRUNode(node);
            // Update the LRU with the get key Node at the front
            appendToFront(node);
        } else {
            Node* node = new Node(key,value);
            if (mpp.size()==cap){
                Node* lastNode = tail->prev;
                mpp.erase(lastNode->key);
                // Erase the last LRU node
                deleteLRUNode(lastNode);
                // Add New Node
                appendToFront(node);
            }else{
                // Add New Node
                appendToFront(node);
            }
            mpp[key] = node;
        }
    }
};
