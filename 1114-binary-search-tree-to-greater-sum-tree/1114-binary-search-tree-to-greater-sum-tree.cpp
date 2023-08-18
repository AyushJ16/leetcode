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
private:
    int solve(TreeNode* root,int val){
        int ans=val;//21
        // cout<<val<<" "<<root->val<<" "<<endl;
        if(root->right){
            ans=solve(root->right,val);
        }
        ans+=root->val;//30
        // cout<<val<<" "<<root->val<<" "<<ans<<endl;
        root->val=ans;
        if(root->left){
            ans=solve(root->left,root->val);
        }
        return ans;//26
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        if(!root){
            return root;
        }
        solve(root,0);
        return root;
    }
};