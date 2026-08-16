class Solution {
public:
    bool dp[21][21];
    bool vis[21][21];

    bool solve(int i, int j, string &s, string &p) {
        if (j == p.size())
            return i == s.size();

        if (vis[i][j])
            return dp[i][j];

        vis[i][j] = true;

        bool firstMatch = (i < s.size() &&
                          (s[i] == p[j] || p[j] == '.'));

        if (j + 1 < p.size() && p[j + 1] == '*') {
            dp[i][j] = solve(i, j + 2, s, p) ||
                       (firstMatch && solve(i + 1, j, s, p));
        } else {
            dp[i][j] = firstMatch && solve(i + 1, j + 1, s, p);
        }

        return dp[i][j];
    }

    bool isMatch(string s, string p) {
        memset(vis, false, sizeof(vis));
        return solve(0, 0, s, p);
    }
};