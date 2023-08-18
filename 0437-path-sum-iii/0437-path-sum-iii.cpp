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
unordered_map<long,int>dis;
    void dfs(TreeNode* root,int &t,int &ans,long &sum){
        // sum+=root->val;
        // dis[sum]=1;
        if(sum==t){
            ans++;
        }
        cout<<sum<<" "<<dis[sum-t]<<endl;
        if(dis[sum-t]>0){
            if((sum-t)==sum && dis[sum-t]>1){cout<<sum<<endl;
            ans+=dis[sum-t]-1;}
            else if(sum-t != sum)
            ans+=dis[sum-t];
        }
        if(root->left){
            sum+=root->left->val;
            dis[sum]++;
            dfs(root->left,t,ans,sum);
            dis[sum]--;
            sum-=root->left->val;
        }
        if(root->right){
            sum+=root->right->val;
            dis[sum]++;
            // if(dis[sum-t]==1){
            //     if(sum-t==sum && dis[sum]>1){cout<<sum<<endl;
            //     ans++;}
            //     else if(sum-t != sum)
            //     ans++;
            // }
            dfs(root->right,t,ans,sum);
            dis[sum]--;
            sum-=root->right->val;
        }
        // dis[sum]=0;
        // sum-=root->val;


    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root){
            return 0;
        }
        long sum=root->val;
        dis[sum]++;
        int ans=0;
        dfs(root,targetSum,ans,sum);
        return ans;
    }
};