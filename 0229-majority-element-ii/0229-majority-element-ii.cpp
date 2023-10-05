class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=(nums.size());
        int req=n/3;
        int num=nums[0];
        int count=1;
        vector<int>ans;
        for(int i=1;i<n;i++){
            if(nums[i]!=num){
                if(count>req){
                    ans.push_back(num);
                }
                count=1;
                num=nums[i];
            }
            else{
                count++;
            }
        }
        if(count>req){
            ans.push_back(num);
        }
        return ans;
    }
};