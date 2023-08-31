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
    bool solve(TreeNode * root, long long up, long long down){
        if(!root){
            return true;
        }
        int val=root->val;
        if(val>up && val<down){
            return solve(root->left,up,val) && solve(root->right,val,down);
        }
        else{
            return false;
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        return solve(root,INT64_MIN,INT64_MAX);
    }
};