class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder.length()==0){
            return true;
        }
        if(preorder[0]=='#' and preorder.size()!=1){
            return false;
        }
        stringstream ss(preorder);
        string curr;
        int nodes=1;
        while(getline(ss,curr,',')){
            nodes--;
            if(nodes<0)return false;
            if(curr != "#")nodes+=2;
        }
        return nodes==0;
        
    }
};