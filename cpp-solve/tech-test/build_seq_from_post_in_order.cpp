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

int pre[LEN];
int in[LEN] = {2, 5, 6, 8, 9, 10, 11};
int post[LEN] = {2, 6, 5, 9, 11, 10, 8};
int t=0;

void setPre(int ps,int pe,int is,int ie){
    if(ps>pe)return;//null
    if(ps==pe){
        pre[t++]=post[ps];
    }else{
        //find the elem is the pair of preOrder (ps)
        int i=is;
        while(in[i]!=post[pe] && i<ie) i++;//redirect
        //root
        pre[t++]=post[pe];
        //left
        setPre(ps, ps+i-is-1, is, i-1);
        //right
        setPre(ps+i-is, pe-1, i+1, ie);
    }
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
    postorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    root->print();
    int n=7;
    t=0;
    setPre(0, n - 1, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        printf("%d, ",pre[i]);
    }
    printf("\n");
    preorder(root);
    return 0;
}