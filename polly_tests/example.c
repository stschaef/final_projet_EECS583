#include <stdio.h>

int main() {    
    int n = 40, m = 20;

    int A[n + m + 1][n + m + 1];
    int B[n + m + 1][n + m + 1];

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        A[i + n + 1][j] = A[i + n][j] + A[i + n + 1][j - 1];
      }
      A[i + n + 1][i + m + 1] = A[i + n][i + m + 1] + A[i + n + 1][i + m];
    }

    printf("%d",1);
    
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        B[i][j] = B[i - 1][j] + B[i][j - 1];
      }
      B[i][i + m + 1] = B[i - 1][i + m] + B[i][i + m];
    }
    
    return 0;
}