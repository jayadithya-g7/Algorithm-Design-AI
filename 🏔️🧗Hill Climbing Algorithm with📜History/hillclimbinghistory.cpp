#include<iostream>
#include<vector>
#include<limits>

using namespace std;

void hillClimbingHistory(const vector<vector<int>>& adjMatrix,const vector<int>& heuristic,int start,int goal){
    int V=adjMatrix.size();
    vector<bool> visited(V,false);
    vector<int> path;
    int current=start;
    
    cout << "Starting Hill Climbing with History from node " << start << " to goal " << goal << endl;

    while(current!=goal){
        visited[current]=true;
        path.push_back(current);

        cout << "  - Visiting node " << current << " (h=" << heuristic[current] << ")" << endl;
        
        int nextNode=-1;
        int minH=numeric_limits<int>::max();
        for(int neighbor=0;neighbor<V;neighbor++){
            if(adjMatrix[current][neighbor]>0 && !visited[neighbor]){
                if(heuristic[neighbor]<minH){
                    minH=heuristic[neighbor];
                    nextNode=neighbor;
                }
            }
        }
        
        if(nextNode==-1){
            cout << "Stuck at a local maximum or dead end." << endl;
            break;
        }
        
        cout << "  - Moving to neighbor " << nextNode << " (h=" << minH << ")" << endl;
        current=nextNode;
    }
    
    if(current == goal){
        path.push_back(current);
        cout << "\nGoal reached!" << endl;
    }

    cout << "\nHill Climbing with History Path: ";
    if(path.empty()){
        cout << "No path found." << endl;
    } else {
        for(int node : path){
            cout << node << " ";
        }
        cout << endl;
    }
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
    cout<<"Enter heuristic values for each vertex:"<<endl;
    for(int i=0;i<V;i++){
        cout<<"Heuristic for vertex "<<i<<": ";
        cin>>heuristic[i];
    }
    int start,goal;
    cout<<"Enter start node: ";
    cin>>start;
    cout<<"Enter goal node: ";
    cin>>goal;

    hillClimbingHistory(adjMatrix,heuristic,start,goal);

    return 0;
}
