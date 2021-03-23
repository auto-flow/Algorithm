#include "bits/stdc++.h"

using namespace std;

int main() {
    double x = 3;
    double l = 0, r = x, eps = 1e-8, mid;
    while (l < r) {
        mid = (l + r) / 2;
        double cx = mid * mid;
        if (abs(cx - x) < eps) break;
        if (cx < x) l = mid;
        else r = mid;
    }
}