Beam Search:
-

What it is:
-

Beam Search is a heuristic search algorithm that is a limited version of Best-First Search. Unlike A*, which keeps a priority queue of all promising nodes, Beam Search explores only a fixed number of the most promising nodes at each level of the search tree. 

This fixed number is called the beam width.

By limiting the search to only the best candidates, Beam Search significantly reduces memory usage and can find a solution much faster than an exhaustive search. However, because it prunes less-promising paths, it is not guaranteed to find the optimal or shortest path.

The Code Explained:
-

The implementation uses a priority_queue to keep track of the most promising nodes at the current level.


Node Struct: A simple struct to store the vertex ID, the path taken to get there, and the heuristic value, which is used to determine its priority. The operator< is overloaded to ensure the priority queue sorts nodes in descending order of their heuristic value, effectively making it a min-priority queue (so the "best" node is always at the top).


beamSearch Function:

It uses a priority_queue as the frontier to store nodes to explore.


In each step of the main while loop, it extracts the top beamWidth nodes from the frontier (or fewer, if the frontier is smaller).


It then generates all unvisited neighbors for these nodes, adding them to a nextCandidates vector.


The nextCandidates vector is sorted, and a new frontier is created containing only the top beamWidth nodes from this vector, pruning the rest. This process repeats until the goal is found or the frontier is empty.

<img width="1256" height="388" alt="image" src="https://github.com/user-attachments/assets/b028e6db-e50a-4415-816d-3d46826efc33" />


testcase
-

<img width="522" height="1020" alt="image" src="https://github.com/user-attachments/assets/b126af9d-c53e-4d9f-b700-2d92ff477e2f" />
