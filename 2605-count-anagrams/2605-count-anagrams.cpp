#define ll long long
#define mod 1000000007
const int N=1e5+1;
class Solution {
public:
    ll fact[N];

    void pre(){
       fact[0]=1;
       for(int i=1;i<N;i++){
          fact[i]=(1ll*fact[i-1]*i)%mod;
       }
    }
    
    ll binexp(int a,int b,int m){
       int result=1;
       while(b>0){
          if(b&1){
             result=(1ll*result*a)%m;
          }
          a=(1ll*a*a)%m;
          b>>=1;
       }

       return result;
    }
    
    int countAnagrams(string s) {
        pre();
        int i=0;
        int n=s.length();
        
        ll ans=1;
        while(i<n){
            vector<int> cnt(26,0);
            int count=0;
            ll curr;
            while(i<n && s[i]!=' '){
                count++;
                cnt[s[i]-'a']++;
                i++;
            }
            curr=fact[count];
            ll den=1;
            for(int i=0;i<26;i++) 
            if(cnt[i]>1) 
            den=(den*fact[cnt[i]])%mod;

            curr=(curr*binexp(den,mod-2,mod))%mod;
            ans=(ans*curr)%mod;
            i++;
        }
        
        return int(ans%mod);
    }
};