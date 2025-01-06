class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size(), mxlen = 0, i = 0;
        while(i < n){
            bool incr = 0, decr = 0;
            int st = i;
            while(i + 1 < n && arr[i] < arr[i+1]){
                incr = true;
                i++;
            }
            while(incr && i + 1 < n && arr[i] > arr[i+1]){
                decr = true;
                i++;
            }
            if(incr && decr) mxlen = max(mxlen, i - st + 1);
            else i++;
        }
        return mxlen;
    }
};