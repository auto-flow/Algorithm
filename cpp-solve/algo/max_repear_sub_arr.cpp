#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findLength(vector<int> &A, vector<int> &B) {
        int m = A.size(), n = B.size(), res = 0;
        // 枚举对应关系
        for (int diff = -(m - 1); diff <= n - 1; ++diff) {
            // 遍历公共部分
            for (int i = max(0, -diff), l = 0; i < min(m, n - diff); ++i) {
                l = (A[i] == B[i + diff]) ? (l + 1) : 0;
                res = max(res, l);
            }
        }
        return res;
    }
};

int main() {
    vector<int> a{1, 2, 3, 2, 1};
    vector<int> b{3, 2, 1, 4, 7};
    Solution().findLength(a, b)
}