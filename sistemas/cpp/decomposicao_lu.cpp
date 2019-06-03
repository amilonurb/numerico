#include <bits/stdc++.h>

using namespace std;

typedef vector<double> vd;
typedef vector<vd> vvd;

#define loop(init_var, init_value, range) for (int init_var = (init_value); init_var < (range); init_var++)
#define loop_eq(init_var, init_value, range) for (int init_var = (init_value); init_var <= (range); init_var++)

void print_matriz(vvd&, string&);
double sum(vvd&, vvd&, int, int);
void lu(vvd&);

void print_matriz(vvd &matriz, const string &title) {
    cout << title << '\n';
    loop(i, 0, matriz[0].size()) {
        loop(j, 0, matriz[i].size()) {
            cout << matriz[i][j] << '\t';
        }
        cout << endl;
    }
}

double sum(vvd &a, vvd &b, int j, int i) {
    double sum = 0.0;
    loop(k, 0, i) {
        sum += a[k][j] * b[i][k];
    }
    return sum;
}

void lu(vvd &matriz) {
    int n = matriz[0].size();
    vvd lower = vvd(n, vector<double>(n));
    vvd upper = vvd(n, vector<double>(n));

    print_matriz(matriz, "Matriz A");

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
    print_matriz(lower, "Matriz L");

    cout << '\n';
    print_matriz(upper, "Matriz U");
}