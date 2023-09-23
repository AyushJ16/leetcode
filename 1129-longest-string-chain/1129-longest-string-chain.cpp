class Solution {
static bool cmp(const string &a,const string &b){
    return a.size()<b.size();
}
unordered_map<string,int>dp;
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        // cout<<words[0];
        int ans=0;
        for(auto &word:words){
            dp[word]=1;
            for(int i=0;i<word.length();i++){
                string temp=word.substr(0,i)+word.substr(i+1);
                if(dp.find(temp)!=dp.end()){
                    dp[word]=max(dp[word],1+dp[temp]);
                }
            }
            ans=max(ans,dp[word]);

        }
        return ans;
    }
};