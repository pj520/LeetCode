//
// Created by ps on 18-9-6.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>


using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if (s.size() <= 10) return res;
        int mask = 0x7ffffff;
        unordered_map<int, int> m;
        int cur = 0, i = 0;
        while (i < 9) {
            cur = (cur << 3) | (s[i++] & 7);
        }
        while (i < s.size()) {
            cur = ((cur & mask) << 3) | (s[i++] & 7);
            if (m.find(cur) != m.end()) {
                if (m[cur] == 1) res.push_back(s.substr(i - 10, 10));
                ++m[cur];
            } else {
                m[cur] = 1;
            }
        }
        return res;
    }
};

class Solution2 {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> res;
        unordered_set<int> st;
        int cur = 0, i = 0;
        while (i < 9) cur = cur << 3 | (s[i++] & 7);
        while (i < s.size()) {
            cur = ((cur & 0x7ffffff) << 3) | (s[i++] & 7);
            if (st.count(cur)) res.insert(s.substr(i - 10, 10));
            else st.insert(cur);
        }
        return vector<string>(res.begin(), res.end());
    }
};

class Solution3 {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> res;
        unordered_set<int> st;
        unordered_map<int, int> m{{'A', 0},
                                  {'C', 1},
                                  {'G', 2},
                                  {'T', 3}};
        int cur = 0, i = 0;
        while (i < 9) cur = cur << 2 | m[s[i++]];
        while (i < s.size()) {
            cur = ((cur & 0x3ffff) << 2) | (m[s[i++]]);
            if (st.count(cur)) res.insert(s.substr(i - 10, 10));
            else st.insert(cur);
        }
        return vector<string>(res.begin(), res.end());
    }
};

class Solution4 {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string> res, st;
        for (int i = 0; i + 9 < s.size(); ++i) {
            string t = s.substr(i, 10);
            if (st.count(t)) res.insert(t);
            else st.insert(t);
        }
        return vector<string>{res.begin(), res.end()};
    }
};

int main(int argc, char *argv[]) {

    return 0;
}