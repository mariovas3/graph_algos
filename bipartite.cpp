#include<bits/stdc++.h>

//process the component
void dfs(int vertex,bool&check,int color,const std::vector<std::vector<int>>&adj,std::vector<std::pair<bool,int>>&taken){
    
    //checks if the bipartite property holds
    if(taken[vertex].first==true&&taken[vertex].second==color)check=false;
    
    //usual dfs processing
    if(check&&taken[vertex].first==false){
    
        //set color different to that of the parent
        taken[vertex].first=true;taken[vertex].second=(color==1?2:1);
        if(!adj[vertex].empty()){
            for(int x:adj[vertex]){
                dfs(x,check,taken[vertex].second,adj,taken);
            }
        }
    }    
}


//in the "taken" array, taken[i].first indicates visited or not
//taken[i].second indicates the color in {0,1,2} 1/2 for red/blue, 0 if not visited yet
bool bipartite(const std::vector<std::vector<int>>&adj){
    int n=adj.size();bool check=true;
    std::vector<std::pair<bool,int>>taken(n,{false,0});

    //goes through all of the components
    for(int i=0;i<n;i++){
        if(check==false)return check;
        if(taken[i].first==false)dfs(i,check,1,adj,taken);
    }
    return true;
}