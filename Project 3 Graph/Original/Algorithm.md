## Algorithm

1. Start.
2. Read the number of buildings `n` and pathways `e`.
3. Initialize the adjacency matrix with zeros.
4. Read the pathways and their distances.
5. Store each pathway distance in the adjacency matrix.
6. Read the source building `src` and destination building `dest`.
7. Initialize all distances to infinity, parents to `-1`, and visited status to false.
8. Set the source building distance to `0`.
9. Repeat until all reachable buildings are processed:
   - Select the unvisited building with the minimum distance.
   - Mark the selected building as visited.
   - Check all adjacent buildings.
   - Update the distance and parent if a shorter path is found.
10. Display the shortest distances from the source building to all other buildings.
11. If the destination is unreachable, display "No route available".
12. Otherwise, reconstruct and display the shortest route using the parent array.
13. Display the total shortest distance to the destination.
14. Stop.
  
