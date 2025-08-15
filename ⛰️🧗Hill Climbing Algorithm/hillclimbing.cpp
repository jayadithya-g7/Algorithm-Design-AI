#include<iostream>
#include<vector>
#include<limits>

using namespace std;

bool hillClimbing(int current,int goal,const vector<vector<int>>& adjMatrix,const vector<int>& heuristic,vector<int>& path,vector<bool>& visited){
    path.push_back(current);
    visited[current]=true;

    cout << "  - Visiting node " << current << " with heuristic value " << heuristic[current] << endl;
    
    if(current==goal){
        cout << "Goal reached!" << endl;
        return true;
    }
    
    int nextNode=-1;
    int minHeuristic=numeric_limits<int>::max();
    
    for(size_t i=0;i<adjMatrix.size();i++){
        if(adjMatrix[current][i]>0 && !visited[i]){
            if(heuristic[i]<minHeuristic){
                minHeuristic=heuristic[i];
                nextNode=i;
            }
        }
    }
    
    if(nextNode==-1){
        cout << "Stuck at a local maximum or dead end." << endl;
        return false;
    }
    cout << "  - Moving to neighbor " << nextNode << " with heuristic " << minHeuristic << endl;
    return hillClimbing(nextNode,goal,adjMatrix,heuristic,path,visited);
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
    vector<int> heuristic(V);
    cout<<"Enter heuristic values for each node:"<<endl;
    for(int i=0;i<V;i++){
        cout<<"Heuristic for node "<<i<<": ";
        cin>>heuristic[i];
    }
    
    int start,goal;
    cout<<"Enter start node: ";
    cin>>start;
    cout<<"Enter goal node: ";
    cin>>goal;
    
    vector<int> path;
    vector<bool> visited(V,false);
    
    cout << "\nStarting Hill Climbing from node " << start << " to goal " << goal << endl;
    bool found=hillClimbing(start,goal,adjMatrix,heuristic,path,visited);
    
    cout << "\nPath: ";
    if(found){
        for(int node : path){
            cout<<node<<" ";
        }
    } else {
        cout << "No path found." << endl;
    }
    cout<<endl;
    
    return 0;
}
