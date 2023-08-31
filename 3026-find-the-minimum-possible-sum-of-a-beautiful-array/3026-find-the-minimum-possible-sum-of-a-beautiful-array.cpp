#define ll long long
class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        ll pos=1;
        ll ans=0;
        unordered_set<int> del;
        ll num=1;
        while(pos<=n){
            if(num>target){
                ans+=num;
                pos++;
                num++;
                continue;
            }
            if(del.empty() || del.find(num)==del.end()){
                ans+=num;
                del.insert(target-num);
                pos++;
            }
            num++;
        }
        return ans;
        
    }
};