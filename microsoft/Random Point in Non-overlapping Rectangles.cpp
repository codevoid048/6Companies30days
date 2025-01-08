class Solution {
public:
    map<int,vector<int>> mp;
    int sum = 0; 
    Solution(vector<vector<int>>& rects) {
        for(auto r : rects){
            sum += (r[3] - r[1] + 1)*(r[2] - r[0] + 1);; 
            mp[sum] = r;
        }
    }
    vector<int> pick() {
        int r = rand() % sum;
        auto temp = mp.upper_bound(r);
        vector<int> z = temp->second;
        int x = z[0] + rand() % (z[2] - z[0] + 1);
        int y = z[1] + rand() % (z[3] - z[1] + 1);
        return {x,y};
       }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rs);
 * vector<int> param_1 = obj->pick();
 */