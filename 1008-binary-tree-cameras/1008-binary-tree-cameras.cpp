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
    // map<tuple<TreeNode*,int,int> ,int>dp;
    int count=0;
private:
    // int solve(TreeNode* root,int cond,int dis){
    //     int r=INT_MAX,nr=INT_MAX;
    //     if(dp.find({root,cond,dis})!=dp.end()){
    //         return dp[{root,cond,dis}];
    //     }
    //     // int t=0;
    //     if(cond==0 && dis==3){
    //         r=0;
    //         if(root->left){
    //             r+=solve(root->left,0,1);
    //         }
    //         if(root->right){
    //             r+=solve(root->right,0,1);
    //         }
    //         r++;
    //         // r=t;
    //     }
    //     if(cond ==0 && dis<3){
    //         if(!root->left && !root->right ){
    //             if(dis==2)
    //             return 1;
    //             else if(dis==1)
    //             return 0;
    //         }
    //         r=0,nr=0;
    //         if(root->left){
    //             nr+=solve(root->left,0,dis+1);
    //             r+=solve(root->left,0,1);
    //         }
    //         if(root->right){
    //             nr+=solve(root->right,0,dis+1);
    //             r+=solve(root->right,0,1);
    //         }
    //         r++;
    //     }
    //     dp[{root,cond,dis}]=min(r,nr);
    //     return dp[{root,cond,dis}];
    // }
    int dfs(TreeNode * root){
        // int a=1,b=1;
        // if(!root){
        //     return 1;
        // }
        int a=1,b=1;
        if(root->left)
        a=dfs(root->left);
        if(root->right)
        b=dfs(root->right);
        if(a==0 || b==0){
            count++;
            return 2;
        }
        if(a==1 && b==1){
            return 0;
        }
        return 1;
    }

public:
    int minCameraCover(TreeNode* root) {
        if(!root){
            return 0;
        }
        // if(!root->left && !root->right){
        //     return 1;
        // }
        int x=dfs(root);
        if(x==0)count++;
        return count;
        // solve(root,1);
    }
};