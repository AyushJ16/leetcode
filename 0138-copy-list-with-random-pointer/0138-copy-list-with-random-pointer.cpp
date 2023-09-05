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
private:
    void insertAtTail(Node * &tail,int val){
        tail->next=new Node(val);
        tail=tail->next;
    }
public:
    Node* copyRandomList(Node* head) {
        if(!head){return NULL;}
        Node * h1=new Node(head->val);
        Node * t1=h1;
        auto curr=head->next;
        // head->next=h1;
        Node * next=NULL;
        while(curr){
            next=curr->next;
            insertAtTail(t1,curr->val);
            curr=next;
        }
        curr =head;
        Node * curr1=h1;
        next=NULL;
        Node * next1=NULL;
        while(curr && curr1){
            next=curr->next;
            next1=curr1->next;
            curr->next=curr1;
            curr1->next=next;
            curr=next;
            curr1=next1;
        }
        curr=head;
        curr1=h1;
        next=NULL;
        while(curr && curr->next){
            next=curr->next->next;
            if(curr->random)
            curr->next->random=curr->random->next;
            else
            curr->next->random=NULL;
            curr=next;
        }
        curr=head;
        next=NULL;
        curr1=h1;
        next1=NULL;
        while(curr1 && curr){
            next=curr1->next;
            if(next){
                next1=next->next;
            }
            curr->next=next;
            curr1->next=next?next1:NULL;
            curr=next;
            curr1=next?next1:next;
        }
        return h1;
    }
};