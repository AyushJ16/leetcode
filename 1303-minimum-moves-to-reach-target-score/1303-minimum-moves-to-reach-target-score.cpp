class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        if(maxDoubles==0){
            return target-1;
        }
        int ans=0;
        while(target>1 && maxDoubles>0){
            if(target%2 != 0){
                ans++;
                target--;
            }
            else{
                target/=2;
                ans++;
                maxDoubles--;
            }
        }
        if(target>1){
            ans+=(target-1);
        }
        return ans;
    }
};