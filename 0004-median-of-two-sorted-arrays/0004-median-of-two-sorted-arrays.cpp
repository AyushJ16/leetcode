class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int x=nums1.size(), y=nums2.size();   //store size
        while(nums1.size()<(x+y))nums1.push_back(-1);   //Merge array
        int mainindex=(x+y)-1, i=x-1, j=y-1;
        while(i>=0 && j>=0){
            if(nums1[i] > nums2[j])nums1[mainindex--] = nums1[i--];
            else  nums1[mainindex--] = nums2[j--];
        }
        while(j>=0)nums1[mainindex--] = nums2[j--];
        if(nums1.size()%2==1)return (double)nums1[nums1.size()/2];  //median
        else return (double)((nums1[(x+y)/2] + nums1[((x+y)/2)-1]))/2;
    }
};