class TimeMap {
// it is recommended to define data structures inside private variable !
// one should not write anything inside constructor !!!

// q is asking us to use hass table

map<string,vector<pair<string,int>>> mpp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        // mpp[key] is a vector so need to use push_back !!!
        mpp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        int low=0, high=mpp[key].size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mpp[key][mid].second==timestamp){
                return mpp[key][mid].first;
            }
            else if(mpp[key][mid].second<timestamp){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        if(high<0){
            return "";
        }
        return mpp[key][high].first;
    }
};
