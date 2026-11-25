/*Dry Run with n = 4
The board starts as:

. . . .
. . . .
. . . .
. . . .

Column 0 (leftmost)
Try row 0: Place Q at (0,0). ✅ Safe.

Q . . .
. . . .
. . . .
. . . .

Column 1
Try row 0: ❌ Same row as (0,0). Skip.

Try row 1: ❌ Same diagonal as (0,0) (\). Skip.

Try row 2: ✅ Safe! Place Q at (2,1).

Q . . .
. . . .
. Q . .
. . . .

Column 2
Try row 0: ❌ Same diagonal as (2,1) (/). Skip.

Try row 1: ❌ Same diagonal as (0,0) (/). Skip.

Try row 2: ❌ Same row as (2,1). Skip.

Try row 3: ❌ Same diagonal as (2,1) (\). Skip.

Stuck! 🙁 No safe square. Backtrack — erase the queen at (2,1).

Back to Column 1
Try row 3: ✅ Safe! Place Q at (3,1).

Q . . .
. . . .
. . . .
. Q . .

Column 2
Try row 0: ❌ Same diagonal as (3,1) (\). Skip.

Try row 1: ✅ Safe! Place Q at (1,2).

Q . . .
. . Q .
. . . .
. Q . .

Column 3
Try row 0: ❌ Same row as (0,0). Skip.

Try row 1: ❌ Same row as (1,2). Skip.

Try row 2: ✅ Safe! Place Q at (2,3).

Q . . .
. . Q .
. . . Q
. Q . .

🎉 All 4 columns filled! Save this board!
Then the code backtracks (erases (2,3), tries other options) to find all valid solutions. For n=4 there are 2 solutions (the one above and its mirror).

The Three Arrays (like "no-entry" signs)
Array	What it means	Analogy
leftRow[row]	"Row row is taken"	A sign on the row saying "no more queens here"
lowerDiagnol[row+col]	"This \ diagonal is taken"	A sign along the \ diagonal
upperDiagnol[n-1+col-row]	"This / diagonal is taken"	A sign along the / diagonal

When you place a queen, you put up all three signs. When you backtrack, you take them down. Before placing, you check: "Are any signs already here?" If yes → that square is not safe.

In one sentence
The code tries every possible spot, column by column. If it hits a dead end, it undoes its last move and tries a different spot — until it finds every way to place all the queens safely.

*/

