🌲 Branch & Bound with History
-

What it is:
-
Branch & Bound is an optimization algorithm that finds the shortest path by exploring a search space. Its main strategy is to prune away bad paths. It keeps track of the best-found solution so far and uses that as a bound to discard any path that already costs more.

The Code Explained:
-

Similar to A*, this algorithm uses a priority queue to explore the lowest-cost paths first. The "history" part of the name simply means the code tracks the full path taken to reach a node.

Node Struct: This struct is simpler than the one for A* because it doesn't need a heuristic.

cost: The total cost from the start node to this vertex.

path: A vector that stores the sequence of vertices, representing the path history.

Priority Queue: The queue sorts nodes based on their current cost. By always expanding the node with the lowest cost, the algorithm efficiently finds the shortest path while pruning any expensive detours. The operator> overload handles this cost-based ordering.

struct Node{
    int vertex;
    int cost;
    vector<int> path;
    bool operator>(const Node& other)const{
        return cost > other.cost;
    }
};

testcase
-

<img width="788" height="690" alt="image" src="https://github.com/user-attachments/assets/9051fd7c-426b-4b66-b5fb-594e3a7e0c21" />
