class Solution {
public:
    int getSum(int a, int b) {
        unsigned int carry=(a&b)<<1;
        int ans=a^b;
        int temp;
        while(carry>0){
            temp=ans^carry;
            carry=ans&carry;
            carry=carry<<1;
            ans=temp;
        }
        return ans;
    }
};