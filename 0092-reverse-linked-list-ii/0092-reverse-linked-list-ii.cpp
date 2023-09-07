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
private:
    ListNode * reverse(ListNode * head,int k){
        if(head==NULL || !head->next)return head;
        ListNode* prev=NULL; 
        ListNode* curr=head;
        ListNode* nexti=NULL;
        while(curr && k>=1){
            nexti=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nexti;
            k--;
        }
        if(nexti!=NULL){
            head->next=nexti;
        }
        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL)return head;
        int k=right - left +1;
        // cout<<k<<" ";
        if (k==1)return head;
        auto curr=head;
        if(left==1){
            return reverse(curr,k);
            
        }
        while(left>2 && curr !=NULL ){
            curr=curr->next;
            left--;
        }
        if(curr!=NULL){
            auto nexti=curr->next;
            curr->next=reverse(nexti,k);
        }
        return head;
    }
};