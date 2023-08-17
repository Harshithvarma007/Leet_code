bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int row_map[9][9] = {0};
    int column_map[9][9] = {0};
    int subgrid_map[9][9] = {0};

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                int number = board[i][j] - '1';

                if (row_map[i][number]++ > 0 || column_map[j][number]++ > 0 || subgrid_map[(i / 3) * 3 + j / 3][number]++ > 0) {
                    return false;
                }
            }
        }
    }

    return true;
}