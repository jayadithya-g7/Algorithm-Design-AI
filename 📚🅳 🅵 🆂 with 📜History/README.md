Depth-First Search with History
-

What it is:
-

Depth-First Search with History is a graph traversal algorithm that finds a path by exploring as far as possible along each branch before backtracking.

The "history" component refers to using data structures to keep a record of visited nodes and the path taken to reach them. 

This is essential for preventing the algorithm from getting stuck in infinite loops in a cyclic graph and for being able to reconstruct the final path from the start node to the goal.


The Code Explained:-
-


This implementation uses an iterative approach with a stack, which is a common alternative to recursion.


Stack: The stack is the core data structure that manages the order of nodes to visit. Because of its Last-In, First-Out (LIFO) nature, the algorithm always explores the most recently added neighbor first, giving it its characteristic "depth-first" behavior.


visited Vector: This boolean array serves as the primary "history" tracker. Once a node is processed, its corresponding entry is marked true, ensuring it won't be revisited.


parent Vector: This vector stores the parent of each node, forming a trail that can be followed backward from the goal node to the start node to reconstruct the path.


<img width="854" height="330" alt="image" src="https://github.com/user-attachments/assets/802d176b-1cc2-4fdc-b249-b7d83cfc5890" />


Testcase
-

<img width="522" height="938" alt="image" src="https://github.com/user-attachments/assets/bc0c1288-3d5d-44de-b903-29903b4d600a" />
