class Solution {
public:
    int waysToReachStair(int k) {
        int res = 0;
        for(int i = 1, j = 1; j - k <= i; i++, j *= 2){
            res += C(i, j - k);
        }
        return res;
    }
    int C(int a, int b) {
        if(b > a || b < 0){
            return 0;
        }
        long long res = 1;
        for(int i = a, j = 1; j <= b; i--, j++){
            res *= i;
            res /= j;
        }
        return res;
    }
};