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
    map<TreeNode* , TreeNode *> parents;
    int ans=0;
private:    
    void markParents(TreeNode * root, TreeNode * parent){
        if(!root){
            return;
        }
        parents[root]=parent;
        if(parents[parent]){
            if(parents[parent]->val%2==0){
                ans+=root->val;
            }
        }
        markParents(root->left,root);
        markParents(root->right,root);
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        markParents(root,NULL);
        return ans;
    }
};