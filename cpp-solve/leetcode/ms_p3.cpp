#include "bits/stdc++.h"

using namespace std;

int solution(vector<int> &A, int M) {
    map<int, int> hashmap;
//    map<int,vector<int>>  hashmap;
    for (int num:A) {
        int m = num % M;
        if (m < 0) m += M;
        hashmap[m]++;
    }
    int ans = 0;
    for (int m = 0; m < M; ++m) {
        ans = max(ans, hashmap[m]);
    }
    return ans;
}

int main() {
//    cout << -4 % 3 << endl;
    vector<int> case1 = {-3, -2, 1, 0, 8, 7, 1};
    vector<int> case2 = {7, 1, 11, 8, 4, 10};
    cout << solution(case1, 3) << endl;
    cout << solution(case2, 8) << endl;
    return 0;
}