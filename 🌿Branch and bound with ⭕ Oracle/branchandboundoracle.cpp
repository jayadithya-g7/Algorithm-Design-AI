#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<map>

using namespace std;

struct Node {
    int vertex;
    int cost;
    bool operator>(const Node& other) const {
        return cost > other.cost;
    }
};

void branchBoundOracle(const vector<vector<int>>& adjMatrix, int start, int goal){
    int V = adjMatrix.size();
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    map<int, int> minCost;
    map<int, int> parent;
    
    pq.push({start, 0});
    minCost[start] = 0;

    cout << "Starting Branch & Bound with Oracle..." << endl;

    while(!pq.empty()){
        int current = pq.top().vertex;
        int currentCost = pq.top().cost;
        pq.pop();
        
        cout << "  - Expanding node " << current << " with cost " << currentCost << endl;

        if(currentCost > minCost[current]) {
            continue;
        }

        if(current == goal){
            break;
        }

        for(int neighbor = 0; neighbor < V; ++neighbor){
            if(adjMatrix[current][neighbor] > 0){
                int newCost = currentCost + adjMatrix[current][neighbor];
                if(newCost < minCost[neighbor] || minCost.find(neighbor) == minCost.end()){
                    minCost[neighbor] = newCost;
                    parent[neighbor] = current;
                    pq.push({neighbor, newCost});
                    cout << "    -> Found a new best path to " << neighbor << " with cost " << newCost << endl;
                }
            }
        }
    }
    
    vector<int> path;
    int at = goal;
    if(minCost.find(goal) == minCost.end()){
        cout << "\nNo path found." << endl;
        return;
    }
    while(at != -1){
        path.insert(path.begin(), at);
        if(at == start) break;
        at = parent[at];
    }
    
    cout << "\nOptimal path found (The Oracle's knowledge): ";
    for(int node : path) {
        cout << node << " ";
    }
    cout << "\nTotal cost: " << minCost[goal] << endl;
}

int main(){
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;
    vector<vector<int>> adjMatrix(V, vector<int>(V));
    cout << "Enter adjacency matrix:" << endl;
    for(int i = 0; i < V; ++i){
        for(int j = 0; j < V; ++j){
            cin >> adjMatrix[i][j];
        }
    }
    int start, goal;
    cout << "Enter start node: ";
    cin >> start;
    cout << "Enter goal node: ";
    cin >> goal;
    branchBoundOracle(adjMatrix, start, goal);
    return 0;
}
