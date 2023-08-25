/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root){
            return {};
        }
        queue<Node *>q;
        vector<vector<int> > ans;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> temp;
            for(int i=0;i<size;i++){
                auto p=q.front();
                temp.push_back(p->val);
                q.pop();
                for(auto &n:p->children){
                    q.push(n);
                }
            }
            ans.push_back(temp);
        }
        return ans;

    }
};