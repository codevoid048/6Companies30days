class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long mxsum = 0, sum = 0;
        int l = 0;
        map<int,int> mp;
        for(int i = 0; i < nums.size(); i++){
            if(i - l + 1 <= k){
                if(mp.find(nums[i]) == mp.end()){
                   sum += nums[i];
                   mp[nums[i]]++;
                }
                else{
                    while(nums[l] != nums[i]){
                        sum -= nums[l];
                        mp.erase(nums[l]);
                        l++;
                    }
                    mp[nums[l]]--;
                    l++;
                }
            }
            //cout << sum << " ";
            if(i - l + 1 == k){
                mxsum = max(sum, mxsum);
                mp.erase(nums[l]);
                sum -= nums[l];
                l++;
           }
        }
        return mxsum;
    }
};