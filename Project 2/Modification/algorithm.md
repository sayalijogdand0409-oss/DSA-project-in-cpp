## Algorithm: Non-Recursive Preorder Traversal with Modifications

1. Start.
2. Create a binary tree with root and child nodes.
3. Initialize an empty stack and set maximum stack size to 0.
4. If the root is NULL, display an empty traversal and stop.
5. Push the root node onto the stack.
6. Update the maximum stack size.
7. While the stack is not empty, repeat:
   a. Display the current stack contents from top to bottom.
   b. Pop the top node from the stack.
   c. Visit and print the popped node's data.
   d. Store the visited node in the non-recursive traversal result.
   e. If the right child exists, push it onto the stack.
   f. If the left child exists, push it onto the stack.
   g. Update the maximum stack size if the current stack size is greater.
   h. Display the updated stack contents.
8. Perform recursive preorder traversal of the same binary tree.
9. Display the non-recursive preorder traversal result.
10. Display the recursive preorder traversal result.
11. Compare both traversal results.
12. If both results are equal, display that both traversals produce the same output; otherwise, display that the outputs are different.
13. Display the maximum stack size used.
14. Stop.
