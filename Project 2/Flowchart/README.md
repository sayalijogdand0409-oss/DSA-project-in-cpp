## 🔄 Flowchart

The following flowchart illustrates the non-recursive preorder traversal of a binary tree using a stack.

```mermaid
flowchart TD
    A([Start]) --> B[Create an empty stack]
    B --> C[Push root node onto stack]
    C --> D{Is stack empty?}

    D -- Yes --> E([End])
    D -- No --> F[Pop top node from stack]
    F --> G[Print node data]
    G --> H{Does right child exist?}

    H -- Yes --> I[Push right child onto stack]
    H -- No --> J{Does left child exist?}
    I --> J

    J -- Yes --> K[Push left child onto stack]
    J -- No --> D
    K --> D

    style A fill:#d4edda,stroke:#28a745,color:#000
    style E fill:#f8d7da,stroke:#dc3545,color:#000
    style D fill:#fff3cd,stroke:#ffc107,color:#000
    style H fill:#fff3cd,stroke:#ffc107,color:#000
    style J fill:#fff3cd,stroke:#ffc107,color:#000
```

### Flowchart Explanation

1. **Start:** Begin the program.
2. **Initialize Stack:** Create an empty stack and push the root node.
3. **Check Stack:** If the stack is empty, terminate the traversal.
4. **Pop and Visit:** Pop the top node and print its data.
5. **Push Right Child:** If the right child exists, push it onto the stack.
6. **Push Left Child:** If the left child exists, push it onto the stack.
7. **Repeat:** Return to the stack check and continue until the stack is empty.

### Sample Output

```text
Preorder Traversal: 1 2 4 5 3
```

### Complexity Analysis

- **Time Complexity:** O(n)
- **Space Complexity:** O(n)

Here, `n` represents the total number of nodes in the binary tree.

**Note:** The right child is pushed before the left child because the stack follows the LIFO (Last In, First Out) principle. This ensures that nodes are visited in preorder: **Root → Left → Right**.
