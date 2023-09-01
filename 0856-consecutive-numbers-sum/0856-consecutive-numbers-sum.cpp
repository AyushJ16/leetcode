class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int cnt = 0;
        for(int m=1;m*(m+1)<=2*n;m++){
            if((2*n - m*(m-1))%(2*m) == 0) cnt++;
        }
        return cnt;
    }
};