﻿#include <bits/stdc++.h>

using namespace std;

typedef vector<double> vd;
typedef vector<vector<double>> vvd;

#define each(element, collection) for (auto &element : collection)
#define loop(init_var, init_value, range) for (int init_var = (init_value); init_var < (range); init_var++)
#define loop_rv(init_var, init_value, range) for (int init_var = (init_value); init_var >= (range); init_var--)
#define loop_eq(init_var, init_value, range) for (int init_var = (init_value); init_var <= (range); init_var++)

void print_vector(const vd &vetor, const string &title);
void print_matrix(const vvd &matriz, const string &title);
void solveGauss(vvd &a, vd &b);
void solveLinearSystem(const vvd &a, const vd &b);

int main() {
    vvd a = {
        {2.0, 3.0, -1.0},
        {4.0, 4.0, -3.0},
        {2.0, -3.0, 1.0}
    };

    vd b = {5.0, 3.0, -1.0};

    solveGauss(a, b);
    return 0;
}

void print_vector(const vd &vetor, const string &title) {
    cout << title << '\n';
    each(v, vetor) {
        cout << v << '\t'
    }
    cout << endl;
}

void print_matrix(const vvd &matriz, const string &title) {
    cout << title << '\n';
    loop(i, 0, matriz[0].size()) {
        loop(j, 0, matriz[i].size()) {
            cout << matriz[i][j] << '\t';
        }
        cout << endl;
    }
}

void solveGauss(vvd &a, vd &b) {
    int n = b.size();
    loop(k, 0, n - 1) {
        loop(i, k + 1, n) {
            double m = a[i][k] / a[k][k];
            loop(j, k, n) {
                a[i][j] = a[i][j] - m * a[k][j];
            }
            b[i] = b[i] - m * b[k];
        }
    }
    solveLinearSystem(a, b);
}

void solveLinearSystem(const vvd &a, const vd &b) {
    int n = b.size();
    vd x = vd(n, INT_MIN);
    x[n - 1] = b[n - 1] / a[n - 1][n - 1];
    loop_rv(i, n - 1, 0) {
        double sum = 0.0;
        loop(j, i + 1, n) {
            sum += a[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / a[i][i];
    }

    cout << "Solucao do Sistema\n";
    for (int i = 0; i < x.size(); i++) {
        cout << "X[" << (i + 1) << "] = " << x[i] << '\t';
    }
    cout << endl;
}