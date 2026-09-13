# include <iostream>
# include <vector>
# include <set>
using namespace std;
// Articulation points are those when cutt off that node it splits the graph into 2 or more components
class Graph{
public:
    vector<vector<int>> adj;
    int V;
    int time;
    vector<int> dt,low;
    Graph(int V){
        this->V = V;
        adj.resize(V);
    }
    
    void addEdge(int u , int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u , int parU , vector<bool> &vis,set<int> &CriticalPoints){
        vis[u] = true;
        dt[u] = low[u] = ++time;
        int children = 0;

        for(int i = 0 ; i < adj[u].size() ; i++){
            int v = adj[u][i];

            if(!vis[v]){
                children++;
                dfs(v,u,vis,CriticalPoints);
                low[u] = min(low[u],low[v]);

                if(parU != -1 && low[v] >= dt[u]){
                    // Articulation Point
                    CriticalPoints.insert(u);
                }
            }
            else if(v != parU){
                low[u] = min(low[u],dt[v]);
            }
        }

        if(parU == -1 && children > 1){
            // Articulation Point
            CriticalPoints.insert(u);
        }
    }
    int articulationPoints(){
        time = 0;
        dt.resize(V);
        low.resize(V);
        vector<bool> vis(V,false);
        set<int> CriticalPoints;

        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                dfs(i,-1,vis,CriticalPoints);
            }
        }
        return CriticalPoints.size();
    }
};