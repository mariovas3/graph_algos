#include<bits/stdc++.h>

//processing one component
void dfs(int vertex,const std::vector<std::vector<int>>&adj,std::vector<bool>&taken){
    if(!taken[vertex]){
        taken[vertex]=true;
        if(!adj[vertex].empty()){
            for(int x:adj[vertex]){
                dfs(x,adj,taken);
            }
        }
    }
}

//processing all components
int comps(const std::vector<std::vector<int>>&adj){
    int count=0,n=adj.size();
    std::vector<bool>taken(n,false);
    for(int i=0;i<n;i++){
        if(!taken[i]){
            dfs(i,adj,taken);
            count++;
        }
    }
    return count;
}