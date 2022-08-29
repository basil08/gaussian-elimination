#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

const int N = 3;
const float TOLERANCE = pow(10, -6);

void printA(float A[N][N]) {
    for (int i = 0; i < N; i ++) {
         for (int j = 0; j < N; j++) {
            cout << A[i][j] << " ";
         }
         cout << endl;
    }
    cout << "---------" << endl;
}

void printb(float b[N][1]) {
    for (int i = 0; i < N; i ++)
            cout << b[i][0] << endl;
    cout << "---------" << endl;
}


// Performs gaussian elimination by partial pivots
void gaussEliminationByPartialPivot(float A[N][N], float b[N][1]) {
    float alpha;

    for (int i = 0; i < N-1; i++) {
        // pivot element is A[i][i];
        for (int j = i+1; j < N; j++) {
            alpha = - (A[j][i] / A[i][i]);

            for (int k = 0; k < N; k++) {
                // k keeps track of columns while jth row is modified
                A[j][k] = A[j][k] + alpha * A[i][i];

                if (A[j][k] < TOLERANCE) {
                    A[j][k] = 0;
                }
            }

            b[j][0] = b[j][0] + alpha * b[i][0];
        }
    }
}

// Back subsitution
void printSolutions(float A[N][N], float b[N][1]) {
    cout << "TODO: printSolutions" << endl;
}

int main(int argc, char** argv) {
    // input matrix A (nXn)
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cin >> A[i][j];
    //     }
    // }
    // // input matrix b (nX1)
    // for (int i = 0; i < N; i++) {
    //     cin >> b[i][0];
    // }

    float A[N][N] = {{3, -0.1, 0.2}, {0.1, 7, -0.3}, {0.3, -0.2, 10}};
    float b[N][1] = {{7.85}, {-19.3}, {71.4}};

    // debug
    printA(A);
    printb(b);

    // perform gauss elimination

    gaussEliminationByPartialPivot(A, b);

    printA(A);
    printb(b);

    printSolutions(A, b);

}