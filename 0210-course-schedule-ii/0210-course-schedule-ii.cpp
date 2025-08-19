
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        vector<int>ans;
        for (auto &pre : prerequisites) {
            int u = pre[1]; 
            int v = pre[0]; 
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        
        while (!q.empty()) {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            

            for (auto neigh : adj[node]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0) q.push(neigh);
            }
        }

          if (ans.size() == numCourses) 
            return ans;
        else 
            return {};
    }
};
