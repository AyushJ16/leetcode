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
    string ans="";
    void dfs(TreeNode* root,string &s){
        if(!root->left && !root->right){
            s=(char)('a'+root->val)+s;
            if(ans=="" || ans.compare(s)>0){
                ans=s;
            }
            s.erase(s.begin());
            return;
        }
        s=(char)('a'+root->val)+s;
        if(root->left){
            dfs(root->left,s);
        }
        if(root->right){
            dfs(root->right,s);
        }
        s.erase(s.begin());
        return;
    }
    string smallestFromLeaf(TreeNode* root) {
        if(!root){
            return "";
        }
        string s="";
        dfs(root,s);
        return ans;
    }
};