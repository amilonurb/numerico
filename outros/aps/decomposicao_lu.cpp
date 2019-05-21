#include "lu.h"

void print_matrix(const vvd &matriz, const string &title) {
    cout << title << '\n';
    int i, j;
    loop(i, 0, matriz[0].size()) {
        loop(j, 0, matriz[i].size()) {
            cout << matriz[i][j] << '\t';
        }
        cout << endl;
    }
}

double sum(const vvd &a, const vvd &b, int j, int i) {
    double sum = 0.0;
    int k;
    loop(k, 0, i) {
        sum += a[k][j] * b[i][k];
    }
    return sum;
}

void lu(const vvd &matriz) {
    int n = matriz[0].size();

    vvd lower = vvd(n, vector<double>(n));
    vvd upper = vvd(n, vector<double>(n));

    print_matrix(matriz, "Matriz A");

    loop(j, 0, n) {
        lower[j][j] = 1;
        loop_eq(i, 0, j) {
            upper[i][j] = matriz[i][j] - sum(upper, lower, j, i);
        }

        loop(i, j, n) {
            lower[i][j] = (matriz[i][j] - sum(upper, lower, j, i)) / upper[j][j];
        }
    }
    
    cout << '\n';
    print_matrix(lower, "Matriz L");

    cout << '\n';
    print_matrix(upper, "Matriz U");
}