class CountSquares {
    map<vector<int>,int> mpp;
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        mpp[point]++;
    }
    
    int count(vector<int> point) {
        int res=0;
        int px=point[0], py=point[1];
        for(auto &it:mpp){
            int x=it.first[0], y=it.first[1], freq=it.second;
            // check for diagonal point !!!---skip points matching horizontally, same, vertically, non diagonally !!!
            if(abs(px-x)!=abs(py-y) || x==px || y==py){
                continue;
            }
            if(mpp.find({x,py})!=mpp.end() && mpp.find({px,y})!=mpp.end()){
                res+=freq*mpp[{x,py}]*mpp[{px,y}];
            }
        }
        return res;
    }
};
