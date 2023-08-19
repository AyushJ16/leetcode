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
    int solve(TreeNode * root,int limit, int val){
        int l=INT_MIN,r=INT_MIN;
        val+=root->val;
        if(!root->right && !root->left){
            l=val,r=val;
        }
        if(root->right){
            r=solve(root->right,limit,val);
            if(r<limit){
                root->right=NULL;
            }

        }
        if(root->left){
            l=solve(root->left,limit,val);
            if(l<limit){
                root->left=NULL;
            }
        }
        return max(l,r);
    }
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if(!root){
            return root;
        }
        if(!root->right && !root->left){
            if(root->val < limit){
                return NULL;
            }
            else{
                return root;
            }
        }
        int ans=solve(root,limit,0);
        if(ans>=limit)
        return root;
        return NULL;
    }
};