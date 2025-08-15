#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>

using namespace std;

vector<int> beamSearch(const vector<vector<int>>& adjMatrix,const vector<int>& heuristic,int start,int goal,int beamWidth){
    int V=adjMatrix.size();
    map<int,bool> visited;
    map<int,int> parent;
    vector<int> currentLevel;
    currentLevel.push_back(start);
    visited[start]=true;

    cout << "Starting Beam Search with beam width " << beamWidth << endl;

    while(!currentLevel.empty()){
        vector<pair<int,int>> candidates;
        cout << "\nExpanding level with " << currentLevel.size() << " nodes: ";
        for(int node : currentLevel) cout << node << " ";
        cout << endl;

        for(int node : currentLevel){
            if(node==goal){
                cout << "\nGoal reached!" << endl;
                vector<int> path;
                for(int at=goal;at!=-1;at=parent[at]){
                    path.insert(path.begin(),at);
                }
                return path;
            }
            for(int neighbor=0;neighbor<V;++neighbor){
                if(adjMatrix[node][neighbor]>0 && !visited[neighbor]){
                    candidates.push_back({heuristic[neighbor],neighbor});
                    parent[neighbor]=node;
                }
            }
        }

        sort(candidates.begin(),candidates.end());

        currentLevel.clear();
        cout << "  - Generated " << candidates.size() << " candidates. Pruning to " << min(beamWidth,(int)candidates.size()) << "." << endl;
        for(int i=0;i<min(beamWidth,(int)candidates.size());++i){
            int nextNode=candidates[i].second;
            if(!visited[nextNode]){
                visited[nextNode]=true;
                currentLevel.push_back(nextNode);
            }
        }
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
    int beamWidth;
    cout<<"Enter beam width: ";
    cin>>beamWidth;
    vector<int> path=beamSearch(adjMatrix,heuristic,start,goal,beamWidth);
    if(path.empty()){
        cout<<"No path found."<<endl;
    }else{
        cout<<"\nPath found: ";
        for(int node:path){
            cout<<node<<" ";
        }
        cout<<endl;
    }
    return 0;
}
