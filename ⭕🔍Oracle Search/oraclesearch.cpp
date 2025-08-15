#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void oracleSearch(const vector<vector<int>>& adjMatrix,int start,int goal){
    int V=adjMatrix.size();
    vector<bool> visited(V,false);
    vector<int> parent(V,-1);
    stack<int> s;
    
    cout << "Step 1: The 'Oracle' finds a path using DFS..." << endl;
    
    s.push(start);
    visited[start]=true;
    
    bool found = false;
    while(!s.empty()){
        int node=s.top();
        s.pop();

        if(node==goal){
            found = true;
            break;
        }
        
        for(int neighbor=V-1;neighbor>=0;neighbor--){
            if(adjMatrix[node][neighbor]>0 && !visited[neighbor]){
                visited[neighbor]=true;
                parent[neighbor]=node;
                s.push(neighbor);
            }
        }
    }

    if(!found){
        cout << "No path found by the oracle." << endl;
        return;
    }
    
    vector<int> path;
    int at = goal;
    while(at != -1){
        path.insert(path.begin(),at);
        at = parent[at];
    }
    
    cout << "The Oracle's knowledge: ";
    for(int node : path) {
        cout << node << " ";
    }
    cout << endl;
    
    vector<int> oracle(V,-1);
    for(size_t i=0;i<path.size()-1;i++){
        oracle[path[i]]=path[i+1];
    }

    cout << "\nStep 2: Following the Oracle's path." << endl;
    cout << "Oracle Search path: ";
    int current=start;
    cout << current << " ";
    while(current!=goal){
        current=oracle[current];
        cout << current << " ";
    }
    cout << endl;
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
    cin>>start;
    cout << "Enter goal node: ";
    cin>>goal;
    
    oracleSearch(adjMatrix,start,goal);
    
    return 0;
}
