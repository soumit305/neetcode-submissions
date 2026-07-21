/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* it = head;
        int len = 0;
        while(it){
            len++;
            it = it->next;
        }
        int idx = len - n;
        ListNode* nodeToDelete = head;
        ListNode* prev = head;
        while(idx--){
            nodeToDelete = nodeToDelete->next;
            if (prev->next != nodeToDelete) prev = prev->next;
        }
        if (prev == nodeToDelete) return prev->next;
        prev->next = nodeToDelete->next;
        nodeToDelete->next = nullptr;
        delete(nodeToDelete);
        return head;
    }
};
