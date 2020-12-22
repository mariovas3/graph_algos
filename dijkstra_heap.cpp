#include<bits/stdc++.h>

#define INF 1e9+5

//implemented with heap runs in O(V+E*log(E)) time
//V is #vertices, E is #edges
//not reliable with negative weighted edges

std::vector<int> dijkstraPaths(int start,const std::vector<std::vector<std::pair<int,int>>>&adj){
    std::priority_queue<std::pair<int,int>>min_cost;//defaults to max heap, hence, use -distance
    min_cost.push({0,start});
    int n=adj.size();
    std::vector<int>distances(n,INF);distances[start]=0;
    std::vector<bool>processed(n,false);

    while(!min_cost.empty()){
        int a=min_cost.top().second;min_cost.pop();
        processed[a]=true;
        for(auto e:adj[a]){
            if(processed[e.first]==false&&distances[e.first]>distances[a]+e.second){
                distances[e.first]=distances[a]+e.second;
                min_cost.push({-distances[e.first],e.first});
            }
        }
    }

    return distances;
}