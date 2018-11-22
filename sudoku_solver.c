#include <stdio.h>
#include <stdlib.h>

int solve_sudoku(int sudoku[][9], int row, int col);
int check(int sudoku[][9], int row, int col, int num);
int printArray(int pary[][9]);

int main(int argc, char *argv[])
{
   int i, j;

   /* printf("Check for instance file: %s\n", argv[1]); */

   FILE *fp = fopen(argv[1], "r");
    if (fp == 0) {
      printf("\nCould not find %s\n", argv[1]);
      exit(0);
    }

    int sudoku[9][9];
    for (i = 0; i < 9; i++) 
      {
	for (j = 0; j < 9; j++) 
	  {
	    char s[] = "0";
	    fscanf(fp, " %c", &s[0]);
	    sudoku[i][j] = atoi(s);
	  }
      }
    printf("\n<< Sudoku Puzzle >>\n");
    printf("------------------------\n\n");
    printArray(sudoku);
    printf("------------------------\n\n");
    printf("\n<< Solved sudoku >>\n");
    printf("------------------------\n");

    if(solve_sudoku(sudoku, 0, 0))
    {
      printf("\n");
        for(i = 1; i < 10; ++i)
        {
	  for(j = 1; j < 10; ++j) {
	    printf(" %d", sudoku[i - 1][j - 1]);
	  }
	  printf("\n");
	}   
    printf("------------------------\n\n");
    printf("\n");
    }

    else
      {
	printf("Unable to solve sudoku\n");
	printf("------------------------\n\n");
      }

    return 0;
}

int solve_sudoku(int sudoku[][9], int row, int col)
{
    int i;
    if (row < 9 && col < 9)
    {
        if (sudoku[row][col] != 0)
        {
            if ((col + 1) < 9) 
	      return solve_sudoku(sudoku, row, col + 1);

            else if ((row + 1) < 9) 
	      return solve_sudoku(sudoku, row + 1, 0);

            else return 1;
        }
        else
        {
            for (i = 0; i < 9; ++i)
            {
                if(check(sudoku, row, col, i + 1))
                {
                    sudoku[row][col] = i + 1;
                    if ((col + 1) < 9)
		      /* printf("%d\n", col + 1); */
                    {
                        if (solve_sudoku(sudoku, row, col + 1)) 
			  return 1;
                        
			else 
			  sudoku[row][col] = 0;
                    }
                    else if ((row + 1) < 9)
                    {
                        if (solve_sudoku(sudoku, row + 1, 0)) 
			  return 1;
                        
			else 
			  sudoku[row][col] = 0;
                    }
                    else 
		      return 1;
                }
            }
        }
        return 0;
    }
    else 
      return 1;
}


int check(int sudoku[][9], int row, int col, int num)
{
    int row_begin = (row / 3) * 3;
    int col_begin = (col / 3) * 3;

    /* printf("Check for beginning of row:  %d\n", row_begin); */
    /* printf("Check for beginning of col:  %d\n", col_begin); */

    int i;
    for(i = 0; i < 9; ++i)
    {
        if (sudoku[row][i] == num) 
	  return 0;
        if (sudoku[i][col] == num) 
	  return 0;
        if (sudoku[row_begin + (i % 3)][col_begin + (i / 3)] == num) 
	  return 0;
    }
    return 1;
}


int printArray(int pary[][9])
{
    int r,c; //row and col counter
 
    for (r = 0; r < 9; r++)
    {
        for (c = 0; c < 9; c++)
        {
            printf(" %d", pary[r][c]);
        }
        printf("\n");
    }
    return 0;
}
