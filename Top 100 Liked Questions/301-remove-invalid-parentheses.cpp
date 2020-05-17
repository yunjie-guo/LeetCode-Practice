class Solution {
    private:
        vector<string> ans;
    public:
        vector<string> removeInvalidParentheses(string s) {

            int left=0, right=0;
            // count how many left or right parentheses we need to remove
            for( char c : s ) {
                if( c == '(' )
                    left++;
                else if( c==')' ) {
                    if( left )
                        left--;
                    else
                        right++;
                }
            }

            dfs( s, left, right, 0 );

            return ans;
        }

        void dfs( string s, int left, int right, int index ) {
            if( left==0 && right==0 ) {
                if( isValid(s) )
                    ans.push_back(s);
                return;
            }

            for( int i = index; i<s.size(); i++ ) {
                if( i!=index && s[i] == s[i-1] )
                    continue;
                
                // remove s[i] and dfs
                string next = s.substr( 0, i ) +s.substr( i+1 );
                if( s[i] == ')' && right>0 ) {
                    dfs( next, left, right-1, i );
                }
                if( s[i] == '(' && right==0 && left>0 ) {
                    dfs( next, left-1, right, i );
                }
            }

        }

        bool isValid( string& s ) {
            int count = 0;
            for( char c : s ) {
                if( c == '(' )
                    count++;
                else if( c==')') 
                    count--;
                if( count<0 )
                    return false;
            }

            return count==0;
        }
    
};