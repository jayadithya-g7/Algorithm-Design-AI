Breadth-First Search with History
-

What it is:
-

Breadth-First Search with History is a graph traversal algorithm that finds the shortest path in an unweighted graph. 


The "history" component refers to the use of data structures that remember which nodes have been visited and how a node was reached. 


This is crucial for two reasons: it prevents the algorithm from getting stuck in infinite loops in a cyclic graph, and it allows for the reconstruction of the complete path from the start node to the goal node once the goal is found.



The Code Explained:-
-

The provided code is a standard implementation of Breadth-First Search (BFS). The "history" component is correctly handled by the visited array and the parent array. The visited array prevents cycles and redundant exploration, while the parent array allows for the reconstruction of the path.

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

The implementation uses a queue for its level-by-level exploration, and two auxiliary data structures to maintain history.


Queue: A queue is used to manage the nodes to be visited. Its First-In, First-Out (FIFO) nature guarantees that the algorithm explores all nodes at the current depth before moving to the next level, thereby finding the shortest path.


visited Vector: This boolean array acts as the primary "history" tracker. Once a node is added to the queue, its corresponding entry in the visited array is marked true, ensuring it won't be enqueued or processed again.


parent Vector: This vector stores the parent of each node in the shortest path tree. By tracing back from the goal node to the start node using this array, the complete path can be reconstructed.

<img width="868" height="320" alt="image" src="https://github.com/user-attachments/assets/13c98170-e4d1-4319-b7f2-b3b7329d23c2" />


testcase
-


<img width="524" height="930" alt="image" src="https://github.com/user-attachments/assets/6db2d8f8-0119-4f4f-8e78-ba1294ce3128" />
