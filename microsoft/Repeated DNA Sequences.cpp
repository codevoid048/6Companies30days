class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        string str = "";
        map<string, int> mp;
        for(int i = 0; i < n; i++){
            if(i < 9){
                str += s[i];
                continue;
            }
            str += s[i];
            mp[str]++;
            reverse(str.begin(), str.end());
            str.pop_back();
            reverse(str.begin(), str.end());
        }
        vector<string> res;
        for(auto &[str, freq] : mp){
            if(freq > 1) res.push_back(str);
        }
        return res;
    }
};