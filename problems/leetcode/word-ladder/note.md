## Idea

Seems easy:
- each pair of words that differ by a single letter are connected nodes in the graph
- we need to find the shortest path from beginWord to endWord

## Analysis

Say there are V words and E connections between them.

### How do we assemble the graph structure?

- Easy way: examine each pair of words in V^2 time.

### How do we find the shortest path?

- BFS

### Complexity

`O(V^2)` time

`O(V)` space
