#ifndef BST_H
#define BST_H
#include <iostream>

// 定义BST节点结构
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    int asl=0;
    BinarySearchTree() : root(nullptr) {}

    // 插入节点
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // 删除节点
    void remove(int value) {
        root = removeRecursive(root, value);
    }

    // 查找节点
    bool search(int value) {
        return searchRecursive(root, value);
    }

    // 中序遍历(排序)
    void inorderTraversal() {
        inorderRecursive(root);
    }

private:
    // 插入节点的递归实现
    TreeNode* insertRecursive(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->value) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->value) {
            node->right = insertRecursive(node->right, value);
        }

        return node;
    }

    // 删除节点的递归实现
    TreeNode* removeRecursive(TreeNode* node, int value) {
        if (node == nullptr) {
            return node;
        }

        if (value < node->value) {
            node->left = removeRecursive(node->left, value);
        } else if (value > node->value) {
            node->right = removeRecursive(node->right, value);
        } else {
            // 节点有一个或没有子节点的情况
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            // 节点有两个子节点的情况
            TreeNode* minRightSubtree = findMin(node->right);
            node->value = minRightSubtree->value;
            node->right = removeRecursive(node->right, minRightSubtree->value);
        }
        return node;
    }

    // 查找节点的递归实现
    bool searchRecursive(TreeNode* node, int value) {
        if (node == nullptr) {
            return false;
        }
        asl++;
        if (value == node->value) {
            return true;
        } else if (value < node->value) {
            return searchRecursive(node->left, value);
        } else {
            return searchRecursive(node->right, value);
        }
    }

    // 中序遍历的递归实现(排序)
    void inorderRecursive(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        inorderRecursive(node->left);
        std::cout << node->value << " ";
        inorderRecursive(node->right);
    }

    // 查找子树中的最小值节点
    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    TreeNode* root;
};



#endif