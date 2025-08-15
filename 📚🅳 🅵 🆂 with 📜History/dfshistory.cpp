#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> dfs(int start,int goal,const vector<vector<int>>& adjMatrix){
    int V=adjMatrix.size();
    vector<bool> visited(V,false);
    vector<int> parent(V,-1);
    stack<int> s;

    s.push(start);
    visited[start]=true;
    cout << "Starting DFS from node " << start << " to goal " << goal << endl;

    while(!s.empty()){
        int current=s.top();
        s.pop();

        cout << "  - Visiting node " << current << endl;

        if(current==goal){
            cout << "Goal reached!" << endl;
            break;
        }

        for(int neighbor=V-1;neighbor>=0;neighbor--){
            if(adjMatrix[current][neighbor]==1&&!visited[neighbor]){
                visited[neighbor]=true;
                parent[neighbor]=current;
                s.push(neighbor);
                cout << "    -> Pushed neighbor " << neighbor << endl;
            }
        }
    }

    vector<int> path;
    int at=goal;
    while(at!=-1){
        path.insert(path.begin(),at);
        if(at == start && parent[at] == -1) break;
        at=parent[at];
    }

    if(path.size() > 1 || (!path.empty() && path[0] == start)) {
        return path;
    }
    return {};
}

int main(){
    int V;
    cout<<"Enter number of vertices: ";
    cin>>V;
    vector<vector<int>> adjMatrix(V,vector<int>(V));
    cout<<"Enter adjacency matrix:"<<endl;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin>>adjMatrix[i][j];
        }
    }
    int start,goal;
    cout<<"Enter start node: ";
    cin>>start;
    cout<<"Enter goal node: ";
    cin>>goal;
    
    vector<int> path = dfs(start,goal,adjMatrix);
    
    if(path.empty()){
        cout<<"\nNo path found."<<endl;
    } else {
        cout<<"\nDFS with history path: ";
        for(int node:path){
            cout<<node<<" ";
        }
        cout<<endl;
    }
    return 0;
}
