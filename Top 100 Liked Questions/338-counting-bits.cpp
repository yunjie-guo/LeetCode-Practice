class Solution {
public:
        vector<int> countBits(int num){
            vector<int> ans(num + 1);
            ans[0] = 0;
            int a = 1;
            for(int i = 1; i <= num; i++){
                if(i == 2 * a){a *= 2;}
                ans[i] = ans[i - a] + 1;
            }
            return ans;
        }
};