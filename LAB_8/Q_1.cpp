#include<bits/stdc++.h>
using namespace std;
// const int N=10;
// int parent[N],sz[N];

struct DisjointSet
{
	int *parent;
    int *sz;

	// Constructor
	DisjointSet(int n)
	{
		parent = new int[n+1];
        sz= new int[n+1];

		// Every node is a parent of itself
		for (int i = 0; i <n; i++){
			parent[i] = i;
            sz[i]=1;}
	}

	// Path Compression
	int find(int s)
	{
		/* Make the parent of the nodes in the path
		from u--> parent[u] point to parent[u] */
		if (s == parent[s])
			return s;
		return parent[s] = find(parent[s]);
	}

	void Union(int a, int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        if(sz[a]<=sz[b]){
            parent[a]=b;
            sz[b]+=sz[a];
        }
        else{
            parent[b]=a;
            sz[a]+=sz[b];
        }
        
    }
}
};
bool compareEdges(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
    return a.first > b.first; // Compare by weight in descending order
}

int main(){
    freopen("testcases_Q1.txt","r",stdin);
    freopen("output_Q1.txt","w",stdout);
    int num_nodes,num_edges;
    cin>>num_nodes>>num_edges;
    
    vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<num_edges;++i){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({wt,{u,v}});

    }
    
    sort(edges.begin(),edges.end(),compareEdges);
    DisjointSet ds(num_nodes);

    int total_cost=0;
    cout<<"EDGES USED :-"<<endl;
    for(auto &edge:edges){
        int wt=edge.first;
        int u=edge.second.first;
        int v=edge.second.second;
        if(ds.find(u)==ds.find(v)){
            continue;
        }
        ds.Union(u,v);
        total_cost+=wt;
        cout<<u<<' '<<v<<endl;


    }
    cout<<"TOTAL COST: "<<total_cost<<endl;

}