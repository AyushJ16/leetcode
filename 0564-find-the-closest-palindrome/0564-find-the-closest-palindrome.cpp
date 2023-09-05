#define ll long long
class Solution {
private:
    ll r(ll num,ll f){
        if(f!=0){
            num/=10;
        }
        string n=to_string(num);
        reverse(n.begin(),n.end());
        return stoll(n);
    }
public:
    string nearestPalindromic(string n) {
        int size=n.size();
        if(size==1 ||(size==2 && n=="10"||n=="11")){
            if(size==2){
                if(n=="10"){
                  
                  return "9";
                }
                if(n=="11"){
                    return "9";
                }
            }
            int ans=stoi(n);
            return to_string(ans-1);
        }
        ll num=stoll(n);
        ll mul=pow(10,size/2);
        ll half=num/mul;
        ll ans=half*mul+r(half,size%2),ans1=(half-1)*mul+r(half-1,size%2),ans2=(half+1)*mul+r(half+1,size%2);
        ll diff1=abs(num-ans),diff2=abs(num-ans1),diff3=abs(num-ans2);
        ll fans;
        if(diff1<diff2 && diff1!=0){
            if(diff3<diff1 && diff3!=0){
                fans=ans2;
            }
            else{
                fans=ans;
                // cout<<diff1<<" "<<diff2<<endl;
            }
        }
        else{
            if(diff3<diff2 && diff3!=0){
                fans=ans2;
            }
            else{
                fans=ans1;
            }
        }
        ll mx=pow(10,size)+1;
        ll mn=pow(10,size-1)-1;
        // cout<<mn<<endl;
        if(abs(num-mn)<=abs(num-mx)){
            if(abs(num-fans)>=abs(num-mn)){
                return to_string(mn);
            }
            else{
                return to_string(fans);
            }
        }
        else{
            if(abs(num-fans)<=abs(num-mx)){
                return to_string(fans);
            }
            else{
                return to_string(mx);
            }
        }
    }
};