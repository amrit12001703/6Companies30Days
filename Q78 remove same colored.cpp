class Solution {
public:
    // since the move made by one player doesnt effect second player
    // all we need to do is to calculate the consequetive a, and b
    // no of moves will will be n-3
    // the one with max moves will win
    bool winnerOfGame(string s) {

        int a = 0, b = 0, n = s.size();

        for (int i = 1; i < n - 1; i++) {
            // if 3 consequetive alphabets are similar
            if (s[i - 1] == s[i] && s[i] == s[i + 1]) {
                if (s[i] == 'A')
                    a++;
                else
                    b++;
            }
        }

        return a > b;
    }
};