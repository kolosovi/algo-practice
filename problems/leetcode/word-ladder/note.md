## Idea

Seems easy:
- each pair of words that differ by a single letter are connected nodes in the graph
- we need to find the shortest path from beginWord to endWord

## Analysis

Say there are V words and E connections between them.

### How do we assemble the graph structure?

- Easy way: examine each pair of words in V^2 time.

There must be a better way. So each word (e.g. 'cat') can have up to M replacements, where M is the number of letters in the word:

```
*at
c*t
ca*
```

A word that is adjacent to 'cat' must have equal replacements.
E.g 'bat' has the following replacements:

```
*at
b*t
ba*
```

We may build a mapping from replacement to list of words that have it. Then go over the mapping and build the graph.
This is a bit better than O(N^2) I guess? It takes O(MN) time to build the mapping. To find neighbors of a word it takes O(N) time (if each word has every other word as a neighbor).
So OK I guess.

### How do we find the shortest path?

- BFS

### Complexity

`O(V^2)` time

`O(V)` space
