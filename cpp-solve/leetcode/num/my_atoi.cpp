#include "bits/stdc++.h"

using namespace std;

int my_atoi(string &s) {
    int num = 0;
    int i = 0;
    int len = s.size();
    int flag = 1;
    while (s[i] == ' ') {
        i++;
    }
    if (s[i] == '+') {
        i++;
    } else if (s[i] == '-') {
        flag = -1;
        i++;
    }
    while (i < len) {
        if (s[i] < '0' || s[i] > '9') break;
        int cur = (int) (s[i] - '0');
        if (num > INT_MAX / 10) { return flag == 1 ? INT_MAX : INT_MIN; }
        if (num == INT_MAX / 10) {
            if (flag == 1 && cur >= 7) return INT_MAX;
            if (flag == -1 && cur >= 8) return INT_MIN;
        }
        num = num * 10 + cur;
        i++;
    }
    return flag * num;
}


class Solution {
public:
    int myAtoi(string s) {
        return my_atoi(s);
    }
};

int main() {
    cout << Solution().myAtoi("-2147483648") << endl;
}

