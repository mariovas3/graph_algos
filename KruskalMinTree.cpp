#include<bits/stdc++.h>

//finds the leader of the set for a vertex x;
int find(int x,const std::vector<int>&union_find){
    while(union_find[x]>=0)x=union_find[x];
    return x;
}

//checks if a,b are from the same component
bool check(int a,int b,const std::vector<int>&union_find){
    return find(a,union_find)==find(b,union_find);
}

//unite if not from the same components (i.e. check is false);
void unite(int a,int b,std::vector<int>&union_find){
    a=find(a,union_find),b=find(b,union_find);

    if(union_find[a]>=union_find[b])std::swap(a,b);
    
    union_find[a]+=union_find[b];
    union_find[b]=a;
}

//O(E*log(V)) time;     checks each edge with check(a,b,union_find) in log(V) time;
//the pairs are (w,{a,b}); w-weight, from a to b;
//returns the sum and the vector of edges as a pair;
template<class T>
std::pair<T,std::vector<std::pair<int,int>>> kruskalMin(const std::vector<std::pair<T,std::vector<int>>>&adj, int n_nodes){
   std::vector<int>union_find(n_nodes,-1);
   //max heap by default, so will use negative weights in the pairs when pushing;
   std::priority_queue<std::pair<T,std::vector<int>>>edges;
   std::vector<std::pair<int,int>>minTree;

   for(auto x:adj)edges.push(std::pair<T,std::vector<int>>(-x.first,x.second));

    int count=0;T sum=0;
    while(!edges.empty()&&count<n_nodes-1){
        auto e=edges.top();edges.pop();
        if(!check(e.second[0],e.second[1],union_find)){
            unite(e.second[0],e.second[1],union_find);count++;sum+=(-e.first);
            minTree.push_back({e.second[0],e.second[1]});
        }
    }
    return {sum,minTree};
}