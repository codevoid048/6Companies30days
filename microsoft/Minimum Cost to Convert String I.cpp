#define ll long long
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        ll res = 0;
        vector<vector<ll>> v(26, vector<ll>(26, INT_MAX));
        for(int i = 0; i < original.size(); ++i){
            int s = original[i] - 'a', ed = changed[i] - 'a';
            v[s][ed] = min(v[s][ed], cost[i]*1ll);
        }
        for(int k = 0; k < 26; k++)
            for(int i = 0; i < 26; i++)
                for(int j = 0; j < 26; j++)
                    v[i][j] = min(v[i][j], v[i][k] + v[k][j]);

        for(int i = 0; i < source.size(); i++){
            if(source[i] == target[i]) continue;
            int s = source[i] - 'a', k = target[i] - 'a';
            if(v[s][k] >= INT_MAX) return -1;
            res += v[s][k];
        }
        return res;
    }
};
// Floyd Warshall algorithm to calucate 