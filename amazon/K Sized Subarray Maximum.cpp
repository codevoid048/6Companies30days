class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        vector<int> ans;
        deque<int>q(k);
        int i = 0, n = arr.size();
        for(; i < k; ++i){
            while((!q.empty()) && arr[i] >= arr[q.back()])
                q.pop_back();
            q.push_back(i);
        }
        for(; i < n; ++i){
            ans.push_back(arr[q.front()]);
            while((!q.empty()) && q.front() <= i - k) q.pop_front();
            while((!q.empty()) && arr[i] >= arr[q.back()]) q.pop_back();
            q.push_back(i);
        }
        ans.push_back(arr[q.front()]);
        return ans;
    }
};