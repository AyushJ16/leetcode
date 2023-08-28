class Solution {
private:
    void merge(int l,int r,int mid,vector<int>&nums){
        vector<int> temp;
        int i=l;
        int k=mid;
        int j=mid+1;
        while(i<=k && j<=r){
            if(nums[i]>nums[j]){
                temp.push_back(nums[j]);
                j++;
            }
            else{
                temp.push_back(nums[i]);
                i++;
            }
        }
        while(i<=k){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=r){
            temp.push_back(nums[j]);
            j++;
        }
        for(int s=l;s<=r;s++){
            nums[s]=temp[s-l];
        }
        return;
    }
    void sort(int l,int r,vector<int> &nums){
        if(l>=r){
            return;
        }
        int mid=(l+r)/2;
        sort(l,mid,nums);
        sort(mid+1,r,nums);
        merge(l,r,mid,nums);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
        sort(l,r,nums);
        return nums;
    }
};