class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size()==0)
            return;
        int r=board.size();
        int c=board[0].size();
        for(int i=0;i<r;i++){
            dfs(board,i,0);
            dfs(board,i,c-1);
        }
        for(int j=1;j<c;j++){
            dfs(board,0,j);
            dfs(board,r-1,j);
        }
        
        
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='1')
                    board[i][j]='O';
    }
    void dfs(vector<vector<char>>& board , int i, int j){
        int r=board.size();
        int c=board[0].size();
        if(board[i][j]=='O'){
            board[i][j]='1';
            if(i+1<r)
                dfs(board,i+1,j);
            if(i>1)
                dfs(board,i-1,j);
            if(j+1 <c)
                dfs(board,i,j+1);
            if(j>1)
                dfs(board,i,j-1);

        }
    }
};