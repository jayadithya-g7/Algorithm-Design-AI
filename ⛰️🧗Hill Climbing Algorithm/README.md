⛰️ Hill Climbing
-

What it is:
-

Hill Climbing is a simple, greedy search algorithm used in artificial intelligence to find a path to a goal. 

It works by always moving to the next state (or node) that brings it closer to the goal. 

It's called "hill climbing" because it's analogous to climbing a hill in the dark—at each step, you only look for the direction with the steepest upward slope and take a step in that direction, without any long-term planning. Because of this greedy nature, 

it's not guaranteed to find the optimal solution and can easily get stuck in a "local maximum" (a peak that isn't the highest point in the entire search space) or a dead end.

The Code Explained:
-

The implementation is a recursive function that makes a series of "best-choice" moves.


Heuristic Values: The algorithm's behavior is entirely dependent on the heuristic values, which represent the "height" of the hill. The search always chooses the neighbor with the lowest heuristic value, as this is assumed to be the closest to the goal.


Greedy Choice: At each step, the for loop iterates through all unvisited neighbors to find the one with the smallest heuristic value. It then immediately moves to that node and makes a recursive call.


Path Tracking: The path vector stores the sequence of nodes visited. If a goal is found, this vector contains the path taken.


Local Maximum/Dead End: If the algorithm reaches a node from which all neighbors have already been visited or have a higher heuristic value, nextNode remains -1, and the function returns false, indicating it's stuck.

<img width="1184" height="416" alt="image" src="https://github.com/user-attachments/assets/1be2cb77-1f22-4416-922f-a017d81446e6" />


Testcase:
-

<img width="682" height="900" alt="image" src="https://github.com/user-attachments/assets/5d9ec8dd-f19a-449e-94e9-b4a3d9a2da75" />
