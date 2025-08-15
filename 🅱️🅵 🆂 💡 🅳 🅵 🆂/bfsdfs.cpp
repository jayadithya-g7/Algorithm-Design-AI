#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

vector<int> dfs_bfs(int start,int goal,const vector<vector<int>>& adjMatrix){
    int V=adjMatrix.size();
    vector<bool> visited(V,false);
    vector<int> parent(V,-1);
    stack<int> s;
    bool found=false;
    int lastVisited=-1;

    cout<<"Starting DFS from node "<<start<<endl;
    s.push(start);

    while(!s.empty()){
        int current=s.top();
        s.pop();

        if(!visited[current]){
            visited[current]=true;
            lastVisited=current;
            cout<<"  - DFS visiting node "<<current<<endl;

            if(current==goal){
                found=true;
                break;
            }

            for(int neighbor=V-1;neighbor>=0;neighbor--){
                if(adjMatrix[current][neighbor]==1&&!visited[neighbor]){
                    parent[neighbor]=current;
                    s.push(neighbor);
                }
            }
        }
    }

    if(!found){
        cout<<"\nDFS did not find the goal. Switching to BFS from last visited node "<<lastVisited<<endl;
        queue<int> q;
        if(lastVisited != -1){
             q.push(lastVisited);
        }
       
        while(!q.empty()){
            int current=q.front();
            q.pop();

            cout<<"  - BFS visiting node "<<current<<endl;

            if(current==goal){
                found=true;
                break;
            }
            
            for(int neighbor=0;neighbor<V;neighbor++){
                if(adjMatrix[current][neighbor]==1&&!visited[neighbor]){
                    visited[neighbor]=true;
                    parent[neighbor]=current;
                    q.push(neighbor);
                }
            }
        }
    }

    vector<int> path;
    if(found){
        int at=goal;
        while(at!=-1){
            path.insert(path.begin(),at);
            at=parent[at];
        }
    }
    return path;
}

int main(){
    int V;
    cout<<"Enter number of vertices: ";
    cin>>V;
    vector<vector<int>> adjMatrix(V,vector<int>(V));
    cout<<"Enter adjacency matrix:\n";
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
    vector<int> path=dfs_bfs(start,goal,adjMatrix);
    cout<<"\nDFS+BFS path: ";
    if(path.empty()){
        cout<<"No path found."<<endl;
    } else {
        for(int node:path){
            cout<<node<<" ";
        }
        cout<<endl;
    }
    return 0;
}



  
  
