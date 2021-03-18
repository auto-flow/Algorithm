#include <bits/stdc++.h>

#define FF(a, b) for(int a=0;a<b;a++)
#define F(a, b) for(int a=1;a<=b;a++)
#define LEN 200
#define INF ((1<<30)-1)
#define bug(x) cout<<#x<<"="<<x<<endl;

using namespace std;
typedef long long ll;
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
int in[LEN];
int post[LEN] = {2, 6, 5, 9, 11, 10, 8};
int t = 0;
int flag = 1;

void setIn(int preS, int preE, int postS, int postE) {
    if (preS == preE) {
        in[t++] = pre[preS];
        return;
    }
    //finding the elem which is the root of left sub_tree
    int i = postS;
    while (i <= postE && post[i] != pre[preS + 1]) i++;
    //calculate the numbers of left sub_tree
    int leftNum = i - postS + 1;
    //is paradox
    if (i == postE - 1) {
        flag = 0;
        setIn(preS + 1, preS + leftNum, postS, i);//default consider this is a right leaf
        in[t++] = pre[preS];
        return;
    }
    //build the in_order traversal sequence
    setIn(preS + 1, preS + leftNum, postS, i);
    in[t++] = pre[preS];
    setIn(preS + leftNum + 1, preE, i + 1, postE - 1);
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
    postorder(root);
    printf("\n");
    root->print();
    int n = 7;
    t = 0;
    setIn(0, n - 1, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        printf("%d, ", in[i]);
    }
    printf("\n");
    inorder(root);
    bug(flag)
    return 0;
}