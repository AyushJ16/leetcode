class Solution {
private:
    void countSort(vector<int>&nums,int n,int exp){
        vector<int> output(n);
        vector<int>count(10,0);
        for(int i=0;i<n;i++){
            count[(nums[i]/exp)%10]++;
        }
        for(int i=1;i<=9;i++){
            count[i]+=count[i-1];
        }
        for(int i=n-1;i>=0;i--){
            output[count[(nums[i]/exp)%10 ]-1]=nums[i];
            count[(nums[i]/exp)%10]--;
        }
        for(int i=n-1;i>=0;i--){
            nums[i]=output[i];
        }
    }
    void radixsort(vector<int> &nums,int n){
        int m=*max_element(nums.begin(),nums.end());
        for(int exp=1;m/exp>0;exp*=10){
            countSort(nums,n,exp);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]+=50000;
        }
        radixsort(nums,n);
        for(int i=0;i<n;i++){
            nums[i]-=50000;
        }
        return nums;

    }
};