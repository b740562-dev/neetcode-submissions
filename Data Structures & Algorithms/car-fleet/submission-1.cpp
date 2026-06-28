class Solution {
    static bool compare(pair<int,int>& a,pair<int,int>& b){
        return a.first<b.first;
    }
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // if two cars collide then travel will happen from the speed of ahead car to reach the dest
        // see if behind car takes time >=ahead one they will collide and become a fleet !!!
        // we will keep a monoonically decreasing stack !!!

        stack<pair<int,int>> st;
        int n=speed.size();

        vector<pair<int,int>> pospeed;
        for(int i=0;i<n;i++){
            pospeed.push_back({target-position[i],speed[i]});
        }

        sort(pospeed.begin(),pospeed.end(),compare);

        // traverse from right so that so we can get after fleeting kis speed pe traverse ho rha !!!

        for(int i=0;i<n;i++){
            if(st.empty() || (double)pospeed[i].first/pospeed[i].second>(double)st.top().first/st.top().second){
                st.push({pospeed[i].first,pospeed[i].second});
            }
        }
        return st.size(); 
    }
};
