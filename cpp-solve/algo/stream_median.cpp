#include "bits/stdc++.h"

using namespace std;

class MedianFinder {
public:
    priority_queue<int> lo;
    priority_queue<int, vector<int>, greater<int> > hi;

    void addNum(int num) {
        lo.push(num);
        hi.push(lo.top());
        lo.pop();
        if (lo.size() < hi.size()) {
            lo.push(hi.top());
            hi.pop();
        }
    }

    double findMedian() {
        if (lo.size() == hi.size()) {
            return (lo.top() + hi.top()) / 2;
        } else {
            return lo.top();
        }
    }
};

int main() {
    MedianFinder medianFinder;
    medianFinder.addNum(1);
    medianFinder.addNum(2);
    medianFinder.addNum(3);
    medianFinder.addNum(4);
    cout<<"fuck";
}