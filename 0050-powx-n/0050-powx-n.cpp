class Solution {
private:
    double solve(double b,long long e){
        if(e==0){
            return 1;
        }
        double ans;
        if(e%2==0){
            ans=solve(b,e/2);
            ans*=ans;
        }
        else{
            ans=solve(b,e-1);
            ans*=b;
        }
        cout<<ans<<endl;
        return ans;
    }
public:
    double myPow(double x, long long n) {
        double ans=solve(x,abs(n));
        if(n<0){
            return (1/ans);
        }
        return ans;
    }
};