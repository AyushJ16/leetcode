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
    vector<int> largestValues(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<int> ans;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            long long maxi=INT32_MIN;
            for(int i=0;i<size;i++){
                auto p=q.front();
                q.pop();
                maxi=max(maxi,1ll*p->val);
                if(p->right)q.push(p->right);
                if(p->left)q.push(p->left);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};