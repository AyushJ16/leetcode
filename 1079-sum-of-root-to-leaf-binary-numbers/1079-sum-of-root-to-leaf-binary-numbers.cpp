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
    int solve(TreeNode * root, int val){
        if(!root){
            return val;
        }
        int ans=0;
        // ans+=pow(2,val)*root->val;
        val=val*2 + root->val;
        if(!root->left && !root->right){
            return val;
        }
        if(root->left){
            ans+=solve(root->left,val);

        }
        if(root->right){
            ans+=solve(root->right,val);
        }
        return ans;
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        if(!root){
            return 0;

        }
        return solve(root,0);
    }
};