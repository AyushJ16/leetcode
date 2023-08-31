class MedianFinder {
priority_queue<int>peeche;
priority_queue<int,vector<int>,greater<int>>aage;
public:
    MedianFinder() {

        
    }
    
    void addNum(int num) {
        if(peeche.size()==0){
            peeche.push(num);
        }
        else if(aage.size()==peeche.size()){
            if(num>aage.top()){
                peeche.push(aage.top());
                aage.pop();
                aage.push(num);
            }
            else{
                peeche.push(num);
            }
        }
        else{
            if(num>=peeche.top()){
                aage.push(num);
            }
            else{
                aage.push(peeche.top());
                peeche.pop();
                peeche.push(num);
            }
        }
        
    }
    
    double findMedian() {
        if(peeche.size()>aage.size()){
            return (double)(peeche.top());
        }
        else{
            return (double)(aage.top()+peeche.top())/2;
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */