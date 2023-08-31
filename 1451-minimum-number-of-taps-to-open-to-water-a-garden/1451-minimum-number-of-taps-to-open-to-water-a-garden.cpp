class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>jumps(n+1,0);
        for(int i=0;i<n+1;i++){
            if(ranges[i]==0){
                continue;
            }
            int l=max(0,i-ranges[i]);
            int r=i+ranges[i];
            jumps[l]=max(jumps[l],r-l);
        }
        int o=0,c=0;
        int ans=0;
        for(int i=0;i<=n;i++){
            // cout<<ans<<" "<<o<<" "<<c<<" "<<jumps[i]+i<<endl;
            if(i>c){   
                if(i>o){
                    return -1;
                }
                ans++;
                c=o;

            }
            o=max(o,i+jumps[i]);
        }
        return ans;

        
    }
};