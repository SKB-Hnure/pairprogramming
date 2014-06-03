#include <iostream>
#include <stdio.h>

int main()
{ int k=1;
    int A[9][9];
    for (int i=0;i<9;i++)
     for (int j=0;j<9;j++)
     A[i][j]=0;

    for (int n=0;n<=16;n++)
    { if (n<=8)
    {
    for (int i=n;i>=0;i--)
     for (int j=0;j<=n;j++)
      if ((i+j)==n)
      {
     if (A[i][j]==0)
     {A[i][j]=k;
      k++;
      }
      }
    }
    else
    {
    for (int i=8;i>=n-8;i--)
     for (int j=n-8;j<=8;j++)
      if ((i+j)==n)
      {
     if (A[i][j]==0)
     {
     A[i][j]=k;
      k++;
      }
      }
    }
   }
    for (int i=0;i<9;i++)
    {
     for (int j=0;j<9;j++)
      printf("%5d", A[i][j]);
      printf("\n");
      }
    return 0;
}
