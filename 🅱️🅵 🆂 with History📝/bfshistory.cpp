#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> bfs(int start,int goal,const vector<vector<int>>& adjMatrix){
    int V=adjMatrix.size();
    vector<bool> visited(V,false);
    vector<int> parent(V,-1);
    queue<int> q;

    visited[start]=true;
    q.push(start);

    cout<<"Starting BFS from node "<<start<<" to goal "<<goal<<endl;

    while(!q.empty()){
        int current=q.front();
        q.pop();

        cout<<"  - Visiting node "<<current<<endl;

        if(current==goal){
            cout<<"Goal reached!"<<endl;
            break;
        }

        for(int neighbor=0;neighbor<V;neighbor++){
            if(adjMatrix[current][neighbor]==1&&!visited[neighbor]){
                visited[neighbor]=true;
                parent[neighbor]=current;
                q.push(neighbor);
                cout<<"    -> Enqueued neighbor "<<neighbor<<endl;
            }
        }
    }

    vector<int> path;
    int at=goal;
    while(at!=-1){
        path.insert(path.begin(),at);
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
    
    vector<int> path=bfs(start,goal,adjMatrix);
    
    if(path.empty()){
        cout<<"No path found from "<<start<<" to "<<goal<<endl;
    }else{
        cout<<"\nBFS with history path: ";
        for(int node:path)
            cout<<node<<" ";
        cout<<endl;
    }
    return 0;
}
