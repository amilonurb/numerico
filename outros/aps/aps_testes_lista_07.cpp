#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<double>> vvd;

#define loop(init_var, init_value, range) for (init_var = init_value; init_var < range; init_var++)
#define loop_eq(init_var, init_value, range) for (init_var = init_value; init_var <= range; init_var++)

void print_matrix(const vvd &matriz, const string &title) {
    cout << title << '\n';
    loop(i, 0, matriz[0].size()) {
        loop(j, 0, matriz[i].size()) {
            cout << matriz[i][j] << '\t';
        }
        cout << endl;
    }
}

double sum(const vvd &a, const vvd &b, int j, int i) {
    double sum = 0.0;
    loop(k, 0, i) {
        sum += a[k][j] * b[i][k];
    }
    return sum;
}

void lu(const vvd &matriz) {
    int n = matriz[0].size();

    vvd lower = vvd(n, vector<double>(n));
    vvd upper = vvd(n, vector<double>(n));

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

int main() {
    vvd ex1 = {{5.0, 2.0, 1.0}, {-1.0, 4.0, 2.0}, {2.0, -3.0, 10.0}};
    vvd ex2 = {{2.0, 3.0, -1.0}, {1.0, 0.0, 2.0}, {0.0, 3.0, -1.0}};
    vvd ex3 = {{10.0, 7.0, 8.0}, {7.0, 5.0, 6.0}, {8.0, 6.0, 10.0}};
    vvd ex4 = {{2.0, 5.0, 3.0}, {5.0, 2.0, 1.0}, {1.0, 3.0, 6.0}};
    vvd ex5 = {{8.0, -4.0, -2.0}, {-4.0, 10.0, -2.0}, {-2.0, -2.0, 10.0}};

    cout << "LISTA 07 - Decomposicao LU\n";
    cout << "Questao 1";
    lu(ex1);
    cout << "\n\n";

    cout << "Questao 2\n";
    lu(ex2);
    cout << "\n\n";

    cout << "Questao 3\n";
    lu(ex3);
    cout << "\n\n";

    cout << "Questao 4\n";
    lu(ex4);
    cout << "\n\n";

    cout << "Questao 5\n";
    lu(ex5);
    cout << "\n\n";
    return 0;
}