class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& p) {
        // sort the people with people the largest h and smallest k in the front 
        // ex: [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
        // sort: [7,0][7,1][6,1][5,0][5,2][4,4]
        // the first element  is sorted in order, so the position is indicated by the second element
        // ans: [7,0]
        // ans: [7,0][7,1]
        // ans: [7,0][6,1][7,1]
        // ans: [5,0][7,0][6,1][7,1]
        // ans: [5,0][7,0][5,2][6,1][7,1]
        // ans: [5,0][7,0][5,2][6,1][4,4][7,1]
        
        sort(p.begin(), p.end(), [](auto& a, auto& b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
        });
        vector<vector<int>> res;
        for(auto& e : p) res.insert(res.begin() + e[1], e);
        return res;
        
    }
};