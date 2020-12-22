#include<bits/stdc++.h>

//assumes start in {0,adj.size()-1}
std::vector<int> bfs(int start,const std::vector<std::vector<int>>&adj){
    std::vector<int>order;
    std::vector<bool>taken((int)adj.size(),false);
    std::queue<int>nodes;
    int k,n=adj.size();

    //process all components
    for(int i=0;i<n;i++){    
        if(taken[(start+i)%n])continue;

        nodes.push((start+i)%n);taken[(start+i)%n]=true;
        while(!nodes.empty()){
            k=nodes.front();
            nodes.pop();
            order.push_back(k);

            if(!adj[k].empty()){
                for(int x:adj[k]){
                    if(!taken[x]){
                        nodes.push(x);taken[x]=true;
                    }
                }
            }
        }
    }
    return order;
}