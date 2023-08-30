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
    ListNode * reverse(ListNode * head){
        ListNode * prev=NULL;
        ListNode * next=NULL;
        ListNode * curr=head;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        ans.push_back(-1);
        ListNode * curr=reverse(head);
        stack<int>st;
        while(curr){
            if(st.empty() ){
                ans.emplace(ans.begin(),0);
                st.push(curr->val);
            }
            else{
                if(st.top()>curr->val){
                    ans.emplace(ans.begin(),st.top());
                    st.push(curr->val);
                }
                else{
                    while(!st.empty() && st.top()<=curr->val){
                        st.pop();
                    }
                    if(st.empty()){
                        ans.emplace(ans.begin(),0);
                    }
                    else{
                        ans.emplace(ans.begin(),st.top());
                    }
                    st.push(curr->val);
                }
                
            }
            curr=curr->next;
        }
        ans.pop_back();
        return ans;

    }
};