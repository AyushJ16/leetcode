class Solution {
public:
    int getinverse(long long int a,int b,int c){
        long long int ans = 1;
        while(b){
            if(b&1){
                ans = (ans*a)%c;
            }
            a = (a*a)%c;
            b >>= 1;
        }
        return ans;
    }
    int countAnagrams(string s) {
        int mod = 1e9+7;
        int n = s.length(),i;
        vector<int> fact(n+10,1);
        for(i = 2; i <= n+8; i++){
            fact[i] = (fact[i-1]*1LL*i)%mod;
        }
        long long int ans = 1,tmp;
        vector<int> factinv(n+10,0);
        for(int i = 0; i <= n+8; i++){
            factinv[i] = getinverse(fact[i],mod-2,mod);
        }
        vector<int> dp(26,0);
        int k = 0;
        for(auto &i: s){
            if(i==' '){
                tmp = fact[k];//
                for(auto &j: dp){
                    tmp = (tmp*1LL*factinv[j])%mod;
                }
                ans = (ans*tmp)%mod;
                fill(dp.begin(),dp.end(),0);
                k = 0;
            }else{
                dp[i-'a']++;
                k++;
            }
        }
        tmp = fact[k];
        for(auto &j: dp){
        tmp = (tmp*1LL*factinv[j])%mod;
        }
        ans = (ans*tmp)%mod;
        return ans;
    }
};