#include<bits/stdc++.h>


#define INF 1e9+5

//runs in O(V^3) time;
//graph represented in matrix form with adj[i][j] is the weight from i to j

std::vector<std::vector<int>> FWpath(const std::vector<std::vector<int>>&adj){
    int n=adj.size();
    std::vector<std::vector<int>>paths(n,std::vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)paths[i][j]=0;
            else if(adj[i][j])paths[i][j]=adj[i][j];
            else paths[i][j]=INF;
        }
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                paths[i][j]=std::min(paths[i][j],paths[i][k]+paths[k][j]);
            }
        }
    }
    return paths;
}