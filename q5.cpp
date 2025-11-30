#include <iostream>
using namespace std;

/* ----------------------------------------------------------
   (a) DIAGONAL MATRIX  (stores only n elements)
-----------------------------------------------------------*/
class Diagonal {
    int n;
    int *A;
public:
    Diagonal(int n) {
        this->n = n;
        A = new int[n];
        for(int i = 0; i < n; i++) A[i] = 0;
    }

    void set(int i, int j, int x) {
        if(i == j) A[i-1] = x;
    }

    int get(int i, int j) {
        if(i == j) return A[i-1];
        return 0;
    }

    void display() {
        cout << "\nDiagonal Matrix:\n";
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};

/* ----------------------------------------------------------
   (b) TRI-DIAGONAL MATRIX  (stores 3n - 2 elements)
-----------------------------------------------------------*/
class TriDiagonal {
    int n;
    int *A; // size = 3n - 2
public:
    TriDiagonal(int n) {
        this->n = n;
        A = new int[3*n - 2];
        for(int i = 0; i < 3*n - 2; i++) A[i] = 0;
    }

    void set(int i, int j, int x) {
        if(i - j == 1) A[i - 2] = x;              // Lower diagonal
        else if(i == j) A[n - 1 + i - 1] = x;     // Main diagonal
        else if(j - i == 1) A[2*n - 1 + i - 1] = x; // Upper diagonal
    }

    int get(int i, int j) {
        if(i - j == 1) return A[i - 2];
        else if(i == j) return A[n - 1 + i - 1];
        else if(j - i == 1) return A[2*n - 1 + i - 1];
        return 0;
    }

    void display() {
        cout << "\nTri-Diagonal Matrix:\n";
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};

/* ----------------------------------------------------------
   (c) LOWER TRIANGULAR MATRIX  (stores n(n+1)/2 elements)
-----------------------------------------------------------*/
class LowerTriangular {
    int n;
    int *A;
public:
    LowerTriangular(int n) {
        this->n = n;
        A = new int[n*(n+1)/2];
        for(int i = 0; i < n*(n+1)/2; i++) A[i] = 0;
    }

    int index(int i, int j) {
        return (i*(i-1))/2 + (j-1);
    }

    void set(int i, int j, int x) {
        if(i >= j)
            A[index(i,j)] = x;
    }

    int get(int i, int j) {
        if(i >= j)
            return A[index(i,j)];
        return 0;
    }

    void display() {
        cout << "\nLower Triangular Matrix:\n";
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};

/* ----------------------------------------------------------
   (d) UPPER TRIANGULAR MATRIX  (stores n(n+1)/2 elements)
-----------------------------------------------------------*/
class UpperTriangular {
    int n;
    int *A;
public:
    UpperTriangular(int n) {
        this->n = n;
        A = new int[n*(n+1)/2];
        for(int i = 0; i < n*(n+1)/2; i++) A[i] = 0;
    }

    int index(int i, int j) {
        return (j*(j-1))/2 + (i-1);
    }

    void set(int i, int j, int x) {
        if(i <= j)
            A[index(i,j)] = x;
    }

    int get(int i, int j) {
        if(i <= j)
            return A[index(i,j)];
        return 0;
    }

    void display() {
        cout << "\nUpper Triangular Matrix:\n";
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};

/* ----------------------------------------------------------
   (e) SYMMETRIC MATRIX  (stores n(n+1)/2 elements)
-----------------------------------------------------------*/
class SymmetricMatrix {
    int n;
    int *A;
public:
    SymmetricMatrix(int n) {
        this->n = n;
        A = new int[n*(n+1)/2];
        for(int i = 0; i < n*(n+1)/2; i++) A[i] = 0;
    }

    int index(int i, int j) {
        if(i >= j)
            return (i*(i-1))/2 + (j-1);
        else
            return (j*(j-1))/2 + (i-1);
    }

    void set(int i, int j, int x) {
        A[index(i,j)] = x;
    }

    int get(int i, int j) {
        return A[index(i,j)];
    }

    void display() {
        cout << "\nSymmetric Matrix:\n";
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};

/* ----------------------------------------------------------
   MAIN PROGRAM — ALL PARTS RUN HERE
-----------------------------------------------------------*/
int main() {
    int n = 4;

    Diagonal d(n);
    d.set(1,1,5); d.set(2,2,8); d.set(3,3,3); d.set(4,4,6);
    d.display();

    TriDiagonal td(n);
    td.set(1,1,4); td.set(1,2,7);
    td.set(2,1,1); td.set(2,2,5); td.set(2,3,2);
    td.set(3,2,9); td.set(3,3,6); td.set(3,4,3);
    td.set(4,3,8); td.set(4,4,2);
    td.display();

    LowerTriangular lt(n);
    lt.set(1,1,5);
    lt.set(2,1,2); lt.set(2,2,8);
    lt.set(3,1,3); lt.set(3,2,7); lt.set(3,3,1);
    lt.set(4,1,4); lt.set(4,2,9); lt.set(4,3,6); lt.set(4,4,2);
    lt.display();

    UpperTriangular ut(n);
    ut.set(1,1,5); ut.set(1,2,3); ut.set(1,3,7); ut.set(1,4,2);
    ut.set(2,2,8); ut.set(2,3,4); ut.set(2,4,1);
    ut.set(3,3,6); ut.set(3,4,9);
    ut.set(4,4,2);
    ut.display();

    SymmetricMatrix sm(n);
    sm.set(1,1,5); sm.set(1,2,3); sm.set(1,3,7); sm.set(1,4,2);
    sm.set(2,2,8); sm.set(2,3,4); sm.set(2,4,1);
    sm.set(3,3,6); sm.set(3,4,9);
    sm.set(4,4,2);
    sm.display();

    return 0;
}
