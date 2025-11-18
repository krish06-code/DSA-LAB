#include <iostream>
#include <vector>
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

Node* searchRec(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return searchRec(root->left, key);
    else return searchRec(root->right, key);
}

Node* searchIter(Node* root, int key) {
    while (root && root->data != key) {
        if (key < root->data) root = root->left;
        else root = root->right;
    }
    return root;
}

Node* minNode(Node* root) {
    if (!root) return NULL;
    while (root->left) root = root->left;
    return root;
}

Node* maxNode(Node* root) {
    if (!root) return NULL;
    while (root->right) root = root->right;
    return root;
}

Node* inorderSuccessor(Node* root, int key) {
    Node* curr = root;
    Node* succ = NULL;
    while (curr && curr->data != key) {
        if (key < curr->data) {
            succ = curr;
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    if (!curr) return NULL;
    if (curr->right) return minNode(curr->right);
    return succ;
}

Node* inorderPredecessor(Node* root, int key) {
    Node* curr = root;
    Node* pred = NULL;
    while (curr && curr->data != key) {
        if (key > curr->data) {
            pred = curr;
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }
    if (!curr) return NULL;
    if (curr->left) return maxNode(curr->left);
    return pred;
}

int main() {
    Node* root = NULL;
    vector<int> keys = {50, 30, 70, 20, 40, 60, 80};
    for (int x : keys) root = insertNode(root, x);

    int key = 40;
    Node* s1 = searchRec(root, key);
    Node* s2 = searchIter(root, key);
    Node* mn = minNode(root);
    Node* mx = maxNode(root);
    Node* succ = inorderSuccessor(root, key);
    Node* pred = inorderPredecessor(root, key);

    if (s1) cout << "Found(rec): " << s1->data << endl;
    else cout << "Not found(rec)\n";
    if (s2) cout << "Found(iter): " << s2->data << endl;
    else cout << "Not found(iter)\n";
    if (mn) cout << "Min: " << mn->data << endl;
    if (mx) cout << "Max: " << mx->data << endl;
    if (succ) cout << "Successor of " << key << " is " << succ->data << endl;
    else cout << "No successor\n";
    if (pred) cout << "Predecessor of " << key << " is " << pred->data << endl;
    else cout << "No predecessor\n";

    return 0;
}
