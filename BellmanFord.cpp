#include<bits/stdc++.h>

#define INF 1e9+5
//O(V*E) time, where V is #vertices and E is #edges 

std::vector<int> BFpath(int start,const std::vector<std::vector<std::pair<int,int>>>&adj){
    int n=adj.size();
    std::vector<int>distances(n,INF);distances[start]=0;
    bool neg_cycle=false;//checks if there is a negative cycle in the graph;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!adj[j].empty()){
                for(auto p:adj[j]){
                    if(distances[p.first]>distances[j]+p.second){
                        distances[p.first]=distances[j]+p.second;
                        if(i==n-1)neg_cycle=true;
                    }
                }
            }
        }
    }
    if(neg_cycle)distances.assign(n,-1);
    return distances;
}