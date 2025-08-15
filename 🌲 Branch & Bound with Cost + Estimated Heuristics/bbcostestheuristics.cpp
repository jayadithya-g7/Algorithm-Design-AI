#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<map>

using namespace std;

struct Node{
    int vertex;
    int cost;
    int estimate;
    vector<int> path;
    bool operator>(const Node& other)const{
        return(cost+estimate)>(other.cost+other.estimate);
    }
};

void branchboundheuristic(const vector<vector<int>>& adjMatrix,const vector<int>& heuristic,int start,int goal){
    int V=adjMatrix.size();
    priority_queue<Node,vector<Node>,greater<Node>> pq;
    map<int,int> minCost;

    pq.push({start,0,heuristic[start],{start}});
    minCost[start]=0;

    cout<<"Starting search from node "<<start<<" to node "<<goal<<endl;

    while(!pq.empty()){
        Node current=pq.top();
        pq.pop();

        cout<<"Expanding node "<<current.vertex<<" with total cost "<<current.cost+current.estimate<<endl;

        if(current.vertex==goal){
            cout<<"Goal reached!"<<endl;
            cout<<"Path: ";
            for(int v:current.path){
                cout<<v<<" ";
            }
            cout<<"\nTotal Cost: "<<current.cost<<endl;
            return;
        }

        if(current.cost > minCost[current.vertex]){
            continue;
        }

        for(int neighbor=0;neighbor<V;neighbor++){
            if(adjMatrix[current.vertex][neighbor]>0){
                int newCost=current.cost+adjMatrix[current.vertex][neighbor];
                if(minCost.find(neighbor)==minCost.end() || newCost < minCost[neighbor]){
                    minCost[neighbor]=newCost;
                    vector<int> newPath=current.path;
                    newPath.push_back(neighbor);
                    pq.push({neighbor,newCost,heuristic[neighbor],newPath});
                    cout<<"  - Found new path to neighbor "<<neighbor<<" with cost "<<newCost<<endl;
                }
            }
        }
    }
    cout<<"Goal not reachable."<<endl;
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
    branchboundheuristic(adjMatrix,heuristic,start,goal);
    return 0;
}
