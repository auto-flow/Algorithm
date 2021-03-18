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