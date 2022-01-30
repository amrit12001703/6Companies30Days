// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int height(int n) {
        // using positive root of n(n+1) = 2*n formula
        // return (-1 + sqrt(1 + 8*n)) / 2;

        // brute force
        int i = floor(sqrt(2 * n));

        int r = (i * (i + 1)) / 2;
        if (r > n) i--;

        return i;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        cout << ob.height(N) << endl;
    }
    return 0;
}  // } Driver Code Ends