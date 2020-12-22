#include<bits/stdc++.h>

//process one component
void dfs(int start,const std::vector<std::vector<int>>&adj,std::vector<int>&order,std::vector<bool>&taken){
    if(!taken[start]){
        taken[start]=true;order.push_back(start);
        if(!adj[start].empty()){
            for(int x:adj[start]){
                dfs(x,adj,order,taken);
            }
        }
    }
}

//goes through all components
std::vector<int> dfsNode(int start,const std::vector<std::vector<int>>&adj){
    std::vector<int>order;
    std::vector<bool>taken((int) adj.size(),false);
    int n=adj.size();

    for(int i=0;i<(int)adj.size();i++){
        dfs((start+i)%n,adj,order,taken);
    }

    return order;
}