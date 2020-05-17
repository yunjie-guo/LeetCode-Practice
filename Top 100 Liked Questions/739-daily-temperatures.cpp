class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> s; // s save the index of the elements in T
        vector<int> ans;
        ans.resize(T.size(), 0);
        for (int i = T.size()-1; i >= 0; --i){
            while (!s.empty() && T[i] >= T[s.top()]){
                s.pop();
            }
            ans[i] = s.empty() ? 0 : s.top() - i;
            s.push(i);
        }
        return ans;
    }
};