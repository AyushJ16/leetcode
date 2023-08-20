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
    vector<vector<int>> ans;
private:
    void solve(TreeNode* root, int t, vector<int> &path,int &s){
        s+=root->val;
        path.push_back(root->val);
        if(s==t && !root->left && !root->right){
            ans.push_back(path);
            s-=root->val;
            path.pop_back();
            return;
        }
        if(root->left){
            solve(root->left,t,path,s);
        }
        if(root->right){
            solve(root->right,t,path,s);
        }
        path.pop_back();
        s-=root->val;
        return;
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root){
            return ans;
        }
        vector<int>path;
        int s=0;
        solve(root,targetSum,path,s);
        return ans;
    }
};