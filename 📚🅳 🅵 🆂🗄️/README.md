Depth-First Search (DFS)
-

What it is:
-

Depth-First Search (DFS) is a graph traversal algorithm that explores as far as possible along each branch before backtracking. 


It's often compared to navigating a maze: you follow one path until you hit a dead end, then you turn around and try a different one. 


Because it prioritizes depth over breadth, DFS can find a path quickly if one exists deep within the graph, but it is not guaranteed to find the shortest path in an unweighted graph.

The Code Explained:
-

This implementation of DFS is recursive, meaning the function calls itself to explore deeper into the graph.


visited Set: A set is used to keep track of the nodes in the current path. This is vital for preventing the algorithm from getting stuck in an infinite loop in a graph that contains cycles.
As the function backtracks (returns false), it removes the current node from the visited set to allow other paths to be explored.


path Vector: This vector stores the sequence of nodes that form the current path from the start. When a recursive call returns true (indicating the goal was found), the vector contains the complete path.
If the function backtracks, the current node is removed from the path via pop_back().


Recursive Nature: The if(dfs(...)) statement is the core of the recursive call. It checks if the call to a neighbor successfully found the goal. If so, it immediately returns true up the call stack, effectively stopping the search.

<img width="1196" height="460" alt="image" src="https://github.com/user-attachments/assets/16db3214-7bb2-41b8-be09-464bc5074e35" />

Testcase
-

<img width="542" height="820" alt="image" src="https://github.com/user-attachments/assets/5a12d989-5397-4f9d-9a84-52d01ef3250d" />
