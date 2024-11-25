template <typename T>
class graph{
    public:
        vector<vector<int>> adj;
        
        graph(int V){
            adj.resize(V);
        }
        
        void addEdge(T u, T v, bool direction){
            adj[u].push_back(v);
            
            if(direction == 0) adj[v].push_back(u);
        }
        
        void printAdj(vector<vector<int>>& ans){
            for(int i = 0; i < adj.size(); i++){
                for(auto j : adj[i]){
                    ans[i].push_back(j);
                }
            }
        }
};

class Solution {
  public:
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        graph<int> g(V);
        
        for(int i = 0; i < edges.size(); i++){
            g.addEdge(edges[i].first, edges[i].second, 0);
        }
        
        vector<vector<int>> ans(V);
        g.printAdj(ans);
        
        return ans;
    }
};
