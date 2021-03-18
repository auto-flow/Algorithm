#include "bits/stdc++.h"
#include "tree.h"


using namespace std;

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int root = preorder[0];
        auto index = find(inorder.begin(), inorder.end(), root);
        int n_left = distance(index, inorder.begin()) - 1;
        int n_right = distance(inorder.end(), index) - 1;
//        return new TreeNode(
//                root,
//                buildTree(vector<int>(preorder.begin()+1,preorder.begin()+n_left+1),vector<int>()),
//                buildTree(),
//        );
    }
};

int main() {
    vector<int> v{1, 2, 3, 4};
    cout << *find(v.begin(), v.end(), 3) << endl;
    cout << distance(v.begin(), find(v.begin(), v.end(), 3)) << endl;
}