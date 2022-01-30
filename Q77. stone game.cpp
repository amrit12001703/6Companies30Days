class Solution {
public:
    // using dp
    bool stoneGame(vector<int>& piles) {
        // when alex just needs to win
        // since given that piles.length is even, but sum(piles[i]) is odd is odd
        // which means the one playing first can brute force win the game
        // this can be valid solution given winner doesn't need to score max stones

        // eg - 5   3   4   5   --->>> alex have choice to pick either even index or odd index element, he picks odd
        //      5   3   4       --->>> bob has no choice but to pick any even index element, he picks max
        //          3   4       --->>> alex has even index as well as odd index choice, he picks odd
        //          3           --->>> bob is left with no choice but to pick even
        //          bob has 8, while alex have 9 stones thus alex can brute force always win the game
        return true;

        // but if alex needs to win as well as score max possible stones
        // return maxStones(piles, piles.size()) > 0;
    }

    //     int maxStones(vector<int>& arr, int n) {
    //         // similar to pots of gold game in gfg
    //         vector<vector<int>> dp(n, vector<int>(n));

    //         // using dp gap method
    //         for (int gap = 0; gap < n; gap++) {
    //             for (int i = 0, j = gap; j < n; j++, i++) {
    //                 if (gap == 0) {
    //                     dp[i][j] = arr[i];
    //                 }
    //                 else if (gap == 1) {
    //                     dp[i][j] = max(arr[i], arr[j]);
    //                 }
    //                 else {
    //                     // when i pick ith pot
    //                     // opponent will pick either i+1th pot, in that case i can pick from i+2 - j
    //                     // or he can pick jth pot, in that case i can pick from i+1 - j-1
    //                     int vali = arr[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
    //                     // same when j pick jth pot
    //                     int valj = arr[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);

    //                     // I will pick such value which will give me overall win
    //                     // for that i-to-j interval
    //                     int val = max(vali, valj);

    //                     dp[i][j] = val;
    //                 }
    //             }
    //         }

    //         return dp[0][n - 1];
    //     }
};