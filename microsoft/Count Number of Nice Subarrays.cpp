class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int res = 0, n = nums.size(), cnt = 0;
        for(int i = 0; i < n; i++) nums[i] %= 2;
        vector<int> pr(n+1, 0);
        pr[0] = 1;
        for(int i = 0; i < n; i++){
            cnt += nums[i];
            if(cnt >= k) res += pr[cnt - k];
            pr[cnt]++;
        }
        return res;
    }
};