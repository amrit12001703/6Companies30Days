#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define mod 1000000007
#define endl '\n'

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pii> perf;
        for (int i = 0; i < n; i++) {
            perf.push_back(pii(efficiency[i], speed[i]));
        }

        sort(perf.rbegin(), perf.rend());

        priority_queue<int> engineers;

        long teamSpeed = 0;
        long teamPerformances = 0;
        for (auto it : perf) {
            int spd = it.second;
            engineers.push(-spd);

            if (engineers.size() <= k) {
                teamSpeed += spd;
            }
            else {
                teamSpeed += spd + engineers.top();
                engineers.pop();
            }

            cout << teamSpeed << " " << it.first << endl;
            teamPerformances = max(teamPerformances, teamSpeed * it.first);
        }
        return teamPerformances % mod;
    }
};