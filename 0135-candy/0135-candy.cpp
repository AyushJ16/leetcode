class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> c(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i-1]<ratings[i]){
                c[i]=c[i-1]+1;
            }
        }
        int temp=1;
        c[n-1]=max(c[n-1],temp);
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                temp=temp+1;
                c[i]=max(temp,c[i]);
            }
            else{
                temp=1;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=c[i];
        }
        return ans;


    }
};