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
    int getHeight(TreeNode * root){
        if(!root){
            return 0;

        }
        return max(getHeight(root->left),getHeight(root->right))+1;
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root){
            return NULL;
        }
        auto lh=getHeight(root->left);
        auto rh=getHeight(root->right);
        if(lh==rh){
            return root;
        }
        else if(lh>rh){
             return subtreeWithAllDeepest(root->left);
        }
        else{
            return subtreeWithAllDeepest(root->right);
        }
    }
};