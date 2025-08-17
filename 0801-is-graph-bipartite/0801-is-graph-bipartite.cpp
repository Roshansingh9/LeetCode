class Solution {
public:
    bool dfs(int node, int color, vector<int>& colors, vector<vector<int>>& graph) {
        colors[node] = color;  
        for (int neigh : graph[node]) {
            if (colors[neigh] == -1) {
                
                if (!dfs(neigh, 1 - color, colors, graph)) 
                    return false;
            } else if (colors[neigh] == color) {
                
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1); 

        for (int i = 0; i < n; i++) {
            if (colors[i] == -1) { 
                
                if (!dfs(i, 0, colors, graph)) 
                    return false;
            }
        }
        return true;
    }
};
