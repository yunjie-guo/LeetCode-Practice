const static int io_opt = []() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	return 0;
}();

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int m = 0;
        int n = matrix.size()-1;
        int size = matrix[0].size();
        // start from the left bottom
        while(n>=0 && m<size){
            int temp = matrix[n][m];
            if (temp<target) {
                ++m;
            } else if (temp>target) {
                --n;
            } else {
                return true;
            }
        }
        return false;
    }
};