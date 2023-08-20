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
int ans;
private:
    int solve(TreeNode * root,int prev){
        if(!root){
            return 0;
        }
        int l=solve(root->left,root->val);
        int r=solve(root->right,root->val);
        if(root->left && root->val==root->left->val ){
            l+=1;
        }
        else l=0;
        if(root->right && root->val == root->right->val){
            r+=1;
        }
        else r=0;
        ans=max(ans,l+r);

        return max(l,r);
        
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        if(!root){
            return 0;
        }
        ans=0;
        // int n=0;
        solve(root,-1001);
        return ans;
    }
};