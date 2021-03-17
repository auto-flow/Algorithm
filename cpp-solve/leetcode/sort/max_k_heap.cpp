#include "bits/stdc++.h"

using namespace std;


struct cmp {
    bool operator()(int &a, int &b) {
        return a > b;
    }
};

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, cmp > heap;
        for (int num:nums) {
            if (heap.size() < k) {
                heap.push(num);
            } else if (num > heap.top()) {
                heap.pop();
                heap.push(num);
            }
        }
        return heap.top();
    }
};

struct cmp_vec{
    bool operator()(vector<int>& a,vector<int>& b){
        // 优先比较 0 然后 1 然后 2
        if(a[0]==b[0]){
            if(a[1]==b[1]){
                return a[2]>b[2];
            }
            return a[1]>b[1];
        }
        return a[0]>b[0];
}
};

void fuck_heap(){
    priority_queue<vector<int>, vector<vector<int>>, cmp_vec > heap;
    heap.push({1,2,3});
}

int main() {
    fuck_heap();
}