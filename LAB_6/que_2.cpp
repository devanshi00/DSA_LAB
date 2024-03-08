#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}
vector<int> longestpath (int V, vector<int> adj[],vector<int> indegree) {

    vector<int> LP(V,INT16_MIN);
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            LP[i]=0;
        }
    }
    for(int i=0; i<V; i++)
        for(auto j: adj [i]){
            LP[j]=max(LP[j],LP[i]+1);
        }
        return LP;

    }

    
        


int main(){
    int V=5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 4);
    vector<int> indegree(V, 0);
    for(int i=0; i<V; i++)
        for(auto it: adj [i]){
            indegree[it]++;
        }
    
    vector<int>LP=longestpath(V,adj,indegree);
    for(int i=0;i<V;i++){
        cout<<"Longest path of "<<i<<" is "<<LP[i]<<endl;
    }

return 0;
}