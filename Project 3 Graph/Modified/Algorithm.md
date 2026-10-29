## Modified Algorithm

1. Start.
2. Read the number of vertices and edges.
3. Construct the adjacency matrix by entering the edges and their weights.
4. Read the initial source vertex.
5. Initialize the distance array with infinity and the parent array with -1.
6. Set the source vertex distance to 0.
7. Apply Dijkstra's algorithm to calculate the shortest distances to all reachable vertices.
8. Display the shortest distances from the current source vertex.
9. Display the menu:
   - Change Source Vertex
   - Display Shortest Path
   - Update Edge Weight
   - Exit
10. If the user selects Change Source Vertex:
    - Read and validate the new source vertex.
    - Reinitialize the distance and parent arrays.
    - Apply Dijkstra's algorithm again.
    - Display the updated shortest distances.
11. If the user selects Display Shortest Path:
    - Read and validate the destination vertex.
    - If the destination is unreachable, display "No path available".
    - Otherwise, reconstruct and display the complete shortest path using the parent array.
    - Display the total shortest distance.
12. If the user selects Update Edge Weight:
    - Read the two vertices of the existing edge and its new weight.
    - Validate the edge and weight.
    - Update the edge weight in both directions.
    - Apply Dijkstra's algorithm again from the current source.
    - Display the recalculated shortest distances.
13. Repeat the menu until the user selects Exit.
14. Stop.
