class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int,int>> v[n];
        for (int i = 0; i < connections.size(); ++i){
            int a = connections[i][0]; // father
            int b = connections[i][1]; // son
            v[a].push_back(make_pair(b,1));
            v[b].push_back(make_pair(a,0));
        }
        queue<int> q;
        vector<int> father(n,-1);
        q.push(0);
        int ans = 0;
        while (!q.empty()){
            // now is a good node linking to the city zero
            int now = q.front();
            q.pop();
            for (auto i : v[now]){
                if (i.first == father[now]){
                    continue;
                }
                // link the node to now to link to the city zero
                father[i.first] = now;
                ans += i.second;
                q.push(i.first);
            }
        }
        return ans;
    }
};