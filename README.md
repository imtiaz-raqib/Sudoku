# Sudoku
This C program takes a .txt file with a sudoku puzzle and spits out the solved sudoku puzzle within the terminal. If the solver deems the puzzle is not solavable, it will say "Unable to solve puzzle"\
The .txt file will be arranged in 9x9 square, with the empty boxes being represented by a 0.

Example

0 0 2 0 0 0 5 0 0\
0 1 0 7 0 5 0 2 0\
4 0 0 0 9 0 0 0 7\
0 4 9 0 0 0 7 3 0\
8 0 1 0 3 0 4 0 9\
0 3 6 0 0 0 2 1 0\
2 0 0 0 8 0 0 0 4\
0 8 0 9 0 2 0 6 0\
0 0 7 0 0 0 8 0 0

The program is run by compiling sudoku_solver.c and running it with followed by the .txt file

Example

imtiazud@Yanet: ~> gcc -Wall sudoku_solver.c -o sudoku\
imtiazud@Yanet: ~> ./sudoku 001.txt
