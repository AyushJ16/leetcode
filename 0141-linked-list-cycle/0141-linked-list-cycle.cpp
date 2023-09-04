/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)return false;
        if(head->next==head)return true;
        auto slow=head;
        auto fast=head;
        while(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
            if(fast){
                fast=fast->next;
            }
            if(slow==fast && slow!=NULL){
                return true;
            }
        }
        return false;
    }
};