#include <iostream>
#include <stack>
using namespace std;

// Structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Non-recursive preorder traversal
void preorder(Node* root) {
    if (root == nullptr)
        return;

    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* current = s.top();
        s.pop();

        cout << current->data << " ";

        // Push the right child first
        if (current->right != nullptr)
            s.push(current->right);

        // Push the left child second
        if (current->left != nullptr)
            s.push(current->left);
    }
}

int main() {
    // Create the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Display preorder traversal
    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    // Free allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
