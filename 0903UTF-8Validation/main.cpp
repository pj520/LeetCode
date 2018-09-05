//
// Created by ps on 18-9-3.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    bool validUtf8(vector<int> &data) {
        for (int i = 0; i < data.size(); ++i) {
            if (data[i] < 0b10000000) {
                continue;
            } else {
                int cnt = 0, val = data[i];
                for (int j = 7; j >= 1; --j) {
                    if (val >= pow(2, j)) ++cnt;
                    else break;
                    val -= pow(2, j);
                }
                if (cnt == 1) return false;
                for (int j = i + 1; j < i + cnt; ++j) {
                    if (data[j] > 0b10111111 || data[j] < 0b10000000)
                        return false;
                }
                i += cnt - 1;
            }
        }
        return true;
    }
};

class Solution2 {
public:
    bool validUtf8(vector<int> &data) {
        int cnt = 0;
        for (int d : data) {
            if (cnt == 0) {
                if ((d >> 5) == 0b110) cnt = 1;
                else if ((d >> 4) == 0b1110) cnt = 2;
                else if ((d >> 3) == 0b11110) cnt = 3;
                else if (d >> 7) return false;
            } else {
                if ((d >> 6) != 0b10) return false;
                --cnt;
            }
        }
        return cnt == 0;
    }
};


int main(int argc, char *argv[]) {

    vector<int> testV;
//    [248,130,130,130]
    testV.push_back(248);
    testV.push_back(130);
    testV.push_back(130);
    testV.push_back(130);

    Solution solution;
    bool ret = solution.validUtf8(testV);

    return 0;
}