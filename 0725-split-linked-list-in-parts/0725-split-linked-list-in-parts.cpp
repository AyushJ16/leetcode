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
    int getLength(ListNode * head){
        int t=0;
        while(head){
            t++;
            head=head->next;
        }
        return t;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k,nullptr);
        if(!head){
            return ans;
        }
        int l=getLength(head);
        int n=l/k;
        int t=l%k;
        ListNode* curr=head;
        int pos=0;
        while(curr){
            int j=n;
            if(t>0){
                j++;
                t--;
            }
            ans[pos]=curr;
            pos++;
            for(int i=0;i<j-1;i++){
                curr=curr->next;
            }
            auto temp=curr->next;
            curr->next=NULL;
            curr=temp;
        }
        return ans;
        
    }
};