#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Recursive preorder traversal
void recursivePreorder(Node* root, vector<int>& result) {
    if (root == NULL)
        return;

    result.push_back(root->data);
    recursivePreorder(root->left, result);
    recursivePreorder(root->right, result);
}

// Display current stack contents
void displayStack(stack<Node*> s) {
    cout << "Stack (top to bottom): ";

    if (s.empty()) {
        cout << "Empty";
    }

    while (!s.empty()) {
        cout << s.top()->data << " ";
        s.pop();
    }

    cout << endl;
}

// Non-recursive preorder traversal
vector<int> iterativePreorder(Node* root, int& maxStackSize) {
    vector<int> result;
    stack<Node*> s;
    maxStackSize = 0;

    if (root == NULL)
        return result;

    s.push(root);
    maxStackSize = s.size();

    cout << "\n--- Non-Recursive Preorder Traversal ---\n";

    while (!s.empty()) {
        displayStack(s);

        Node* current = s.top();
        s.pop();

        cout << "Visited node: " << current->data << endl;
        result.push_back(current->data);

        // Push right child first
        if (current->right != NULL)
            s.push(current->right);

        // Push left child second
        if (current->left != NULL)
            s.push(current->left);

        if ((int)s.size() > maxStackSize)
            maxStackSize = s.size();

        cout << "After processing node " << current->data << ":\n";
        displayStack(s);
        cout << "-----------------------------\n";
    }

    return result;
}

int main() {
    // Create binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int maxStackSize = 0;

    vector<int> iterativeResult =
        iterativePreorder(root, maxStackSize);

    vector<int> recursiveResult;
    recursivePreorder(root, recursiveResult);

    cout << "\nNon-Recursive Preorder: ";
    for (int value : iterativeResult)
        cout << value << " ";

    cout << "\nRecursive Preorder: ";
    for (int value : recursiveResult)
        cout << value << " ";

    cout << "\n\nComparison: ";

    if (iterativeResult == recursiveResult)
        cout << "Both traversals produce the same output.\n";
    else
        cout << "Traversal outputs are different.\n";

    cout << "Maximum stack size used: "
         << maxStackSize << endl;

    return 0;
}
