class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<char>q;
        int r=0,d=0,bd=0,br=0;
        for(int i=0;i<senate.size();i++){
            q.push(senate[i]);
            if(senate[i]=='R'){
                r++;
            }
            else d++;
        }
        while(r && d){
            char curr=q.front();
            q.pop();
            if(curr=='D'){
                if(bd){
                    bd--;
                    d--;

                }
                else{
                    br++;
                    q.push('D');
                }
            }
            else{
                if(br){
                    br--;
                    r--;
                }
                else{
                    bd++;
                    q.push('R');
                }
            }
        }
        return d?"Dire":"Radiant";
    }
};