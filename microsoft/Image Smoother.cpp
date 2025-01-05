class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();
        vector<vector<int>> res(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                long long sum = 0, cnt = 0;
                for(int x = i - 1; x <= i + 1; x++){
                    for(int y = j - 1; y <= j + 1; y++){
                        if(0 <= x && x < n && 0 <= y && y < m){
                            sum += img[x][y];
                            cnt++;
                        }
                    }
                }
                res[i][j] = sum/cnt;
            }
        }
        return res;
    }
};