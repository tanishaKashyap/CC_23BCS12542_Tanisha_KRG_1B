#include<bits/stdc++.h>
using namespace std;

vector<int> topo(int V, vector<int> adj[]){
    vector<int> in(V,0),ans;
    for(int i=0;i<V;i++){
        for(auto v:adj[i]) in[v]++;
    }
    queue<int> q;
    for(int i=0;i<V;i++){
        if(in[i]==0) q.push(i);
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        ans.push_back(u);
        for(auto v:adj[u]){
            in[v]--;
            if(in[v]==0) q.push(v);
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<string> w(n);
    for(int i=0;i<n;i++) cin>>w[i];

    vector<int> adj[26];

    for(int i=0;i<n-1;i++){
        int len=min(w[i].size(),w[i+1].size());
        bool f=false;
        for(int j=0;j<len;j++){
            if(w[i][j]!=w[i+1][j]){
                adj[w[i][j]-'a'].push_back(w[i+1][j]-'a');
                f=true;
                break;
            }
        }
        if(!f && w[i].size()>w[i+1].size()){
            cout<<"Impossible";
            return 0;
        }
    }

    vector<int> res=topo(26,adj);

    if(res.size()!=26){
        cout<<"Impossible";
        return 0;
    }

    for(auto x:res) cout<<char(x+'a');
    return 0;
}
