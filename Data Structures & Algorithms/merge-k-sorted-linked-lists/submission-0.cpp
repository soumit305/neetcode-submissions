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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>> > pq;
        for (ListNode* list : lists){
            if (list) {
                pq.push({list->val,list});
            }
        }
        while(!pq.empty()){
            auto it = pq.top(); pq.pop();
            ListNode* node = it.second;
            temp->next = node;
            temp = temp->next;
            if (node->next) pq.push({node->next->val,node->next});
        }
        return dummy->next;
    }
};
