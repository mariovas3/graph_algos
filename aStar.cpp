#include<bits/stdc++.h>
using namespace std;

const int INF=1e9+5;


// calculate the heuristic (Manhattan distance for grid)
// done in O(1) time and O(1) space;
int dist(const int& r1,const int& c1,const int& r2,const int& c2){
    return abs(r1-r2)+abs(c1-c2);
}


// arrange path to be from start to end;
// O(path) time
void revPath(vector<vector<int>>&shortest){
    int i=0,j=shortest.size()-1;

    while(i<j){
        auto temp=shortest[i];
        shortest[i][0]=shortest[j][0];
        shortest[i][1]=shortest[j][1];
        shortest[j][0]=temp[0];
        shortest[j][1]=temp[1];
        i++;j--;
    }
}

// finding the path
// O(path) time;
vector<vector<int>>findPath(int r1,int c1,const vector<vector<vector<int>>>&paths){
    vector<vector<int>>shortest;
    while(paths[r1][c1][1]!=r1||paths[r1][c1][2]!=c1){
        shortest.push_back({r1,c1});
        auto temp=paths[r1][c1];// G,predecessorROW,predecessorCOL;
        r1=temp[1];
        c1=temp[2];
    }
    shortest.push_back({r1,c1});
    revPath(shortest);
    return shortest;
}

// finding neighbours of (i,j) in O(1) time;
vector<vector<int>> findNeib(int i,int j,const vector<vector<int>>&graph){
    int n=graph.size(),m=graph[0].size();
    vector<vector<int>>neib;

    // check for bounds and whether the element is accessible i.e. if 0
    if(i-1>=0&&graph[i-1][j]==0)neib.push_back({i-1,j});
    if(i+1<n&&graph[i+1][j]==0)neib.push_back({i+1,j});
    if(j-1>=0&&graph[i][j-1]==0)neib.push_back({i,j-1});
    if(j+1<m&&graph[i][j+1]==0)neib.push_back({i,j+1});

    return neib;
}

// O(n*m*log(n*m)) time and O(m*n) space
vector<vector<int>> aStar(int s1, int s2, int e1,int e2, vector<vector<int>> graph) {
  int n=graph.size(),m=graph[0].size();
  // min_heap ot get the cheapest nodes
  priority_queue<vector<int>>min_cost;// -F,-G,ROW,COL 
  // store the path cost and predecessor node;
  vector<vector<vector<int>>>paths(n,vector<vector<int>>(m,{INF,-1,-1}));

  // the start node has path cost 0 and
  // is its own predecessor;
  paths[s1][s2]={0,s1,s2};
  // push it to the min_heap
  min_cost.push({-dist(s1,s2,e1,e2),0,s1,s2});

  while(!min_cost.empty()){
    // get the cheapest node in O(log(n*m)) time;
    auto v=min_cost.top();
    int F=-v[0],G=-v[1],r1=v[2],c1=v[3];
    // if the node is the end goal node
    // return the shortest path;
    if(r1==e1&&c1==e2)return findPath(e1,e2,paths);
    // otherwise proceed with the node;
    min_cost.pop();
    // find the neighbours of (r1,c1)
    auto neib=findNeib(r1,c1,graph);
    // that would be the path cost to either of the neighbours;
    int temp_gcost=paths[r1][c1][0]+1;
    // process each neighbour;
    for(auto nei:neib){
        // if the temp_gcost is better than the previous
        // gcost for the neighbour, then I found a better path
        // to that neighbour, so update the gcost and predecessor
        // in paths;
        if(paths[nei[0]][nei[1]][0]>temp_gcost){
            paths[nei[0]][nei[1]]={temp_gcost,r1,c1};
            int fcost=temp_gcost+dist(nei[0],nei[1],e1,e2);
            min_cost.push({-fcost,-temp_gcost,nei[0],nei[1]});
        }
    }
  }
    // if a path is not returned, then the end point
    // is not reachable.
    return {};
}
