#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    vector<int> indegree(V, 0);
    // Build graph
    for(auto &e : edges) {
        adj[e[0]].push_back(e[1]);
        indegree[e[1]]++;
    }
    queue<int> q;
    // Push nodes with indegree 0
    for(int i = 0; i < V; i++) {
        if(indegree[i] == 0)
            q.push(i);
    }
    vector<int> ans;

    // BFS
    while(!q.empty()) {
        int node = q.front(); q.pop();
        ans.push_back(node);
        for(int v : adj[node]) {
            if(--indegree[v] == 0)
                q.push(v);
        }
    }
    return ans;
}
int main() {
    int V = 4;
    vector<vector<int>> edges = {{3,0}, {2,0}, {1,0}};
    vector<int> res = topoSort(V, edges);
    for(int x : res) cout << x << " ";
    return 0;
}