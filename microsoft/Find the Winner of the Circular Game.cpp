class Solution {
public:
    int findTheWinner(int n, int k) {
        int lf = 0;
        for(int i = 2; i <= n; i++){
            lf = (lf + k) % i;
        }
        return lf + 1;
    }
};

//Josephus Problem
//g(i,k) = (g(i−1,k)+k) % i for i > 1
//https://en.wikipedia.org/wiki/Josephus_problem#The_general_case