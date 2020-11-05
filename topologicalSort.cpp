#include<unordered_map>
#include<vector>
#include<deque>
using namespace std;

//this implementation of topological sort is done on a graph that is stored in an adjecency list

//dfs from vertex
void dfs(int vertex,vector<int>&states,const unordered_map<int,vector<int>>&graph,deque<int>&result){
    if(!states[0]&&states[vertex]==0){
        states[vertex]=1;
        if(graph.find(vertex)!=graph.end()){
            for(int x:graph.at(vertex)){
                if(states[x]==1)states[0]=-1;

                dfs(x,states,graph,result);
            }
        }
        result.push_front(vertex);
        states[vertex]=2;
    }
}


//assuming the graph has verteces={1,2,3,...,n};
deque<int> topologicalSort(unordered_map<int,vector<int>>graph,int n_nodes){
    if(!graph.empty()){

        deque<int>result;
        //3 states 0-not touched, 1-currently exploring, 2-explored
        vector<int>states(n_nodes+1,0);

        for(auto iter=graph.begin();iter!=graph.end();iter++){
            if(states[iter->first]==0)dfs(iter->first,states,graph,result);
        }
        //if it is a DAG return the deque, otherwise if it has a cycle return {-1};
        if(!states[0])return result;
        return {-1};
    }
    return {};
}