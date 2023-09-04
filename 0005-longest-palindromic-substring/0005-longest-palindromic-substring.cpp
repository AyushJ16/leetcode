class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,0));
        int maxlen=0;
        int start=-1;
        for(int i=0;i<n;i++){
            for(int j=i;j<i+2;j++){
                if(j>=n){
                    break;
                }
                if(i==j){

                    dp[i][j]=1;
                    if(j-i+1>maxlen){
                        start=i;
                        maxlen=j-i+1;
                    }
                }
                if(j==i+1 && s[i]==s[j]){
                    dp[i][j]=1;
                    if(j-i+1>maxlen){
                        start=i;
                        maxlen=j-i+1;
                    }
                }
                // if(i+2==j && s[i]==s[j]){
                //     dp[i][j]=1;
                //     if(j-i+1>maxlen){
                //         start=i;
                //         maxlen=j-i+1;
                //     }
                // }
            }
        }
        for(int l=3;l<=n;l++){
            for(int i=0;i<(n-l+1);i++){
                int j=i+l-1;
                if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j]=1;
                    if(maxlen < l){
                        maxlen=l;
                        start=i;
                    }
                }
            }
        }
        cout<<maxlen<<" "<<start<<endl;
        return s.substr(start,maxlen);
        // return "";
    }
};