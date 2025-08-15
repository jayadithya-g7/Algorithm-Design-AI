#include <iostream>
#include <vector>
#include <set>

using namespace std;

void britishMuseumDFS(int current,int goal,const vector<vector<int>>& adjMatrix,set<int>& visited,vector<int>& path) {
    visited.insert(current);
    path.push_back(current);

    cout << "  - Exploring node " << current;
    cout << ". Current path: ";
    for(int node : path) cout << node << " ";
    cout << endl;
    
    if (current==goal){
        cout << "\nGoal reached! Path found: ";
        for(int node : path){ cout << node << " ";
        }
        cout << endl;
    }
    
    int V=adjMatrix.size();
    
    for(int neighbor=0;neighbor<V;neighbor++){
        if(adjMatrix[current][neighbor]==1 && visited.find(neighbor)==visited.end()) {
            britishMuseumDFS(neighbor,goal,adjMatrix,visited,path);
        }
    }
    
    path.pop_back();
    visited.erase(current);
}

int main(){
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> adjMatrix(V,vector<int>(V));
    cout << "Enter the adjacency matrix:" << endl;
    for(int i=0;i<V;i++){
        for (int j=0;j<V;j++){
            cin >> adjMatrix[i][j];
        }
    }

    int start,goal;
    cout << "Enter start node: ";
    cin >> start;
    cout << "Enter goal node: ";
    cin >> goal;

    set<int> visited;
    vector<int> path;
    
    cout << "\nStarting British Museum Search from node " << start << " to goal " << goal << endl;
    britishMuseumDFS(start,goal,adjMatrix,visited,path);

    cout << "\nSearch complete." << endl;
    return 0;
}
