#include<iostream>
#include<vector>
#include<set>

using namespace std;

bool dfs(int current,int goal,const vector<vector<int>>& adjMatrix,set<int>& visited,vector<int>& path){
    visited.insert(current);
    path.push_back(current);

    cout << "  - Visiting node " << current << ". Current path: ";
    for(int node : path) cout << node << " ";
    cout << endl;

    if(current==goal){
        cout << "Goal reached!" << endl;
        return true;
    }

    int V=adjMatrix.size();
    for(int neighbor=0;neighbor<V;neighbor++){
        if(adjMatrix[current][neighbor]==1 && visited.find(neighbor)==visited.end()){
            if(dfs(neighbor,goal,adjMatrix,visited,path)){
                return true;
            }
        }
    }
    path.pop_back();
    visited.erase(current);
    return false;
}

int main(){
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;
    vector<vector<int>> adjMatrix(V,vector<int>(V));
    cout << "Enter adjacency matrix:" << endl;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin>>adjMatrix[i][j];
        }
    }
    int start,goal;
    cout << "Enter start node: ";
    cin >> start;
    cout << "Enter goal node: ";
    cin >> goal;
    
    set<int> visited;
    vector<int> path;

    cout << "\nStarting DFS from node " << start << " to goal " << goal << endl;
    dfs(start,goal,adjMatrix,visited,path);

    cout << "\nPath found: ";
    for(int node:path){
        cout << node << " ";
    }
    cout << endl;
    
    return 0;
}
