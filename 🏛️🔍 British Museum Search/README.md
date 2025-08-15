🏛️ British Museum Search
-

What it is:-
-

The British Museum Search is a name given to a simple, brute-force algorithm that explores every possible path from a starting node until it finds the goal. 

The name is a humorous reference to the idea of a person blindly wandering through the British Museum, exploring every room and corridor until they stumble upon their destination. 

This algorithm is effectively an uninformed Depth-First Search (DFS) that continues to explore after finding a solution, finding every possible path.


The Code Explained:
-

The implementation uses a recursive function that systematically explores the graph. Because it finds all possible paths, it uses two main data structures to keep track of its state.


visited Set: This set tracks the nodes in the current path to prevent the algorithm from getting stuck in an infinite loop in a cyclic graph. By adding and removing nodes as the recursion goes deeper and then backtracks, it ensures all possible paths are explored.


path Vector: This vector maintains the sequence of nodes from the start to the current position. When the algorithm reaches the goal, this vector contains one of the possible paths.


Recursion: The core of the algorithm is a recursive call that goes deep into the graph. After exploring all paths from a node, the function backtracks by removing the current node from the path and visited set, allowing it to explore other branches.

<img width="1176" height="352" alt="image" src="https://github.com/user-attachments/assets/eda43402-7474-4433-ad05-19a800e6ae9f" />

Testcase
-

<img width="664" height="826" alt="image" src="https://github.com/user-attachments/assets/94302504-5303-4576-919b-48a4d2adf2e7" />
