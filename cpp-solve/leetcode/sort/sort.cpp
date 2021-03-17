#include "bits/stdc++.h"
#include "vector_util.h"

using namespace std;

class Heap {
    vector<int> heap;

    void sink(vector<int> &nums, int k, int n) {
        while (true) {
            int i = k * 2 + 1, j = k * 2 + 2;
            if (i >= n) break;
            int min_ix = i;
            if (j < n && nums[j] < nums[i]) min_ix = j;
            if (nums[min_ix] > nums[k]) break;
            swap(nums[min_ix], nums[k]);
            k = min_ix;
        }
    }

    void swim(vector<int> &nums, int k) {
        for (int p = (k + 1) / 2; p >= 0 && nums[p] < nums[k]; k = p, p = (k + 1) / 2) {
            swap(nums[k], nums[p]);
        }
    }

    void push(int elem) {
        heap.push_back(elem);
        swim(heap, heap.size() - 1);
    }

    int pop() {
        int n = heap.size();
        int ret = heap[0];
        swap(heap[0], heap[n - 1]);
        sink(heap, 0, n - 1);
        heap.pop_back();
        return ret;
    }
};

class Solution {
public:
    // -----------堆排序-----------------------------------
    void sink(vector<int> &nums, int k, int n) {
        while (true) {
            int i = k * 2 + 1, j = k * 2 + 2;
            if (i >= n) break;
            int min_ix = i;
            if (j < n && nums[j] < nums[i]) min_ix = j;
            if (nums[min_ix] > nums[k]) break;
            swap(nums[min_ix], nums[k]);
            k = min_ix;
        }
    }

    void swim(vector<int> &nums, int k) {
        for (int p = (k + 1) / 2; p >= 0 && nums[p] < nums[k]; k = p, p = (k + 1) / 2) {
            swap(nums[k], nums[p]);
        }
    }

    void heap_sort(vector<int> &nums) {
        int n = nums.size();
        for (int k = n / 2; k >= 0; --k) {
            sink(nums, k, n);
        }
        while (n > 0) {
            swap(nums[0], nums[--n]);
            sink(nums, 0, n);
        }
        reverse(nums.begin(), nums.end());
    }

    // -----------归并排序-----------------------------------
    void bottom_up_merge_sort(vector<int> &nums) {
        int n = nums.size();
        for (int sz = 1; sz < n; sz <<= 1) {
            for (int l = 0; l + sz < n; l += sz * 2) {
                int r = min(l + 2 * sz - 1, n - 1);
                int mid = l + sz - 1;
                merge(nums, l, r, mid);
            }
        }
    }

    void merge(vector<int> &nums, int l, int r, int mid) {
        int i = l, j = mid + 1, k = 0;
        vector<int> merged(r - l + 1, 0);
        while (i <= mid && j <= r) {
            if (nums[i] < nums[j]) merged[k++] = nums[i++];
            else merged[k++] = nums[j++];
        }
        while (i <= mid) merged[k++] = nums[i++];
        while (j <= r) merged[k++] = nums[j++];
        for (i = 0; i < k; ++i) nums[l + i] = merged[i];
    }

    void merge_sort(vector<int> &nums, int l, int r) {
        if (l >= r) return;
        int mid = (l + r) / 2;
        merge_sort(nums, l, mid);
        merge_sort(nums, mid + 1, r);
        merge(nums, l, r, mid);
    }

    // -----------快速排序-----------------------------------
    void quick_sort_with_stack(vector<int> &nums) {
        deque<vector<int>> stack;
        stack.push_back({0, (int) nums.size() - 1});
        while (!stack.empty()) {
            vector<int> top = stack.back(); // 不能用 &
            stack.pop_back();
            int l = top[0], r = top[1];
            if (l >= r) continue;
            int j = partition(nums, l, r);
            stack.push_back({l, j - 1});
            stack.push_back({j + 1, r});
        }
    }

    int partition(vector<int> &nums, int l, int r) {
        int rid = rand() % (r - l + 1) + l;
        swap(nums[l], nums[rid]);
        int j = l;
        int pivot = nums[l];
        for (int i = l + 1; i <= r; i++) {
            if (nums[i] < pivot) {
                j += 1;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[l], nums[j]);
        return j;
    }

    void quick_sort(vector<int> &nums, int l, int r) {
        if (l >= r) return;
        int j = partition(nums, l, r);
        quick_sort(nums, l, j - 1);
        quick_sort(nums, j + 1, r);
    }

    vector<int> MySort(vector<int> &arr) {
        int n = arr.size();
        heap_sort(arr);
        return arr;
    }
};

int main() {
    vector<int> nums = {884688278, 387052570, 77481420, 537616843, 659978110, 215386675, 604354651, 64838842, 830623614,
                        544526209, 292446044, 570872277, 946770900, 411203381, 445747969, 480363996, 31693639,
                        303753633, 261627544, 884642435, 978672815, 427529125, 111935818, 109686701, 714012242,
                        691252458, 230964510, 340316511, 917959651, 544069623, 193715454, 631219735, 219297819,
                        151485185, 986263711, 805374069, 915272981, 493886311, 970466103, 819959858, 733048764,
                        393354006, 631784130, 70309112, 513023688, 17092337, 698504118, 937296273, 54807658, 353487181,
                        82447697, 177571868, 830140516, 536343860, 453463919, 998857732, 280992325, 13701823, 728999048,
                        764532283, 693597252, 433183457, 157540946, 427514727, 768122842, 782703840, 965184299,
                        586696306, 256184773, 984427390, 695760794, 738644784, 784607555, 433518449, 440403918,
                        281397572, 546931356, 995773975, 738026287, 861262547, 119093579, 521612397, 306242389,
                        84356804, 42607214, 462370265, 294497342, 241316335, 158982405, 970050582, 740856884, 784337461,
                        885254231, 633020080, 641532230, 421701576, 298738196, 918973856, 472147510, 169670404};
//    vector<int> nums={};
    Solution().MySort(nums);
    cout << vector2str(nums) << endl;
    cout << nums[nums.size() - 2] << endl;
    cout << 986263711 << endl;
}