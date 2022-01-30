// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
public:
    //Function to find the largest number after k swaps.
    void findMaxUtil(string str, string& max, int k, int pos)
    {
        if (k == 0)
            return;

        char maxm = str[pos];
        for (int i = pos + 1; i < str.length();i++)
        {
            if (maxm < str[i])
                maxm = str[i];
        }

        if (maxm != str[pos])
            k--;

        for (int i = str.length() - 1; i >= pos;i--)
        {
            if (str[i] == maxm)
            {
                swap(str[i], str[pos]);
                if (str.compare(max) > 0)
                    max = str;

                findMaxUtil(str, max, k, pos + 1);

                swap(str[i], str[pos]);
            }
        }
    }

    string max = "";
    // int stoi(string str) {
    //     int temp = 0;
    //     for (int i = 0; i < str.length(); i++) {
    //         temp = temp * 10 + (str[i] - '0');
    //     }
    //     return temp;
    // }
    // // using recursion and backtracking
    // void helper(string str, int k) {
    //     if(stoi(str) > stoi(mx)) {
    //         mx = str;
    //     }

    //     if(k==0)    return;
    //     // iterating and swapping all possiblities
    //     for(int i = 0; i<str.size()-1; i++) {
    //         for(int j=i+1; j<str.size(); j++) {
    //             if(str[j] > str[i]) {
    //                 string temp = str;
    //                 swap(temp[j], temp[i]);
    //                 helper(temp, k-1);
    //             }
    //         }
    //     }
    // }

    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
        findMaxUtil(str, max, k, 0);
        // helper(str, k);
        return max;
    }

};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
// } Driver Code Ends