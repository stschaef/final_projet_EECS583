#include <stdio.h>

int main() {    
    int n = 40, m = 20;

    int A[n + m + 1][n + m + 1];

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        A[i][j] = A[i - 1][j] + A[i][j - 1];
      }
      A[i][i + m + 1] = A[i - 1][i + m] + A[i][i + m];
    }

    return 0;
}