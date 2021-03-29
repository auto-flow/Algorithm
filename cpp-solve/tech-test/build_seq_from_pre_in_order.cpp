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
int post[LEN];
int t = 0;

void setPost(int ps,int pe,int is,int ie){
    if(ps>pe)return;//null
    if(ps==pe){
        post[t++]=pre[ps];
    }else{
        //find the elem is the pair of preOrder (ps)
        int i=is;
        while(in[i]!=pre[ps] && i<ie) i++;//redirect
        //left
        setPost(ps+1, ps+i-is, is, i-1);
        //right
        setPost(ps+i-is+1, pe, i+1, ie);
        //root
        post[t++]=pre[ps];
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
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    root->print();
    int n = 7;
    t = 0;
    setPost(0, n - 1, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        printf("%d, ", post[i]);
    }
    printf("\n");
    postorder(root);
    return 0;
}