#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int>>& adj, int u, int v){
    adj[u].push_back(v);
}
void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& finishOrder) {
        vis[node] = 1;
        for (int it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, finishOrder);
            }
        }
        finishOrder.push_back(node);
    }

    void dfs2(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        for (int it : adj[node]) {
            if (!vis[it]) {
                dfs2(it, adj, vis);
            }
        }
    }
int kosaraju(int V, vector<vector<int>>& adj) {
        vector<int> vis(V, 0);
        vector<int> finishOrder;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, finishOrder);
            }
        }

        // Creating the transpose graph (adjT)
        vector<vector<int>> adjT(V);
        for (int i = 0; i < V; i++) {
            vis[i] = 0;
            for (int it : adj[i]) {
                adjT[it].push_back(i);
            }
        }

        // Last DFS using the finish order
        int scc = 0;
        for (int i = V - 1; i >= 0; i--) {
            int node = finishOrder[i];
            if (!vis[node]) {
                scc++;
                dfs2(node, adjT, vis);
            }
        }
        return scc;
    }
int main(){
    int V=8;
    vector<vector<int>>adj(V);
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);
    addEdge(adj, 6, 4);
    addEdge(adj, 4, 7);
    addEdge(adj, 6, 7);
    int ans=kosaraju(V,adj);
    cout<<ans<<endl;

return 0;
}