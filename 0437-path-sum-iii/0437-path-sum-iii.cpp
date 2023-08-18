class Solution {
public:
    void solve(TreeNode* root,vector<int> &v,int &ct,int k){
        if(root == NULL) return ;
        v.push_back(root->val);

        solve(root->left,v,ct,k);
        solve(root->right,v,ct,k);

        int n = v.size();
        long long sum = 0;

        for(int i = n - 1;i >= 0;--i){
            sum += v[i];
            if(sum == k)
                ct++;
        }
        v.pop_back();
    }
    int pathSum(TreeNode* root, int k) {
        vector<int> v;
        int ct = 0;
        solve(root,v,ct,k);
        return ct;
    }
};