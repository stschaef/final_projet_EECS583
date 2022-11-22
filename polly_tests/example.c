#include <stdio.h>

int main() {
    int H = 100, W = 100;
    int C[H][W], A[H][W], M[H][W];
    int KW = 3, KH = 3;
    for (int i = 0; i < H - KH; ++i) {
        for (int j = 0; j < W - KW; ++j) {
            C[i][j] = 0.;
            for (int k = 0; k < KH; ++k) {
                for (int l = 0; l < KW; ++l) {
                    C[i][j] += A[i+k][j+l] * M[k][l];
                }
            }
        }
    }
            
    // int n = 4, m = 2;

    // int A[n + m + 1][n + m + 1];

    // for (int i = 1; i <= n; i++) {
    //   for (int j = 1; j <= m; j++) {
    //     A[i][j] = A[i - 1][j] + A[i][j - 1];
    //     printf("%d ", A[i][j]);
    //   }
    //   A[i][i + m + 1] = A[i - 1][i + m] + A[i][i + m];
    // }

  return 0;
}