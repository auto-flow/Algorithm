#include <bits/stdc++.h>

#define FF(a, b) for(int a=0;a<b;a++)
#define F(a, b) for(int a=1;a<=b;a++)
#define LEN 200
#define INF ((1<<30)-1)
#define bug(x) cout<<#x<<"="<<x<<endl;

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

int pre[LEN] = {8, 5, 2, 6, 10, 9, 11};
int in[LEN] = {2, 5, 6, 8, 9, 10, 11};

TreeNode *build_tree(int ps, int pe, int is, int ie) {
    if (ps > pe) return NULL;
    if (ps == pe) return new TreeNode(in[is]);
    int i = is;
    while (i <= ie && in[i] != pre[ps]) i++;
    // post -> pre ,  pe -> ps
    TreeNode *node = new TreeNode(in[i]);
    int n_left = i - is;    //左侧元素数量
    node->left = build_tree(ps + 1, ps + n_left, is, is + n_left - 1);
    node->right = build_tree(ps + n_left + 1, pe, i + 1, ie);
    // 相比post的左侧两个参数，全部 + 1 , 中序部分不变
    return node;
}

void preorder(TreeNode *node) {
    if (node == nullptr) return;
    printf("%d, ", node->val);
    preorder(node->left);
    preorder(node->right);
}

void inorder(TreeNode *node) {
    if (node == nullptr) return;
    inorder(node->left);
    printf("%d, ", node->val);
    inorder(node->right);
}

void postorder(TreeNode *node) {
    if (node == nullptr) return;
    postorder(node->left);
    postorder(node->right);
    printf("%d, ", node->val);
}

int main() {
    system("chcp 65001");
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
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    root->print();
    int n = 7;
    TreeNode *root_bd = build_tree(0, n - 1, 0, n - 1);
    root_bd->print();
    return 0;
}