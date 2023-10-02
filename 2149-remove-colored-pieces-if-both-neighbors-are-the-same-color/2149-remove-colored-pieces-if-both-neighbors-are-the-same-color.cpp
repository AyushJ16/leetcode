class Solution {
public:
    bool winnerOfGame(string colors) {
        colors='&'+colors;
        colors+='&';
        int a=0,b=0;
        for(int i=1;i<colors.size()-2;i++){
            if(colors[i]=='A' && colors[i-1]=='A'  && colors[i+1]=='A')
            a++;
            if(colors[i]=='B' && colors[i-1]=='B'  && colors[i+1]=='B')
            b++;
        }
        return a>b;
    }
};