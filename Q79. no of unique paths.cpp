// { Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
public:
    //Function to find total number of unique paths.
    // using simple 2d dp
    // where dp[i][j] represent possible unique ways to reach there
    // can also be done using dfs
    int dfs(vector <vector<int>> dp, int i, int j) {
        if(i>dp.size() || j>dp[0].size() || !dp[i][j]) {
            return 0;
        }

        if(i == dp.size() || j == dp[0].size()) return 1;

        dp[i][j] = 0;
        int total = dfs(dp, i+1, j) + dfs(dp, i, j+1);

        return total;
    }
    int NumberOfPath(int a, int b)
    {
        vector <vector<int>> dp(a , vector<int> (b, 1));
        return dfs(dp, 0, 0);

        // vector <vector<int>> dp(a+1 , vector<int> (b+1, 1));
        // for(int i=1; i<=a; i++){
        //     for(int j=1; j<=b; j++){
        //         dp[i][j] = dp[i-1][j] + dp[i][j-1];
        //     }
        // }
        // return dp[a-1][b-1];
    }
};


// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        //taking dimensions of the matrix
        int a, b;
        cin >> a >> b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a, b) << endl;
    }
}

// } Driver Code Ends