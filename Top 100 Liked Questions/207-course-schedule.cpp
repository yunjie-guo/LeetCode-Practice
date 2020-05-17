class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegrees(numCourses);
        // Topological Sorting
        for(auto& p : prerequisites) {
            // p0 needs p1 to be the prerequisite
            adjList[p[1]].push_back(p[0]);
            // p0's prerequisite count increases 1
            ++inDegrees[p[0]];
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; ++i) {
            if(inDegrees[i] == 0) {
                // course i has no prerequisite and can be removed in the graph
                q.push(i);
            }
        }
        
        int count = 0;
        while(!q.empty()) {
            int current = q.front();
            q.pop();
            ++count;
            
            for(auto& next : adjList[current]) {
                if(--inDegrees[next] == 0) {
                    // course next's prerequisites are available and can be removed
                    q.push(next);
                }
            }
        }
        
        // the number of available courses is the same as numCourses
        return numCourses == count;
    }
};