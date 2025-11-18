#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int v) : data(v), left(NULL), right(NULL) {}
};

Node* insertNode(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data) root->left = insertNode(root->left, key);
    else if (key > root->data) root->right = insertNode(root->right, key);
    return root;
}

Node* minNode(Node* root) {
    if (!root) return NULL;
    while (root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return NULL;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            Node* r = root->right;
            delete root;
            return r;
        } else if (!root->right) {
            Node* l = root->left;
            delete root;
            return l;
        } else {
            Node* succ = minNode(root->right);
            root->data = succ->data;
            root->right = deleteNode(root->right, succ->data);
        }
    }
    return root;
}

int maxDepth(Node* root) {
    if (!root) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return 1 + max(l, r);
}

int minDepth(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    if (!root->left) return 1 + minDepth(root->right);
    if (!root->right) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    vector<int> keys = {50, 30, 70, 20, 40, 60, 80};
    for (int x : keys) root = insertNode(root, x);

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 20);
    root = deleteNode(root, 30);
    root = deleteNode(root, 50);

    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;

    cout << "Max depth: " << maxDepth(root) << endl;
    cout << "Min depth: " << minDepth(root) << endl;

    return 0;
}
