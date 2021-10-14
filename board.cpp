Let's take a standard problem.
N-Queens Problem: Given a chess board having  cells, we need to place  queens in such a way that no queen is attacked by any other queen. A queen can attack horizontally, vertically and diagonally.

So initially we are having  unattacked cells where we need to place  queens. Let's place the first queen at a cell , so now the number of unattacked cells is reduced, and number of queens to be placed is . Place the next queen at some unattacked cell. This again reduces the number of unattacked cells and number of queens to be placed becomes . Continue doing this, as long as following conditions hold.

The number of unattacked cells is not .
The number of queens to be placed is not .
If the number of queens to be placed becomes , then it's over, we found a solution. But if the number of unattacked cells become , then we need to backtrack, i.e. remove the last placed queen from its current cell, and place it at some other cell. We do this recursively.
Complete algorithm is given below:

is_attacked( x, y, board[][], N)
    //checking for row and column
    if any cell in xth row is 1
        return true
    if any cell in yth column is 1
        return true

    //checking for diagonals
    if any cell (p, q) having p+q = x+y is 1          
        return true
    if any cell (p, q) having p-q = x-y is 1
        return true
    return false


N-Queens( board[][], N )
    if N is 0                     //All queens have been placed
        return true
    for i = 1 to N {
        for j = 1 to N {
            if is_attacked(i, j, board, N) is true
                skip it and move to next cell
            board[i][j] = 1            //Place current queen at cell (i,j)
            if N-Queens( board, N-1) is true    // Solve subproblem
                return true                   // if solution is found return true
            board[i][j] = 0            /* if solution is not found undo whatever changes 
                                       were made i.e., remove  current queen from (i,j)*/
        }
    }
    return false
