#include <bits/stdc++.h>

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
    loop(i, 0, x.size()) {
        cout << "X[" << (i + 1) << "] = " << x[i] << '\t';
    }
    cout << endl;
}

int main() {
    vvd ex1_a = {{3.0, 3.0, 1.0}, {2.0, 2.0, -1.0}, {1.0, -1.0, 5.0}};
    vd ex1_b = {7.0, 3.0, 5.0};

    vvd ex2_a = {{2.0, -3.0, 1.0}, {4.0, -6.0, -1.0}, {1.0, 2.0, 1.0}};
    vd ex1_b = {-5.0, -7.0, 4.0};

    vvd ex3_a = {{1.0, 2.0, 1.0}, {2.0, 3.0, 1.0}, {3.0, 5.0, 2.0}};
    vd ex1_b = {3.0, 5.0, 1.0};

    vvd ex4_a_a = {{1.0, 4.0, 0.0}, {2.0, -1.0, 0.0}, {0.0, 3.0, 1.0}};
    vd ex1_b = {6.0, 3.0, 5.0};

    vvd ex4_a_b = {{1.0, 4.0, 1.0}, {2.0, -1.0, 2.0}, {1.0, 3.0, 1.0}};
    vd ex1_b = {6.0, 3.0, 5.0};

    vvd ex4_a_c = {{1.0, 4.0, -1.0}, {2.0, -1.0, -2.0}, {-1.0, 3.0, 1.0}};
    vd ex1_b = {6.0, 3.0, 5.0};

    vvd ex5_a = {
        {-1.0, 0.25, 0.0, 0.25, 0.0, 0.0, 0.0, 0.0, 0.0},
        {0.25, -1.0, 0.25, 0.0, 0.25, 0.0, 0.0, 0.0, 0.0},
        {0.0, 0.25, -1.0, 0.0, 0.0, 0.25, 0.0, 0.0, 0.0},
        {0.25, 0.0, 0.0, -1.0, 0.25, 0.0, 0.25, 0.0, 0.0},
        {0.0, 0.25, 0.0, 0.25, -1.0, 0.25, 0.0, 0.25, 0.0},
        {0.0, 0.0, 0.25, 0.0, 0.25, -1.0, 0.0, 0.0, 0.25},
        {0.0, 0.0, 0.0, 0.25, 0.0, 0.0, -1.0, 0.25, 0.0},
        {0.0, 0.0, 0.0, 0.0, 0.25, 0.0, 0.25, -1.0, 0.25},
        {0.0, 0.0, 0.0, 0.0, 0.0, 0.25, 0.0, 0.25, -1.0}
    };
    vd ex1_b = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.25, -0.25, -0.25};

    cout << "LISTA 08 - Eliminacao de Gauss\n";
    cout << "Questao 1";
    solveGauss(ex1_a, ex1_b);
    cout << "\n\n";

    cout << "Questao 2\n";
    solveGauss(ex2_a, ex2_b);
    cout << "\n\n";

    cout << "Questao 3\n";
    solveGauss(ex3_a, ex3_b);
    cout << "\n\n";

    cout << "Questao 4a\n";
    solveGauss(ex4_a_a, ex4_b_a);
    cout << "\n\n";

    cout << "Questao 4b\n";
    solveGauss(ex4_a_b, ex4_b_b);
    cout << "\n\n";

    cout << "Questao 4c\n";
    solveGauss(ex4_a_c, ex4_b_c);
    cout << "\n\n";

    cout << "Questao 5\n";
    solveGauss(ex5_a, ex5_b);
    cout << "\n\n";
    return 0;
}