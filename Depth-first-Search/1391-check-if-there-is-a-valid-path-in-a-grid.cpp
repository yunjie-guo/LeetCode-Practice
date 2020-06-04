class Solution {
public:
    vector<vector<int> > flag;
    
    bool enter(int a, int b, int dir){
        if (dir==0){ if (a==1 || a==4 || a==6){return b==3 || b==5 || b==1;}} // right
        if (dir==1){ if (a==1 || a==3 || a==5){return b==4 || b==6 || b==1;}} // left
        if (dir==2){ if (a==3 || a==4 || a==2){return b==5 || b==6 || b==2;}} // down
        if (dir==3){ if (a==2 || a==5 || a==3){return b==3 || b==4 || b==2;}} // up
        return false;
    }
    
    bool dfs(vector<vector<int>>& grid, int x, int y, int x0, int y0){
        if (x<0 || y<0 || x>x0 || y>y0 || flag[x][y]==1) return false; // already comes or out of bound
        if (x==x0&&y==y0) return true; // arrive the destination
        flag[x][y] = true;
        int cur = grid[x][y];
        int up = -1, down = -1, right = -1, left = -1;
        if (x>0) up = grid[x-1][y];
        if (x<x0) down = grid[x+1][y];
        if (y>0) left = grid[x][y-1];
        if (y<y0) right = grid[x][y+1];
        return (enter(cur,up,3)&&dfs(grid,x-1,y,x0,y0))
            || (enter(cur,down,2)&&dfs(grid,x+1,y,x0,y0))
            || (enter(cur,left,1)&&dfs(grid,x,y-1,x0,y0))
            || (enter(cur,right,0)&&dfs(grid,x,y+1,x0,y0));
    }
    
    bool hasValidPath(vector<vector<int>>& grid) {
        int x = grid.size();
        int y = grid[0].size();
        vector<int> temp(y,0);
        flag.resize(x,temp);
        --x;
        --y;
        return dfs(grid, 0, 0, x, y);
    }
};