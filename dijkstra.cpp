#include <vector>
#include<iostream>
using namespace std;

//implementation with array so O(V^2+E) time O(V) space, V is #nodes, E is #edges
//each edge has {vertex,cost}, graph is stored in an adjecency list, so each index is a starting vertex

vector<int> dijkstra(int start, vector<vector<vector<int>>> edges) {
 	int n=edges.size();
	vector<bool>taken(n,false);//check if node is already explored
	vector<int>costs(n,INT32_MAX);//a vector containing the costs
	
	costs[start]=0;
	taken[start]=true;
	
	int vertex=start;
	int min=INT32_MAX,diff=INT32_MAX;
	int i,count=n;
	
	while(count){
		if(!edges[vertex].empty()){
			for(auto x:edges[vertex]){
				if(taken[x[0]]==false&&costs[x[0]]>costs[vertex]+x[1]){
					costs[x[0]]=costs[vertex]+x[1];
				}
			}
		}
        //finding the next min cost to explore
		for(i=0;i<n;i++)if(taken[i]==false&&diff>costs[i]){min=i;diff=costs[i];}
        
        //if no avilable min edges found return the vector of costs;
		if(min==INT32_MAX){

			//optional loop if you want to have -1 instead of INF to appear for unreachable nodes
            for(int &x:costs)if(x==INT32_MAX)x=-1;
			return costs;
		}
		taken[min]=true;
		vertex=min;
		min=INT32_MAX;
		diff=INT32_MAX;
		count--;
	}

    //optional loop if you want to have -1 instead of INF to appear for unreachable nodes
	for(int &x:costs)if(x==INT32_MAX)x=-1;
	return costs;
}