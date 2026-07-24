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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* it = dummy;
        ListNode* it1 = l1;
        ListNode* it2 = l2;
        int sum = 0;
        int carry = 0;
        while(it1 && it2){
            int val1 = it1->val;
            int val2 = it2->val;
            sum = (val1 + val2 + carry)%10;
            carry = (val1 + val2 + carry)/10;
            it->next = new ListNode(sum);
            it = it->next;
            it1 = it1->next;
            it2 = it2->next;
        }
        while(it1){
            int val1 = it1->val;
            sum = (val1 + carry)%10;
            carry = (val1 + carry)/10;
            it->next = new ListNode(sum);
            it = it->next;
            it1 = it1->next;
        }
        while(it2){
            int val1 = it2->val;
            sum = (val1 + carry)%10;
            carry = (val1 + carry)/10;
            it->next = new ListNode(sum);
            it = it->next;
            it2 = it2->next;
        }
        if (carry){
            it->next = new ListNode(carry);
            it = it->next;
        }
        return dummy->next;
    }
};
