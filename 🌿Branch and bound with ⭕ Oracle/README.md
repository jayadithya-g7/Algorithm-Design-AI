Branch & Bound with Oracle
-

What it is:
-

The concept of a Branch & Bound with Oracle is a theoretical model of an optimal search. 


The "oracle" represents a source of perfect information that instantly provides the shortest path from any given node to the goal. 


In this practical implementation, the "oracle" is simulated by running a standard shortest path algorithm (Dijkstra's) to pre-calculate the optimal path. 


The code then uses this knowledge to quickly return the correct path and its cost. This is a powerful demonstration of how perfect heuristics (like an oracle) can make a search algorithm exceptionally efficient.

The Code Explained:-
-

The implementation uses a priority queue to find the shortest path, a standard technique for Branch & Bound algorithms.

Node Struct: A simple struct that holds a vertex and its current cost from the start node. The operator> overload ensures the priority queue prioritizes the node with the lowest cost, which is the core principle of a greedy search like Dijkstra's.

minCost Map: This map stores the shortest distance found so far to each node from the start. It acts as the "bound" in the Branch & Bound framework. If a new path to a node is more expensive than the current minimum, it is pruned from the search.

parent Map: This map records the path taken to reach each node. Once the goal is reached, this map allows for the reconstruction of the optimal path.

"Oracle Simulation": The entire search process effectively acts as the "oracle" by finding the optimal path first. Once the search completes, the results (minCost and parent map) are the "perfect knowledge" used to output the final result.

<img width="934" height="346" alt="image" src="https://github.com/user-attachments/assets/a33770a8-ea30-4cf9-87bf-69f33fc5d45e" />

Testcase
-

<img width="756" height="944" alt="image" src="https://github.com/user-attachments/assets/c4b7d2a1-8b22-4d15-92e4-6329f07034d1" />
