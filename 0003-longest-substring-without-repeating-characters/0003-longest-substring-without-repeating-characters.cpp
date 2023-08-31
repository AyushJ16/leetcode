class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int ans=0;
        int start=-1;
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]=i;
                if(start==-1){
                    start=i;
                }
                
            }
            else{
                int t=mp[s[i]]+1;
                if(t>start){
                    start =t;
                }
                mp[s[i]]=i;
            }
            ans=max(ans,i-start+1);
        }
        cout<<start<<endl;
        return ans;
    }
};