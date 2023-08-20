class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder.length()==0){
            return true;
        }
        if(preorder[0]=='#' and preorder.size()!=1){
            return false;
        }
        int c=1;
        for(int i=0;i<preorder.size();){
            c--;
            if(c<0){
                return false;
            }
            if(preorder[i]!='#')c+=2;
            while(i<preorder.size() && preorder[i]!=',' ){
                i++;
            }
            i++;

        }
        return c==0;
        
    }
};