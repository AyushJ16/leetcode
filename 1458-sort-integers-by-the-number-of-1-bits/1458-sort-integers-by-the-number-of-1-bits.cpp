class Solution {
static bool cmp(const int &a,const int &b){
    int ca=__builtin_popcount(a);
    int cb=__builtin_popcount(b);
    if(ca==cb){
        return a<b;
    }
    return ca<cb;
}
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};