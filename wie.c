#include <stdio.h>
#include <string.h>
#include <stdio.h>
#define MAX 1000
char board[MAX][MAX+1];
char x[MAX+1], y[MAX+1];
int main(int argc, char *argv[])
{
  int n, i, j, r;
  r = scanf("%d\n", &n);
  memset(x, '.', n);
  memset(y, '.', n);
  for(i=0; i<n; i++)
  {
    r = scanf("%s\n", board[i]);
    int found_W = 0;
    for(j=0; j<n; j++)
    {
      if(board[i][j] == 'W')
      {
        x[j] = 'W';
        found_W = 1;
      }
    }
    if(found_W == 1)
      y[i] = 'W';
  }
  int curx = 0;
  for(i=0; i<n; i++)
  {
    if(y[i] != 'W')
    {
      /*printf("enter i: %d\n", i);*/
      for(j=curx; j<n; j++, curx++)
      {
        if(x[curx] != 'W')
          break;
      }
      board[i][curx++] = 'W';
      /*printf("%d %d\n", i, curx);*/
    }
    board[i][n] = '\0';
    printf("%s\n", board[i]);
  }
  return 0;
}
