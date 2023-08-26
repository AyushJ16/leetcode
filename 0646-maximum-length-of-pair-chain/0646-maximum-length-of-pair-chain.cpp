class Solution {
public:
    static bool f(const vector<int>&a,const vector<int>&b){
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end(),f);
        int le=-1001;
        int ans=0;
        for(int i=0;i<n;i++){
            // cout<<pairs[i][0]<<" "<<pairs[i][1]<<" "<<le<<endl;
            if(pairs[i][0]>le){
                ans+=1;
                le=pairs[i][1];
            }
        }
        return ans;
    }
};