#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}
bool is_cycle (int V, vector<int> adj[]) {
    vector<int> indegree(V, 0);
    for(int i=0; i<V; i++){
        for(auto it: adj [i]){
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int> topo;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    if(topo.size()==V){
        return false;
    }
    return true;
}
        


int main(){
    int V=5;
    vector<int>adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 0, 3);
    addEdge(adj, 3, 4);

    cout<<is_cycle(V,adj)<<endl;
return 0;
}

