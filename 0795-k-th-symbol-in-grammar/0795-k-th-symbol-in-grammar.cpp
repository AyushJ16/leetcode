class Solution {
public:
    int kthGrammar(int n, int k) {
        bool f=true;
        int len=pow(2,n-1);
        while(len!=1){
            len/=2;
            if(k>len){
                k-=len;
                f=!f;
            }
        }
        return (f)?0:1;
    }
};