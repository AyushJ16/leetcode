class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int>count(100001,0);
        for(auto &e:nums){
            count[e+50000]++;
        }
        int pos=0;
        for(int i=0;i<=100000;i++){
            for(int j=0;j<count[i];j++){
                nums[pos]=i-50000;
                pos++;
            }
        }
        return nums;
    }
};