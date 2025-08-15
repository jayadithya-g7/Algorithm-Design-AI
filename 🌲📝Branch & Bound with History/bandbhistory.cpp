#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

struct Node{
    int vertex;
    int cost;
    vector<int> path;
    bool operator>(const Node& other)const{
        return cost > other.cost;
    }
};

void branchBoundHistory(const vector<vector<int>>& adjMatrix,int start,int goal){
    int V=adjMatrix.size();
    priority_queue<Node,vector<Node>,greater<Node>> pq;
    vector<int> minCost(V,INT_MAX);
    
    pq.push({start,0,{start}});
    minCost[start]=0;

    while(!pq.empty()){
        Node current=pq.top();
        pq.pop();

        if(current.vertex==goal){
            cout<<"Path: ";
            for(int v:current.path){
                cout<<v<<" ";
            }
            cout<<"\nTotal Cost: "<<current.cost<<endl;
            return;
        }

        if(current.cost > minCost[current.vertex]) continue;

        for(int neighbor=0;neighbor<V;neighbor++){
            if(adjMatrix[current.vertex][neighbor]>0){
                int newCost=current.cost+adjMatrix[current.vertex][neighbor];
                if(newCost<minCost[neighbor]){
                    minCost[neighbor]=newCost;
                    vector<int> newPath=current.path;
                    newPath.push_back(neighbor);
                    pq.push({neighbor,newCost,newPath});
                }
            }
        }
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
    int start,goal;
    cout<<"Enter start node: ";
    cin>>start;
    cout<<"Enter goal node: ";
    cin>>goal;
    branchBoundHistory(adjMatrix,start,goal);
    return 0;
}
