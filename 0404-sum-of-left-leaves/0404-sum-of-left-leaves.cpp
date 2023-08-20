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
int sum=0;
public:
    int sumOfLeftLeaves(TreeNode* root,int i=1) {
        if(!root){
            return sum;
        }
        // cout<<i<<endl;
        if(!root->left && !root->right ){
            if(i==0){
            sum+=root->val;
            return sum;}
            else{
                return sum;
            }
        }
        sumOfLeftLeaves(root->left,0);
        sumOfLeftLeaves(root->right,1);
        return sum;
    }
};