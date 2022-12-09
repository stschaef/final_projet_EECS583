#include <stdio.h>

#define N 1536
float A[32][64];
float B[64][128];
float C[32][128];
float A1[N];
float B1[N];
float C1[N];
// void init_array()
// {
//     int i, j;

//     for (i = 0; i < N; i++)
//     {
//         for (j = 0; j < N; j++)
//         {
//             A[i][j] = (1 + (i * j) % 1024) / 2.0;
//             B[i][j] = (1 + (i * j) % 1024) / 2.0;
//         }
//     }
// }

// void print_array()
// {
//     int i, j;

//     for (i = 0; i < N; i++)
//     {
//         for (j = 0; j < N; j++)
//         {
//             fprintf(stdout, "%lf ", C[i][j]);
//             if (j % 80 == 79)
//                 fprintf(stdout, "\n");
//         }
//         fprintf(stdout, "\n");
//     }
// }

int main()
{
    int i, j, k;
    double t_start, t_end;

    // init_array();

    // for(i=0; i<N; i++)  {
    //     C1[i] = A1[i] + B1[i];
    // }

    for (i = 0; i < 32; i++)
    {
        for (j = 0; j < 128; j++)
        {
            C[i][j] = 0;
            for (k = 0; k < 64; k++)
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
        }
    }

    // _pc_set_dim_count(2);
    // _pc_set_dim_length(0, 128);
    // _pc_set_dim_length(1, 32);

    // __pcf C_v = _pc_set1_f(0);

    // for(k=0; k<64; k++)
    //     // load from A: (0 * 32 + 64 * 128) * 4 / 64
    //     __pcf A_v = _pc_load_f(A + k, {0, 64});

    //     // load from B
    //     __pcf B_v = _pc_load_f(B + k * 64, {1, 0});

    //     __pcf mult_v = _pc_mul_f(A_v, B_v);

    //     C_v = _pc_add_f(C_v, mult_v);

    // _pc_store_f(C, C_v, {1, 32});

#ifdef TEST
    print_array();
#endif
    return 0;
}