#include "bits/stdc++.h"

using namespace std;

int partition(vector<int> &nums, int l, int r) {
    int rix = rand() % (r - l + 1) + l;
    swap(nums[rix], nums[l]);
    int j = l, pivot = nums[l];
    for (int i = l + 1; i <= r; ++i) {
        if (nums[i] < pivot) {
            ++j;
            swap(nums[j], nums[i]);
        }
    }
    swap(nums[j], nums[l]);
    return j;
}


class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int target = n - k;
        while (true) {
            int j = partition(nums, l, r);
            if (j == target) return nums[j];
            else if (j < target) l = j + 1;
            else r = j - 1;
        }
    }
};

int main() {
    vector<int> v{2, 1};
    int ans = Solution().findKthLargest(v, 2);
    cout << ans << endl;
}