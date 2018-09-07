//
// Created by ps on 18-9-7.
//

#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return n1 + n2 - 2 * dp[n1][n2];
    }
};

class Solution2 {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 0; i <= n1; ++i) dp[i][0] = i;
        for (int j = 0; j <= n2; ++j) dp[0][j] = j;
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n1][n2];
    }
};

class Solution3 {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> memo(n1 + 1, vector<int>(n2 + 1, 0));
        return helper(word1, word2, 0, 0, memo);
    }

    int helper(string word1, string word2, int p1, int p2, vector<vector<int>> &memo) {
        if (memo[p1][p2] != 0) return memo[p1][p2];
        int n1 = word1.size(), n2 = word2.size();
        if (p1 == n1 || p2 == n2) return n1 - p1 + n2 - p2;
        if (word1[p1] == word2[p2]) {
            memo[p1][p2] = helper(word1, word2, p1 + 1, p2 + 1, memo);
        } else {
            memo[p1][p2] = 1 + min(helper(word1, word2, p1 + 1, p2, memo), helper(word1, word2, p1, p2 + 1, memo));
        }
        return memo[p1][p2];
    }
};

int main(int argc, char *argv[]) {

    return 0;
}