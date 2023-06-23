def comprobar(board, row, column):
    for i in range(row):
        if board[i] == column or \
            board[i] - i == column - row or \
            board[i] + i == column + row:
            return False

    return True

def Nqueens(board, row, n):
    if row == n:
        return True

    for column in range(n):
        if comprobar(board, row, column):
            board[row] = column
            if Nqueens(board, row + 1, n):
                return True
            board[row] = -1  # Sin solución, se deshace la colocación

    return False  # No se pudo colocar una reina en ninguna de las columnas de esta fila

def print_board(board, n):
    """Imprime el tablero con las reinas colocadas."""
    for row in range(n):
        line = ""
        for column in range(n):
            if board[row] == column:
                line += "Q "
            else:
                line += ". "
        print(line)
    print("\n")
    
def solveNQueens(n):
    """Resuelve el problema de las N reinas."""
    board = [-1] * n
    if Nqueens(board, 0, n):
        print_board(board, n)
        return True
    else:
        print("No hay solución.")
        return False
    
solveNQueens(8)