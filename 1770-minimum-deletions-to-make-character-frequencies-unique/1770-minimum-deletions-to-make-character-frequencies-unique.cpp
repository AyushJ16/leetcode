class Solution {
public:
    int minDeletions(string s) {
        int n=s.length();
        vector<int>freq(n+1,0);
        vector<int>c(26,0);
        for(int i=0;i<n;i++){
            c[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            freq[c[i]]++;

        }
        int ans=0;
        int tot=0;
        for(int i=n;i>=1;i--){
            // cout<<freq[i]<<" "<<tot<<" "<<i<<endl;
            if(freq[i]==0 && tot==0){
                continue;
            }
            int t=0;
            t+=freq[i]+tot;
            ans+=(t-1);
            tot=t-1;
        }
        // ans+=tot;
        return ans;
    }
};