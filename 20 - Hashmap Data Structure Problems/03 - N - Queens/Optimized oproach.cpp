class Solution {
    public:

        void addSolution(vector<vector<string>>& ans, vector<int>& board, int n){
            vector<string> temp;

            for(int i = 0; i < n; i++){
                string row(n, '.');
                row[board[i]] = 'Q';
                temp.push_back(row);
            }
            ans.push_back(temp);
        }

        void solve(int col, vector<vector<string>>& ans, vector<int>& board, unordered_set<int>& rows, unordered_set<int>& primaryDiag, unordered_set<int>& secondaryDiag, int n){
            if(col == n){
                addSolution(ans, board, n);
                return;
            }

            for(int row = 0; row < n; row++){
                int diag1 = row - col;
                int diag2 = row + col;

                if(rows.find(row) == rows.end() && primaryDiag.find(diag1) == primaryDiag.end() && secondaryDiag.find(diag2) == secondaryDiag.end()){
                    board[col] = row;
                    rows.insert(row);
                    primaryDiag.insert(diag1);
                    secondaryDiag.insert(diag2);

                    solve(col + 1, ans, board, rows, primaryDiag, secondaryDiag, n);

                    board[col] = -1;
                    rows.erase(row);
                    primaryDiag.erase(diag1);
                    secondaryDiag.erase(diag2);
                }
            }
        }
        vector<vector<string>> solveNQueens(int n) {
            vector<int> board(n, -1);
            vector<vector<string>> ans;
            unordered_set<int> rows;
            unordered_set<int> primaryDaig;
            unordered_set<int> secondaryDaig;

            solve(0, ans, board, rows, primaryDaig, secondaryDaig, n);
            return ans;
        }
};
