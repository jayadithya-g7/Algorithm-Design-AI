Beam Search with History
-

What it is:
-

Beam Search with History is a variation of the Beam Search algorithm that adds a mechanism to prevent revisiting nodes. 

Like standard Beam Search, it is a heuristic search that explores a limited number of the most promising nodes at each level (the beam width). 

The "history" component ensures that once a node has been visited, the algorithm does not process it again. 

This prevents infinite loops in graphs with cycles and improves efficiency by avoiding redundant work.

The Code Explained:
-

This implementation uses a vector to represent the current level of nodes to be expanded and a map to track visited nodes.


Main Loop: The while loop iterates level by level. At each level, it explores the neighbors of every node in currentLevel, adding unvisited neighbors as candidates.


Candidate Selection: All generated candidates are stored in a vector<pair<int,int>> and then sorted based on their heuristic value. The algorithm then selects only the top beamWidth candidates to form the next currentLevel. This is the core "pruning" behavior of Beam Search.


parent Map: A map is used to store the parent of each node as the path is being built. This allows for simple and efficient path reconstruction after the goal is found.


visited Map: This map acts as the "history" component. It prevents the algorithm from re-visiting nodes, ensuring the search doesn't get stuck in a loop and is more efficient.


<img width="1208" height="424" alt="image" src="https://github.com/user-attachments/assets/476293e4-0a39-48a7-a891-acde6b9ecc37" />

testcase
-

<img width="528" height="824" alt="image" src="https://github.com/user-attachments/assets/fb508807-46fe-40af-a47c-9bb4b2972e6c" />
