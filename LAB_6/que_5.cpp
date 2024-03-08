#include<bits/stdc++.h>
using namespace std;
void addEdge (vector<int>adj[],int u,int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int timer=1;
int timer2=1;
void dfs(int parent,int node,vector<int>adj[],vector<int>&visited,vector<int>&low,vector<int>&in,vector<pair<int,int>>&bridge){
    visited[node]=1;
    in[node]=low[node]=timer++;
    for(auto it:adj[node]){
        if(it==parent){
            continue;
        }
        if(visited[it]==0){
            dfs(node,it,adj,visited,low,in,bridge);
            low[node]=min(low[node],low[it]);
            if(low[it]>in[node]){
               bridge.push_back({node,it});
            }
            
        }
        else{
                low[node]=min(low[node],low[it]);
            }
    }
}
void articulation_point(int parent,int node,vector<int>adj[],vector<int>&visited_a,vector<int>&low_a,vector<int>&in_a,vector<int>&marked){
    visited_a[node]=1;
    in_a[node]=low_a[node]=timer2++;
    int child=0;
    for(auto it:adj[node]){
        if(it==parent){
            continue;
        }
        if(visited_a[it]==0){
            articulation_point(node,it,adj,visited_a,low_a,in_a,marked);
            low_a[node]=min(low_a[node],low_a[it]);
            if(low_a[it]>=in_a[node] && parent!=-1){
               marked[node]=1;
            }
            child++;

        }
        else{
                low_a[node]=min(low_a[node],in_a[it]);
            }
    }
    if(parent==-1 && child>1){
        marked[node]=1;
    }
}
int main(){
    int V=5;
    vector<int>adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 0, 3);
    addEdge(adj, 3, 4);

    vector<int>visited(V,0),low(V,-1),in(V,-1);
    vector<pair<int,int>>bridge;
    dfs(-1,0,adj,visited,low,in,bridge);
    for(auto it:bridge){
        cout<<"BRIDGES BETWEEN "<<it.first<<" "<<it.second<<endl;
    }
     vector<int>visited_a(V,0),low_a(V,-1),in_a(V,-1),marked(V,0);
     articulation_point(-1,0,adj,visited_a,low_a,in_a,marked);
     cout<<"ARTICULATION POINTS ARE ";
     for(int i=0;i<V;i++){
         if(marked[i]==1){
             cout<<i<<" ";
         }
     }

return 0;
}