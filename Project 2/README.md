# Non-Recursive Preorder Traversal of a Binary Tree in C++

## Project Overview

This project implements preorder traversal of a binary tree without using recursion. It uses a stack data structure to traverse the tree iteratively.

Preorder traversal visits nodes in the following order:

**Root → Left → Right**

The project demonstrates the use of binary trees, stacks, pointers, and iterative algorithms in C++.

## Objectives

- To implement preorder traversal without recursion.
- To use a stack for traversing a binary tree.
- To understand binary tree data structures.
- To learn iterative tree traversal techniques.
- To analyze the time and space complexity of the algorithm.

## Technologies Used

- **Programming Language:** C++
- **Data Structure:** Binary Tree
- **Stack:** C++ Standard Template Library (STL)
- **Header Files:** `<iostream>` and `<stack>`
- **Compiler:** GCC/G++ or any standard C++ compiler

## What Is Preorder Traversal?

Preorder traversal is a depth-first search technique used to visit all nodes in a binary tree.

The traversal follows three steps:

1. Visit the root node.
2. Traverse the left subtree.
3. Traverse the right subtree.

### Example Binary Tree

```text
        1
       / \
      2   3
     / \
    4   5
```

### Preorder Traversal Output

```text
1 2 4 5 3
```

## Algorithm

1. Start.
2. Check whether the root node is `NULL`.
3. If the root is `NULL`, stop the traversal.
4. Create an empty stack.
5. Push the root node onto the stack.
6. Repeat while the stack is not empty:
   - Pop the top node from the stack.
   - Print the node's data.
   - If the right child exists, push it onto the stack.
   - If the left child exists, push it onto the stack.
7. Stop when the stack becomes empty.

### Why Is the Right Child Pushed First?

A stack follows the LIFO (Last In, First Out) principle.

The right child is pushed first, followed by the left child. Therefore, the left child is processed first.

This ensures that the traversal follows the correct preorder sequence:

**Root → Left → Right**

## Source Code

Save the following code in a file named `preorder.cpp`.

```cpp
#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

void preorder(Node* root) {
    if (root == nullptr)
        return;

    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* current = s.top();
        s.pop();

        cout << current->data << " ";

        if (current->right != nullptr)
            s.push(current->right);

        if (current->left != nullptr)
            s.push(current->left);
    }
}

int main() {
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Preorder Traversal: ";
    preorder(root);

    cout << endl;

    return 0;
}
```

## How to Compile and Run

### Step 1: Install a C++ Compiler

Install GCC/G++ or another C++ compiler if it is not already available on your system.

### Step 2: Compile the Program

Open a terminal in the project directory and execute:

```bash
g++ preorder.cpp -o preorder
```

### Step 3: Run the Program

**On Windows:**

```bash
preorder.exe
```

**On Linux or macOS:**

```bash
./preorder
```

## Sample Output

```text
Preorder Traversal: 1 2 4 5 3
```

## Complexity Analysis

Let `n` represent the total number of nodes in the binary tree.

### Time Complexity: O(n)

Each node is pushed onto the stack and popped from it at most once. Therefore, the algorithm takes O(n) time.

### Space Complexity: O(n)

In the worst case, the stack may store up to O(n) nodes. Therefore, the auxiliary space complexity is O(n).

## Project Structure

```text
Non-Recursive-Preorder-Traversal/
│
├── preorder.cpp
└── README.md
```

| File | Description |
|---|---|
| `preorder.cpp` | Contains the C++ implementation of non-recursive preorder traversal. |
| `README.md` | Contains the project overview, algorithm, instructions, and complexity analysis. |

## Key Concepts Demonstrated

- Binary tree creation
- Node and pointer manipulation
- Stack data structure
- C++ Standard Template Library (STL)
- Iterative depth-first traversal
- Time and space complexity analysis

## Advantages

- Avoids recursive function calls.
- Uses an explicit stack to manage traversal.
- Demonstrates an alternative to recursive preorder traversal.
- Handles empty trees and single-node trees.
- Can be extended to implement other tree traversal algorithms.

## Future Enhancements

- Implement inorder traversal without recursion.
- Implement postorder traversal without recursion.
- Accept binary tree input from the user.
- Add insertion and deletion operations.
- Create a menu-driven program for tree operations.

## Learning Outcomes

After completing this project, you will be able to:

1. Understand preorder traversal of a binary tree.
2. Implement iterative tree traversal using a stack.
3. Explain why the right child is pushed before the left child.
4. Analyze the time and space complexity of the algorithm.
5. Compile and execute C++ programs.

## Author

**Name:** Sayali Jodand

## License

This project is intended for educational purposes and learning data structures and algorithms.

You are welcome to use and modify the code for personal learning and practice.
