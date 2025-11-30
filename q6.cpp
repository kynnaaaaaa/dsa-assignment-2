#include <iostream>
using namespace std;

void transpose(int A[][3], int nz) {
    int B[20][3];
    B[0][0] = A[0][1];
    B[0][1] = A[0][0];
    B[0][2] = A[0][2];

    int k = 1;
    for (int i = 0; i < A[0][1]; i++) {
        for (int j = 1; j <= nz; j++) {
            if (A[j][1] == i) {
                B[k][0] = A[j][1];
                B[k][1] = A[j][0];
                B[k][2] = A[j][2];
                k++;
            }
        }
    }

    for (int i = 0; i < k; i++)
        cout << B[i][0] << " " << B[i][1] << " " << B[i][2] << endl;
}

int main() {
    int A[5][3] = {
        {3, 3, 3},
        {0, 0, 5},
        {1, 2, 7},
        {2, 1, 9}
    };

    transpose(A, 3);
}



b)#include <iostream>
using namespace std;

struct Term { int r, c, v; };

int main() {
    Term A[3] = {{0,0,3}, {0,2,5}, {2,1,8}};
    Term B[3] = {{0,0,3}, {1,2,5}, {2,1,2}};

    Term C[10];
    int i = 0, j = 0, k = 0;

    while (i < 3 && j < 3) {
        if (A[i].r == B[j].r && A[i].c == B[j].c) {
            C[k] = {A[i].r, A[i].c, A[i].v + B[j].v};
            i++; j++; k++;
        }
        else if (A[i].r < B[j].r || 
            (A[i].r == B[j].r && A[i].c < B[j].c)) {
            C[k++] = A[i++];
        }
        else {
            C[k++] = B[j++];
        }
    }

    while (i < 3) C[k++] = A[i++];
    while (j < 3) C[k++] = B[j++];

    for (int p = 0; p < k; p++)
        cout << C[p].r << " " << C[p].c << " " << C[p].v << endl;
}

