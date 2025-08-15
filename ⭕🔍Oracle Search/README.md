🔮 Oracle Search
-

What it is:
-

In the context of search algorithms, an Oracle Search is a conceptual model where an "oracle" (a source of perfect information) provides the optimal path to the goal, and the search algorithm simply follows it. 


This is a hypothetical scenario used to benchmark other algorithms. In this practical implementation, the "oracle" is a preliminary search (a DFS) that finds a path and stores it in a special oracle data structure. 


The final part of the code then demonstrates the search by simply following the path provided by this "oracle."



The Code Explained:
-

The code performs its task in two distinct stages.


Stage 1: The Oracle's Work: The first part of the oracleSearch function runs a standard Depth-First Search (DFS) using a stack. 

This DFS finds a path from the start to the goal. This path, along with the parent array used to reconstruct it, is the "knowledge" of the oracle. 

It is important to note that since a simple DFS is used, the path found is not guaranteed to be the shortest or most efficient one.

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Stage 2: Following the Oracle: After a path is found and reconstructed into a vector, the code creates a final oracle array. 

This array is populated such that oracle[i] holds the next node on the path after node i. 

The final while loop simply traverses the graph by using this oracle array as a lookup table, demonstrating how a perfect search would operate.

<img width="858" height="294" alt="image" src="https://github.com/user-attachments/assets/35163b47-b0fd-4f51-b343-271d813d1cf9" />


Testcase
-

<img width="648" height="656" alt="image" src="https://github.com/user-attachments/assets/cc9f2232-96fb-4f9a-877d-ebaa69c78a47" />
