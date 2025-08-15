#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>

using namespace std;

struct Node{
    int id;
    vector<int> path;
    int heuristic;
    bool operator<(const Node& other)const{
        return heuristic > other.heuristic;
    }
};

void beamSearch(int start,int goal,const vector<vector<int>>& adjMatrix,const vector<int>& heuristic,int beamWidth){
    int V=adjMatrix.size();
    map<int,bool> visited;
    priority_queue<Node> frontier;

    cout << "Starting Beam Search with beam width " << beamWidth << endl;
    
    frontier.push({start,{start},heuristic[start]});
    visited[start]=true;

    while(!frontier.empty()){
        vector<Node> nextCandidates;
        
        cout << "\nExpanding level with " << min(beamWidth,(int)frontier.size()) << " nodes:" << endl;
        
        for(int i=0;i<beamWidth&&!frontier.empty();i++){
            Node current=frontier.top();
            frontier.pop();
            
            cout << "  - Exploring node " << current.id << " (h=" << current.heuristic << ")" << endl;
            
            if(current.id==goal){
                cout << "\nGoal reached!" << endl;
                cout << "Path found: ";
                for(int node : current.path) cout << node << " ";
                cout << endl;
                return;
            }
            
            for(int neighbor=0;neighbor<V;neighbor++){
                if(adjMatrix[current.id][neighbor]>0&&!visited[neighbor]){
                    vector<int> newPath=current.path;
                    newPath.push_back(neighbor);
                    nextCandidates.push_back({neighbor,newPath,heuristic[neighbor]});
                }
            }
        }
        
        sort(nextCandidates.begin(),nextCandidates.end());
        
        priority_queue<Node> nextFrontier;
        for(int i=0;i<min(beamWidth,(int)nextCandidates.size());i++){
            nextFrontier.push(nextCandidates[i]);
            visited[nextCandidates[i].id]=true;
        }
        frontier=nextFrontier;
    }
    
    cout << "\nNo path found." << endl;
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
    int beamWidth;
    cout<<"Enter start node: ";
    cin>>start;
    cout<<"Enter goal node: ";
    cin>>goal;
    cout<<"Enter beam width: ";
    cin>>beamWidth;
    
    beamSearch(start,goal,adjMatrix,heuristic,beamWidth);
    
    return 0;
}
