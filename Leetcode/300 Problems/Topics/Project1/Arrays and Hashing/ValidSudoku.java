import java.util.HashMap;
import java.util.HashSet;

public class ValidSudoku{
    public static boolean checkBox(char[][] board, int idxI, int idxJ) {
        HashSet<Character> blockSet = new HashSet<>();
        //if idxI = 3 and indJ = 0
        //rows = 6 and cols = 3
        int rows = idxI + 3;
        int cols = idxJ + 3;
        //and because i initializes to idxI but only goes to rows, we loop 3 times (once for each row)
        for (int i = idxI; i < rows; i++) {
            //same for columns
            for (int j = idxJ; j < cols; j++) {
                if (board[i][j] == '.') {
                    continue;
                }

                if (blockSet.contains(board[i][j])) {
                    return false;
                }

                blockSet.add(board[i][j]);
            }
        }

        return true;
    }

    //[0,0], [0,3],[0,6]
    //[3,0], [3,3],[3,6]
    //[6,0], [6,3],[6,6]
    public static boolean isValidSudoku(char[][] board) {

        //check row and column
        for (int i = 0; i < 9; ++i) {
            HashSet<Character> rowSet = new HashSet<Character>();
            HashSet<Character> columnSet = new HashSet<Character>();
            for (int j = 0; j < 9; ++j) {
                char r = board[i][j];
                char c = board[j][i];

                if (r != '.') {
                    if (rowSet.contains(r)) {
                        return false;
                    }else {
                        rowSet.add(r);
                    }
                }

                if (c != '.') {
                    if (columnSet.contains(c)) {
                        return false;
                    }else {
                        columnSet.add(c);
                    }
                }
            }
        }
        //check box
        for (int i = 0; i < 9; i = i + 3) {
            for (int j = 0; j < 9; j = j + 3) {
                //checkBlock will return true if valid
                if (!checkBox(board, i, j)) {
                    return false;
                }
            }
        }
        return true;
    }
}
