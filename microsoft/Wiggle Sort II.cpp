class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> temp(nums);
        sort(temp.begin(), temp.end());
        int l = 0, r = nums.size() - 1;
        int m = r/2 + 1;
        while(r >= 0){
            if(r & 1) nums[r] = temp[m++];
            else nums[r] = temp[l++];
            r--;
        }
        // vector<int> fr(5001, 0);
        // for(int &i : nums) fr[i]++;
        // int x = 1, y = 0, n = nums.size(), i = 5000;
        // while(i >= 0){
        //     if(fr[i]){
        //         nums[x < n ? x : y] = i;
        //         if(x < n) x += 2;
        //         else y += 2;
        //         fr[i]--;
        //     }
        //     else i--;
        // }
    }
};