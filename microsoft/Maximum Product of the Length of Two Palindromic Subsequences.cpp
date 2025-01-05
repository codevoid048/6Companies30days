// Learnt this back tracking approach from https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/solutions/1458499/c-backtrack-c-users-please-pass-string-by-reference-to-pass

class Solution {
public:
    int mx = 0;
    bool check(string& s){
        int l = 0, r = s.length() - 1;
        while(l < r){
            if(s[l++] != s[r--]) 
               return false;
        }
        return true;
    }
    void dfs(string &s, int i, string &s1, string &s2){
        if(i >= s.size()){
            if(check(s1) && check(s2)){
                int n = s1.size(), m = s2.size();
                mx = max(mx, n*m);
            }
            return;
        }
        s1.push_back(s[i]);
        dfs(s, i+1, s1, s2);
        s1.pop_back();
        
        s2.push_back(s[i]);
        dfs(s, i+1, s1, s2);
        s2.pop_back();
        dfs(s, i+1, s1, s2);
    }
    
    int maxProduct(string s) {
        string s1 = "", s2 = "";
        dfs(s, 0, s1, s2);
        return mx;
    }
};

/*
Simple explanation :
if you notice I am trying all three possibilities :-

    1) I pick s[i] for s1 but don't pick s[i] for s2 (because they should be disjoint)
       - I explore this path and find the result (and then backtrack)

    2) I pick s[i] for s2 but don't pick s[i] for s1 (because they should be disjoint)
        - I explore this path and find the result (and then backtrack)

    3) I don't pick s[i] at all - I explore this path and find the result
        (and then backtrack)

In any of the path, if I get s1 and s2 both as palindrome we update our
result with maximum length. It's like a classic Backtrack approach.
*/