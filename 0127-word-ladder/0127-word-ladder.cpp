class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set <string> list;
        priority_queue<pair<int,string>,vector<pair<int,string> >, greater<pair<int,string> > >pq;
        for(auto &it:wordList){
            list.insert(it);
        }
        if(list.find(endWord)==list.end()){
            return 0;
        }
        list.erase(beginWord);
        pq.push({1,beginWord});
        while(!pq.empty()){
            auto p=pq.top();
            int len=get<0>(p);
            string curr=get<1>(p);
            pq.pop();
            if(curr==endWord){
                return len;
            }
            for(int i=0;i<curr.length();i++){
                string original=curr;
                for(char c='a';c<='z';c++){
                    original[i]=c;
                    if(list.count(original)!=0){
                        pq.push({len+1,original});
                        list.erase(original);
                    }
                }
            }
        }
        return 0;
    }
};