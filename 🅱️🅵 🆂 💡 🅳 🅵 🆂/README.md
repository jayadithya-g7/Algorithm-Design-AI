DFS + BFS Hybrid Search
-

What it is:
-

The DFS + BFS Hybrid Search is a compound algorithm that combines the strengths of two fundamental search strategies. 


It first uses a Depth-First Search (DFS), which quickly explores deep into the graph, hoping to find the goal early. 


If the DFS search completes without finding the goal, the algorithm then switches to a Breadth-First Search (BFS), starting from the last node visited by DFS. 


The BFS ensures that a path is found if one exists, as it's a complete algorithm that guarantees finding a path in an unweighted graph if one exists.


The Code Explained:
-


The provided code implements a hybrid search strategy that attempts a Depth-First Search (DFS) first, and if that fails to find the goal, it switches to a Breadth-First Search (BFS) from the last node visited by the DFS. This is an interesting approach to combine the quick exploration of DFS with the completeness of BFS.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

The implementation uses a stack for the DFS part and a queue for the BFS part.


DFS (Stack-based): The first part of the dfs_bfs function uses a stack to explore the graph in a LIFO (Last-In, First-Out) manner. It goes as deep as possible down a single path before backtracking.


BFS (Queue-based): If the DFS portion fails, the code seamlessly transitions to a queue. It starts from the last node reached by the DFS, and then explores the remaining unvisited parts of the graph in a level-by-level fashion.


visited Vector: This boolean array is crucial. It's shared between both search phases, ensuring that nodes already visited by DFS are not re-explored by BFS.


parent Vector: This array stores the parent of each node, allowing the code to reconstruct the final path from the goal node back to the start.


<img width="880" height="432" alt="image" src="https://github.com/user-attachments/assets/2cd16de3-2391-4945-baa2-397a703b6396" />



testcase
-

<img width="524" height="688" alt="image" src="https://github.com/user-attachments/assets/5afab26c-1283-49a0-b695-8e6fa3ec667b" />
