class Solution {
public:
    int bestClosingTime(string s) {
        int n=s.size();
        vector<int> o(n+1,0),c(n+1,0);
        for(int i=1;i<=n;i++){
            if(i==0){
                o[i]=s[i]=='N';
            }
            else{
                o[i]=o[i-1]+(int)(s[i-1]=='N');
            }
        }
        // o[n]=o[n-1];
        for(int i=n-1;i>=0;i--){
            c[i]=c[i+1]+(int)(s[i]=='Y');
        }
        int mini=INT_MAX;
        int ans=INT_MAX;
        for(int i=n;i>=0;i--){
            // cout<<c[i]<<" "<<o[i]<<" "<<i<<endl;
            if((c[i]+o[i])<=mini){
                mini=c[i]+o[i];
                ans=i;
            }
        }
        return ans;
    }
};