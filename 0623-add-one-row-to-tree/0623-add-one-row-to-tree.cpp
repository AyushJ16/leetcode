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
    void solve(TreeNode * root,int d,int depth,int val,int &req){
        if(req==0){
            return;
        }
        if(depth==d){
            // req=0;
            auto n1=new TreeNode(val);
            auto n2=new TreeNode(val);
            if(root->left){
                n1->left=root->left;
                root->left=n1;
            }
            else{
                root->left=n1;
            }
            if(root->right){
                n2->right=root->right;
                root->right=n2;
            }
            else{
                root->right=n2;
            }
            return;
        }
        if(root->left){
            solve(root->left,d+1,depth,val,req);
        }
        if(root->right){
            solve(root->right,d+1,depth,val,req);
        }
        return;
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root && depth>1){
            return root;
        }
        if(depth==1){
            TreeNode * node=new TreeNode(val);
            node->left=root;
            // node->left=new TreeNode(val);
            return node;
        }
        int req=2;
        solve(root,2,depth,val,req);
        return root;


    }
};