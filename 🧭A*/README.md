🧭 A* Search Algorithm
-

What it is:
-

A* is an informed search algorithm used for finding the shortest path in a weighted graph. It's smart because it uses an educated guess, or heuristic, to guide its search, making it much faster than a simple pathfinder on large graphs.

The Code Explained:
-
The algorithm works by maintaining a priority queue of nodes to visit. Each node's priority is determined by a combined score: 

fScore = gScore + hScore



Node Struct: This structure holds all the necessary information for a vertex.

<br/>

gScore: The actual cost from the start node to this vertex.

<br/>

hScore: The estimated cost from this vertex to the goal, provided by the heuristic.

<br/>

Priority Queue: The priority_queue is the core of the search. It automatically keeps the node with the lowest fScore at the top, ensuring the algorithm always explores the most promising path first. The operator> overload in the Node struct tells the priority queue how to compare and order the nodes.

struct Node{
    int vertex;
    int gScore;
    int hScore;
    bool operator>(const Node& other)const{
        return (gScore+hScore) > (other.gScore+other.hScore);
    }
};

testcase
-

<img width="712" height="890" alt="image" src="https://github.com/user-attachments/assets/77e7d3d9-fa2b-4094-93bc-81add44f3053" />

