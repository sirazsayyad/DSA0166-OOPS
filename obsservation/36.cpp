#include <iostream>
#include <queue>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;
    void inorder(TreeNode* node);
    TreeNode* copyTree(TreeNode* node);
    bool compareTrees(TreeNode* node1, TreeNode* node2);
public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree();
    void insert(int value);
    void inorderTraversal();
    BinaryTree* copy();
    bool compare(BinaryTree* otherTree);
};

BinaryTree::~BinaryTree() {
    std::queue<TreeNode*> q;
    if (root) q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
        delete node;
    }
}

void BinaryTree::insert(int value) {
    TreeNode* newNode = new TreeNode(value);
    if (!root) {
        root = newNode;
        return;
    }
    TreeNode* current = root;
    TreeNode* parent = nullptr;
    while (true) {
        parent = current;
        if (value < current->data) {
            current = current->left;
            if (!current) {
                parent->left = newNode;
                return;
            }
        } else {
            current = current->right;
            if (!current) {
                parent->right = newNode;
                return;
            }
        }
    }
}

void BinaryTree::inorder(TreeNode* node) {
    if (node) {
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }
}

void BinaryTree::inorderTraversal() {
    inorder(root);
    std::cout << std::endl;
}

TreeNode* BinaryTree::copyTree(TreeNode* node) {
    if (!node) return nullptr;
    TreeNode* newNode = new TreeNode(node->data);
    newNode->left = copyTree(node->left);
    newNode->right = copyTree(node->right);
    return newNode;
}

BinaryTree* BinaryTree::copy() {
    BinaryTree* newTree = new BinaryTree();
    newTree->root = copyTree(root);
    return newTree;
}

bool BinaryTree::compareTrees(TreeNode* node1, TreeNode* node2) {
    if (!node1 && !node2) return true;
    if (!node1 || !node2) return false;
    return node1->data == node2->data && compareTrees(node1->left, node2->left) && compareTrees(node1->right, node2->right);
}

bool BinaryTree::compare(BinaryTree* otherTree) {
    return compareTrees(root, otherTree->root);
}

int main() {
    BinaryTree bt;
    bt.insert(50);
    bt.insert(30);
    bt.insert(70);
    bt.insert(20);
    bt.insert(40);
    bt.insert(60);
    bt.insert(80);

    bt.inorderTraversal();

    BinaryTree* copiedTree = bt.copy();
    copiedTree->inorderTraversal();

    std::cout << "Trees are " << (bt.compare(copiedTree) ? "equal" : "not equal") << std::endl;

    delete copiedTree;
    return 0;
}
