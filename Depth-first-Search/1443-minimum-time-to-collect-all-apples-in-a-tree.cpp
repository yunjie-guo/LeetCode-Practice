class Solution {
public:
    vector<int> visited;
    int dfs(int node, int cost, vector<bool>& hasApple, vector<vector<int> >& adj){
        if (visited[node]) return 0;
        visited[node] = true;
        int children = 0;
        for (auto e : adj[node]){
            children += dfs(e, 2, hasApple, adj); // start from node
        }
        if (children==0 && !hasApple[node]){
            return 0;
            // node has no apple and its children have no apple
        }
        return cost + children;
        
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int> > adj(n);
        visited.resize(n, false);
        for (auto e: edges) {
            adj[e[0]].push_back(e[1]); // adjecency list
		    adj[e[1]].push_back(e[0]);
        }
        return dfs(0, 0, hasApple, adj);
    }
};