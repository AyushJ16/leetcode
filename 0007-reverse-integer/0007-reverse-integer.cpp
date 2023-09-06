class Solution {
public:
    int reverse(int x) {
        string s;
        bool n=0;
        if(x<0){
            n=1;
            if(abs(x)>=INT_MAX){
                return 0;
            }
            x*=-1;
        }
        long long ans;
        s=to_string(x);
        ::reverse(s.begin(),s.end());
        ans=stoll(s);
        if(ans>=INT_MAX){
            return 0;
        }
        if(n){
            ans*=-1;
        }

        return ans;
        
    }
};