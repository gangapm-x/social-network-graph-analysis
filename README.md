# Social Network Graph Analysis

## Aim

To implement and analyse a small social network using Adjacency Matrix and Adjacency List representations.

## Given Connections

The social network contains the following connections:

- A-B
- A-C
- B-D
- B-E
- C-F
- E-F

## Vertices

A, B, C, D, E, F

## Graph Representations

The network is implemented using:

1. Adjacency Matrix
2. Adjacency List

## BFS

Breadth First Search is performed starting from vertex A.

Expected traversal:

A B C D E F

## DFS

Depth First Search is performed starting from vertex A.

Expected traversal:

A B D E F C

## Search Operation

A specified vertex is searched using the graph representation.

The number of operations required is recorded.

## Comparison

| Criteria | Adjacency Matrix | Adjacency List |
|---|---|---|
| Space | O(V²) | O(V + E) |
| Edge checking | O(1) | O(degree) |
| BFS | O(V²) | O(V + E) |
| DFS | O(V²) | O(V + E) |
| Memory usage | High | Low |
| Best for | Dense graphs | Sparse graphs |

## Sparse Network Analysis

A social network can contain a large number of users but relatively fewer connections for each user.

Therefore, an adjacency list is more suitable for a sparse social network because it stores only the existing connections.

## Conclusion

The adjacency list requires less memory for sparse graphs and provides efficient graph traversal.

Hence, the adjacency list is the preferred representation for a sparse social network.
