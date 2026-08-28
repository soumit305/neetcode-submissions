/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*> mpp;
        Node* it = head;
        Node* dummy = new Node(-101);
        Node* copyIt = dummy;
        while (it){
            Node* node = new Node(it->val);
            mpp[it] = node;
            copyIt->next = node;
            it = it->next;
            copyIt = copyIt->next;
        }
        it = head;
        copyIt = dummy->next;
        while(it){
            copyIt->random = mpp[it->random];
            it = it->next;
            copyIt = copyIt->next;
        }
        return dummy->next;
    }
};
