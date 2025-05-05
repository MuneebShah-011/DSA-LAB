#include <iostream>
using namespace std;

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
};

class BST {
private:
    BSTNode* root;

    void inorder(BSTNode* node) {
        if (node == NULL)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    BSTNode* insert(BSTNode* node, int val) {
        if (node == NULL) {
            BSTNode* newNode = new BSTNode();
            newNode->data = val;
            newNode->left = newNode->right = NULL;
            return newNode;
        }
        if (val < node->data)
            node->left = insert(node->left, val);
        else
            node->right = insert(node->right, val);
        return node;
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int val) {
        root = insert(root, val);
        cout << val << " " << endl;
    }

    void display() {
        inorder(root);
        cout << endl;
    }
};

int height(struct AVLNode* node);

struct AVLNode {
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;
};

class AVL {
private:
    AVLNode* root;

    int height(AVLNode* node) {
        return node ? node->height : 0;
    }

    int getBalance(AVLNode* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));
        return x;
    }

    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));
        return y;
    }

    AVLNode* insert(AVLNode* node, int val) {
        if (node == NULL) {
            AVLNode* newNode = new AVLNode();
            newNode->data = val;
            newNode->left = newNode->right = NULL;
            newNode->height = 1;
            return newNode;
        }
        if (val < node->data)
            node->left = insert(node->left, val);
        else
            node->right = insert(node->right, val);

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);

        if (balance > 1 && val < node->left->data)
            return rightRotate(node);

        if (balance < -1 && val > node->right->data)
            return leftRotate(node);

        if (balance > 1 && val > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && val < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorder(AVLNode* node) {
        if (node == NULL)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    AVL() {
        root = NULL;
    }

    void insert(int val) {
        root = insert(root, val);
        cout << val << " " << endl;
    }

    void display() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST obj1;
    cout << "Testing BST\n";
    obj1.insert(30);
    obj1.insert(20);
    obj1.insert(40);
    obj1.insert(10);

    cout << "Inorder traversal: ";
    obj1.display();

    AVL obj2;
    cout << "\nTesting AVL\n";
    obj2.insert(30);
    obj2.insert(20);
    obj2.insert(40);
    obj2.insert(10);

    cout << "Inorder traversal: ";
    obj2.display();

    return 0;
}

