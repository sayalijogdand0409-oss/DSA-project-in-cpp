## Source Code

The program is implemented in C++ to perform preorder traversal of a binary tree without using recursion. It uses a stack data structure to visit the nodes in the order **Root → Left → Right**.

First, a binary tree containing five nodes is created. The root node is pushed onto the stack. The program then pops the top node, prints its data, and pushes its right child followed by its left child, if they exist. This process continues until the stack becomes empty.

The program demonstrates the use of binary trees, stack operations, pointers, and iterative traversal in C++.

### Output

```text
Preorder Traversal: 1 2 4 5 3
```
