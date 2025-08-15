
🌲 Branch & Bound with Cost + Estimated Heuristics
-

What it is:
-

This implementation uses the Branch & Bound framework, enhanced with a heuristic. 
<br/>

The algorithm finds the shortest path by using a priority function that combines the actual path cost (cost) with an estimated cost to the goal (estimate). 
<br/>

This approach is also known as an A* search, as it leverages both the path cost and an informed guess to guide the search, making it highly efficient.


The Code Explained:
-

The code uses a priority queue to intelligently manage which paths to explore.


Node Struct: This struct holds all the key information for a vertex in the search. cost represents the actual cost from the start, while estimate is the heuristic's approximation of the remaining cost to the goal. 
<br/>
The operator> is overridden to prioritize nodes with the lowest total estimated cost (cost + estimate).


Priority Queue: The priority_queue is the central component that keeps the most promising node (the one with the lowest cost + estimate) at the front, ensuring the algorithm expands the best path first.


minCost Map: This map is an optimization that stores the minimum cost found so far to reach each node. This prevents the algorithm from exploring a path to a node that is more expensive than a path already discovered, which is a core concept of effective Branch & Bound and A* implementations.


<img width="890" height="410" alt="image" src="https://github.com/user-attachments/assets/02a2aa4c-159c-4d3f-b740-31265ab555ed" />


testcase
-

<img width="878" height="1226" alt="image" src="https://github.com/user-attachments/assets/f9a45c67-3117-4a81-9e24-d5be055a61ee" />
