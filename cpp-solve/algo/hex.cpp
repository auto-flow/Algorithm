#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string get_hex(int num) {
        char chr[2] = {0};
        if (num <= 9) chr[0] = char('0' + num);
        else chr[0] = char('a' + num - 10);
        return string(chr);
    }

    string toHex(int num) {
        if(num==0)
            return "0";
        unsigned int u = num;
        string ans;
        while (u) {
            ans += get_hex(u & 15);
            u >>= 4;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    cout << Solution().toHex(26);
}