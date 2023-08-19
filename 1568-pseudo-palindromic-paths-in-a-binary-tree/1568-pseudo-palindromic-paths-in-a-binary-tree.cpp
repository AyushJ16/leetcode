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
    vector<int> digits;
    int count=0;
    Solution(){
        digits.resize(10,0);
    }
    bool check(void){
        int o=0;
        for(int i=0;i<10;i++){
            if(digits[i]%2==1){
                o++;
            }
        }
        if(o>1){
            return false;
        }
        return true;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if(!root){
            return 0;
        }
        digits[root->val]++;
        // if(!root->left && !root->right){
        //     return 1;
        // }
        // int count=0;
        if(!root->left && !root->right){
            if(check())
            count++;
        }
        if(root->left){
            pseudoPalindromicPaths(root->left);
        }
        if(root->right){
            pseudoPalindromicPaths(root->right);
        }
        digits[root->val]--;
        return count;
    }

};