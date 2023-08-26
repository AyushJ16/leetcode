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
    int ans=0;
private:
    int solve(TreeNode * root){
        if(!root){
            return 0;
        }
        int l=solve(root->left);
        int r=solve(root->right);
        ans+=abs(l)+abs(r);
        return (1-root->val+l+r);
    }
public:
    int distributeCoins(TreeNode* root) {
        if(!root){
            return 0;
        }
        solve(root);
        return ans;
    }
};