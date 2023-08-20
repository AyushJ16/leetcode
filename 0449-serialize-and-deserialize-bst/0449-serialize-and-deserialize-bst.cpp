/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue <TreeNode*> q;
        q.push(root);
        string s="";
        if(!root)return s;
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            if(curr==NULL){
                s+="#,";
                continue;
            }
            else{
                s+=(to_string(curr->val))+",";
                q.push(curr->left);
                q.push(curr->right);
            }
        }

        return s;        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)
        return nullptr;
        queue <TreeNode*> q;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        if (str=="#")return NULL;
        q.push(root);
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#"){
                curr->left=NULL;
            }
            else{
                auto left=new TreeNode(stoi(str));
                curr->left=left;
                q.push(left);
            }
            getline(s,str,',');
            if(str=="#"){
                curr->right=NULL;
            }
            else{
                auto right=new TreeNode(stoi(str));
                curr->right=right;
                q.push(right);
            }
        
        }
        return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));