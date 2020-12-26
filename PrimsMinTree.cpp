#include<bits/stdc++.h>

//O(V+E*log(E)) time complexity, similar to dijkstra with heap;

//if the graph has multiple components, only the one containing
//the start vertex shall be used to construct the min spanning tree;
//this is because Prim's algorithm maintains a spanning tree at
// all times in contrast to Kruskal's algo;

//pairs are of the format {w,b}; w-weight, b-destination;
template<class T>
std::pair<T,std::vector<std::pair<int,int>>> pirmsTree(int vertex,const std::vector<std::vector<std::pair<int,int>>>&adj){
    int n=adj.size();
    std::priority_queue<std::pair<int,std::vector<int>>>edges;
    T sum=0;
    //the edges that comprise the min spanning tree by Prim's algo
    std::vector<std::pair<int,int>>minTree;
    std::unordered_set<int>visited;
    visited.insert(vertex);

    for(auto x:adj[vertex])edges.push({-x.first,{vertex,x.second}});

    while(!edges.empty()){
        auto e=edges.top();edges.pop();
        if(visited.find(e.second[1])==visited.end()){
            visited.insert(e.second[1]);
            sum+=(-e.first);
            minTree.push_back({e.second[0],e.second[1]});
            vertex=e.second[1];
            for(auto x:adj[vertex]){
                if(visited.find(x.second)==visited.end())edges.push({-x.first,{vertex,x.second}});
            }
        }
    }

    return {sum,minTree};
}
