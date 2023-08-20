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
    int dfs(TreeNode * root,int t){
        if(!root->left && !root->right){
            return 1;
        }
        int l=0,r=0;
        if(root->left){
            l=dfs(root->left,t);
            if(l==1 && root->left->val==t){
                root->left=nullptr;
            }
        }
        if(root->right){
            r=dfs(root->right,t);
            if(r==1 && root->right->val==t){
                root->right=nullptr;
            }
        }
        if(!root->left && !root->right){
            return 1;
        }
        return 0;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root){
            return root;
        }
        if(!root->left && !root->right){
            if(root->val==target)
            {
                return NULL;
            }
        }
        int a=dfs(root,target);
        if(a==1 && root->val==target){
            return NULL;
        }
        else
        return root;
    }
};