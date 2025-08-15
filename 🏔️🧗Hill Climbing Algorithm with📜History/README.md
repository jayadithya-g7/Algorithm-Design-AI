🏔️Hill Climbing with History
-

What it is:
-

Hill Climbing with History is a greedy search algorithm that finds a path by always moving to the next unvisited neighbor with the best heuristic value. 

The "history" component is the key addition to a basic Hill Climbing algorithm: it uses a visited data structure to prevent the search from going back and forth between two nodes. 

This small but vital improvement helps avoid simple cycles and allows the algorithm to explore new territory, increasing the chance of finding a solution.


The Code Explained:
-

This implementation uses an iterative approach with a while loop to repeatedly choose the best next step.


heuristic Vector: The algorithm's behavior is driven by the heuristic values, which are assumed to be a measure of "closeness" to the goal. The search always selects the neighbor with the minimum heuristic value.


visited Vector: This boolean array acts as the "history." When a node is visited, its entry in the array is set to true, ensuring the algorithm won't consider it again as it moves forward.


Greedy Choice: Inside the while loop, the code iterates through all neighbors of the current node to find the one with the lowest heuristic value that has not yet been visited. This is the central greedy decision of the algorithm.


Dead End: If no unvisited neighbors are found, the nextNode variable remains -1, and the loop breaks, indicating that the algorithm has reached a dead end or a local maximum and cannot proceed.

<img width="1186" height="360" alt="image" src="https://github.com/user-attachments/assets/56bc68cd-0cec-46ce-8545-0a66d0fa005d" />


Testcase
-

<img width="766" height="876" alt="image" src="https://github.com/user-attachments/assets/f95b3b50-c807-4ca9-a4df-6cb7f78d1643" />
