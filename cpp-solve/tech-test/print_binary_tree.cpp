#include <bits/stdc++.h>

using namespace std;
typedef int ll;
const double pi = acos(-1);

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() {
        this->left = nullptr;
        this->right = nullptr;
        val = -1;
    };

    TreeNode(int val) {
        this->left = nullptr;
        this->right = nullptr;
        this->val = val;
    };

    TreeNode(int val, TreeNode *left, TreeNode *right) {
        this->left = left;
        this->right = right;
        this->val = val;
    };

    void printBT(const std::string &prefix, const TreeNode *node, bool isLeft) {
        if (node != nullptr) {
            std::cout << prefix;

            std::cout << (isLeft ? "├──" : "└──");

            // print the value of the node
            std::cout << node->val << std::endl;

            // enter the next tree level - left and right branch
            printBT(prefix + (isLeft ? "│   " : "    "), node->left, true);
            printBT(prefix + (isLeft ? "│   " : "    "), node->right, false);
        }
    }

    void print() {
        printBT("", this, false);
    }
};


int main() {
    // 控制台显示乱码纠正
    system("chcp 65001"); //设置字符集 （使用SetConsoleCP(65001)设置无效，原因未知）
    // pass the root node of your binary tree
    TreeNode *root = new TreeNode(
            8,
            new TreeNode(
                    5,
                    new TreeNode(2),
                    new TreeNode(6)
            ),
            new TreeNode(
                    10,
                    new TreeNode(9),
                    new TreeNode(11)
            )
    );
    root->print();
    return 0;
}