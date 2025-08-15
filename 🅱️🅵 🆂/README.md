Breadth-First Search (BFS)
-

What it is:
-

Breadth-First Search (BFS) is a graph traversal algorithm used for finding the shortest path in an unweighted graph. 

It explores the graph by visiting all the neighbors of a node at the current depth level before moving on to the nodes at the next depth level. 

This level-by-level exploration guarantees that the first time the goal node is found, it will be by the shortest possible path from the start.


The Code Explained:
-

The provided code implements a hybrid search strategy that attempts a Depth-First Search (DFS) first, and if that fails to find the goal, it switches to a Breadth-First Search (BFS) from the last node visited by the DFS. This is an interesting approach to combine the quick exploration of DFS with the completeness of BFS.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

The implementation uses a queue as its primary data structure to manage which nodes to visit next.


Queue: The queue stores the nodes to be explored. It follows a First-In, First-Out (FIFO) principle, which is what gives BFS its level-by-level behavior. When a node is dequeued, all of its unvisited neighbors are enqueued.


visited Vector: This boolean vector keeps track of nodes that have already been explored, preventing infinite loops in graphs with cycles and ensuring each node is processed only once.


parent Vector: This vector stores the parent of each node. By backtracking from the goal node up to the start node using this vector, the shortest path can be easily reconstructed.


<img width="848" height="324" alt="image" src="https://github.com/user-attachments/assets/c301e739-c26f-4c0a-ad0f-93d96cffc42a" />

testcase
-

<img width="500" height="874" alt="image" src="https://github.com/user-attachments/assets/d48da965-4006-40fa-95df-76c259c04db6" />

