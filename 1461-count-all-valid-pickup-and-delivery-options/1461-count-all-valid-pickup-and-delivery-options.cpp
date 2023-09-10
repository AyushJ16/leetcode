class Solution {
    const int mod=1e9+7;
public:
    int countOrders(int n) {
        long long ans=1;
        int places=2*n;
        for(int i=n;i>=1;i--){
            ans=(ans*((places-1)*places)/2)%mod;
            places-=2;
        }
        return ans;
    }
};