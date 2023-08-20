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
    int dl=0;
private:
    void solve(TreeNode * root,int d){
        if(!root){
            return;
        }
        if(d==dl){
            ans+=root->val;
        }
        else if(d>dl){
            ans=0;
            dl=d;
            ans+=root->val;
        }
        solve(root->left,d+1);
        solve(root->right,d+1);
        return;

    }

public:
    int deepestLeavesSum(TreeNode* root) {
        if(!root){
            return ans;
        }
        solve(root,1);
        return ans;
    }
};