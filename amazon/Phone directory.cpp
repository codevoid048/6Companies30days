class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s){
        // code here
        int m = s.size();
        vector<vector<string>> res(m);
        vector<bool> valid(n, true);
        for(int i = 0; i < m; i++){
            bool empty = true;
            char key = s[i];
            set<string> st;
            for(int j = 0; j < n; j++){
                if(valid[j]){
                    string name = contact[j];
                    if(name.size() > i){
                        if(name[i] == key){
                            empty = false;
                            st.insert(name);
                        }
                        else valid[j] = false;
                    }
                    else valid[j] = false;
                }
            }
            if(empty) res[i].push_back("0");
            else{
                for(auto it = st.begin(); it != st.end(); it++)
                    res[i].push_back(*it);
            }
        }
        return res;
    }
};