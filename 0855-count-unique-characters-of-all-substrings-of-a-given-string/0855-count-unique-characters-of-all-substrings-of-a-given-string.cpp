class Solution {
public:
    int uniqueLetterString(string s) {
        // int ans=0;
        // int sum=0;
        // int n=s.size();
        
        // for(int i=0;i<s.size();i++){
        //     sum+=i+1;
        //     ans+=sum;
        // }
        // cout<<ans<<" ";
        // unordered_map<char,int> mp;
        // int rep=0;
        // int rem=0;
        // // vector<int>rep(s.size(),0);
        // for(int i=0;i<s.size();i++){
        //     mp[s[i]]++;
        //     if(mp[s[i]]==2){
        //         rep+=2;
        //     }
        //     else if(mp[s[i]]>2){
        //         rep++;
        //     }
        //     rem+=rep;
        // }
        // cout<<rem<<" "<<rep<<endl;
        // ans-=rem;
        // return ans;
        vector<vector<int>>occ(26);
        // for(int i=0;i<26;i++){
        //     occ[i].push_back(-1);
        // }
        for(int i=0;i<s.size();i++){
            occ[s[i]-'A'].push_back(i);
        }
        int ans=0;   
        for(char c='A';c<='Z';c=(char)(c+1)){
            int fi=-1;
            int li=s.size();
            if(occ[c-'A'].size()>0){
                for(int i=0;i<occ[c-'A'].size();i++){
                    if(i<(occ[c-'A'].size()-1)){
                        li=occ[c-'A'][i+1];
                    }
                    else{
                        li=s.size();
                    }
                    ans+=(occ[c-'A'][i]-fi)*(li-occ[c-'A'][i]);
                    fi=occ[c-'A'][i];
                }
            }
        }  
        return ans;   
    }
};