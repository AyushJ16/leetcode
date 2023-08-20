class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        ans.push_back(label);
        if(label==1){
            return ans;
        }
        label/=2;
        while(label>1){
            int level=log2(label)+1;
            int start=pow(2,level-1);
            int end=pow(2,level)-1;
            int pos=end-label;
            int req=start+pos;
            label=req;
            label/=2;
            ans.push_back(req);
        }
        
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};