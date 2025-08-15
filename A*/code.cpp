#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<map>

using namespace std;

struct Node{
    int vertex;
    int gScore;
    int hScore;
    bool operator>(const Node& other)const{
        return (gScore+hScore) > (other.gScore+other.hScore);
    }
};

void astar(const vector<vector<pair<int,int>>>& adjList,const vector<int>& heuristic,int start,int goal){
    int V=adjList.size();
    priority_queue<Node,vector<Node>,greater<Node>> openSet;
    map<int,int> cameFrom;
    vector<int> gScore(V,INT_MAX);
    vector<int> path;

    gScore[start]=0;
    openSet.push({start,gScore[start],heuristic[start]});

    while(!openSet.empty()){
        int current=openSet.top().vertex;
        openSet.pop();

        if(current==goal){
            int temp=goal;
            while(cameFrom.count(temp)){
                path.push_back(temp);
                temp=cameFrom[temp];
            }
            path.push_back(start);

            cout<<"Path: ";
            for(int i=path.size()-1;i>=0;--i){
                cout<<path[i]<<" ";
            }
            cout<<"\nTotal Cost: "<<gScore[goal]<<endl;
            return;
        }

        for(const auto& neighborPair : adjList[current]){
            int neighbor=neighborPair.first;
            int weight=neighborPair.second;
            int newGScore=gScore[current]+weight;

            if(newGScore<gScore[neighbor]){
                cameFrom[neighbor]=current;
                gScore[neighbor]=newGScore;
                openSet.push({neighbor,newGScore,heuristic[neighbor]});
            }
        }
    }
}

int main(){
    int V;
    cout<<"Enter the number of vertices: ";
    cin>>V;

    vector<vector<pair<int,int>>> adjList(V);
    vector<int> heuristic(V);
    int E;
    cout<<"Enter the number of edges: ";
    cin>>E;

    cout<<"Enter the edges (u v weight):"<<endl;
    for(int i=0;i<E;++i){
        int u,v,w;
        cin>>u>>v>>w;
        adjList[u].push_back({v,w});
        adjList[v].push_back({u,w});
    }

    cout<<"Enter the heuristic values for each vertex:"<<endl;
    for(int i=0;i<V;++i){
        cout<<"Heuristic for vertex "<<i<<": ";
        cin>>heuristic[i];
    }
    
    int start,goal;
    cout<<"Enter the start node: ";
    cin>>start;
    cout<<"Enter the goal node: ";
    cin>>goal;

    astar(adjList,heuristic,start,goal);

    return 0;
}
