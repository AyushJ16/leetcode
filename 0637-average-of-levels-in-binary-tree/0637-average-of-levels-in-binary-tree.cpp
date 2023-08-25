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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        queue<TreeNode*> Q;
        Q.push(root);

        while (!Q.empty()) {
            size_t size = Q.size();
            double avg = 0.0;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = Q.front();
                avg += curr->val;
                Q.pop();
                if (curr->left) Q.push(curr->left);
                if (curr->right) Q.push(curr->right);
            }
            result.emplace_back(avg / (double)size);
        }        

        return result;
    }
};