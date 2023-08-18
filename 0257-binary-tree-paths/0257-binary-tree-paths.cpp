/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };   
 */
class Solution {
public:
    map<int,vector<int> > adj;
    vector<string> ans;
    void dfs(TreeNode * node,string &s){
        if(node==NULL){
            return;
        }
        int h=to_string(node->val).length();
        if(!node->left && !node->right){
            s+=to_string(node->val);
            ans.push_back(s);
            s=s.substr(0,s.length()-h);
            return;
        }
        s=s+to_string(node->val)+"->";
        dfs(node->left,s);
        dfs(node->right,s);
        s=s.substr(0,s.length()-2-h);
        return;
        
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root){
            return {""};
        }
        queue<TreeNode*> q;
        q.push(root);
            while(!q.empty()){
                auto p=q.front();
                q.pop();
                if(p->left){
                    adj[p->val].push_back(p->left->val);
                    q.push(p->left);
                }
                if(p->right){
                    adj[p->val].push_back(p->right->val);
                    q.push(p->right);
                }

            
        }
        string s="";
        dfs(root,s);
        return ans;

    }
};