## Algorithm

**Algorithm: Non-Recursive Preorder Traversal Using a Stack**

**Step 1:** Start the program.

**Step 2:** Create a binary tree with a root node.

**Step 3:** If the root node is `NULL`, terminate the traversal.

**Step 4:** Create an empty stack and push the root node onto it.

**Step 5:** Repeat the following steps while the stack is not empty:

- Pop the top node from the stack.
- Visit the node and print its data.
- If the right child exists, push it onto the stack.
- If the left child exists, push it onto the stack.

**Step 6:** Repeat Step 5 until the stack becomes empty.

**Step 7:** Stop the program.

### Traversal Order

**Root → Left → Right**

### Pseudocode

```text
Algorithm Preorder(root)

1. If root == NULL
       Return

2. Create an empty stack S

3. Push root onto S

4. While S is not empty
       a. current = S.top()
       b. S.pop()
       c. Print current.data

       d. If current.right != NULL
              S.push(current.right)

       e. If current.left != NULL
              S.push(current.left)

5. End
```

### Complexity Analysis

- **Time Complexity:** O(n)
- **Space Complexity:** O(n)

Here, `n` represents the total number of nodes in the binary tree.
