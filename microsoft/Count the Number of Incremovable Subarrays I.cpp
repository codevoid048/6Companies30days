class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int prev = -1, f = 1;
                for(int k = 0; k < n; k++){
                    if(k >= i && k <= j) continue;
                    if(prev >= nums[k]){ 
                        f = 0; 
                        break; 
                    }
                    prev = nums[k];
                }
                cnt += f;
            }
        }
        return cnt;
   }
};