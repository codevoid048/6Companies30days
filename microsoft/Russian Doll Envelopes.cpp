class Solution {
private:
    int search(vector<int>& lis, int k){
        int l = 0, r = lis.size() - 1;
        while(l <= r){
            int m = (l + r) / 2;
            if(lis[m] == k) return m;
            else if(lis[m] > k) r = m - 1;
            else l = m + 1;
        }
        return l;
    } 
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](auto &a, auto &b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        int n = envelopes.size();
        vector<int> lis;
        for(int i = 0; i < n; i++){
            if(lis.empty() || lis.back() < envelopes[i][1]){
                lis.push_back(envelopes[i][1]);
            }
            else{
                int idx = search(lis, envelopes[i][1]);
                lis[idx] = envelopes[i][1];
            }
        }
        return lis.size();
    }
};

//Longest Increasing Subsequnce


// class Solution {
// public:
//     int maxEnvelopes(vector<vector<int>>& envelopes) {
//         sort(envelopes.begin(), envelopes.end(), [](auto &a, auto &b){
//             if(a[0] == b[0]) return a[1] > b[1];
//             return a[0] < b[0];
//         });
//         int n = envelopes.size();
//         vector<int> lis;
//         for(int i = 0; i < n; i++){
//             auto it = lower_bound(lis.begin(), lis.end(), envelopes[i][1]);
//             if(it == lis.end()) lis.push_back(envelopes[i][1]);
//             else *it = envelopes[i][1];
//         }
//         return lis.size();
//     }
// };
