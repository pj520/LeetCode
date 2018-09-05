//
// Created by ps on 18-9-3.
//

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;
        int upper = pow(10, n) - 1;
        int lower = pow(10, n - 1);
        for (int i = upper; i > lower; --i) {
            long long cand = creatPalindrome(i);
            for (int j = upper; cand / j < j; --j) {
                if (cand % j == 0) return cand % 1337;
            }
        }
        return -1;
    }

private:
    long long creatPalindrome(int n) {
        string lastHalf = to_string(n);
        reverse(lastHalf.begin(), lastHalf.end());
        return stoll(to_string(n) + lastHalf);
    }
};

class Solution2 {
public:
    int largestPalindrome(int n) {
        if (n == 1)
            return 9;
        for (int tot = 2; tot < 9 * static_cast<int>(std::pow(10, n - 1)); tot++) {
            int top = static_cast<int>(std::pow(10, n)) - tot;
            std::string help = std::to_string(top);
            std::reverse(help.begin(), help.end());
            int bot = std::stoi(help);
            long long mid = tot * static_cast<long long>(tot) - 4 * bot;
            if (mid >= 0)
                if (std::pow(mid, 0.5) == static_cast<int>(std::pow(mid, 0.5)))
                    return (top * static_cast<long long>(std::pow(10, n)) + bot) % 1337;
        }
        return 0;
    }
};

int main(int argc, char *argv[]) {

    return 0;
}