class Solution {
public:
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &upperDiagnol, vector<int> &lowerDiagnol, int n)
    {
        if(col == n)
        {
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++)
        {
            if(leftRow[row] == 0 && lowerDiagnol[row + col] == 0 && upperDiagnol[n-1 + col - row] == 0)
            {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagnol[row+col] = 1;
                upperDiagnol[n-1+col-row] = 1;
                solve(col+1, board, ans, leftRow, upperDiagnol, lowerDiagnol, n);
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagnol[row + col] = 0;
                upperDiagnol[n - 1 + col - row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        vector<int> leftRow(n, 0), upperDiagnol(2 * n - 1, 0), lowerDiagnol(2 * n - 1, 0);
        solve(0, board, ans, leftRow, upperDiagnol, lowerDiagnol, n);
        return ans;
    }
};

/*Dry Run with Code Execution (n = 4)
I'll trace the exact variable values at each step so you can see what every line does.

Initial Call: solveNQueens(4)
vector<vector<string>> ans;          // ans = []
vector<string> board(4);             // board = ["", "", "", ""]
string s(4, '.');                    // s = "...."
for(i=0; i<4; i++) board[i] = s;     // board = ["....", "....", "....", "...."]
vector<int> leftRow(4, 0);           // leftRow = [0, 0, 0, 0]
vector<int> upperDiagnol(7, 0);      // upperDiagnol = [0,0,0,0,0,0,0]
vector<int> lowerDiagnol(7, 0);      // lowerDiagnol = [0,0,0,0,0,0,0]
solve(0, board, ans, leftRow, upperDiagnol, lowerDiagnol, 4);

solve(col=0, ...)
Line: if(col == n) → if(0 == 4) → false, skip.

Line: for(int row = 0; row < 4; row++)

→ row = 0
Line: if(leftRow[0]==0 && lowerDiagnol[0+0]==0 && upperDiagnol[4-1+0-0]==0)
→ if(0==0 && 0==0 && 0==0) → TRUE ✅

Action	Code	Effect
Place	board[0][0] = 'Q'	board[0] = "Q..."
Mark	leftRow[0] = 1	leftRow = [1,0,0,0]
Mark	lowerDiagnol[0+0] = 1	lowerDiagnol = [1,0,0,0,0,0,0]
Mark	upperDiagnol[3+0-0] = 1	upperDiagnol = [0,0,0,1,0,0,0]
Recurse	solve(1, ...)	↓

solve(col=1, ...)
Line: if(1 == 4) → false, skip.

Line: for(int row = 0; row < 4; row++)

→ row = 0
Check: leftRow[0]==0 → 1==0 → FALSE ❌ (row already taken)
→ skip

→ row = 1
Check: leftRow[1]==0 → 0==0 ✅
lowerDiagnol[1+1]==0 → lowerDiagnol[2]==0 ✅
upperDiagnol[3+1-1]==0 → upperDiagnol[3]==0 → FALSE ❌ (diagonal taken!)
→ skip

→ row = 2
Check: leftRow[2]==0 ✅, lowerDiagnol[2+1]==0 → lowerDiagnol[3]==0 ✅, upperDiagnol[3+1-2]==0 → upperDiagnol[2]==0 ✅
→ TRUE ✅

Action	Code	Effect
Place	board[2][1] = 'Q'	board[2] = ".Q.."
Mark	leftRow[2] = 1	leftRow = [1,0,1,0]
Mark	lowerDiagnol[3] = 1	lowerDiagnol = [1,0,0,1,0,0,0]
Mark	upperDiagnol[2] = 1	upperDiagnol = [0,0,1,1,0,0,0]
Recurse	solve(2, ...)	↓

Board now:

Q . . .
. . . .
. Q . .
. . . .

solve(col=2, ...)
Line: if(2 == 4) → false, skip.

→ row = 0
leftRow[0]==0 → 1==0 → ❌ skip

→ row = 1
leftRow[1]==0 ✅, lowerDiagnol[1+2]==0 → lowerDiagnol[3]==0 → 1==0 → ❌ skip

→ row = 2
leftRow[2]==0 → 1==0 → ❌ skip

→ row = 3
leftRow[3]==0 ✅, lowerDiagnol[3+2]==0 → lowerDiagnol[5]==0 ✅, upperDiagnol[3+2-3]==0 → upperDiagnol[2]==0 → 1==0 → ❌ skip

Loop ends. No queen placed. Function returns to solve(col=1).

Back to solve(col=1, row=2) — BACKTRACKING
After solve(2,...) returns, execution continues:

Action	Code	Effect
Un-place	board[2][1] = '.'	board[2] = "...."
Un-mark	leftRow[2] = 0	leftRow = [1,0,0,0]
Un-mark	lowerDiagnol[3] = 0	lowerDiagnol = [1,0,0,0,0,0,0]
Un-mark	upperDiagnol[2] = 0	upperDiagnol = [0,0,0,1,0,0,0]

Loop continues: row++ → row = 3

→ row = 3
Check: leftRow[3]==0 ✅, lowerDiagnol[3+1]==0 → lowerDiagnol[4]==0 ✅, upperDiagnol[3+1-3]==0 → upperDiagnol[1]==0 ✅
→ TRUE ✅

Action	Code	Effect
Place	board[3][1] = 'Q'	board[3] = ".Q.."
Mark	leftRow[3] = 1	leftRow = [1,0,0,1]
Mark	lowerDiagnol[4] = 1	lowerDiagnol = [1,0,0,0,1,0,0]
Mark	upperDiagnol[1] = 1	upperDiagnol = [0,1,0,1,0,0,0]
Recurse	solve(2, ...)	↓

Board now:

Q . . .
. . . .
. . . .
. Q . .

solve(col=2, ...)
→ row = 0
leftRow[0]==0 → 1==0 → ❌ skip

→ row = 1
leftRow[1]==0 ✅, lowerDiagnol[1+2]==0 → lowerDiagnol[3]==0 ✅, upperDiagnol[3+2-1]==0 → upperDiagnol[4]==0 ✅
→ TRUE ✅

Action	Code	Effect
Place	board[1][2] = 'Q'	board[1] = ".Q.."
Mark	leftRow[1] = 1	leftRow = [1,1,0,1]
Mark	lowerDiagnol[3] = 1	lowerDiagnol = [1,0,0,1,1,0,0]
Mark	upperDiagnol[4] = 1	upperDiagnol = [0,1,0,1,1,0,0]
Recurse	solve(3, ...)	↓

Board now:

Q . . .
. . Q .
. . . .
. Q . .

solve(col=3, ...)
→ row = 0
leftRow[0]==0 → 1==0 → ❌ skip

→ row = 1
leftRow[1]==0 → 1==0 → ❌ skip

→ row = 2
leftRow[2]==0 ✅, lowerDiagnol[2+3]==0 → lowerDiagnol[5]==0 ✅, upperDiagnol[3+3-2]==0 → upperDiagnol[4]==0 → 1==0 → ❌ skip

→ row = 3
leftRow[3]==0 → 1==0 → ❌ skip

Loop ends. Returns to solve(col=2).

Back to solve(col=2, row=1) — BACKTRACKING
Action	Code	Effect
Un-place	board[1][2] = '.'	board[1] = "...."
Un-mark	leftRow[1] = 0	leftRow = [1,0,0,1]
Un-mark	lowerDiagnol[3] = 0	lowerDiagnol = [1,0,0,0,1,0,0]
Un-mark	upperDiagnol[4] = 0	upperDiagnol = [0,1,0,1,0,0,0]

Loop continues: row = 2 → leftRow[2]==0 ✅, lowerDiagnol[2+2]==0 → lowerDiagnol[4]==0 → 1==0 → ❌ skip

row = 3 → leftRow[3]==0 → 1==0 → ❌ skip

Loop ends. Returns to solve(col=1).

Back to solve(col=1, row=3) — BACKTRACKING
Action	Code	Effect
Un-place	board[3][1] = '.'	board[3] = "...."
Un-mark	leftRow[3] = 0	leftRow = [1,0,0,0]
Un-mark	lowerDiagnol[4] = 0	lowerDiagnol = [1,0,0,0,0,0,0]
Un-mark	upperDiagnol[1] = 0	upperDiagnol = [0,0,0,1,0,0,0]

Loop ends (row was 3, last). Returns to solve(col=0).

Back to solve(col=0, row=0) — BACKTRACKING
Action	Code	Effect
Un-place	board[0][0] = '.'	board[0] = "...."
Un-mark	leftRow[0] = 0	leftRow = [0,0,0,0]
Un-mark	lowerDiagnol[0] = 0	lowerDiagnol = [0,0,0,0,0,0,0]
Un-mark	upperDiagnol[3] = 0	upperDiagnol = [0,0,0,0,0,0,0]

Loop continues: row = 1

→ row = 1
Check: all three arrays at 0 → TRUE ✅

Place Q at (1,0), recurse... (this path eventually finds the second solution)

. Q . .
Q . . .
. . Q .
. . . Q

col == 4 → ans.push_back(board) ✅ → Solution #2 saved!

Final Result
ans = [
    ["Q...", "...Q", "..Q.", ".Q.."],
    ["...Q", ".Q..", "Q...", "..Q."]
]

2 solutions found for n=4. 🎉

The Key Pattern to Remember
PLACE → RECURSE → UNPLACE

Every time you go deeper (recurse), you place a queen and mark 3 arrays.
Every time you come back (return from recursion), you erase the queen and unmark those same 3 arrays.

This is the entire backtracking idea: try it, if it doesn't work, undo it and try the next option.

*/