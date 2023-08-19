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
public:
    int count=0;
    vector<int> dfs(TreeNode * root,int d){
        vector <int> temp;
        vector<int>l;vector<int> r;
        if(!root->left && !root->right){
            return {1};
        }
        if(root->left){
            l=dfs(root->left,d);
        }
        if(root->right){
            r=dfs(root->right,d);
        }
        for(int i=0;i<r.size();i++){
            for(int j=0;j<l.size();j++){
                if(r[i]+l[j]<=d){
                    count++;
                }
            }
        }
        for(int i=0;i<l.size();i++){
            temp.push_back(l[i]+1);
        }
        for(int i=0;i<r.size();i++){
            temp.push_back(r[i]+1);
        }
        return temp;

    }
    int countPairs(TreeNode* root, int distance) {
        if(!root){
            return 0;

        }
        if(!root->left && !root->right){
            return 0;
        }
        dfs(root,distance);
        return count;
        
    }
};